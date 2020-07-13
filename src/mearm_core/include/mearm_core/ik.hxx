#ifndef __mearm_IK_CORE__
#define __mearm_IK_CORE__

#include <geometry_msgs/Point.h>
#include <tuple>

class InverseKinematicSolver {
  public:
    std::tuple<double, double, double> solve(const geometry_msgs::Point& setpoint) const;
  private:
    std::tuple<double, double> cartToPolar(const std::tuple<double, double> point);
    double getAngle(const double opposite, double adjacent1, double adjacent2);
    const double PI = 3.14159265;
    const double L1 = 80, L2 = 80, L3=68;
};

#endif