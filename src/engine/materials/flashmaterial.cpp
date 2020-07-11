//
// Created by spounka on 01/07/2020.
//

#include "engine/materials/flashmaterial.hpp"

#include <iostream>
#include <cmath>

#include "engine/vector3.hpp"

namespace SE::Graphics
{
	void FlashLightMaterial::SetColor(const Vector3& color)
	{
		m_shader.Use();
		auto x = glGetUniformLocation(m_shader.GetShader(), "Torch.diffuse");
		if (x != -1)
			glUniform3f(x, color.x, color.y, color.z);
		else
			std::cerr << "color attribute not found\n";
	}
	void FlashLightMaterial::SetSpecularity(const Vector3& color)
	{
		m_shader.Use();
		auto x = glGetUniformLocation(m_shader.GetShader(), "Torch.specular");
		if (x != -1)
			glUniform3f(x, color.x, color.y, color.z);
		else
			std::cerr << "specular attribute not found\n";
	}
	void FlashLightMaterial::SetShininess(float shininess)
	{
	}
	void FlashLightMaterial::SetPosition(Vector3 pos)
	{
		m_shader.Use();
		auto x = glGetUniformLocation(m_shader.GetShader(), "Torch.position");
		if (x != -1)
			glUniform3f(x, pos.x, pos.y, pos.z);
		else
			std::cerr << "position attribute not found\n";
	}
	void FlashLightMaterial::SetAmbient(const Vector3& color)
	{
		m_shader.Use();
		auto x = glGetUniformLocation(m_shader.GetShader(), "Torch.ambient");
		if (x != -1)
			glUniform3f(x, color.x, color.y, color.z);
		else
			std::cerr << "ambient attribute not found\n";
	}
	void FlashLightMaterial::SetCLinear(float value)
	{
		m_shader.Use();
		auto x = glGetUniformLocation(m_shader.GetShader(), "Torch.cLinear");
		if (x != -1)
			glUniform1f(x, value);
		else
			std::cerr << "cLinear attribute not found\n";
	}
	void FlashLightMaterial::SetCQuadratic(float value)
	{
		m_shader.Use();
		auto x = glGetUniformLocation(m_shader.GetShader(), "Torch.cQuadratic");
		if (x != -1)
			glUniform1f(x, value);
		else
			std::cerr << "cQuadratic attribute not found\n";
	}
	void FlashLightMaterial::SetDirection(Vector3 dir)
	{
		dir.Normalize();
		m_shader.Use();
		auto x = glGetUniformLocation(m_shader.GetShader(), "Torch.direction");
		if (x != -1)
			glUniform3f(x, dir.x, dir.y, dir.z);
		else
			std::cerr << "direction attribute not found\n";
	}
	void FlashLightMaterial::SetInnerRing(float degrees)
	{
		m_shader.Use();
		auto x = glGetUniformLocation(m_shader.GetShader(), "Torch.innerRing");
		auto y = glGetUniformLocation(m_shader.GetShader(), "Torch.outerRing");
		if (x != -1)
		{
			glUniform1f(x, std::cos(degrees * 0.0174533f));
			glUniform1f(y, std::cos((degrees + 2.0f) * 0.0174533f));
		}
		else
			std::cerr << "cQuadratic attribute not found\n";

	}
}