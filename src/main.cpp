#include <iostream>
#include <vector>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

#define PI 3.1415926;

cv::Mat img_left, img_right;

int main(int argc, char const *argv[])
{
  cv::Mat frame, leftImg, mask;
  int hmin, smin, vmin, hmax, smax, vmax;

  cv::namedWindow("video", cv::WINDOW_NORMAL);
  cv::resizeWindow("video", 640, 480);

   cv::namedWindow("HSV");
    cv::createTrackbar("lowHue", "HSV", &hmin, 255);
    cv::createTrackbar("lowSat", "HSV", &smin, 255);
    cv::createTrackbar("lowVal", "HSV", &vmin, 255);
    cv::createTrackbar("highHue", "HSV", &hmax, 255);
    cv::createTrackbar("highSat", "HSV", &smax, 255);
    cv::createTrackbar("highVal", "HSV", &vmax, 255);

  while (1)
  {
    img_left = cv::imread("/home/pc/文档/test/data/data/right/1620.png"); //75 0 240 99 225 255
    // // 转成灰度图
    cv::cvtColor(img_left, img_left, COLOR_BGR2HSV);

    // HSV调参参数
    cv::Scalar lower(hmin, smin, vmin);
    cv::Scalar upper(hmax, smax, vmax);

    cv::inRange(img_left, lower, upper, mask); // mask为输出图像

    cv::imshow("video", mask);

    cv::waitKey(0);
   
  }
  return 0;
}
