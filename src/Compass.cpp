#include "Compass.hpp"
#include "MathUtils.hpp"
#include "Shape2DUtils.hpp"

Compass::Compass(Widgets::Point& an_old_point, double a_mean, double a_std_dev)
    : old_point(an_old_point), mean(a_mean), std_dev(a_std_dev)
{

}

Compass::~Compass()
{
    
}

double Compass::compass_direction(Widgets::Point& new_point)
{
    double angle = Utils::Shape2DUtils::getAngle(old_point, new_point);
    old_point = new_point;
    angle += Utils::MathUtils::generate_noise(mean, std_dev);

    return Utils::MathUtils::toDegrees(angle);
}