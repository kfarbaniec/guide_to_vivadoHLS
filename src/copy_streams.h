#ifndef SUM_STREAMS_H
#define SUM_STREAMS_H
#include "hls_video.h"

//typedef ap_axiu<8, 1, 1, 1> interface8_t;
//typedef hls::stream<interface8_t> stream8_t;

typedef ap_axiu<24, 1, 1, 1> interface_t;
typedef hls::stream<interface_t> stream_t;

typedef ap_axiu<32, 1, 1, 1> interface32_t;
typedef hls::stream<interface32_t> stream32_t;

void copy_streams(stream_t& stream_hdmi , stream_t& stream_out0, stream_t& stream_out1);

#define MAX_WIDTH 1280
#define MAX_HEIGHT 720

typedef hls::Scalar<1, unsigned char> PIXEL_C1;
typedef hls::Mat<MAX_HEIGHT, MAX_WIDTH, HLS_8UC1> IMAGE_C1;
typedef hls::Scalar<2, unsigned char> PIXEL_C2;
typedef hls::Mat<MAX_HEIGHT, MAX_WIDTH, HLS_8UC2> IMAGE_C2;
typedef hls::Scalar<3, unsigned char> PIXEL_C3;
typedef hls::Mat<MAX_HEIGHT, MAX_WIDTH, HLS_8UC3> IMAGE_C3;
typedef hls::Scalar<4, unsigned char> PIXEL_C4;
typedef hls::Mat<MAX_HEIGHT, MAX_WIDTH, HLS_8UC4> IMAGE_C4;

#endif
