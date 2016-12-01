#ifndef PCAPTHREAD_H
#define PCAPTHREAD_H

#include "common.h"

const int cycle_num = 50;
const int delay_us = 50000;

PointCloudTPtr extract_xyz_I(struct data_packet& processed_packet, PointCloudTPtr cloud);

//Q_DECLARE_METATYPE(pcl::PointCloud<pcl::PointXYZRGBA>::Ptr);
//static PointCloudTPtr cloud(new PointCloudT);
static int NumberUpdate = 0;


class LidarOne : public QThread
{
    Q_OBJECT
public:
    LidarOne(QObject *parent = 0);
    void run();

    QString fileName;
    bool offline;
    bool pause;
    QString portName;

    //void packetHandler_I(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet);

signals:
    void updateCloud(int , pcl::PointCloud<pcl::PointXYZRGBA>::Ptr);

private:

};

#endif // PCAPTHREAD_H
