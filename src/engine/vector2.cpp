//
// Created by spounka on 18/06/2020.
//

#include "engine/vector2.hpp"
#include <cmath>


namespace SE
{
	float Vector2::Magnitude() const
	{
		return std::sqrt(this->x * this->x + this->y * this->y);
	}
	Vector2 Vector2::Normalized() const
	{
		float magnitude = this->Magnitude();
		return Vector2(this->x / magnitude, this->y / magnitude);
	}
	void Vector2::Normalize()
	{
		float magnitude = this->Magnitude();
		this->x /= magnitude;
		this->y /= magnitude;
	}
}
