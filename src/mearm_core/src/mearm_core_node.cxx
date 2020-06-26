#include<ros/ros.h>
#include<ros/time.h>
#include<mearm_core/mearm_core.hxx>

#include<iostream>

int main(int argc, char **argv) {
  ros::init(argc, argv, "mearm_core");
  ros::NodeHandle nh("~");
  
  mearmCore node(nh);
  ros::spin();

  return 0;
}