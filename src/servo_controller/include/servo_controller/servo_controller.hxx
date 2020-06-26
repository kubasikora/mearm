#ifndef __mearm_SERVO_CONTROLLER__
#define __mearm_SERVO_CONTROLLER__

#include<ros/ros.h>
#include<ros/time.h>

#include<thread>

#include<servo_controller/ServoControl.h>


class ServoController {
  public:
    ServoController(ros::NodeHandle nh);
    void commandCallback(const servo_controller::ServoControl::ConstPtr& msg);

  private:
    void servoControlLoop();
    double saturateDuty(const double duty);
    void publishState();

    ros::Subscriber sub_;
    ros::Publisher pub_;
    double duty_;
    std::thread servo_controller_;
};

#endif