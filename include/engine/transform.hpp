#ifndef SE_UTIL_TRANSFORM_HPP
#define SE_UTIL_TRANSFORM_HPP

#include <engine/vector2.hpp>
#include <engine/vector3.hpp>

namespace SE
{
	/**
	 * @brief Class containing all the needed informations to show an object in 3D space
	 */
	class Transform
	{
		/**
		 * @privatesection
		 */
	  private:
	  public:
		/**
		 * Constructor
		 * @param pos Vector3 Position
		 * @param rot Vector3 Rotation
		 * @param scale Vector3 Scale
		 * @see Vector3
		 */
		Transform(Vector3 pos = Vector3(), Vector3 rot = Vector3(), Vector3 scale = Vector3(1)) :
			position(pos), rotation(rot), scale(scale)
		{}

		/**
		 * Public Vector3 for object's position
		 */
		Vector3 position;

		/**
		 * Public Vector3 for object's rotation
		 */
		Vector3 rotation;

		/**
		 * Public Vector3 for object's scale
		 */
		Vector3 scale;

	};
}// namespace SE::Util

#endif