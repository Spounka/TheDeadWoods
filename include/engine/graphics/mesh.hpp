//
// Created by spounka on 18/06/2020.
//

#ifndef THEDEADWOODS_SRC_MESH_HPP_
#define THEDEADWOODS_SRC_MESH_HPP_

#include <GL/glew.h>
#include "engine/vertex.hpp"

#include "engine/vector3.hpp"
#include "glm/mat4x4.hpp"
#include "shader.hpp"

namespace SE::Graphics
{
	/**
	 * @brief base representation of a 3D mesh in the Engine
	 * 
	 */
	class Mesh
	{
	  private:
	  	/**
	  	 * @brief Vertex Array object
	  	 * 
	  	 */
		unsigned int VAO;

		/**
		 * @brief Element buffer object
		 * 
		 */
		unsigned int EBO;

		/**
		 * @brief Vertex Buffer object
		 * 
		 */
		unsigned int VBO;

		/**
		 * @brief number of the indices of the current mesh
		 * 
		 */
		unsigned int numIndices;
	  public:
		
		/**
		 * @brief Construct a new Mesh object
		 * @warning DO NOT USE THIS CLASS DIRECTLY TO CONSTRUCT A MESH
		 * 
		 * @param vertices A vertices array in NDC composing the mesh
		 * @param numVerts number of vertices
		 * @param indices indices array for drawing indexion
		 * @param numIndices number of indices
		 * @see Vertex
		 */

		Mesh(Vertex vertices[], uint32_t numVerts, unsigned int indices[], uint32_t numIndices);

		/**
		 * @brief Draws the mesh on the screen
		 * 
		 */
		void Draw();
	};
}

#endif //THEDEADWOODS_SRC_MESH_HPP_
