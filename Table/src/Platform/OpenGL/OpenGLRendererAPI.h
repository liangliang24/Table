#pragma once
#include "Table/Renderer/RendererAPI.h"


namespace Table
{
	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		virtual void Init() override;

		void SetClearColor(const glm::vec4& color) override;

		void Clear() override;

		void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) override;


		void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;

	};
}

