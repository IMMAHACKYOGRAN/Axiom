#pragma once
#include "RendererAPI.h"

namespace Axiom {

	class RenderCommand
	{
	public:
		inline static void Clear(const glm::vec4& colour)
		{
			s_RendererAPI->Clear(colour);
		}

		inline static void DrawIndexed(const Ref<VertexArray>& vertexArray)
		{
			s_RendererAPI->DrawIndexed(vertexArray);
		}

		inline static void Init()
		{
			s_RendererAPI->Init();
		}

	private:
		static RendererAPI* s_RendererAPI;
	};

}