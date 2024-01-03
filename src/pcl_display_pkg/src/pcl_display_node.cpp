// //writed by gpt --1
// #include <ros/ros.h>
// #include <sensor_msgs/PointCloud2.h>
// #include <pcl/point_cloud.h>
// #include <pcl/point_types.h>
// #include <pcl_conversions/pcl_conversions.h>
// #include <pcl/visualization/cloud_viewer.h>

// pcl::visualization::CloudViewer viewer("Simple Cloud Viewer");

// void cloudCallback(const sensor_msgs::PointCloud2ConstPtr& cloud_msg) {
//     pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
//     pcl::fromROSMsg(*cloud_msg, *cloud);

//     viewer.showCloud(cloud);
// }

// int main(int argc, char** argv) {
//     ros::init(argc, argv, "pcl_display_node");
//     ros::NodeHandle nh;

//     ros::Subscriber sub = nh.subscribe<sensor_msgs::PointCloud2>("/rslidar_points", 1, cloudCallback);

//     ros::spin();
//     return 0;
// }

//writed by gpt
// #include <ros/ros.h>
// #include <sensor_msgs/PointCloud2.h>
// #include <pcl/point_cloud.h>
// #include <pcl/point_types.h>
// #include <pcl_conversions/pcl_conversions.h>
// #include <pcl/visualization/cloud_viewer.h>
// #include <X11/Xlib.h>  // 添加 Xlib 头文件
// #include <GL/gl.h>
// #include <GL/glu.h>

// pcl::visualization::CloudViewer viewer("Simple Cloud Viewer");

// void cloudCallback(const sensor_msgs::PointCloud2ConstPtr& cloud_msg) {
//     pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
//     pcl::fromROSMsg(*cloud_msg, *cloud);

//     // viewer.showCloud(cloud);
//   pcl::visualization::PCLVisualizer::Ptr custom_viewer(new pcl::visualization::PCLVisualizer("Custom Cloud Viewer"));
//     custom_viewer->setBackgroundColor(1.0, 1.0, 1.0);  // 设置背景颜色为白色
//     custom_viewer->addPointCloud(cloud, "cloud");
//     custom_viewer->spinOnce();  // 显示点云
// }


// int main(int argc, char** argv) {
//        XInitThreads();


//     ros::init(argc, argv, "pcl_display_node");
//     ros::NodeHandle nh;

//     ros::Subscriber sub = nh.subscribe<sensor_msgs::PointCloud2>("/rslidar_points", 1, cloudCallback);

//     ros::spin();
//     return 0;
// }
//force gpt to write it
#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/visualization/pcl_visualizer.h>

pcl::visualization::PCLVisualizer::Ptr viewer(new pcl::visualization::PCLVisualizer("Simple Cloud Viewer"));

void cloudCallback(const sensor_msgs::PointCloud2ConstPtr& cloud_msg) {
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
    pcl::fromROSMsg(*cloud_msg, *cloud);

    // Set background color to white (1.0, 1.0, 1.0)
    viewer->setBackgroundColor(1.0, 1.0, 1.0);

    viewer->removeAllPointClouds(); // Remove existing point clouds
    pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(cloud);
    viewer->addPointCloud<pcl::PointXYZRGB>(cloud, rgb, "cloud");

    viewer->spinOnce();
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "pcl_display_node");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe<sensor_msgs::PointCloud2>("/rslidar_points", 1, cloudCallback);

    ros::spin();
    return 0;
}


// //on the csdn
// #include <iostream>
// #include <ros/ros.h>
// #include <pcl/visualization/cloud_viewer.h>
// #include <sensor_msgs/PointCloud2.h>
// #include <pcl_conversions/pcl_conversions.h>
 
// class cloudHandler
// {
// public:
//     cloudHandler()
//     : viewer("Cloud Viewer")
//     {
//      pcl::PointCloud<pcl::PointXYZ> cloud;
//      pcl::io::loadPCDFile ("0.pcd", cloud);
//      viewer.showCloud(cloud.makeShared());
//      viewer_timer = nh.createTimer(ros::Duration(0.1), &cloudHandler::timerCB, this);
//     }
 
//     void timerCB(const ros::TimerEvent&)
//     {
//         if (viewer.wasStopped())
//         {
//             ros::shutdown();
//         }
//     }
 
// protected:
//     ros::NodeHandle nh;
//     pcl::visualization::CloudViewer viewer;
//     ros::Timer viewer_timer;
// };
 
// int main (int argc, char **argv)
// {
//     ros::init (argc, argv, "pcl_filter");
//     cloudHandler handler;
//     ros::spin();
//     return 0;
// }
