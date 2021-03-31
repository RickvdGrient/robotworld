#ifndef COMPASS_HPP_
#define COMPASS_HPP_

#include "Point.hpp"

#include <cstdint>

class Compass
{
public:
    /**
     * @brief Construct a new Compass object
     * 
     */
    Compass() = delete;

    /**
     * @brief Construct a new Compass object
     * 
     * @param an_old_point 
     * @param a_mean 
     * @param a_std_dev 
     */
    Compass(Widgets::Point& an_old_point, double a_mean, double a_std_dev);

    /**
     * @brief Destroy the Compass object
     * 
     */
    virtual ~Compass();

    /**
     * @brief 
     * 
     * @param new_point 
     * @return double 
     */
    double compass_direction(Widgets::Point& new_point);
private:
/* data */
    Widgets::Point old_point;
    double mean;
    double std_dev;
};

#endif