/****************************************************************************
** Meta object code from reading C++ file 'lidartwo.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "lidartwo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lidartwo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LidarTwo[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   10,    9,    9, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_LidarTwo[] = {
    "LidarTwo\0\0,\0"
    "updateCloud(int,pcl::PointCloud<pcl::PointXYZRGBA>::Ptr)\0"
};

void LidarTwo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LidarTwo *_t = static_cast<LidarTwo *>(_o);
        switch (_id) {
        case 0: _t->updateCloud((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< pcl::PointCloud<pcl::PointXYZRGBA>::Ptr(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LidarTwo::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LidarTwo::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_LidarTwo,
      qt_meta_data_LidarTwo, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LidarTwo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LidarTwo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LidarTwo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LidarTwo))
        return static_cast<void*>(const_cast< LidarTwo*>(this));
    return QThread::qt_metacast(_clname);
}

int LidarTwo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void LidarTwo::updateCloud(int _t1, pcl::PointCloud<pcl::PointXYZRGBA>::Ptr _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
