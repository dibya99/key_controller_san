#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "my_key_controller");
    ros::NodeHandle nh;
    ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("my_key_controller",1);
    ros::Rate rate(10);
    while(ros::ok())
    {
        chatter_pub.publish(msg);
        ros::spinOnce();
        rate.sleep();
    }
 
    return 0;
}
