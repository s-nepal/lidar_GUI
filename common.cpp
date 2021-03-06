#include "common.h"

void packetHandler_I(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    struct get_packet *p = (struct get_packet *) userData;
    p->pkthdr = pkthdr;
    p->packet = packet;
    return;

}

void data_structure_builder_I(const struct pcap_pkthdr *pkthdr, const u_char *data, struct data_packet& processed_packet)
{
//    printf("Packet size: %d bytes\n", pkthdr->len);
//    if (pkthdr->len != pkthdr->caplen)
//        printf("Warning! Capture size different than packet size: %ld bytes\n", (long)pkthdr->len);

    // return an empty struct if the packet length is not 1248 bytes
    if(pkthdr -> len != 1248){
        processed_packet = (const struct data_packet){0};
        return;
    }

    if(data[42] != 0xFF || data[43] != 0xEE)
        return;
	
    for(int i = 0; i < 42; i++){
        processed_packet.header[i] = data[i]; // fill in the header
    }

    //cout << endl;
    for(int i = 0; i < 6; i++){
        processed_packet.footer[i] = data[i + 1242]; // fill in the footer
    }

    // populate the payload (block ID, azimuth, 32 distances, 32 intensities  for each of the 12 data blocks)
    int curr_byte_index = 42; // not 43 bcz. in C++, indexing starts at 0, not 1
    uint8_t curr_firing_data[100];
    fire_data temp[12];

    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 100; j++){
            curr_firing_data[j] = data[j + curr_byte_index];
        }
        temp[i].block_id = (curr_firing_data[1] << 8) | (curr_firing_data[0]);
        temp[i].azimuth = (double)((curr_firing_data[3] << 8) | (curr_firing_data[2])) / 100;

        int ctr = 0;
        for(int j = 0; j < 32; j++){
            temp[i].dist[j] = (double)((curr_firing_data[4 + ctr + 1] << 8) | curr_firing_data[4 + ctr]) / 500;
            temp[i].intensity[j] = curr_firing_data[4 + ctr + 2];
            ctr = ctr + 3;
        }
        processed_packet.payload[i] = temp[i];
        curr_byte_index = curr_byte_index + 100;
    }

    return;
}

void data_structure_builder_II(const struct pcap_pkthdr *pkthdr, const u_char *data, struct data_packet_II& processed_packet)
{
       if (pkthdr->len != pkthdr->caplen)
           //printf("Warning! Capture size different than packet size: %ld bytes\n", (long)pkthdr->len);

       // // return an empty struct if the packet length is not 1498 bytes
       if(pkthdr -> len != 1498){
           processed_packet = (const struct data_packet_II){0};
           return;
       }

       // if the payload does not start with 0xFFEE
       if(data[42] != 0xFF || data[43] != 0xEE){
           processed_packet = (const struct data_packet_II){0};
           return;
       }

       // fill in the header
       for(int i = 0; i < 42; i++){
           processed_packet.header[i] = data[i]; // fill in the header
       }

       for(int i = 0; i < 4; i++){
           processed_packet.footer[i] = data[i + 1494]; // fill in the footer
       }

       for(int i = 0; i < 1452; i++){
           processed_packet.payload[i] = data[i + 42]; // fill in the payload
       }

       return;
}


void colorize_point_cloud(double curr_intensity, pcl::PointXYZRGBA *sample)
{
    double intensity_range = 63; //any intensity value above 63 will be red
    double wavelength;

    if(curr_intensity <= 63)
        wavelength = curr_intensity / intensity_range * (780-380) + 380;
    else
        wavelength = 780;

    if((wavelength >= 380) && (wavelength<440)){
        sample->r = (-(wavelength - 440) / (440 - 380))*255;
        sample->g = 0;
        sample->b = 255;

    }else if((wavelength >= 440) && (wavelength<490)){
        sample->r = 0;
        sample->g = ((wavelength - 440) / (490 - 440))*255;
        sample->b = 255;

    }else if((wavelength >= 490) && (wavelength<510)){
        sample->r = 0;
        sample->g = 255;
        sample->b = (-(wavelength - 510) / (510 - 490))*255;

    }else if((wavelength >= 510) && (wavelength<580)){
        sample->r = ((wavelength - 510) / (580 - 510))*255;
        sample->g = 255;
        sample->b = 0;

    }else if((wavelength >= 580) && (wavelength<645)){
        sample->r = 255;
        sample->g = (-(wavelength - 645) / (645 - 580))*255;
        sample->b = 0;

    }else if((wavelength >= 645) && (wavelength<781)){
        sample->r = 255;
        sample->g = 0;
        sample->b = 0;
    }else{
        sample->r = 0;
        sample->g = 0;
        sample->b = 0;
    }
}
