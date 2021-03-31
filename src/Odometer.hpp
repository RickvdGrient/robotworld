#ifndef ODOMETER_HPP_
#define ODOMETER_HPP_

#include "Point.hpp"

#include <utility>

class Odometer
{

public:
    /**
     * @brief Construct a new Odometer object
     * 
     */
    Odometer() = delete;

    /**
     * @brief Construct a new Odometer object
     * 
     * @param an_old_point 
     * @param a_mean 
     * @param a_std_dev 
     */
    Odometer(Widgets::Point& an_old_point, double a_mean, double a_std_dev);

    /**
     * @brief Destroy the Odometer object
     * 
     */
    virtual ~Odometer();

    Widgets::Point& odometer_value(Widgets::Point& new_point);

    private:
    /* data */
    Widgets::Point old_point;
    double mean;
    double std_dev;
};

#endif