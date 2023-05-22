#include "axpch.h"
#include "Texture.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h" 

namespace Axiom
{
	Ref<Texture2D> Texture2D::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: AX_CORE_ASSERT(false, "No render API selected"); return nullptr;
		case RendererAPI::API::OpenGL: return std::make_shared<OpenGLTexture2D>(path);
		}

		AX_CORE_ASSERT(false, "That API doesnt exist");
		return nullptr;
	}
}