//
// Created by spounka on 01/07/2020.
//

#ifndef THEDEADWOODS_SRC_MATERIAL_CPP_AREAMATERIAL_HPP_
#define THEDEADWOODS_SRC_MATERIAL_CPP_AREAMATERIAL_HPP_


#include "engine/graphics/shader.hpp"
#include "engine/vector3.hpp"



namespace SE::Graphics
{
	struct AreaLightMaterial
	{
	  private:
		SE::Graphics::Shader m_shader;
	  public:
		AreaLightMaterial(const SE::Graphics::Shader& shader) : m_shader(shader)
		{}
		void SetColor(const SE::Vector3& color);
		void SetSpecularity(const SE::Vector3& color);
		void SetShininess(float shininess);

		void SetPosition(SE::Vector3 pos);
		void SetAmbient(const SE::Vector3& color);
		void SetCLinear(float value);
		void SetCQuadratic(float value);

	};
}
#include "engine/vector3.hpp"
#endif //THEDEADWOODS_SRC_MATERIAL_CPP_AREAMATERIAL_HPP_
