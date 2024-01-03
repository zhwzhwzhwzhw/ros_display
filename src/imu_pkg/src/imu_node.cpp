#include<ros/ros.h>
#include<sensor_msgs/Imu.h>
#include<tf/tf.h>

void imuback(sensor_msgs::Imu msg)
{
    if(msg.orientation_covariance[0]<0)
    return;
    
    tf::Quaternion quaternion(
        msg.orientation.x,
         msg.orientation.y,
          msg.orientation.z,
           msg.orientation.w

    );
    double roll,pitch,yaw;
tf::Matrix3x3(quaternion).getRPY(roll,pitch,yaw);
roll=roll*180/M_PI;
yaw=yaw*180/M_PI;
pitch=pitch*180/M_PI;
ROS_INFO("roll=%.0f yaw=%0f pitch=%0f",roll,yaw,pitch);
}



int main(int argc, char *argv[])
{
    ros::init(argc,argv,"imu_node");

    ros::NodeHandle nh;
    ros::Subscriber imu_sub=nh.subscribe("imu/data_raw",100,imuback);
    ros::spin();
    return 0;
}
