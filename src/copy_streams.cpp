#include "copy_streams.h"
#include "ap_int.h"
//#include "hls_video.h"
//using namespace hls;


void copy_streams(stream_t& stream_hdmi , stream_t& stream_out0, stream_t& stream_out1){
#pragma HLS DATAFLOW
//#pragma HLS INTERFACE s_axilite port=ctrl
#pragma HLS INTERFACE axis register both port=stream_out0
#pragma HLS INTERFACE axis register both port=stream_hdmi
#pragma HLS INTERFACE axis register both port=stream_out1


//	*x += *y +*z;

	int const rows = MAX_HEIGHT;
	int const cols = MAX_WIDTH;

	IMAGE_C3 img_hdmi(rows, cols);
	IMAGE_C3 img_out0(rows, cols);
	IMAGE_C3 img_out11(rows, cols);

//	IMAGE_C1 img_out1(rows, cols);

	AXIvideo2Mat(stream_hdmi, img_hdmi);
	// AXIvideo2Mat(stream_menu, img_menu);
	hls::Duplicate(img_hdmi, img_out0, img_out11);
//    hls::CvtColor<HLS_RGB2GRAY>(img_out11, img_out1);

	Mat2AXIvideo(img_out0, stream_out0);
	Mat2AXIvideo(img_out11, stream_out1);

}















