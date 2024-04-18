#pragma once

#include "string"
#include <glm/glm.hpp>

namespace Table
{
	class Shader
	{
	public:
		~Shader() = default;

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		static Shader* Create(const std::string& filepath);
		static Shader* Create(const std::string& vertexSrc, const std::string fragmentSrc);
	private:
		uint32_t m_RendererID;
	};
}

