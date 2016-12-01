#include "lidartwo.h"
#include <QThread>
#include <QMutex>
#include <QDebug>
#include<QByteArray>

pcap_t *descr1;
int global_ctr1 = 0;

//LidarTwo constructor
LidarTwo::LidarTwo(QObject *parent): QThread(parent)
{

}

//Overloading run() method from Qthread
void LidarTwo::run()
{
    //code for pcap
    char errbuf[PCAP_ERRBUF_SIZE];
    if(offline){
        const char *file;
        QByteArray ba;
        ba = fileName.toLatin1();
        file = ba.data();
        descr1 = pcap_open_offline(file, errbuf);
    }
    else{
        const char *port;
        QByteArray ba;
        ba = portName.toLatin1();
        port = ba.data();
        descr1 = pcap_open_live(port, 1248, 1, 1, errbuf);
    }
    if (descr1 == NULL) {
      cout << "pcap_open_live() failed: " << errbuf << endl;
      return;
    }
    struct get_packet *p = new struct get_packet;
    struct data_packet_II processed_packet;
    PointCloudTPtr cloud (new PointCloudT);
    for(int i = 0;;i++)
    {
        while(pause){}
        pcap_loop(descr1, 1, packetHandler_I, (u_char *) p);
        data_structure_builder_II(p->pkthdr, p->packet, processed_packet);
        cloud = extract_xyz_II(processed_packet, cloud);
        if(global_ctr1 == cycle_num1)
        {
            emit updateCloud(i, cloud);
            this->msleep(50);
        }

    }

    return;
}


PointCloudTPtr extract_xyz_II(struct data_packet_II& processed_packet, PointCloudTPtr cloud)
{
//    pcl::PointXYZRGBA sample;

//    for(int i = 0; i < 12; i++){
//        double curr_azimuth = (processed_packet.payload[i].azimuth) * PI / 180; //convert degrees to radians
//        for(int j = 0; j < 32; j++){
//            double curr_dist = processed_packet.payload[i].dist[j];
//            double curr_intensity = processed_packet.payload[i].intensity[j];
//            double curr_elev_angle = (elev_angles[j]) * PI / 180;
//            sample.x = curr_dist * sin(curr_azimuth);
//            sample.y = curr_dist * cos(curr_azimuth);
//            sample.z = curr_dist * sin(curr_elev_angle);
//            //call function to colorize the point cloud
//            colorize_point_cloud(curr_intensity, &sample);
//            cloud -> points.push_back(sample);
//        }
//    }

//    if(global_ctr1 > cycle_num1){
//        cloud -> points.clear();
//        global_ctr1 = 0;
//        //usleep(400000); //0.1s delay
//    }
//    global_ctr1++;

//    return cloud;

    //static pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZRGBA>);
    pcl::PointXYZRGBA sample;

    double curr_azimuth, curr_elevation, curr_distance, curr_intensity;

    // static int pkt_cnt = 0;
    // cout << pkt_cnt++ << endl;

    for(int i = 2; i < 1452; i = i + 10){
        curr_azimuth = double((processed_packet.payload[i] << 8) | processed_packet.payload[i + 1]);
        curr_elevation = double((processed_packet.payload[i + 2] << 8) | processed_packet.payload[i + 3]);
        curr_distance = double((processed_packet.payload[i + 4] << 8) | processed_packet.payload[i + 5]);
        curr_intensity = double((processed_packet.payload[i + 6] << 8) | processed_packet.payload[i + 7]);

        curr_azimuth = (curr_azimuth / 100) * PI / 180;
        curr_elevation = (curr_elevation / 100 - 15) * PI / 180; // bcz. a 15 deg offset was applied for UDP writer
        curr_distance = curr_distance / 500;

        //cout << curr_azimuth * 180 / PI << endl;

        sample.x = curr_distance * sin(curr_azimuth);
        sample.y = curr_distance * cos(curr_azimuth);
        sample.z = curr_distance * sin(curr_elevation);
        //call function to colorize the point cloud
        colorize_point_cloud(curr_intensity, &sample);
        cloud -> points.push_back(sample);
    }

    if(global_ctr1 > cycle_num1){
        cloud -> points.clear();
        global_ctr1 = 0;
        //usleep(400000); //0.1s delay
    }
    global_ctr1++;

    return cloud;
}
