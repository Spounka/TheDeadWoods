//
// Created by spounka on 01/07/2020.
//
#include "engine/materials/areamaterial.hpp"

#include <iostream>

namespace SE::Graphics
{
	void AreaLightMaterial::SetColor(const Vector3& color)
	{
		m_shader.Use();
		auto x = glGetUniformLocation(m_shader.GetShader(), "Lamp.diffuse");
		if (x != -1)
			glUniform3f(x, color.x, color.y, color.z);
		else
			std::cerr << "color attribute not found\n";
	}
	void AreaLightMaterial::SetSpecularity(const Vector3& color)
	{
		m_shader.Use();
		auto x = glGetUniformLocation(m_shader.GetShader(), "Lamp.specular");

		if (x != -1)
			glUniform3f(x, color.x, color.y, color.z);
		else
			std::cerr << "specularity attribute not found\n";
	}
	void AreaLightMaterial::SetShininess(float shininess)
	{
	}
	void AreaLightMaterial::SetPosition(Vector3 pos)
	{
		pos.Normalize();
		m_shader.Use();
		auto x = glGetUniformLocation(m_shader.GetShader(), "Lamp.position");
		if (x != -1)
			glUniform3f(x, pos.x, pos.y, pos.z);
		else
			std::cerr << "position attribute not found\n";
	}
	void AreaLightMaterial::SetAmbient(const Vector3& color)
	{
		m_shader.Use();
		auto x = glGetUniformLocation(m_shader.GetShader(), "Lamp.ambient");
		if (x != -1)
			glUniform3f(x, color.x, color.y, color.z);
		else
			std::cerr << "ambient attribute not found\n";
	}
	void AreaLightMaterial::SetCLinear(float value)
	{
		m_shader.Use();
		auto x = glGetUniformLocation(m_shader.GetShader(), "Lamp.cLinear");
		if (x != -1)
			glUniform1f(x, value);
		else
			std::cerr << "cLinear attribute not found\n";
	}
	void AreaLightMaterial::SetCQuadratic(float value)
	{
		m_shader.Use();
		auto x = glGetUniformLocation(m_shader.GetShader(), "Lamp.cQuadratic");
		if (x != -1)
			glUniform1f(x, value);
		else
			std::cerr << "cQuadratic attribute not found\n";
	}
}