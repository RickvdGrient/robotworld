#include "KalmanFilter.hpp"
#include "MathUtils.hpp"

KalmanFilter::KalmanFilter()
{
    a_t = a_t.identity();
    b_t = b_t.identity();
    c_t = {{0, 0, 0}, {0, 0, 1}};
}

KalmanFilter::~KalmanFilter()
{
}

Matrix<double, 3, 1> KalmanFilter::calculate_kalman_filter(Widgets::Point& position, double speed, double direction)
{
    calculate_noise();
    update_c(speed, position.x);
    update_vector_adjustment(position, direction);
    predicted_state_vector();
    predicted_process_error();
    kalman_gain_formula();
    measurement_vector();
    adjusted_state_vector();
    adjusted_process_error();
    prev_mu = mu_t;
    prev_sigma = sigma_t;
    return mu_t;
}

void KalmanFilter::predicted_state_vector()
{
    predicted_mu = (a_t * prev_mu) + (b_t * u_t) + epsilon;
}

void KalmanFilter::predicted_process_error()
{
    predicted_sigma = (a_t * prev_sigma * a_t.transpose()) + (epsilon * epsilon.transpose());
}

void KalmanFilter::kalman_gain_formula()
{
    kalman_gain = (predicted_sigma * c_t.transpose()) * ((c_t * predicted_sigma * c_t.transpose())
        + (delta * delta.transpose())).inverse();
}

void KalmanFilter::measurement_vector()
{
    x_t = predicted_mu;
    z_t = (c_t * x_t) + delta;
}

void KalmanFilter::adjusted_state_vector()
{
    mu_t = predicted_mu + (kalman_gain * (z_t - (c_t * predicted_mu)));
}

void KalmanFilter::adjusted_process_error()
{
    Matrix<double, 3, 3> identity_matrix;
    sigma_t = (identity_matrix - (kalman_gain * c_t)) * predicted_sigma;
}

void KalmanFilter::update_vector_adjustment(Widgets::Point& point, double direction)
{
    u_t = {point.x - prev_mu.at(0, 0), point.y - prev_mu.at(1, 0), direction - prev_mu.at(2, 0)};
}

void KalmanFilter::update_c(double speed, double x_pos)
{
    c_t = {{speed / x_pos, 0, 0}, {0, 0, 1}};
}

void KalmanFilter::calculate_noise()
{
    double position_noise = Utils::MathUtils::generate_noise(0.0, 1.0);
    double direction_noise = Utils::MathUtils::generate_noise(0.0, 2.0);
    double odometer_noise = Utils::MathUtils::generate_noise(0.0, 1.0);
    epsilon = {position_noise, position_noise, direction_noise};
    delta = {odometer_noise, 0};
}