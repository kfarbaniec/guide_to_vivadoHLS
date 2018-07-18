#include "../src/copy_streams.h"
#include "hls_opencv.h"
#include <iostream>
#include <cstring>

#define HDMI_IN "/home/karol/Desktop/fpga_fais/guide_to_vivadoHLS/tb/elon_720.bmp"
#define OUTPUT_IMAGE "elon_out.bmp"
#define COPIED_OUT_IMAGE "copied_elon.bmp"

int main(){
	int const rows = MAX_HEIGHT;
	int const cols = MAX_WIDTH;

/*
 *  	----------------> yy
 * 		|
 * 		|
 * 		|
 * 		|
 * 		|
 * 		v
 * 		xx
 *
 */

	stream_t stream_out0;
	stream_t  stream_hdmi;
	stream_t stream_out1;
	cv::Mat test = cv::imread(HDMI_IN);
	// cv::Mat in1(cv::Size(MAX_HEIGHT, MAX_WIDTH), CV_8UC3, cv::Scalar(0x00,0xFF,0x00)); // menu in
	// cv::Mat in2(cv::Size(MAX_HEIGHT, MAX_WIDTH), CV_8UC3, cv::Scalar(0xFF,0x00,0x00)); // hdmi in

	cv::Mat dst0 = test;
	cv::Mat dst1 = test;

	cvMat2AXIvideo(test, stream_hdmi);

	copy_streams(stream_hdmi , stream_out0, stream_out1);

	AXIvideo2cvMat(stream_out0, dst0);
	AXIvideo2cvMat(stream_out1, dst1);
//
	cv::imwrite(OUTPUT_IMAGE, dst0);
	cv::imwrite(COPIED_OUT_IMAGE, dst1);

return 0;

}
