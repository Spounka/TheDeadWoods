//
// Created by spounka on 13/06/2020.
//

#include "engine/graphics/shader.hpp"

#include <iostream>

#include "engine/util/glslparser/parser.hpp"

namespace SE::Graphics
{

	Shader::Shader(const char* vertPath, const char* fragPath)
	{
		m_shader = glCreateProgram();
		SE::Util::Parser vertSource(vertPath);
		SE::Util::Parser fragSource(fragPath);

		if (vertSource.content.empty())
		{
			std::cerr << "file not loaded correctly " << vertPath << std::endl;
			return;
		}
		if (fragSource.content.empty())
		{
			std::cerr << "file not loaded correctly " << fragPath << std::endl;
			return;
		}

		GLuint vertShader = createShader(GL_VERTEX_SHADER, vertSource.content.c_str(), vertPath);
		GLuint fragShader = createShader(GL_FRAGMENT_SHADER, fragSource.content.c_str(), fragPath);

		if (vertShader > 0)
			glAttachShader(m_shader, vertShader);
		else
			std::cerr << "Shader Creation Failed !\n";

		if (fragShader > 0)
			glAttachShader(m_shader, fragShader);
		else
			std::cerr << "Shader Creation Failed !\n";
		glLinkProgram(m_shader);
		if (!CheckErrorLog(m_shader, true))
		{
			std::cerr << "Program Failed to link";
			return;
		}
	}

	void Shader::Use() const
	{
		glUseProgram(m_shader);
	}

	GLuint Shader::createShader(GLenum type, const char* source, const char* path)
	{
		GLuint shader = glCreateShader(type);
		glShaderSource(shader, 1, &source, nullptr);
		glCompileShader(shader);
		if (CheckErrorLog(shader, false, path) == GL_TRUE)
			return shader;
		else
			return -1;
	}

	Shader::~Shader()
	{ std::cout << "detor being called ...\n"; }

	Shader::Shader() : Shader(DEFAULT_VERT_SOURCE, DEFAULT_FRAG_SOURCE)
	{}

	int Shader::CheckErrorLog(GLuint program, bool isProgram, const char* fileName)
	{
		int success;
		char infoLog[512];
		if (isProgram)
			glGetProgramiv(program, GL_LINK_STATUS, &success);
		else
			glGetShaderiv(program, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			if (isProgram)
			{
				glGetProgramInfoLog(program, 512, nullptr, infoLog);
				std::cerr << "Program Linking Error: " << infoLog << std::endl;
			}
			else
			{
				glGetShaderInfoLog(program, 512, nullptr, infoLog);
				std::cerr << "Shader Compilation Error: " << infoLog << std::endl <<
						  "file path: " << fileName << std::endl;
			}
		}
		return success;
	}

}