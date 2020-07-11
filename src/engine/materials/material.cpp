//
// Created by spounka on 22/06/2020.
//

#include "engine/materials/material.hpp"

#include <iostream>

namespace SE::Graphics
{

	void Material::SetColor(const Vector3& color)
	{
		m_shader.Use();
		auto x = glGetUniformLocation(m_shader.GetShader(), "material.Color");
		if (x != -1)
			glUniform3f(x, color.x, color.y, color.z);
		else
			std::cerr << "color attribute not found\n";
	}
	void Material::SetSpecularity(const Vector3& color)
	{
		m_shader.Use();
		auto x = glGetUniformLocation(m_shader.GetShader(), "material.specular");
		if (x != -1)
			glUniform3f(x, color.x, color.y, color.z);
		else
			std::cerr << "specularity attribute not found\n";
	}
	void Material::SetShininess(float shininess)
	{
		m_shader.Use();
		auto x = glGetUniformLocation(m_shader.GetShader(), "material.shininess");
		if (x != -1)
			glUniform1f(x, shininess);
		else
			std::cerr << "shininess attribute not found\n";
	}
	void Material::SetShader(const Shader& shader)
	{
		this->m_shader = shader;
	}

}
