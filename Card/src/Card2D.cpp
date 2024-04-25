#include "Card2D.h"
#include <glm/gtc/matrix_transform.hpp>
#include <imgui/imgui.h>
#include <glm/gtc/type_ptr.hpp>

Card2D::Card2D()
	:Layer("Card2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Card2D::OnAttach()
{
	TABLE_PROFILE_FUNCTION();
	m_CheckerboardTexture = Table::Texture2D::Create("asset/textures/Checkerboard.png");
	m_FF0Texture = Table::Texture2D::Create("asset/textures/FF0Suki.png");
}

void Card2D::OnDetach()
{
	TABLE_PROFILE_FUNCTION();

}

void Card2D::OnUpdate(Table::TimeStep ts)
{
	TABLE_PROFILE_FUNCTION();

	Table::Renderer2D::ResetStats();

	static float temp = 0;
	temp += ts * 10.0f;
	m_CameraController.OnUpdate(ts);
	Table::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	Table::RenderCommand::Clear();
	Table::Renderer2D::BeginScene(m_CameraController.GetCamera());
	Table::Renderer2D::DrawQuad({ -1.0f,0.0f }, { 0.8f, 0.8f }, { 0.2f,0.2f,1.0f,1.0f });
	//Table::Renderer2D::DrawQuad({ 0.5f,0.5f }, { 2.0f, 0.5f }, { 0.8f,0.2f,1.0f,1.0f });
	Table::Renderer2D::DrawRotatedQuad({ 0.5f,-0.5f }, { 0.75, 0.75f }, -45.0f, { 0.8f,0.2f,1.0f,1.0f });
	Table::Renderer2D::DrawQuad({ 0.0f,0.0f,-0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture, 10.0f);
	Table::Renderer2D::DrawRotatedQuad({ 0.5f,1.0f }, { 1.0f,1.0f },temp , m_FF0Texture,1.0f,{ 0.8f,0.2f,1.0f,1.0f });
	Table::Renderer2D::EndScene();

	Table::Renderer2D::BeginScene(m_CameraController.GetCamera());
	for (float y = -5.0f; y < 5.0f; y += 0.5f)
	{
		for (float x = -5.0f; x < 5.0f; x += 0.5f)
		{
			glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 0.7f };
			Table::Renderer2D::DrawQuad({ x, y }, { 0.45f, 0.45f }, color);
		}
	}
	Table::Renderer2D::EndScene();
}

void Card2D::OnImGuiRender()
{
	ImGui::Begin("Settings");
	auto stats = Table::Renderer2D::GetStats();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
	ImGui::Text("Quads: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("Indices: %d", stats.GetTotalIndexCount());
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Card2D::OnEvent(Table::Event& e)
{
	m_CameraController.OnEvent(e);
}
