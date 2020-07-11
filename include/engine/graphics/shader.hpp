//
// Created by spounka on 13/06/2020.
//

#ifndef SENGINE_SHADER_HPP_
#define SENGINE_SHADER_HPP_

#include <iostream>
#include <GL/glew.h>

#include "engine/util/glslparser/parser.hpp"
#include "engine/config.hpp"

namespace SE::Graphics
{
	/**
	 * @class Shader
	 * @brief Class for creation of shaders
	 * @details The main class used to create new shaders (currently supports fragment/vertex shaders only and together)
	 * @note This class is meant to be used internally
   	 * @warning USE THIS FUNCTION ONLY IF YOU KNOW WHAT YOU ARE DOING
	 */
	class Shader
	{
		/**
		 * @privatesection
		 */
	  private:
		/**
		 * @brief the shader program value
		 */
		GLuint m_shader;

		/**
		 * @brief internal Method for creating shaders
		 * @param type Shader Type (GL_FRAGMENT_SHADER / GL_VERTEX_SHADER)
		 * @param source the shader's source in C-string
		 * @param path file path used to pass to error checking method
		 * @return uint Shader's value to be used
		 * @see CheckErrorLog
		 * @warning USE THIS FUNCTION ONLY IF YOU KNOW WHAT YOU ARE DOING
		 */
		static GLuint createShader(GLenum type, const char* source, const char* path = "");

		/**
		 * Method used to check error logs of created shaders
		 * @param program Program's value (or shader)
		 * @param isProgram if program should be treated as a normal shader or a program
		 * @param fileName string for logging out errors in case of failures
		 * @return 0 if Failure <br>
		 * 		   1 if Success
		 * @warning USE THIS FUNCTION ONLY IF YOU KNOW WHAT YOU ARE DOING
		 */
		static int CheckErrorLog(GLuint program, bool isProgram = false, const char* fileName = "");

	  public:
		/**
		 * Constructor
		 * @param vertPath path to vertex shader
		 * @param fragPath path to fragment shader
		 */
		Shader(const char* vertPath, const char* fragPath);

		/**
		 * @brief Default Constructor
		 * @details Uses the default vertex/fragment shader written for the engine
		 */
		Shader();

		/**
		 * Destructor
		 */
		~Shader();

		/**
		 * @brief Uses the shader.
		 * 
		 * Call this method whenever you are rendering an object using a custom shader
		 * @warning USE THIS METHOD ONLY IF YOU KNOW WHAT YOU ARE DOING
		 */
		void Use() const;

		/**
		 * Shader's value
		 * @return value of m_shader
		 * @see m_shader
		 */
		[[nodiscard]] GLuint GetShader() const
		{ return m_shader; }

	};
}

#endif //SENGINE_SHADER_HPP_
