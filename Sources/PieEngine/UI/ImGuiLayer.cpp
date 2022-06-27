#include "Pie.h"
#include "ImGuiLayer.h"

#include "imgui.h"

#define IMGUI_IMPL_API
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_glfw.h"

#include "App/App.h"

//TEMP
#include "GLFW/glfw3.h"
#include <glad/glad.h>

namespace Core {

	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer") { }

	ImGuiLayer::~ImGuiLayer() { }

	void ImGuiLayer::attach() {
		//ACR_PROFILE_FUNCTION();

		// Setup Dear ImGui context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void) io;

		// Enable Keyboard Controls
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

		// Enable Gamepad Controls
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

		// Enable Docking
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

		// Enable Multi-Viewport / Platform Windows
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;


		/*io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoTaskBarIcons;
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoMerge;*/

		// Setup Dear ImGui style
		//ImGui::StyleColorsDark();
		ImGui::StyleColorsClassic();

		// When viewports are enabled we tweak WindowRounding/WindowBg so playform widnows can look identical to regularones
		ImGuiStyle& style = ImGui::GetStyle();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
			style.WindowRounding = 0.0f;
			style.Colors [ImGuiCol_WindowBg].w = 1.0f;
		}

		Foundation::App& app = Foundation::App::get();
		GLFWwindow* window = static_cast<GLFWwindow*>(app.getWindow().GetNativeWindow());

		// Setup Platform/Renderer bindings
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::detach() {
		//ACR_PROFILE_FUNCTION();

		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	void ImGuiLayer::handle(Foundation::Event& e) { }

	void ImGuiLayer::begin() {
		//ACR_PROFILE_FUNCTION();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void ImGuiLayer::end() {
		//ACR_PROFILE_FUNCTION();

		ImGuiIO& io = ImGui::GetIO();
		Foundation::App& app = Foundation::App::get();
		io.DisplaySize = ImVec2((float) app.getWindow().getWidth(),
								(float) app.getWindow().getWidth());

		// Rendering
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		}

	}

	void ImGuiLayer::setDarkThemeColors() { }

}