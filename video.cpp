#include "video.h"

video::video(QObject *parent) :
    QThread(parent)
{
    QImage dummy(100, 100, QImage::Format_RGB32);
    image = dummy;
    for (int x=0; x<100; x++){
        for(int y=0; y<100; y++){
            image.setPixel(x, y, qRgb(x, y, y));
        }
    }

    pauseVideo = false;
    record = false;
}

video::~video()
{

}

void video::run()
{
    timer.start(100,this);
}

void video::timerEvent(QTimerEvent *)
{
    cv::Mat *frame;
    frame = new cv::Mat;
    camera >> *frame;

    if(!frame->data){
        timer.stop();   //stop the timer if there is no data
        return;
    }

    if(pauseVideo){     //to video in offline mode
        timer.stop();
//        while(pauseVideo){}
//        timer.start(100,this);
    }

    if(record)
        videoRecord->write(*frame);
    cv::resize(*frame, *frame, cv::Size(), 0.5, 0.5, cv::INTER_AREA);
    cv::cvtColor(*frame, *frame, CV_BGR2RGB);
    const QImage dummy(frame->data, frame->cols, frame->rows, frame->step, QImage::Format_RGB888);
    Q_ASSERT(dummy.constBits() == frame->data);
    image = dummy;
    emit imageReady(frame);
}

