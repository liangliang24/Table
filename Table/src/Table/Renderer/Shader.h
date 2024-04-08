#pragma once

#include "string"

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
	private:
		uint32_t m_RendererID;
	};
}

