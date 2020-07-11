//
// Created by spounka on 01/07/2020.
//

#include "engine/materials/sunmaterial.hpp"

namespace SE::Graphics
{
	void SunMaterial::SetColor(const Vector3& color)
	{
		m_shader.Use();
		auto x = glGetUniformLocation(m_shader.GetShader(), "Light.diffuse");
		if (x != -1)
			glUniform3f(x, color.x, color.y, color.z);
		else
			std::cerr << "color attribute not found\n";
	}
	void SunMaterial::SetSpecularity(const Vector3& color)
	{
		m_shader.Use();
		auto x = glGetUniformLocation(m_shader.GetShader(), "Light.specular");
		if (x != -1)
			glUniform3f(x, color.x, color.y, color.z);
		else
			std::cerr << "specularity attribute not found\n";
	}
	void SunMaterial::SetShininess(float shininess)
	{

	}
	void SunMaterial::SetDirection(Vector3 dir)
	{
		dir.Normalize();
		m_shader.Use();
		auto x = glGetUniformLocation(m_shader.GetShader(), "Light.Direction");
		if (x != -1)
			glUniform3f(x, dir.x, dir.y, dir.z);
		else
			std::cerr << "direction attribute not found\n";
	}
	void SunMaterial::SetAmbient(const Vector3& color)
	{
		m_shader.Use();
		auto x = glGetUniformLocation(m_shader.GetShader(), "Light.ambient");
		if (x != -1)
			glUniform3f(x, color.x, color.y, color.z);
		else
			std::cerr << "ambient attribute not found\n";
	}
}