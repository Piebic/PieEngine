#include "Acrpch.h"
#include "OpenGLVertexArray.h"

#include "glad/glad.h"

namespace Acrylic {

	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
		case Acrylic::ShaderDataType::Float:	return GL_FLOAT;

		case Acrylic::ShaderDataType::Float2:	return GL_FLOAT;

		case Acrylic::ShaderDataType::Float3:	return GL_FLOAT;

		case Acrylic::ShaderDataType::Float4:	return GL_FLOAT;

		case Acrylic::ShaderDataType::Mat3:		return GL_FLOAT;

		case Acrylic::ShaderDataType::Mat4:		return GL_FLOAT;

		case Acrylic::ShaderDataType::Int:		return GL_INT;

		case Acrylic::ShaderDataType::Int2:		return GL_INT;

		case Acrylic::ShaderDataType::Int3:		return GL_INT;

		case Acrylic::ShaderDataType::Int4:		return GL_INT;

		case Acrylic::ShaderDataType::Bool:		return GL_BOOL;
		}

		ACR_CORE_ASSERT(false, "Unknown ShaderDataType.");
		return 0;
	}

	OpenGLVertexArray::OpenGLVertexArray() 
	{
		ACR_PROFILE_FUNCTION();

		glCreateVertexArrays(1, &m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		ACR_PROFILE_FUNCTION();

		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		ACR_PROFILE_FUNCTION();

		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		ACR_PROFILE_FUNCTION();

		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer)
	{
		ACR_PROFILE_FUNCTION();

		ACR_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "Vertex buffer has no layout.");

		glBindVertexArray(m_RendererID);
		vertexBuffer->Bind();

		uint32_t index = 0;
		const auto& layout = vertexBuffer->GetLayout();
		for (const auto& element : layout) {
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index,
				element.GetComponentCount(),
				ShaderDataTypeToOpenGLBaseType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)element.Offset);
			index++;
		}

		m_VertexBuffer.push_back(vertexBuffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer)
	{
		ACR_PROFILE_FUNCTION();

		glBindVertexArray(m_RendererID);
		indexBuffer->Bind();

		m_IndexBuffer = indexBuffer;
	}

}