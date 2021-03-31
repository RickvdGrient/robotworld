#ifndef KALMANFILTER_HPP_
#define KALMANFILTER_HPP_

#include "Matrix.hpp"
#include "Point.hpp"

class KalmanFilter
{
public:
    /**
     * @brief Construct a new Kalman Filter object
     * on delete
     */
    KalmanFilter();

    /**
     * @brief Destroy the Kalman Filter object
     *
     */
    virtual ~KalmanFilter();

    Matrix<double, 3, 1> calculate_kalman_filter(Widgets::Point& position, double speed, double direction);

private:
    // previous
    Matrix<double, 3, 1> prev_mu;
    Matrix<double, 3, 3> prev_sigma;

    // noise
    Matrix<double, 3, 1> epsilon;
    Matrix<double, 2, 1> delta;

    Matrix<double, 3, 3> a_t;
    Matrix<double, 3, 3> b_t;
    Matrix<double, 2, 3> c_t;

    Matrix<double, 3, 1> predicted_mu;
    Matrix<double, 3, 3> predicted_sigma;
    Matrix<double, 2, 1> z_t;
    Matrix<double, 3, 1> x_t;
    Matrix<double, 3, 1> u_t;
    Matrix<double, 3, 1> mu_t;
    Matrix<double, 3, 3> sigma_t;
    Matrix<double, 3, 2> kalman_gain;

    void predicted_state_vector();
    void predicted_process_error();
    void kalman_gain_formula();
    void measurement_vector();
    void adjusted_state_vector();
    void adjusted_process_error();
    void update_vector_adjustment(Widgets::Point& point, double direction);
    void update_c(double speed, double x_pos);
    void calculate_noise();
};

#endif