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
		: Layer("Example"), m_CameraController(1280.0f / 720.0f)
	{
		m_VertexArray.reset(Table::VertexArray::Create());
		float vertices[3 * 3] =
		{
			-0.5f,	-0.5f,	0.0f,
			0.5f,	-0.5f,	0.0f,
			0.0f,	0.5f,	0.0f,
		};

		Table::Ref<Table::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Table::VertexBuffer::Create(vertices, sizeof(vertices)));
		Table::BufferLayout layout = {
			{Table::ShaderDataType::Float3, "a_Position"}
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0,1,2 };
		Table::Ref<Table::IndexBuffer> indexBuffer;
		indexBuffer.reset(Table::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);


		m_SquareVA.reset(Table::VertexArray::Create());
		float squareVertices[3 * 4] =
		{
			0.0f, -1.0f, 0.0f,
			1.0f, -1.0f, 0.0f,
			1.0f,  0.0f, 0.0f,
			0.0f,  0.0f, 0.0f
		};
		Table::Ref<Table::VertexBuffer> squareVB;
		squareVB.reset(Table::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout
		({
			{ Table::ShaderDataType::Float3,"a_Position" }
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0,1,2,2,3,0 };
		Table::Ref<Table::IndexBuffer> squareIB;
		squareIB.reset(Table::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		m_TextureVA.reset(Table::VertexArray::Create());
		float textureVertices[5 * 4] =
		{
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};
		Table::Ref<Table::VertexBuffer> textureVB;
		textureVB.reset(Table::VertexBuffer::Create(textureVertices, sizeof(textureVertices)));
		textureVB->SetLayout
		({
			{Table::ShaderDataType::Float3,"a_Position"},
			{Table::ShaderDataType::Float2,"a_TexCoord"}
			});
		m_TextureVA->AddVertexBuffer(textureVB);
		uint32_t textureIndices[6] = { 0,1,2,2,3,0 };
		Table::Ref<Table::IndexBuffer> textureIB;
		textureIB.reset(Table::IndexBuffer::Create(textureIndices, sizeof(textureIndices) / sizeof(uint32_t)));
		m_TextureVA->SetIndexBuffer(textureIB);
		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			void main()
			{
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			
			uniform vec3 u_Color;
			out vec4 color;
			void main()
			{
				color =vec4(u_Color,1.0f);
			}
		)";

		m_Shader = Table::Shader::Create("VertexPosColor", vertexSrc, fragmentSrc);

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

		m_BlueShader = Table::Shader::Create("m_BlueColor", blueShaderVertexSrc, blueShaderFragmentSrc);

		auto textureShader = m_ShaderLibrary.Load("asset/shaders/Texture.glsl");

		m_Texture = Table::Texture2D::Create("asset/textures/Checkerboard.png");
		m_FF0Texture = Table::Texture2D::Create("asset/textures/FF0Suki.png");

		std::dynamic_pointer_cast<Table::OpenGLShader>(textureShader)->Bind();
		std::dynamic_pointer_cast<Table::OpenGLShader>(textureShader)->UploadUniformInt("u_Texture", 0);
	}

	void OnUpdate(Table::TimeStep ts) override
	{
		m_CameraController.OnUpdate(ts);

		Table::RenderCommand::SetClearColor({ 0.1f,0.1f,0.1f,1 });
		Table::RenderCommand::Clear();

		Table::Renderer::BeginScene(m_CameraController.GetCamera());

		//m_BlueShader->Bind();
		Table::Renderer::Submit(m_BlueShader, m_SquareVA);
		double timeValue = glfwGetTime();
		float ColorOffsetVal = static_cast<float>(sin(timeValue));
		ColorOffsetVal = std::clamp(ColorOffsetVal, 0.0f, 1.0f);
		std::dynamic_pointer_cast<Table::OpenGLShader>(m_BlueShader)->UploadUniformFloat("sinColor", ColorOffsetVal);
		glDrawElements(GL_TRIANGLES, m_SquareVA->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);

		std::dynamic_pointer_cast<Table::OpenGLShader>(m_Shader)->Bind();
		std::dynamic_pointer_cast<Table::OpenGLShader>(m_Shader)->UploadUniformFloat3("u_Color", m_SquareColor);

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

		auto textureShader = m_ShaderLibrary.Get("Texture");

		m_Texture->Bind();
		Table::Renderer::Submit(textureShader, m_TextureVA);
		m_FF0Texture->Bind();
		Table::Renderer::Submit(textureShader, m_TextureVA);
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
	
	void OnEvent(Table::Event& e) override
	{
		if (e.GetEventType() == Table::EventType::KeyPressed)
		{
			Table::KeyPressedEvent& event = (Table::KeyPressedEvent&)e;
			if (event.GetKeyCode() == TABLE_KEY_TAB)
			{
				TABLE_TRACE("Tab key is pressed(e)");
			}
			TABLE_TRACE("{0}", event.GetKeyCode());
		}

		m_CameraController.OnEvent(e);
	}

private:
	Table::ShaderLibrary  m_ShaderLibrary;
	Table::Ref<Table::Shader> m_Shader;
	Table::Ref<Table::VertexArray> m_VertexArray;
	Table::Ref<Table::Shader> m_BlueShader;
	Table::Ref<Table::VertexArray> m_SquareVA;
	Table::Ref<Table::VertexArray> m_TextureVA;

	Table::Ref<Table::Texture2D> m_Texture, m_FF0Texture;

	Table::OrthographicCameraController m_CameraController;

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