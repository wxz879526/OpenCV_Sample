#include <stdio.h>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("usage: OpenCV_Demo.exe <image path>\n");
		return -1;
	}

	cv::Mat image = cv::imread(argv[1], cv::IMREAD_COLOR);
	if (!image.data)
	{
		printf("can not read image data\n");
		return -1;
	}

	cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Display Image", image);

	cv::waitKey(0);
	return 0;
}