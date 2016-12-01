#include "lidarone.h"
#include <QThread>
#include <QMutex>
#include <QDebug>
#include <QByteArray>

pcap_t *descr;

int global_ctr = 0;		//to print out the packet number

// PcapThread class definitions
LidarOne::LidarOne(QObject *parent):
    QThread(parent)
{

}

//overloading run() method from QThread
void LidarOne::run()
{
    //code for pcap
    char errbuf[PCAP_ERRBUF_SIZE];
    if(offline){
        const char *file;
        QByteArray ba;
        ba = fileName.toLatin1();
        file = ba.data();
        descr = pcap_open_offline(file, errbuf);
    }
    else{
        const char *port;
        QByteArray ba;
        ba = portName.toLatin1();
        port = ba.data();
        descr = pcap_open_live(port, 1248, 1, 1, errbuf);
    }

    if (descr == NULL) {
      cout << "pcap_open_live() failed: " << errbuf << endl;
      return;
    }
    struct get_packet *p = new struct get_packet;
    struct data_packet processed_packet;
    PointCloudTPtr cloud (new PointCloudT);
    for(int i = 0;;i++)
    {
        while(pause){}
        pcap_loop(descr, 1, packetHandler_I, (u_char *) p); //change last argument
        data_structure_builder_I(p->pkthdr, p->packet, processed_packet);
        cloud = extract_xyz_I(processed_packet, cloud);
        if(global_ctr == cycle_num)
        {
            emit updateCloud(NumberUpdate, cloud);
            NumberUpdate++;
            this->msleep(50);
        }

    }

    return;
}


PointCloudTPtr extract_xyz_I(struct data_packet& processed_packet, PointCloudTPtr cloud)
{
    pcl::PointXYZRGBA sample;
    for(int i = 0; i < 12; i++){
        double curr_azimuth = (processed_packet.payload[i].azimuth) * PI / 180; //convert degrees to radians
        for(int j = 0; j < 32; j++){
            double curr_dist = processed_packet.payload[i].dist[j];
            double curr_intensity = processed_packet.payload[i].intensity[j];
            double curr_elev_angle = (elev_angles[j]) * PI / 180;
            sample.x = curr_dist * sin(curr_azimuth);
            sample.y = curr_dist * cos(curr_azimuth);
            sample.z = curr_dist * sin(curr_elev_angle);
            //call function to colorize the point cloud
            colorize_point_cloud(curr_intensity, &sample);
            cloud -> points.push_back(sample);
        }
    }

    if(global_ctr > cycle_num){
        cloud -> points.clear();
        global_ctr = 0;
        //usleep(400000); //0.1s delay
    }
    global_ctr++;

    return cloud;
}
