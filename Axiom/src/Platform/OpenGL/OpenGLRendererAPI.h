#pragma once

#include "Axiom/Renderer/RendererAPI.h"

namespace Axiom {

	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		virtual void Init() override;

		virtual void Clear(const glm::vec4& colour) override;
		virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) override;

		inline static API GetAPI() { return s_API; }
	private:
		static API s_API;
	};

}