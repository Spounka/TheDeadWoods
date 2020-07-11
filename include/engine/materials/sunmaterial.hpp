//
// Created by spounka on 01/07/2020.
//

#ifndef THEDEADWOODS_SRC_MATERIAL_CPP_SUNMATERIAL_HPP_
#define THEDEADWOODS_SRC_MATERIAL_CPP_SUNMATERIAL_HPP_

#include <engine/graphics/shader.hpp>
#include "engine/vector3.hpp"

namespace SE::Graphics
{
	struct SunMaterial
	{
	  private:
		SE::Graphics::Shader m_shader;
	  public:
		explicit SunMaterial(const SE::Graphics::Shader& shader) : m_shader(shader)
		{}
		void SetColor(const SE::Vector3& color);
		void SetSpecularity(const SE::Vector3& color);
		void SetShininess(float shininess);
		void SetDirection(SE::Vector3 dir);
		void SetAmbient(const SE::Vector3& color);
	};
}
#include "engine/graphics/shader.hpp"
#endif //THEDEADWOODS_SRC_MATERIAL_CPP_SUNMATERIAL_HPP_
