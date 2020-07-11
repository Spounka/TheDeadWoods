//
// Created by spounka on 18/06/2020.
//

#ifndef THEDEADWOODS_SRC_VECTOR3_HPP_
#define THEDEADWOODS_SRC_VECTOR3_HPP_

#include "glm/vec3.hpp"

namespace SE
{

	struct Vector3
	{
	  private:
	  public:
		/**
		 * The x or 1st component of the 3D Vector
		 */
		float x,

			/**
		 * The y or 2nd component of the 3D Vector
		 */
			y,

			/**
		 * The z or 3rd component of the 3D Vector
		 */
			z;

		/**
		 * Default Constructor
		 */
		Vector3()
			: x(0), y(0), z(0)
		{
		}

		/**
		 * Constructor
		 * @param x value for x component
		 * @param y value for y component
		 * @param z value for z component
		 */
		Vector3(float x, float y, float z)
			: x(x), y(y), z(z)
		{
		}

		/**
		 * Constructor
		 * @param vect go from glm::vec2 to SE::Vector3 
	 	 */
		Vector3(glm::vec3 vect)
			: x(vect.x), y(vect.y), z(vect.z)
		{
		}

		/**
		 * Constructor
		 * @param scalar inits all components to value of scalar
		 */
		Vector3(float scalar)
			: Vector3(scalar, scalar, scalar)
		{
		}

		/**
		 * Calculates the magnitude
		 * @return the magnitude of the current Vector
		 */
		[[nodiscard]] float Magnitude() const;

		/**
	 	 * Makes this Vector a unit Vector (direction Vector)
	 	 */
		void Normalize();

		/**
		 * Calculates the normalized Vector without modifying it
	 	 * @return the unit/direct of this Vector
	 	 * @see Normalize
	 	 */
		[[nodiscard]] Vector3 Normalized() const;

		/**
		 * Multiplication of Vector and scalar
		 * @param scalar to multiply this Vector by
		 * @return Vector3 where each component is multiplied by k
	 	 */
		Vector3 operator*(float k) const
		{
			return Vector3(this->x * k, this->y * k, this->z * k);
		}

		/**
		 * Sum of 3D Vector and a scalar
		 * @param scalar to add to this Vector
		 * @return sum of a 3D Vector and k
		 */
		Vector3 operator+(float k) const
		{
			return Vector3(this->x + k, this->y + k, this->z + k);
		}

		/**
		 * Sum of two 3D Vectors
		 * @param other The Vector to add
		 * @return sum of two 3D Vectors
		 */
		Vector3 operator+(const Vector3& other) const
		{
			return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
		}

		Vector3& operator+=(const Vector3& other)
		{
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			return *this;
		}
		Vector3& operator-=(const Vector3& other)
		{
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			return *this;
		}

		/**
		 * Subtracts 3D Vector by scalar
		 * @param scalar to subtract by
		 * @return difference between a 3D Vector and a scalar
		 */
		Vector3 operator-(float k) const
		{
			return Vector3(this->x - k, this->y - k, this->z - k);
		}

		/**
		 * Subtracts two 3D Vectors
		 * @param other the Vector to subtract by
		 * @return the difference between two 3D Vectors
		 */
		Vector3 operator-(const Vector3& other) const
		{
			return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
		}

		/**
		 * Divides this Vector by scalar
		 * @param k scalar to divide by
		 * @return 3D Vector divided by the scalar k
		 */
		Vector3 operator/(float k) const
		{
			return Vector3(this->x / k, this->y / k, this->z / k);
		}

		/**
		 * Compares two 3D Vectors
		 * @param other The Vector to compare by
		 * @return if two 3D Vectors are equal
		 */
		bool operator==(const Vector3& other) const
		{
			return this->x == other.x && this->y == other.y && this->z == other.z;
		}

		/**
         * Calculates the cross product of two Vectors
         * @param other The second Vector for the cross product
         * @return the cross product
         */
		Vector3 operator*(const Vector3& other) const
		{
			float _x = (y * other.z) - (other.y * z);
			float _y = (z * other.x) - (other.z * x);
			float _z = (x * other.y) - (other.x * y);
			return Vector3(_x, _y, _z);
		}

		/**
		 * Formats the SE::Vector3 to a glm::vec3
		 */
		glm::vec3 ToGlm()
		{
			return glm::vec3(x, y, z);
		}
	};
}// namespace SE

#endif//THEDEADWOODS_SRC_VECTOR3_HPP_
