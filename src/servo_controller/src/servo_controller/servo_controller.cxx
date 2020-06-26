#include<servo_controller/servo_controller.hxx>

ServoController::ServoController(ros::NodeHandle nh) {
    const std::string name = "servo_controller";
    sub_ = nh.subscribe(name, 10, &ServoController::commandCallback, this);
    pub_ = nh.advertise<servo_controller::ServoControl>("duty", 30);
    servo_controller_ = std::thread{&ServoController::servoControlLoop, this};
}

void ServoController::commandCallback(const servo_controller::ServoControl::ConstPtr& msg) {
    ROS_INFO("message is %f", msg->duty);
    duty_ = saturateDuty(msg->duty);
}

double ServoController::saturateDuty(const double duty){
    if(duty > 2.0) return 2.0;
    if(duty < 1.0) return 1.0;
    return duty;
}

void ServoController::publishState() {
    servo_controller::ServoControl msg;
    msg.duty = this->duty_;
    pub_.publish(msg);
}

void ServoController::servoControlLoop() {
    ros::Rate loopRate(10);

    while(true){
        /* Change this code to do actual servo control */
        publishState();
        loopRate.sleep();
    }
}

