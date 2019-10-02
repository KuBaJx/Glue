#include "gluepch.h"
#include "OpenGLShader.h"

#include <glad/glad.h>

#include <glm/gtc/type_ptr.hpp>

namespace Glue
{
	OpenGLShader::OpenGLShader(const char* vertexPath, const char* fragmentPath)
	{
		std::string vertexShaderSource, fragmentShaderSource;
		std::ifstream vertexFile, fragmentFile;

		vertexFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		fragmentFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		try {
			vertexFile.open(vertexPath);
			fragmentFile.open(fragmentPath);
			std::stringstream vShaderSource, vFragmentSource;

			vShaderSource << vertexFile.rdbuf();
			vFragmentSource << fragmentFile.rdbuf();

			vertexShaderSource = vShaderSource.str();
			fragmentShaderSource = vFragmentSource.str();
		}
		catch (std::ifstream::failure e)
		{
			GLUE_CORE_ERROR("Failed to read shader file!\n {0}", e.what());
			__debugbreak();
		}

		CreateShader(vertexShaderSource, fragmentShaderSource);
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(m_RendererID);
	}

	uint32_t OpenGLShader::CompileShader(uint32_t type, const std::string& src)
	{
		int success;
		char msg[1024];

		uint32_t id = glCreateShader(type);
		const char* shaderSource = src.c_str();

		glShaderSource(id, 1, &shaderSource, nullptr);
		glCompileShader(id);

		glGetShaderiv(id, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(id, sizeof(msg), nullptr, msg);
			GLUE_CORE_ERROR("Failed to compile {0} SHADER!\n Error: {1}", (type == GL_VERTEX_SHADER) ? "VERTEX" : "FRAGMENT", msg);
			glDeleteShader(id);
			return -1;
		}

		return id;
	}

	uint32_t OpenGLShader::CreateShader(const std::string& vertexPath, const std::string& fragmentPath)
	{
		int success;
		char msg[1024];

		m_RendererID = glCreateProgram();
		uint32_t vertexShader = CompileShader(GL_VERTEX_SHADER, vertexPath);
		uint32_t fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentPath);

		glAttachShader(m_RendererID, vertexShader);
		glAttachShader(m_RendererID, fragmentShader);

		glLinkProgram(m_RendererID);
		glValidateProgram(m_RendererID);

		glGetProgramiv(m_RendererID, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(m_RendererID, sizeof(msg), nullptr, msg);
			GLUE_CORE_ERROR("Shader program linking failed!\n Error: {0}", msg);
			return -1;
		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		return m_RendererID;
	}

	void OpenGLShader::Bind() const
	{
		glUseProgram(m_RendererID);
	}

	void OpenGLShader::Unbind() const
	{
		glUseProgram(NULL);
	}

	void OpenGLShader::SetUniform1f(const std::string& name, float value)
	{
		glUniform1f(GetUniformLocation(name), value);
	}
	
	void OpenGLShader::SetUniform4f(const std::string& name, float v1, float v2, float v3, float va)
	{
		glUniform4f(GetUniformLocation(name), v1, v2, v3, va);;
	}

	void OpenGLShader::SetUniformMat4(const std::string& name, const glm::mat4& matrix)
	{
		glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
	}

	uint32_t OpenGLShader::GetUniformLocation(const std::string& name)
	{
		if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
		{
			return m_UniformLocationCache[name];
		}
		else
		{
			int location = glGetUniformLocation(m_RendererID, name.c_str());
			if (location == -1)
			{
				GLUE_CORE_WARN("Uniform {0} has not been found!\n", name);
			}
			else
			{
				m_UniformLocationCache[name] = location;
				return location;
			}
		}

		return 0;
	}
}