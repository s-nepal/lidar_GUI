#ifndef PCAPTHREAD1_H
#define PCAPTHREAD1_H

#include "common.h"

const int cycle_num1 = 200;
const int delay_us1 = 50000;
const int num_bytes1 = 1498; // number of bytes per UDP packet

PointCloudTPtr extract_xyz_II(struct data_packet_II& processed_packet, PointCloudTPtr cloud);

class LidarTwo : public QThread
{
    Q_OBJECT
public:
    LidarTwo(QObject *parent = 0);
    void run();
    QString fileName;
    bool offline;
    bool pause;
    QString portName;

signals:
    void updateCloud(int , pcl::PointCloud<pcl::PointXYZRGBA>::Ptr);
private:

};

#endif // PCAPTHREAD1_H
