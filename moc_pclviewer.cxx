/****************************************************************************
** Meta object code from reading C++ file 'pclviewer.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "pclviewer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pclviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PCLViewer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   11,   10,   10, 0x0a,
      44,   42,   10,   10, 0x0a,
      98,   42,   10,   10, 0x0a,
     153,   10,   10,   10, 0x0a,
     172,   10,   10,   10, 0x08,
     197,   10,   10,   10, 0x08,
     225,   10,   10,   10, 0x08,
     256,   10,   10,   10, 0x08,
     280,   10,   10,   10, 0x08,
     305,   10,   10,   10, 0x08,
     331,   10,   10,   10, 0x08,
     355,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PCLViewer[] = {
    "PCLViewer\0\0value\0pSliderValueChanged(int)\0"
    ",\0onUpdate(int,pcl::PointCloud<pcl::PointXYZRGBA>::Ptr)\0"
    "onUpdate2(int,pcl::PointCloud<pcl::PointXYZRGBA>::Ptr)\0"
    "setImage(cv::Mat*)\0on_startButton_clicked()\0"
    "on_liveModeButton_clicked()\0"
    "on_offlineModeButton_clicked()\0"
    "on_openButton_clicked()\0"
    "on_pauseButton_clicked()\0"
    "on_recordButton_clicked()\0"
    "on_stopButton_clicked()\0"
    "on_closeButton_clicked()\0"
};

void PCLViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PCLViewer *_t = static_cast<PCLViewer *>(_o);
        switch (_id) {
        case 0: _t->pSliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< pcl::PointCloud<pcl::PointXYZRGBA>::Ptr(*)>(_a[2]))); break;
        case 2: _t->onUpdate2((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< pcl::PointCloud<pcl::PointXYZRGBA>::Ptr(*)>(_a[2]))); break;
        case 3: _t->setImage((*reinterpret_cast< cv::Mat*(*)>(_a[1]))); break;
        case 4: _t->on_startButton_clicked(); break;
        case 5: _t->on_liveModeButton_clicked(); break;
        case 6: _t->on_offlineModeButton_clicked(); break;
        case 7: _t->on_openButton_clicked(); break;
        case 8: _t->on_pauseButton_clicked(); break;
        case 9: _t->on_recordButton_clicked(); break;
        case 10: _t->on_stopButton_clicked(); break;
        case 11: _t->on_closeButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PCLViewer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PCLViewer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_PCLViewer,
      qt_meta_data_PCLViewer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PCLViewer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PCLViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PCLViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PCLViewer))
        return static_cast<void*>(const_cast< PCLViewer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int PCLViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
