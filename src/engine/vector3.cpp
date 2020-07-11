//
// Created by spounka on 18/06/2020.
//

#include "engine/vector3.hpp"

#include <cmath>

namespace SE
{
	float Vector3::Magnitude() const
	{
		return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	}
	Vector3 Vector3::Normalized() const
	{
		float magnitude = this->Magnitude();
		return Vector3(this->x / magnitude, this->y / magnitude, this->z / magnitude);
	}
	void Vector3::Normalize()
	{
		float magnitude = this->Magnitude();
		this->x /= magnitude;
		this->y /= magnitude;
		this->z /= magnitude;
	}
}