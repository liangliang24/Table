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

	m_CameraController.OnUpdate(ts);
	Table::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	Table::RenderCommand::Clear();
	Table::Renderer2D::BeginScene(m_CameraController.GetCamera());
	Table::Renderer2D::DrawQuad({ -1.0f,0.0f }, { 0.8f, 0.8f }, { 0.2f,0.2f,1.0f,1.0f });
	Table::Renderer2D::DrawQuad({ 0.5f,-0.5f }, { 0.75, 0.75f }, { 0.8f,0.2f,1.0f,1.0f });
	Table::Renderer2D::DrawQuad({ 0.0f,0.0f,-0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture);
	Table::Renderer2D::DrawQuad({ 0.5f,0.5f }, { 1.0f,1.0f }, m_FF0Texture);
	Table::Renderer2D::EndScene();
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
