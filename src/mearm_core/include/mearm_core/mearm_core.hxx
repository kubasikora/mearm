#ifndef __mearm_CORE_CONTROLLER__
#define __mearm_CORE_CONTROLLER__

#include<ros/ros.h>
#include<ros/time.h>

#include<thread>

class mearmCore {
  public:
    mearmCore(ros::NodeHandle nh);

  private:
    void coreLoop();
    
    ros::Publisher basePub_, leftPub_, rightPub_, gripperPub_;
    std::thread coreThread_;
};

#endif