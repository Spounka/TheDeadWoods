//
// Created by spounka on 18/06/2020.
//

#ifndef THEDEADWOODS_INCLUDE_VERTEX_HPP_
#define THEDEADWOODS_INCLUDE_VERTEX_HPP_

#include <vector>

#include "vector3.hpp"
#include "vector2.hpp"
#include "engine/graphics/texture.hpp"

namespace SE::Graphics
{
	/**
	 * @brief Representation of a 3D point / Vertex in the world
	 */
	struct Vertex
	{
	  public:
		/**
		 * Constructor
		 * @param pos Position of the Vertex in 3D space
		 * @param uv UV Coordinates of the Vertex
		 * @param normal Normal Vector of the Vertex
		 */
		explicit Vertex(Vector3 pos = Vector3(), Vector2 uv = Vector2(), Vector3 normal = Vector3())
			: position(pos), uvCoords(uv), normals(normal)
		{}
		/**
		 * 3D Position of the Vertex
		 */
		Vector3 position;
		/**
		 * UV of the Vertex
		 */
		Vector2 uvCoords;

		/**
 		 * Normal Vector of the Vertex
	 	 */
		Vector3 normals;

	};
}

#endif //THEDEADWOODS_INCLUDE_VERTEX_HPP_
