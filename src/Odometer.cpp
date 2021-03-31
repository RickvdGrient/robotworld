#include "Odometer.hpp"
#include "MathUtils.hpp"

Odometer::Odometer(Widgets::Point& an_old_point, double a_mean, double a_std_dev)
    : old_point(an_old_point), mean(a_mean), std_dev(a_std_dev)
{
}

Odometer::~Odometer()
{

}

Widgets::Point& Odometer::odometer_value(Widgets::Point& new_point)
{
    Widgets::Point point_diff = new_point - old_point;
    
    double adjusted_x = static_cast<double>((point_diff.x) / 10.0 * std_dev);
    double adjusted_y = static_cast<double>((point_diff.y) / 10.0 * std_dev);

    point_diff.x += Utils::MathUtils::generate_noise(mean, adjusted_x);
    point_diff.y += Utils::MathUtils::generate_noise(mean, adjusted_y);

    old_point += point_diff;

    return old_point;
}