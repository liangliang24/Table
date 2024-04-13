#pragma once

#include "string"
#include <glm/glm.hpp>

namespace Table
{
	class Shader
	{
	public:
		Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
		~Shader();

		void Bind() const;
		void UnBind() const;

		void SetFloat(const std::string& name, float value);
		void SetInt(const std::string& name, int value);

		void UploadeUniformMat4(const std::string& name, const glm::mat4& matrix);
	private:
		uint32_t m_RendererID;
	};
}

