#pragma once

#include "Table.h"

class Card2D : public Table::Layer
{
public:
	Card2D();
	virtual ~Card2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Table::TimeStep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Table::Event& e) override;
private:
	Table::OrthographicCameraController m_CameraController;

	Table::Ref<Table::VertexArray> m_SquareVA;
	Table::Ref<Table::Shader> m_FlatColorShader;

	Table::Ref<Table::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f,0.3f,0.8f,1.0f };
};

