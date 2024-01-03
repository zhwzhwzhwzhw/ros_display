// color_camera_display_pkg/src/color_camera_display_node.cpp
#include "ros/ros.h"
#include "sensor_msgs/Image.h"
#include "cv_bridge/cv_bridge.h"
#include "image_transport/image_transport.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

void colorImageCallback(const sensor_msgs::ImageConstPtr& msg)
{
    try
    {
        cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);

        // Display color image using OpenCV
        cv::imshow("Color Camera", cv_ptr->image);
        cv::waitKey(1);
    }
    catch (cv_bridge::Exception& e)
    {
        ROS_ERROR("cv_bridge exception: %s", e.what());
    }
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "color_camera_display_node");
    ros::NodeHandle nh;

    // Subscribe to color camera topic
    image_transport::ImageTransport it(nh);
    image_transport::Subscriber sub = it.subscribe("/camera/color/image_raw", 10, colorImageCallback);

    // Initialize OpenCV window
    cv::namedWindow("Color Camera", cv::WINDOW_NORMAL);
    cv::resizeWindow("Color Camera", 640, 480);

    ros::spin();

    // Close OpenCV window upon node shutdown
    cv::destroyWindow("Color Camera");

    return 0;
}
