/********************************************************************************
** Form generated from reading UI file 'pclviewer.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PCLVIEWER_H
#define UI_PCLVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_PCLViewer
{
public:
    QAction *actionOpen;
    QWidget *centralwidget;
    QVTKWidget *qvtkWidget;
    QSlider *horizontalSlider_p;
    QLCDNumber *lcdNumber_p;
    QVTKWidget *qvtkWidget_2;
    QPushButton *recordButton;
    QPushButton *openButton;
    QPushButton *pauseButton;
    QPushButton *closeButton;
    QPushButton *startButton;
    QRadioButton *liveModeButton;
    QRadioButton *offlineModeButton;
    QPushButton *playButton;
    QLineEdit *portName;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *portName_2;
    QPushButton *stopButton;
    QLabel *camWidget;
    QFrame *line;
    QFrame *line_2;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QToolBar *toolBar;

    void setupUi(QMainWindow *PCLViewer)
    {
        if (PCLViewer->objectName().isEmpty())
            PCLViewer->setObjectName(QString::fromUtf8("PCLViewer"));
        PCLViewer->resize(1143, 790);
        PCLViewer->setMinimumSize(QSize(0, 0));
        actionOpen = new QAction(PCLViewer);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        centralwidget = new QWidget(PCLViewer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        qvtkWidget = new QVTKWidget(centralwidget);
        qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));
        qvtkWidget->setGeometry(QRect(20, 20, 600, 340));
        horizontalSlider_p = new QSlider(centralwidget);
        horizontalSlider_p->setObjectName(QString::fromUtf8("horizontalSlider_p"));
        horizontalSlider_p->setGeometry(QRect(960, 630, 160, 29));
        horizontalSlider_p->setMinimum(1);
        horizontalSlider_p->setMaximum(6);
        horizontalSlider_p->setValue(2);
        horizontalSlider_p->setOrientation(Qt::Horizontal);
        lcdNumber_p = new QLCDNumber(centralwidget);
        lcdNumber_p->setObjectName(QString::fromUtf8("lcdNumber_p"));
        lcdNumber_p->setGeometry(QRect(1090, 600, 30, 31));
        lcdNumber_p->setDigitCount(1);
        lcdNumber_p->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_p->setProperty("intValue", QVariant(2));
        qvtkWidget_2 = new QVTKWidget(centralwidget);
        qvtkWidget_2->setObjectName(QString::fromUtf8("qvtkWidget_2"));
        qvtkWidget_2->setGeometry(QRect(20, 390, 600, 340));
        recordButton = new QPushButton(centralwidget);
        recordButton->setObjectName(QString::fromUtf8("recordButton"));
        recordButton->setGeometry(QRect(940, 490, 80, 23));
        QFont font;
        font.setPointSize(20);
        recordButton->setFont(font);
        openButton = new QPushButton(centralwidget);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        openButton->setGeometry(QRect(840, 520, 80, 23));
        pauseButton = new QPushButton(centralwidget);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));
        pauseButton->setGeometry(QRect(1040, 520, 80, 23));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        pauseButton->setFont(font1);
        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(1040, 670, 80, 23));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(840, 490, 80, 23));
        liveModeButton = new QRadioButton(centralwidget);
        liveModeButton->setObjectName(QString::fromUtf8("liveModeButton"));
        liveModeButton->setGeometry(QRect(660, 490, 81, 21));
        offlineModeButton = new QRadioButton(centralwidget);
        offlineModeButton->setObjectName(QString::fromUtf8("offlineModeButton"));
        offlineModeButton->setGeometry(QRect(660, 520, 81, 21));
        playButton = new QPushButton(centralwidget);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        playButton->setGeometry(QRect(940, 520, 80, 23));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        playButton->setFont(font2);
        portName = new QLineEdit(centralwidget);
        portName->setObjectName(QString::fromUtf8("portName"));
        portName->setGeometry(QRect(710, 670, 101, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(660, 670, 71, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(660, 630, 71, 16));
        portName_2 = new QLineEdit(centralwidget);
        portName_2->setObjectName(QString::fromUtf8("portName_2"));
        portName_2->setGeometry(QRect(710, 630, 101, 21));
        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(1040, 490, 80, 23));
        camWidget = new QLabel(centralwidget);
        camWidget->setObjectName(QString::fromUtf8("camWidget"));
        camWidget->setGeometry(QRect(660, 20, 455, 340));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(630, 10, 20, 731));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(650, 380, 481, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(780, 400, 221, 20));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        label_3->setFont(font3);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(660, 600, 181, 20));
        QFont font4;
        font4.setBold(true);
        font4.setWeight(75);
        label_5->setFont(font4);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(660, 460, 181, 20));
        label_6->setFont(font4);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(850, 180, 111, 20));
        label_7->setFont(font3);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(960, 600, 71, 20));
        label_8->setFont(font4);
        PCLViewer->setCentralWidget(centralwidget);
        label_7->raise();
        closeButton->raise();
        startButton->raise();
        qvtkWidget->raise();
        horizontalSlider_p->raise();
        lcdNumber_p->raise();
        qvtkWidget_2->raise();
        recordButton->raise();
        openButton->raise();
        pauseButton->raise();
        liveModeButton->raise();
        offlineModeButton->raise();
        playButton->raise();
        portName->raise();
        label->raise();
        label_2->raise();
        portName_2->raise();
        stopButton->raise();
        camWidget->raise();
        line->raise();
        line_2->raise();
        label_3->raise();
        label_5->raise();
        label_6->raise();
        label_8->raise();
        menuBar = new QMenuBar(PCLViewer);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1143, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        PCLViewer->setMenuBar(menuBar);
        toolBar = new QToolBar(PCLViewer);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        PCLViewer->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionOpen);

        retranslateUi(PCLViewer);
        QObject::connect(horizontalSlider_p, SIGNAL(sliderMoved(int)), lcdNumber_p, SLOT(display(int)));

        QMetaObject::connectSlotsByName(PCLViewer);
    } // setupUi

    void retranslateUi(QMainWindow *PCLViewer)
    {
        PCLViewer->setWindowTitle(QApplication::translate("PCLViewer", "PCLViewer", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("PCLViewer", "Open", 0, QApplication::UnicodeUTF8));
        recordButton->setText(QApplication::translate("PCLViewer", "\342\200\242", 0, QApplication::UnicodeUTF8));
        openButton->setText(QApplication::translate("PCLViewer", "Open", 0, QApplication::UnicodeUTF8));
        pauseButton->setText(QApplication::translate("PCLViewer", "||", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("PCLViewer", "Close", 0, QApplication::UnicodeUTF8));
        startButton->setText(QApplication::translate("PCLViewer", "Start", 0, QApplication::UnicodeUTF8));
        liveModeButton->setText(QApplication::translate("PCLViewer", "Live", 0, QApplication::UnicodeUTF8));
        offlineModeButton->setText(QApplication::translate("PCLViewer", "Offline", 0, QApplication::UnicodeUTF8));
        playButton->setText(QApplication::translate("PCLViewer", "\342\226\272", 0, QApplication::UnicodeUTF8));
        portName->setText(QString());
        label->setText(QApplication::translate("PCLViewer", "Port 2", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PCLViewer", "Port 1", 0, QApplication::UnicodeUTF8));
        portName_2->setText(QString());
        stopButton->setText(QApplication::translate("PCLViewer", "\342\226\240", 0, QApplication::UnicodeUTF8));
        camWidget->setText(QString());
        label_3->setText(QApplication::translate("PCLViewer", "CONTROL PARAMETERS", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("PCLViewer", "Data Input Ethernet Ports", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("PCLViewer", "Data Display Mode", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("PCLViewer", "Video Feed", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("PCLViewer", "Point Size", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("PCLViewer", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("PCLViewer", "Edit", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("PCLViewer", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PCLViewer: public Ui_PCLViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCLVIEWER_H
