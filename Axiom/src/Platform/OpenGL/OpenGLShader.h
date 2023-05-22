#pragma once
#include "Axiom/Renderer/Shader.h"
#include <glm/glm.hpp>

// BAD BAD BAD VERY BAD NOT GOOD
typedef unsigned int GLenum;

namespace Axiom {

	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& filePath);
		OpenGLShader(const std::string& vertexsrc, const std::string& fragsrc);
		virtual ~OpenGLShader();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		void UploadUniformFloat(const std::string& name, float value);
		void UploadUniformFloat2(const std::string& name, const glm::vec2& vec);
		void UploadUniformFloat3(const std::string& name, const glm::vec3& vec);
		void UploadUniformFloat4(const std::string& name, const glm::vec4& vec);

		void UploadUniformInt(const std::string& name, int value);
		void UploadUniformInt2(const std::string& name, const glm::vec2& vec);
		void UploadUniformInt3(const std::string& name, const glm::vec3& vec);
		void UploadUniformInt4(const std::string& name, const glm::vec4& vec);

		void UploadUniformMat3(const std::string& name, const glm::mat3& matrix);
		void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);
	private:
		std::string ReadFile(const std::string& filePath);
		std::unordered_map<GLenum, std::string> Preprocess(const std::string& source);
		void Compile(const std::unordered_map<GLenum, std::string>& shaderSrcs);
	private:
		uint32_t m_RendererID;
	};
}
