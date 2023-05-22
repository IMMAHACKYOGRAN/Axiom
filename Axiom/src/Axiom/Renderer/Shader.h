#pragma once
#include <string>

namespace Axiom 
{
	class Shader 
	{
	public:
		virtual ~Shader() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		static Ref<Shader> Create(const std::string& filePath);
		static Ref<Shader> Create(const std::string& vertexsrc, const std::string& fragsrc);
	};
}