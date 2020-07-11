//
// Created by spounka on 18/06/2020.
//

#ifndef THEDEADWOODS_INCLUDE_VECTOR2_HPP_
#define THEDEADWOODS_INCLUDE_VECTOR2_HPP_

#include "glm/vec2.hpp"

namespace SE
{
	/**
	 * @brief a struct for representing 2D vectors.
	 * 
	 * 2D vectors representation and helper functions needed for
	 * calculations and some representations
	 */
	struct Vector2
	{
	  public:
		/**
		 * The x or 1st component of the 2D vector
		 */
		float x,
		/**
		 * The y or 2nd component of the 2D vector
		 */
		y;
		/**
		 * Default Constructor
		 */
		Vector2() : x(0), y(0)
		{}
		/**
		 * Constructor
		 * @param x value for x component
		 * @param y value for y component
		 */
		Vector2(float x, float y) : x(x), y(y)
		{}

		/**
		 * Constructor
		 * @param scalar inits all components to value of scalar
		 */
		Vector2(float scalar) : Vector2(scalar, scalar)
		{}

		/**
		 * Constructor
		 * @param vect go from glm::vec2 to SE::Vector2 
		 */
		Vector2(glm::vec2 vect) : x(vect.x), y(vect.y)
		{}

		/**
		 * Calculates the magnitude
		 * @return float the magnitude
		 */
		[[nodiscard]] float Magnitude() const;

		/**
		 * Calculates the normalized vector without modifying it
		 * @return Vector2 the unit/direction of this vector
		 * @see Normalize
		 */
		[[nodiscard]] Vector2 Normalized() const;

		/**
		 * Makes this Vector a unit vector (direction vector)
		 */
		void Normalize();

		/**
		 * Multiplication of Vector and scalar
		 * @param k scalar to multiply this vector by
		 * @return Vector2 where each component is multiplied by k
		 */
		Vector2 operator*(float k) const
		{ return Vector2(this->x * k, this->y * k); }

		/**
		 * Sum of 2D Vector and a scalar
		 * @param k scalar to add to this vector
		 * @return sum of a 2D vector and k
		 */
		Vector2 operator+(float k) const
		{ return Vector2(this->x + k, this->y + k); }

		/**
		 * Sum of two 2D Vectors
		 * @param other The Vector to add
		 * @return sum of two 2D Vectors
		 */
		Vector2 operator+(const Vector2& other) const
		{ return Vector2(this->x + other.x, this->y + other.y); }

		/**
		 * Subtracts 2D vector by scalar
		 * @param scalar to subtract by
		 * @return difference between a 2D Vector and a scalar
		 */
		Vector2 operator-(float k) const
		{ return Vector2(this->x - k, this->y - k); }

		/**
		 * Subtracts two 2D Vectors
		 * @param other the vector to subtract by
		 * @return the difference between two 2D Vectors
		 */
		Vector2 operator-(const Vector2& other) const
		{ return Vector2(this->x - other.x, this->y - other.y); }

		/**
		 * Divides this vector by scalar
		 * @param k scalar to divide by
		 * @return 2D Vector divided by the scalar k
		 */
		Vector2 operator/(float k) const
		{ return Vector2(this->x / k, this->y / k); }

		/**
		 * Compares two 2D Vectors
		 * @param other The Vector to compare by
		 * @return if two 2D Vectors are equal
		 */
		bool operator==(const Vector2& other) const
		{ return this->x == other.x && this->y == other.y; }
	};
}

#endif //THEDEADWOODS_INCLUDE_VECTOR2_HPP_
