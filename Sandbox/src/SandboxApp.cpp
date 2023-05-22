#include <Axiom.h>
#include "imgui/imgui.h"
#include <glm/gtc/type_ptr.hpp>
#include <Platform/OpenGL/OpenGLShader.h>

class ExampleLayer : public Axiom::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f), m_TrianglePos(0.0f)
	{
		m_VertexArray = Axiom::VertexArray::Create();

		float vertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};

		m_VertexBuffer = Axiom::VertexBuffer::Create(vertices, sizeof(vertices));
		Axiom::BufferLayout layout = {
			{ Axiom::ShaderDataType::Float3, "a_Position" },
			{ Axiom::ShaderDataType::Float2, "a_TexCoord" },
		};
		m_VertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(m_VertexBuffer);

		uint32_t indices[6] = { 0, 1, 2, 2, 3, 0 };
		m_IndexBuffer = Axiom::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
		m_VertexArray->SetIndexBuffer(m_IndexBuffer);

		m_TextureShader = Axiom::Shader::Create("assets/shaders/texture.glsl");
		m_Texture = Axiom::Texture2D::Create("assets/textures/Checkerboard.png");

		std::dynamic_pointer_cast<Axiom::OpenGLShader>(m_TextureShader)->Bind();
		std::dynamic_pointer_cast<Axiom::OpenGLShader>(m_TextureShader)->UploadUniformInt("u_Texture", 0);
	}

	// Engine Implemented Function
	void OnUpdate(Axiom::TimeStep ts) override
	{
		if (Axiom::Input::IsKeyPressed(AX_KEY_LEFT))
			m_CameraPosition.x -= m_CameraSpeed * ts;
		if (Axiom::Input::IsKeyPressed(AX_KEY_RIGHT))
			m_CameraPosition.x += m_CameraSpeed * ts;
		if (Axiom::Input::IsKeyPressed(AX_KEY_DOWN))
			m_CameraPosition.y -= m_CameraSpeed * ts;
		if (Axiom::Input::IsKeyPressed(AX_KEY_UP))
			m_CameraPosition.y += m_CameraSpeed * ts;

		Axiom::RenderCommand::Clear({ 0.12f, 0.12f, 0.12f, 1 });

		m_Camera.SetPosition(m_CameraPosition);

		Axiom::Renderer::BeginScene(m_Camera);

		m_Texture->Bind();
		Axiom::Renderer::Submit(m_TextureShader, m_VertexArray);

		Axiom::Renderer::EndScene();
	}

	// Engine Implemented Function
	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Settings");
		ImGui::Text("hello");
		ImGui::ColorEdit3("Colour", glm::value_ptr(m_ShaderColour));
		ImGui::End();
	}

	// Engine Implemented Function
	void OnEvent(Axiom::Event& e) override
	{
	}

private:
	Axiom::Ref<Axiom::Shader> m_Shader;
	Axiom::Ref<Axiom::VertexArray> m_VertexArray;

	Axiom::Ref<Axiom::Shader> m_TextureShader;
	Axiom::Ref<Axiom::Texture2D> m_Texture;

	Axiom::Ref<Axiom::VertexBuffer> m_VertexBuffer;
	Axiom::Ref<Axiom::IndexBuffer> m_IndexBuffer;

	Axiom::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraSpeed = 1;

	glm::vec3 m_TrianglePos;
	glm::vec3 m_ShaderColour = { 0.2f, 0.3f, 1.0f };
};

class Sandbox : public Axiom::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Axiom::Application* Axiom::CreateApplicaiton()
{
	return new Sandbox();
}