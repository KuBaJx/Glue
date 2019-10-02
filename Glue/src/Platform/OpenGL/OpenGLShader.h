#pragma once

#include "Glue/Renderer/Shader.h"

#include <glm/glm.hpp>

namespace Glue
{
	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const char* vertexPath, const char* fragmentPath);
		virtual ~OpenGLShader();

		virtual void Bind() const override;
		virtual void Unbind() const override;
		virtual void SetUniform1f(const std::string& name, float value) override;
		virtual void SetUniform4f(const std::string& name, float v1, float v2, float v3, float va) override;
		virtual void SetUniformMat4(const std::string& name, const glm::mat4& matrix) override;

		uint32_t GetUniformLocation(const std::string& name);

	private:
		uint32_t CreateShader(const std::string& vertexPath, const std::string& fragmentPath);
		uint32_t CompileShader(uint32_t type, const std::string& source);

	private:
		uint32_t m_RendererID;
		std::unordered_map<std::string, int> m_UniformLocationCache;
	};
}