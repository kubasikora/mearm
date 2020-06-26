#include<ros/ros.h>
#include<ros/time.h>
#include<miniarm_core/miniarm_core.hxx>

#include<iostream>

int main(int argc, char **argv) {
  ros::init(argc, argv, "miniarm_core");
  ros::NodeHandle nh("~");
  
  MiniarmCore node(nh);
  ros::spin();

  return 0;
}