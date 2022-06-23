#include "Acrpch.h"
#include "OpenGLContext.h"

#include "GLFW/glfw3.h"
#include <glad/glad.h>

namespace Acrylic {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) 
		: m_WindowHandle(windowHandle)
	{
		ACR_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::init() 
	{
		ACR_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ACR_CORE_ASSERT(status, "Failed to initialize Glad!");

		ACR_CORE_INFO("OpenGL info:");
		ACR_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		ACR_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		ACR_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers() 
	{
		ACR_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

};