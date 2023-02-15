//
// Created by kr3hy on 22-11-19.
//
#include "nodelet/nodelet.h"
#include "pluginlib/class_list_macros.h"
#include "ros/ros.h"
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace cv_nodelet{
//using namespace
  class cv_test : public nodelet::Nodelet{
  public:
      cv_test(){}
      void readImg(std::string path)
      {
          cv::Mat img;
          img=cv::imread(path);
          cv::imshow("test",img);
          cv::waitKey(5000);
      }
  private:

  };
};