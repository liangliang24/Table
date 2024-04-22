#include "Card2D.h"
#include <Platform/OpenGL/OpenGLShader.h>
#include <glm/gtc/matrix_transform.hpp>
#include <imgui/imgui.h>
#include <glm/gtc/type_ptr.hpp>

Card2D::Card2D()
	:Layer("Card2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Card2D::OnAttach()
{
	m_SquareVA = Table::VertexArray::Create();

	float squareVertices[5 * 4] =
	{
		-0.5f,-0.5f,0.0f,
		0.5f,-0.5f,0.0f,
		0.5f,0.5f,0.0f,
		-0.5f,0.5f,0.0f
	};

	Table::Ref<Table::VertexBuffer> squareVB;
	squareVB.reset(Table::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
	squareVB->SetLayout
	(
		{
			{Table::ShaderDataType::Float3, "a_Position"}
		}
	);
	m_SquareVA->AddVertexBuffer(squareVB);

	uint32_t squareIndices[6] = { 0,1,2,2,3,0 };
	Table::Ref<Table::IndexBuffer> squareIB;
	squareIB.reset(Table::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
	m_SquareVA->SetIndexBuffer(squareIB);

	m_FlatColorShader = Table::Shader::Create("asset/shaders/FlatColor.glsl");
}

void Card2D::OnDetach()
{

}

void Card2D::OnUpdate(Table::TimeStep ts)
{
	m_CameraController.OnUpdate(ts);

	Table::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	Table::RenderCommand::Clear();

	Table::Renderer::BeginScene(m_CameraController.GetCamera());

	std::dynamic_pointer_cast<Table::OpenGLShader>(m_FlatColorShader)->Bind();
	std::dynamic_pointer_cast<Table::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);

	Table::Renderer::Submit(m_FlatColorShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

	Table::Renderer::EndScene();
}

void Card2D::OnImGuiRender()
{
	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Card2D::OnEvent(Table::Event& e)
{
	m_CameraController.OnEvent(e);
}
