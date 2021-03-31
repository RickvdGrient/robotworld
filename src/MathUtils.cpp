#include "MathUtils.hpp"
#include <cmath>

namespace Utils
{
	/**
	 *
	 */
	/* static */ double MathUtils::toRadians( double aDegrees)
	{
		return aDegrees * PI / 180.0;
	}
	/**
	 *
	 */
	/* static */ double MathUtils::toDegrees( double aRadian)
	{
		return aRadian * 180.0 / PI;
	}

	/* static */ double MathUtils::pythagorean(int32_t x_coordiate, int32_t y_coordinate)
	{
		return std::sqrt((static_cast<double>(x_coordiate) * static_cast<double>(x_coordiate))
		 + (static_cast<double>(y_coordinate) * static_cast<double>(y_coordinate)));
	}

	/* static */ double MathUtils::generate_noise(double mean, double std_dev)
	{
		std::normal_distribution<double> distr(mean, std_dev);
		return std::round(distr(generator));
	}
} //namespace Utils
