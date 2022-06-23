#pragma once

#include "Acrylic/Renderer/Shader.h"
#include <glm/glm.hpp>

typedef unsigned int GLenum;
typedef int GLint;

// Documentation: https://www.khronos.org/opengl/wiki/Shader_Compilation

namespace Acrylic {

	class OpenGLShader: public Shader
	{
	public:
		OpenGLShader(const std::string& filepath);
		OpenGLShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);
		~OpenGLShader();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual void SetMat4(const std::string& name, const glm::mat4& matrix) override;
		virtual void SetMat3(const std::string& name, const glm::mat3& matrix) override;

		virtual void SetFloat4(const std::string& name, const glm::vec4& values) override;
		virtual void SetFloat3(const std::string& name, const glm::vec3& values) override;
		virtual void SetFloat2(const std::string& name, const glm::vec2& values) override;
		virtual void SetFloat(const std::string& name, float value) override;

		virtual void SetIntArray(const std::string& name, int* values, uint32_t count) override;
		virtual void SetInt(const std::string& name, int value) override;

		virtual const std::string& GetName() const override { return m_Name; }

		void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);
		void UploadUniformMat3(const std::string& name, const glm::mat3& matrix);

		void UploadUniformFloat4(const std::string& name, const glm::vec4& values);
		void UploadUniformFloat3(const std::string& name, const glm::vec3& values);
		void UploadUniformFloat2(const std::string& name, const glm::vec2& values);
		void UploadUniformFloat(const std::string& name, float value);

		void UploadUniformIntArray(const std::string& name, int* values, uint32_t count);
		void UploadUniformInt(const std::string& name, int value);

	private:
		GLint GetUniformLocation(const std::string& name) const;
		std::string ReadFile(const std::string& filepath);
		std::unordered_map<GLenum, std::string> PreProcess(const std::string& source);
		void Compile(std::unordered_map<GLenum, std::string>& shaderSources);

	private:
		std::string m_Name;
		uint32_t m_RendererID;
		mutable std::unordered_map<std::string, GLint> m_UniformLocationCache;
	};

}