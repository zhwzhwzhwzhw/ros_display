#include<ros/ros.h>
#include<nav_msgs/Odometry.h>
#include<math.h>

using namespace std;

double dis=0;
int count=0;
double ox=0;
double oy=0;
double num1 = 3.21541e-05;
double num2=0.01;
void odom_callback(nav_msgs::Odometry msg)//display distance has a big problem
{//i will find some solution
   
double px=msg.pose.pose.position.x;
double py=msg.pose.pose.position.y;
 if(::count==0)
    {
        ::count+=1;
        ox=px;
        oy=py;
        return;
    }
dis+=sqrt((px-ox)*(px-ox)+(py-oy)*(py-oy))/100;
if(sqrt((px-ox)*(px-ox)+(py-oy)*(py-oy))<num2)
{
    cout<<"*********************"<<endl;
cout<<"position:("<<px<<","<<py<<")"<<endl;
cout<<"did not move"<<endl;
cout<<"*********************"<<endl;
dis=0;
    return;
}
cout<<"*********************"<<endl;
cout<<"position:("<<px<<","<<py<<")"<<endl;
cout<<"distance covered"<<dis<<endl;
cout<<"*********************"<<endl;
}


int main(int argc, char *argv[])
{
    ros::init(argc,argv,"odom_node");
    ros::NodeHandle nh;

    ros::Subscriber odom_sub=nh.subscribe("/odom",10,odom_callback);
     ros::spin();
    return 0;
}

//yan_zhuo's code
// #include "ros/ros.h"
// #include "nav_msgs/Odometry.h"
// void odometryCallback(const nav_msgs::Odometry::ConstPtr &msg)
// {
//     ROS_INFO("Position: x=%f, y=%f, z=%f",
//              msg->pose.pose.position.x,
//              msg->pose.pose.position.y,
//              msg->pose.pose.position.z);
//     ROS_INFO("Orientation: x=%f, y=%f, z=%f, w=%f",
//              msg->pose.pose.orientation.x,
//              msg->pose.pose.orientation.y,
//              msg->pose.pose.orientation.z,
//              msg->pose.pose.orientation.w);
//     ROS_INFO("----------------------------------------------");
// }
// int main(int argc, char **argv)
// {
//     ros::init(argc, argv, "show_odo_node");
//     ros::NodeHandle nh;
//     ros::Subscriber sub = nh.subscribe("/odom", 10, odometryCallback);
//     ros::spin();
//     return 0;
// }