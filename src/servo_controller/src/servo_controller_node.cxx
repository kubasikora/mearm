#include<ros/ros.h>
#include<ros/time.h>
#include<servo_controller/servo_controller.hxx>

#include<iostream>

int main(int argc, char **argv) {
  ros::init(argc, argv, "servo_controller", ros::init_options::AnonymousName);
  ros::NodeHandle nh("~");

  std::string servoName;
  nh.getParam("name", servoName);

  ServoController node(nh);
  ros::spin();

  return 0;
}