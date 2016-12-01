#ifndef PCLVIEWER_H
#define PCLVIEWER_H

#include <iostream>

// Qt
#include <QMainWindow>
#include <QProcess>
#include <QDateTime>
#include <QVBoxLayout>
#include <QImage>
//#include <QCamera>
//#include <QCameraInfo>
//#include <QCameraViewfinder>
//#include <QCameraImageCapture>

#include "lidarone.h"
#include "lidartwo.h"
#include "recordpcapdata.h"
#include "video.h"

namespace Ui
{
  class PCLViewer;
}

class PCLViewer : public QMainWindow
{
  Q_OBJECT

public:
    explicit PCLViewer (QWidget *parent = 0);
    ~PCLViewer ();
    LidarOne *mThread;
    LidarTwo *mThread2;
    RecordPcapData *fromLidarOne;
    RecordPcapData *fromLidarTwo;
    //video *videoWindow;

public slots:
    void pSliderValueChanged (int value);

    void onUpdate(int , pcl::PointCloud<pcl::PointXYZRGBA>::Ptr);
    void onUpdate2(int , pcl::PointCloud<pcl::PointXYZRGBA>::Ptr);
    void setImage(cv::Mat *);

protected:
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer2;
    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud;
//  QCamera *camera;
//  QCameraImageCapture *imageCapture;

private slots:
    void on_startButton_clicked();
    void on_liveModeButton_clicked();
    void on_offlineModeButton_clicked();
    void on_openButton_clicked();
    void on_pauseButton_clicked();
    void on_recordButton_clicked();
    void on_stopButton_clicked();
    void on_closeButton_clicked();

private:
   Ui::PCLViewer *ui;
   //related to camera widget
   video *cvwidget;
};

#endif // PCLVIEWER_H
