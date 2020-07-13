#include<ik.hxx>

std::tuple<double, double, double> InverseKinematicSolver::solve(const geometry_msgs::Point& setpoint) const {
    double& [radius, theta] = cartToPolar(setpoint.y, setpoint.x);
    radius -= L3;
    double& [R, angP] = cartToPolar(radius, setpoint.z);
    const double B = getAngle(L2, L1, R), C = getAngle(R, L1, L2);
    return std::make_tuple(theta, angP + B, C + (angP + B) - PI);
}


std::tuple<double, double> InverseKinematicSolver::cartToPolar(const std::tuple<double, double> point){
    const double radius = std::sqrt(std::pow(point.first,2) + std::pow(point.second));
    if(radius == 0)
        throw "Error";
    
    double c = point.first / radius, s = point.second / radius;
    if(c > 1) c = 1;
    if(c < -1) c = -1;

    double theta = std::acos(c);
    if(s < 0) theta *= -1;

    return std::make_tuple(radius, theta);
}

double InverseKinematicSolver::getAngle(const double opposite, double adjacent1, double adjacent2){
    double den = 2*adjacent1*adjacent2;
    if(den == 0)
        throw "Error";
    double c = (std::pow(adjacent1,2) + std::pow(adjacent2,2) - std::pow(opposite,2)) / den;
    if(c > 1 || c < -1)
        throw "Error";
    
    return std::acos(c);
} 