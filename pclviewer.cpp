#include "pclviewer.h"
#include "../build/ui_pclviewer.h"
#include <unistd.h>
#include <QString>
#include <QFileDialog>

PCLViewer::PCLViewer (QWidget *parent) :
  QMainWindow (parent),
  ui (new Ui::PCLViewer)
{
    ui->setupUi (this);
    this->setWindowTitle ("PCL viewer");

    //qRegisterMetaType<pcl::PointCloud<pcl::PointXYZRGBA>::Ptr>("PCLPointer");

    //Disable all the Buttons until a mode is chosen
    ui->startButton->setEnabled(false);
    ui->pauseButton->setEnabled(false);
    ui->recordButton->setEnabled(false);
    ui->openButton->setEnabled(false);
    ui->playButton->setEnabled(false);
    ui->stopButton->setEnabled(false);

    ui->portName->setToolTip("name of ethernet port...eg: eth0");
    ui->portName_2->setToolTip("name of ethernet port...eg: eth1");

    //initialise mThread
    mThread = new LidarOne(this);
    mThread2 = new LidarTwo(this);

    mThread->pause = false;
    mThread2->pause = false;
    mThread->offline = false;
    mThread2->offline = false;

    // Set up the QVTK window for visualizion point cloud data
    viewer.reset (new pcl::visualization::PCLVisualizer ("viewer", false));
    ui->qvtkWidget->SetRenderWindow (viewer->getRenderWindow ());
    viewer->setupInteractor (ui->qvtkWidget->GetInteractor (), ui->qvtkWidget->GetRenderWindow ());
    ui->qvtkWidget->update ();

    viewer2.reset(new pcl::visualization::PCLVisualizer ("viewer2", false));
    ui->qvtkWidget_2->SetRenderWindow (viewer2->getRenderWindow());
    viewer2->setupInteractor (ui->qvtkWidget_2->GetInteractor(), ui->qvtkWidget_2->GetRenderWindow());
    ui->qvtkWidget_2->update();

    connect (mThread, SIGNAL(updateCloud(int , pcl::PointCloud<pcl::PointXYZRGBA>::Ptr)), this, SLOT(onUpdate(int , pcl::PointCloud<pcl::PointXYZRGBA>::Ptr)));
    connect (mThread2, SIGNAL(updateCloud(int , pcl::PointCloud<pcl::PointXYZRGBA>::Ptr)), this, SLOT(onUpdate2(int , pcl::PointCloud<pcl::PointXYZRGBA>::Ptr)));

    // Connect point size slider
    connect (ui->horizontalSlider_p, SIGNAL (valueChanged (int)), this, SLOT (pSliderValueChanged (int)));

}


void PCLViewer::pSliderValueChanged (int value)
{
    viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, value, "cloud");
    viewer2->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, value, "cloud");
    ui->qvtkWidget->update ();
}


PCLViewer::~PCLViewer ()
{
    printf("deleting cloud and ui");
    delete ui;
}

void PCLViewer::onUpdate(int Number, pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud)
{
    if(!viewer->updatePointCloud(cloud, "cloud"))
    {
        viewer->addPointCloud(cloud, "cloud");
    }
    ui->qvtkWidget->update ();
}

void PCLViewer::onUpdate2(int Number, pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud)
{
    //mutex.lock();
    if(!viewer2->updatePointCloud(cloud, "cloud"))
    {
        viewer2->addPointCloud(cloud, "cloud");
    }
    ui->qvtkWidget_2->update();
}

void PCLViewer::on_startButton_clicked()
{
    mThread->offline = false;
    mThread2->offline = false;
    mThread->portName = ui->portName->text();
    mThread2->portName = ui->portName_2->text();
    mThread->start();
    mThread2->start();
    //videoWindow->start();
    ui->recordButton->setEnabled(true);

}

void PCLViewer::on_liveModeButton_clicked()
{
    ui->offlineModeButton->setEnabled(false);
    ui->liveModeButton->setEnabled(false);
    ui->startButton->setEnabled(true);
    //ui->recordButton->setEnabled(true);

    //Camera
    ui->camWidget->setScaledContents(true);
    cvwidget = new video(this);
    cvwidget->camera.open(0);
    if(!cvwidget->camera.isOpened()){
        qDebug() << "camera is disabled";
        cvwidget->enableCamera = false;
    }
    else{
        cvwidget->enableCamera = true;
        cvwidget->liveMode = true;
        ui->camWidget->setPixmap(QPixmap::fromImage(cvwidget->image));
        this->connect (cvwidget, SIGNAL(imageReady(cv::Mat *)), this, SLOT (setImage(cv::Mat *)));
        cvwidget->record = false;
        cvwidget->start();  //start camera
    }
}

void PCLViewer::on_offlineModeButton_clicked()
{
    ui->liveModeButton->setEnabled(false);
    ui->offlineModeButton->setEnabled(false);
    ui->openButton->setEnabled(true);
    ui->pauseButton->setEnabled(true);
}

void PCLViewer::on_openButton_clicked()
{
    //mThread->terminate();
    QString fileName = QFileDialog::getOpenFileName(this,
                                     tr("Open Tar File"), QDir::currentPath());
    if(fileName.isEmpty()){
        return;
    }

    QString command = "tar -xzvf " + fileName;
    if((QProcess::execute(command)) < 0)
        qDebug() << "error in extracting files from" << fileName;
    mThread->fileName = "Lidar_1.pcap";
    mThread2->fileName = "Lidar_2.pcap";
    ui->label->setText("File Name");
    ui->label_2->setText("File Name");
    ui->portName->setText(mThread->fileName);
    ui->portName_2->setText(mThread2->fileName);
    mThread->start();
    mThread2->start();
    mThread->offline = true;
    mThread2->offline = true;

    //camera
    ui->camWidget->setScaledContents(true);
    cvwidget = new video(this);
    cvwidget->camera.open("out.avi");
    if(!cvwidget->camera.isOpened()){
        qDebug() << "video file not found";
    }
    else{
        cvwidget->liveMode = false;
        this->connect (cvwidget, SIGNAL(imageReady(cv::Mat *)), this, SLOT (setImage(cv::Mat *)));
        cvwidget->start();
    }
}

void PCLViewer::on_pauseButton_clicked()
{
    if(mThread->pause){
        mThread->pause = false;
        mThread2->pause = false;
        cvwidget->pauseVideo = false;
        cvwidget->timer.start(100,cvwidget);
        ui->pauseButton->setText("Pause");
    }
    else{
        mThread->pause = true;
        mThread2->pause = true;
        cvwidget->pauseVideo = true;
        ui->pauseButton->setText("Play");
    }

}

void PCLViewer::on_recordButton_clicked()
{
    fromLidarOne = new RecordPcapData(this);
    fromLidarOne -> flag = 1;
    fromLidarTwo = new RecordPcapData(this);
    fromLidarTwo -> flag = 2;
    fromLidarOne->record = true;
    fromLidarTwo->record = true;
    fromLidarOne->fileName = "Lidar_1.pcap";
    fromLidarTwo->fileName = "Lidar_2.pcap";
    fromLidarOne->portName = mThread->portName;
    fromLidarTwo->portName = mThread2->portName;
    fromLidarOne->start();
    fromLidarTwo->start();
    ui->recordButton->setEnabled(false);
    ui->stopButton->setEnabled(true);

    // if camera is available, open videoWriter
    if(cvwidget->enableCamera){
        int frame_width = cvwidget->camera.get(CV_CAP_PROP_FRAME_WIDTH);
        int frame_height = cvwidget->camera.get(CV_CAP_PROP_FRAME_HEIGHT);
        cvwidget->videoRecord  = new cv::VideoWriter("out.avi", CV_FOURCC('M','J', 'P', 'G'), 10, cv::Size(frame_width, frame_height), true);
        cvwidget->record = true;
    }

}

void PCLViewer::on_stopButton_clicked()
{
    ui->stopButton->setEnabled(false);
    fromLidarOne->record = false; fromLidarTwo->record = false;

    //camera
    if(cvwidget->enableCamera){
        cvwidget->record = false;
        delete cvwidget->videoRecord;
    }

    QDateTime dateTime = QDateTime::currentDateTime();
    QString command = dateTime.toString("yyyyMMdd_hhmmss'.tar.gz'");                    //to generate the filename based on time
    qDebug() << command;
    command = QString("tar -czvf %1 Lidar_1.pcap Lidar_2.pcap out.avi").arg(command);
    qDebug() << command;
    if((QProcess::execute(command)) < 0)
        qDebug() << "error in compressing files";
    if((QProcess::execute("rm Lidar_1.pcap Lidar_2.pcap out.avi")) < 0)
        qDebug() << "error in removing files Lidar_1.pcap Lidar_2.pcap out.avi";
    ui->recordButton->setEnabled(true);
}

void PCLViewer::on_closeButton_clicked()
{
    if(mThread->offline)
        if((QProcess::execute("rm Lidar_1.pcap Lidar_2.pcap out.avi")) < 0)
            qDebug() << "error in removing files ... \nLidar_1.pcap\nLidar_2.pcap\nout.avi";
    this->close();
}

void PCLViewer::setImage(cv::Mat *frame)
{
    ui->camWidget->setPixmap(QPixmap::fromImage(cvwidget->image));
    delete frame;
}
