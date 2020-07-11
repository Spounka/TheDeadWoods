//
// Created by spounka on 22/06/2020.
//

#ifndef THEDEADWOODS_INCLUDE_ENGINE_MATERIAL_HPP_
#define THEDEADWOODS_INCLUDE_ENGINE_MATERIAL_HPP_

#include "engine/graphics/shader.hpp"
#include "engine/vector3.hpp"

namespace SE::Graphics
{
	struct Material
	{
	  private:
		Shader m_shader;
	  public:
		inline Shader GetShader() const
		{ return m_shader; }
		explicit Material(const Shader& shader) : m_shader(shader)
		{}
		void UseMaterial()
		{ m_shader.Use(); }

		void SetColor(const SE::Vector3& color);
		void SetSpecularity(const SE::Vector3& color);
		void SetShininess(float shininess);
		void SetShader(const Shader& shader);

	};

}
#endif //THEDEADWOODS_INCLUDE_ENGINE_MATERIAL_HPP_
