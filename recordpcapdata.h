#ifndef RECORDPCAPDATA_H
#define RECORDPCAPDATA_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include "common.h"

class RecordPcapData : public QThread
{
    Q_OBJECT
public:
    RecordPcapData(QObject *parent = 0);
    void run();
    bool record;
    QString portName;
    QString fileName;
    pcap_t *descr;
    pcap_dumper_t *pd;
private:

};

#endif // RECORDPCAPDATA_H
