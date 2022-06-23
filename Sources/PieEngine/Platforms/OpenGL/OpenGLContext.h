#pragma once

#include "Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace PieGraphics {

	class OpenGLContext: public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void init() override;
		virtual void swapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};

}

