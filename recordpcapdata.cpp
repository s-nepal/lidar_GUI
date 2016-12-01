#include "recordpcapdata.h"

RecordPcapData::RecordPcapData(QObject *parent) :
    QThread(parent)
{

}

void RecordPcapData::run()
{
    char errbuf[PCAP_ERRBUF_SIZE];

    const char *port;
    QByteArray ba;
    ba = portName.toLatin1();
    port = ba.data();

    descr = pcap_open_live(port, 1248, 1, 1, errbuf);
    if(descr == NULL){
        qDebug() << "pcap_open_live failed: " << errbuf;
        return;
    }

    const char *file;
    QByteArray bafile;
    bafile = fileName.toLatin1();
    file = bafile.data();

    if((pd = pcap_dump_open(descr, file)) == NULL){
        qDebug() << "error in opening file" << fileName;
        return;
    }
    int pcount = 0;
    while(record){
        if((pcount = pcap_loop(descr, 1, &pcap_dump, (u_char *) pd)) < 0){
            cout << "error in reading packets";
            return;
        }
    }
    pcap_dump_close(pd);
    pcap_close(descr);
}
