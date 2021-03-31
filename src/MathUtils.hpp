#ifndef MATHUTILS_HPP_
#define MATHUTILS_HPP_

#include "Config.hpp"
#include <random>

namespace Utils
{
	/**
	 *
	 */
	const double PI = 3.141592654;
	/**
	 *
	 */
	const double ALMOST_ZERO = 0.000000000000001;

	static std::default_random_engine generator;

	/**
	 *
	 */
	class MathUtils
	{
		public:
			/**
			 *
			 */
			static double toRadians( double aDegrees);
			/**
			 *
			 */
			static double toDegrees( double aRadian);

			/**
			 * @brief pythagorean theorem
			 * 
			 */
			static double pythagorean(int32_t x_coordinate, int32_t y_coordinate);

			/**
			 * @brief Returns normal distribution. Mean and std_dev must be added
			 * 
			 * @param mean 
			 * @param std_dev 
			 * @return double 
			 */
			static double generate_noise(double mean, double std_dev);
	};
	//	class Math
} // namespace Utils
#endif // MATHUTILS_HPP_
