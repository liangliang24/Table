#include <Table.h>

#include "imgui/imgui.h"
#include <GLFW/include/GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <Platform/OpenGL/OpenGLShader.h>
#include <glm/gtc/type_ptr.hpp>

class ExampleLayer:public Table::Layer
{
public:
	ExampleLayer()
		: Layer("Example"),m_Camera(-1.6f, 1.6f, -0.9f, 0.9f),m_CameraPosition(0.0f)
	{
		m_VertexArray.reset(Table::VertexArray::Create());

		float vertices[3 * 7] =
		{
			-0.5f,	-0.5f,	0.0f,	0.0f,	0.2f,	0.8f,	1.0f,
			0.5f,	-0.5f,	0.0f,	0.2f,	0.3f,	0.8f,	1.0f,
			0.0f,	0.5f,	0.0f,	0.8f,	0.8f,	0.2f,	1.0f
		};

		std::shared_ptr<Table::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Table::VertexBuffer::Create(vertices, sizeof(vertices)));
		Table::BufferLayout layout = {
			{Table::ShaderDataType::Float3, "a_Position"},
			{Table::ShaderDataType::Float4, "a_Color"}
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0,1,2 };
		std::shared_ptr<Table::IndexBuffer> indexBuffer;
		indexBuffer.reset(Table::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);
		m_SquareVA.reset(Table::VertexArray::Create());


		float squareVertices[3 * 4] =
		{
			-0.75f, -0.75f, 0.0f,
			 0.75f, -0.75f, 0.0f,
			 0.75f,  0.75f, 0.0f,
			-0.75f,  0.75f, 0.0f
		};
		std::shared_ptr<Table::VertexBuffer> squareVB;
		squareVB.reset(Table::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout
		({
			{ Table::ShaderDataType::Float3,"a_Position" }
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0,1,2,2,3,0 };
		std::shared_ptr<Table::IndexBuffer> squareIB;
		squareIB.reset(Table::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			out vec4 v_Color;
			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			
			out vec4 color;
			in vec3 v_Position;
			in vec4 v_Color;
			void main()
			{
				color = v_Color;
			}
		)";

		m_Shader.reset(Table::Shader::create(vertexSrc, fragmentSrc));

		std::string blueShaderVertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;	
			uniform mat4 u_Transform;

			out vec3 v_Position;
			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
			}
		)";

		std::string blueShaderFragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			in vec3 v_Position;
			uniform float sinColor;
			void main()
			{
				color = vec4(sinColor, 0.3, 0.8, 1.0);
			}
		)";

		m_BlueShader.reset(Table::Shader::create(blueShaderVertexSrc, blueShaderFragmentSrc));
	}

	void OnUpdate(Table::TimeStep ts) override
	{
		if (Table::Input::IsKeyPressed(TABLE_KEY_LEFT))
		{
			m_CameraPosition.x -= m_CameraMovedSpeed * ts;
		}
		else if (Table::Input::IsKeyPressed(TABLE_KEY_RIGHT))
		{
			m_CameraPosition.x += m_CameraMovedSpeed * ts;
		}

		if (Table::Input::IsKeyPressed(TABLE_KEY_UP))
		{
			m_CameraPosition.y += m_CameraMovedSpeed * ts;
		}
		else if (Table::Input::IsKeyPressed(TABLE_KEY_DOWN))
		{
			m_CameraPosition.y -= m_CameraMovedSpeed * ts;
		}

		if (Table::Input::IsKeyPressed(TABLE_KEY_A))
		{
			m_CameraRotation += m_CameraRotationSpeed * ts;
		}

		if (Table::Input::IsKeyPressed(TABLE_KEY_D))
		{
			m_CameraRotation -= m_CameraRotationSpeed * ts;
		}

		Table::RenderCommand::SetClearColor({ 0.1f,0.1f,0.1f,1 });
		Table::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		Table::Renderer::BeginScene(m_Camera);

		//m_BlueShader->Bind();
		Table::Renderer::Submit(m_BlueShader, m_SquareVA);
		double timeValue = glfwGetTime();
		float ColorOffsetVal = static_cast<float>(sin(timeValue));
		ColorOffsetVal = std::clamp(ColorOffsetVal, 0.0f, 1.0f);
		std::dynamic_pointer_cast<Table::OpenGLShader>(m_BlueShader)->UploadUniformFloat("sinColor", ColorOffsetVal);
		glDrawElements(GL_TRIANGLES, m_SquareVA->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);

		//m_Shader->Bind();
		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));
		for (int x = 0;x < 20;x++)
		{
			for (int y = 0;y < 20;y++)
			{
				glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
				Table::Renderer::Submit(m_Shader, m_VertexArray, transform);
			}
		}
		//Table::Renderer::Submit(m_Shader, m_VertexArray);
		//glDrawElements(GL_TRIANGLES, m_VertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);

		Table::Renderer::EndScene();
		if (Table::Input::IsKeyPressed(TABLE_KEY_TAB))
		{
			TABLE_TRACE("Tab key is pressed(poll)");
		}
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Settings");
		ImGui::ColorEdit3("Square Color",glm::value_ptr(m_SquareColor));
		ImGui::End();
	}
	
	void OnEvent(Table::Event& event) override
	{
		if (event.GetEventType() ==  Table::EventType::KeyPressed)
		{
			Table::KeyPressedEvent& e = (Table::KeyPressedEvent&)event;
			if (e.GetKeyCode() == TABLE_KEY_TAB)
			{
				TABLE_TRACE("Tab key is pressed(event)");
			}
			TABLE_TRACE("{0}", e.GetKeyCode());
		}
	}

private:
	std::shared_ptr<Table::Shader> m_Shader;
	std::shared_ptr<Table::VertexArray> m_VertexArray;
	std::shared_ptr<Table::Shader> m_BlueShader;
	std::shared_ptr<Table::VertexArray> m_SquareVA;

	Table::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraMovedSpeed = 5.0f;

	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 180.0f;

	glm::vec3 m_SquareColor = { 0.2f,0.3f,0.8f };
};

class Card : public Table::Application
{
public:
	Card()
	{
		PushLayer(new ExampleLayer());
	}

	~Card()
	{

	}

};

Table::Application* Table::CreateApplication()
{
	return new Card();
}