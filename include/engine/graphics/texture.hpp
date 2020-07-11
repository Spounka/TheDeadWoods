//
// Created by spounka on 13/06/2020.
//

#ifndef THEDEADWOODS_SRC_TEXTURE_HPP_
#define THEDEADWOODS_SRC_TEXTURE_HPP_

#include <GL/glew.h>

namespace SE::Graphics
{
	/**
	 * 2D Texture representation of the Engine
	 */
	struct Texture
	{
	  private:
		/**
		 * @privatesection
		 */
		 
		/**
		 * ID of the texture to be used with <i> `glBindTexture()` <i>
		 */
		GLuint m_texture;
	  public:
	  	/**
	  	 * @warning NOT USED YET
	  	 * 
	  	 */
		const char* ID;

		/**
		 * @brief Construct a new Texture object
		 * 
		 * @param texturePath path to the texture file
		 */
		explicit Texture(const char* texturePath);

		/**
		 * @brief binds the texture to the buffer for usage with a shader
		 * @see Shader
		 * 
		 */
		void Bind();
	};
}

#endif //THEDEADWOODS_SRC_TEXTURE_HPP_
