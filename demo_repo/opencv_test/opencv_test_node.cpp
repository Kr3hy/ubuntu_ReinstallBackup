////
//// Created by kr3hy on 22-10-30.
////
//#include <ros/ros.h>
//#include <stdio.h>
//#include <image_transport/image_transport.h>
//#include <cv_bridge/cv_bridge.h>
//#include <sensor_msgs/image_encodings.h>
//#include <opencv4/opencv2/imgproc/imgproc.hpp>
//#include <opencv4/opencv2/highgui/highgui.hpp>
//
//static const char WINDOW[] = "Image window";
//static void help()
//{
//    printf("\nThis program demonstrates converting OpenCV Image to ROS Image messages  \n"
//    );
//
//}
//
//int main(int argc, char** argv)
//{
////    help();
////    ros::init(argc, argv, "image_converter");
//
//    //Reading an image from the file
//    cv::Mat cv_image = cv::imread("/media/kr3hy/WD Elements/潮起不落/9.jpg");
////    if(cv_image.empty() )
////    {
////        ROS_ERROR("Read the picture failed!");
////        return -1;
////    }
////
////    //Convert OpenCV image to ROS message
////    ros::NodeHandle node;
////    image_transport::ImageTransport transport(node);
////    image_transport::Publisher image_pub;
////    image_pub=transport.advertise("OutImage", 1);
////    ros::Time time=ros::Time::now();
////
////    cv_bridge::CvImage cvi;
////    cvi.header.stamp = time;
////    cvi.header.frame_id = "image";
////    cvi.encoding = "bgr8";
////    cvi.image = cv_image;
////
////    sensor_msgs::Image im;
////    cvi.toImageMsg(im);
////    image_pub.publish(im);
////    ROS_INFO("Converted Successfully!");
////
////    //Show the image
////    cv::namedWindow(WINDOW);
//    cv::imshow(WINDOW,cv_image);
//    cv::waitKey(5000);
////
////    ros::spin();
//    return 0;
//}
//#include<stdio.h>
//#include <iostream>
//#include <opencv4/opencv2/opencv.hpp>
//#include <opencv4/opencv2/core/core.hpp>
//#include <opencv4/opencv2/highgui/highgui.hpp>
//#include <opencv4/opencv2/imgproc.hpp>
//
//using namespace cv;
//int main()
//{
//    Mat image = Mat::zeros(300, 600, CV_8UC3);
//    circle(image, Point(300, 200), 10, Scalar(25, 110, 288), -100);
//    circle(image, Point(400, 200), 50, Scalar(255, 123, 127), -100);
//    imshow("Show Window", image);
//    waitKey(0);
//    return 0;
//    Mat m = (Mat_<int>(3, 2) << 11, 12, 33, 43, 51, 16);//自定义一个矩阵
//}

//#include <iostream>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//using namespace cv;
//int main()
//{
//    cv::VideoCapture capture(1);
//    if (!capture.isOpened())
//    {
//        printf("Open camera is failed!");
//        system("pause");
//        return -1;
//    }
//    //设置摄像头的拍摄属性为分辨率1280x1024，帧率30fps
////    capture.set(cv::CAP_PROP_FRAME_HEIGHT, 1024);
////    capture.set(cv::CAP_PROP_FRAME_WIDTH, 1280);
////    capture.set(cv::CAP_PROP_FPS, 30.0);
////    capture.set(cv::CAP_PROP_FOURCC, -1);
//    //double fps = capture.get(cv::CAP_PROP_FPS);//获得帧率
//    //int fourcc = capture.get(cv::CAP_PROP_FOURCC);
//    //cv::VideoWriter outputVideo("D:\\ygs\\fuse\\DD.avi", outCompressCodec, 25.0, cv::Size(1280, 1024), true);
////    cv::VideoWriter outputVideo;
////    int codec = cv::VideoWriter::fourcc('M', 'J', 'P', 'G');
////    outputVideo.open("D:\\ygs\\fuse\\DDt.avi", codec, 30.0, cv::Size(1280, 1024), true);//灰度false
//    while (capture.isOpened())
//    {
//        cv::Mat frame;//, grayImage, filterImage;
//        if ((frame.rows != 0) || (frame.cols != 0))
//        {
//            printf("frame capture failed!\n");
//            system("pause");
//            exit(0);
//        }
//        capture >> frame;
//        //图像处理
////        int Row = frame.rows;//行
////        int Col = frame.cols;
////        int numChannel = frame.channels();
////        /*//灰度化
////        //Mat grayImage = imread("D:\\ygs\\csdn.jpg", 0);  //first参数0为灰度，1为彩色
////        cvtColor(frame, grayImage, cv::COLOR_BGR2GRAY);//second
////        //均值滤波
////        blur(grayImage, filterImage, cv::Size(7, 7), cv::Point(-1, -1));*/
////        filterImage = frame;
////        outputVideo << filterImage;
//        imshow("VideoPlay", frame);
//        if (char(cv::waitKey(1)) == 'q')
//        {
//            capture.release();
////            outputVideo.release();
//            exit(0);
//        }
//    }
//}

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "ros/ros.h"
#include "ros/console.h"
#include "sensor_msgs/Image.h"
#include "cv_bridge/cv_bridge.h"
//#include "time.h"

static int g_num=200;
void ScanCallback(const sensor_msgs::Image::ConstPtr &msg)
{
//    std::cout<<msg->encoding<<std::endl;
    cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(
            *msg,sensor_msgs::image_encodings::TYPE_8UC3);
    //bgr8: CV_8UC3, color image with blue-green-red color order
    cv::Mat img = cv_ptr->image;
//    cv::imshow("show",cv_ptr->image);
    cv::waitKey(500);
    std::string path="/home/kr3hy/桌面/ros_review/photos_11_28_2/";
    path.append(std::to_string(g_num));
    path.append(".jpg");
    g_num=g_num+1;
//
    cv::imwrite(path,cv_ptr->image);
    ROS_INFO("%d",g_num);
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL,"");
    ros::init(argc, argv, "listener");
    ros::NodeHandle node;
    cv::waitKey(2000);
    ros::Subscriber subScan = node.subscribe("/hk_camera/image_raw",60,ScanCallback);
//    ros::Subscriber subScan = node.subscribe("/camera/image",60,ScanCallback);
    ros::spin();
    return 0;
}