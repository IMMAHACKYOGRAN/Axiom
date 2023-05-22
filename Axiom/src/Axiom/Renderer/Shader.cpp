#include "axpch.h"
#include "Shader.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Axiom
{
	Ref<Shader> Shader::Create(const std::string& filePath)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: AX_CORE_ASSERT(false, "No render API selected"); return nullptr;
		case RendererAPI::API::OpenGL: return std::make_shared<OpenGLShader>(filePath);
		}

		AX_CORE_ASSERT(false, "That API doesnt exist");
		return nullptr;
	}

	Ref<Shader> Shader::Create(const std::string& vertexsrc, const std::string& fragsrc)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: AX_CORE_ASSERT(false, "No render API selected"); return nullptr;
		case RendererAPI::API::OpenGL: return std::make_shared<OpenGLShader>(vertexsrc, fragsrc);
		}

		AX_CORE_ASSERT(false, "That API doesnt exist");
		return nullptr;
	}
}