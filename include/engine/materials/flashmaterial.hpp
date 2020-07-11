//
// Created by spounka on 01/07/2020.
//

#ifndef THEDEADWOODS_SRC_MATERIAL_CPP_FLASHMATERIAL_HPP_
#define THEDEADWOODS_SRC_MATERIAL_CPP_FLASHMATERIAL_HPP_


#include "engine/vector3.hpp"
#include "engine/graphics/shader.hpp"

namespace SE::Graphics
{
	struct FlashLightMaterial
	{
	  private:
		SE::Graphics::Shader m_shader;
	  public:
		FlashLightMaterial(const SE::Graphics::Shader& shader) : m_shader(shader)
		{}
		void SetColor(const SE::Vector3& color);
		void SetSpecularity(const SE::Vector3& color);
		void SetShininess(float shininess);

		void SetDirection(SE::Vector3 dir);
		void SetPosition(SE::Vector3 pos);
		void SetAmbient(const SE::Vector3& color);
		void SetCLinear(float value);
		void SetCQuadratic(float value);
		void SetInnerRing(float degrees);

	};
}

#endif //THEDEADWOODS_SRC_MATERIAL_CPP_FLASHMATERIAL_HPP_
