#include<mearm_core/mearm_core.hxx>
#include<servo_controller/ServoControl.h>

#include<random>
#include<thread>

mearmCore::mearmCore(ros::NodeHandle nh){
    basePub_ = nh.advertise<servo_controller::ServoControl>("/mearm_re/base/servo_controller", 30);
    leftPub_ = nh.advertise<servo_controller::ServoControl>("/mearm_re/left/servo_controller", 30);
    rightPub_ = nh.advertise<servo_controller::ServoControl>("/mearm_re/right/servo_controller", 30);
    gripperPub_ = nh.advertise<servo_controller::ServoControl>("/mearm_re/gripper/servo_controller", 30);

    coreThread_ = std::thread{&mearmCore::coreLoop, this};
}

void mearmCore::coreLoop() {
    std::uniform_real_distribution<double> unif(-1, 1);
    std::default_random_engine re;
    
    ros::Rate loopRate(10);

    const double dutyBase = 1.5;

    while(ros::ok()){
        servo_controller::ServoControl msg;
        msg.duty = dutyBase + unif(re);
        basePub_.publish(msg);

        msg.duty = dutyBase + unif(re);
        leftPub_.publish(msg);

        msg.duty = dutyBase + unif(re);
        rightPub_.publish(msg);

        msg.duty = dutyBase + unif(re);
        gripperPub_.publish(msg);

        ros::spinOnce();
        loopRate.sleep();
    }
}