#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

void onMouse(int event, int x, int y, int flags, void* userdata)
{
	cv::Mat* im = reinterpret_cast<cv::Mat*>(userdata);

	switch (event)
	{
	case cv::EVENT_LBUTTONDOWN:
		std::cout << "at (" << x << "," << y << ") value is: " << static_cast<int>(im->at<uchar>(cv::Point(x, y))) << std::endl;
		break;
	default:
		break;
	}
}

int main()
{
	cv::Mat image;
	std::cout << "This image is " << image.rows << ",  x " << image.cols << std::endl;

	image = cv::imread("puppy.bmp", cv::IMREAD_UNCHANGED);

	if (image.empty())
	{
		std::cout << "read image error " << std::endl;
		return -1;
	}

	std::cout << "This image is " << image.rows << ",  x " << image.cols << std::endl;
	std::cout << "This image has " << image.channels() << "channels" << std::endl;

	cv::namedWindow("Origin Image");
	cv::imshow("Origin Image", image);

	cv::setMouseCallback("Origin Image", onMouse, reinterpret_cast<void*>(&image));
	
	cv::Mat result;
	cv::flip(image, result, 1); // 1 水平翻转 0 垂直翻转 -1 水平和垂直方向都翻转

	cv::namedWindow("Output Image");
	cv::imshow("Output Image", result);

	cv::waitKey(0);

	cv::imwrite("output.bmp", result);

	cv::namedWindow("Drawing on an image");
	cv::circle(image, cv::Point(155, 110), 65, cv::FONT_HERSHEY_PLAIN, 1, 255, 2);
	cv::imshow("Drawing on an image", image);
	cv::waitKey(0);

	return 0;
}