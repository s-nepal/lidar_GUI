#ifndef VIDEO_H
#define VIDEO_H

#include <QObject>
#include <QThread>
#include <QImage>
#include <QBasicTimer>
#include <QDebug>
#include "opencv2/opencv.hpp"
#include <opencv/cv.h>
#include <opencv/highgui.h>


class video : public QThread
{
    Q_OBJECT
public:
    video(QObject *parent = 0);
    ~video();
    void run();
    QBasicTimer timer;
    QImage image;
    cv::VideoCapture camera;
    cv::VideoWriter *videoRecord;
    bool record;
    bool enableCamera;
    bool liveMode;
    bool pauseVideo;
signals:
    void imageReady(cv::Mat *);
protected:
    //timer Event for receiving a frame from camera
    void timerEvent(QTimerEvent *);
private:

};

#endif // VIDEO_H
