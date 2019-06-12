#pragma once

namespace Glue
{
	class Shader
	{
	public:
		virtual ~Shader() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		virtual void SetUniform1f(const std::string& name, float value) = 0;
		virtual void SetUniform4f(const std::string& name, float v1, float v2, float v3, float va) = 0;
		
		static Shader* Create(const char* vertexPath, const char* fragmentPath);
	};
}