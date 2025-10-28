#include "Engine/Window.h"
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>


namespace Engine {


	Window::Window(int width, int height, const std::string& title)
		: m_Width(width), m_Height(height), m_Title(title) {
	}


	Window::~Window() {
		if (m_Raw) glfwDestroyWindow(m_Raw);
	}


	bool Window::Init() {
		if (!glfwInit()) return false;


		// Request core profile and 4.5+ for modern features if available
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


		m_Raw = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);
		if (!m_Raw) {
			spdlog::error("glfwCreateWindow failed");
			return false;
		}


		glfwMakeContextCurrent(m_Raw);
		// load GL functions (assuming glad)
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			spdlog::error("Failed to initialize GLAD");
			return false;
		}


		return true;
	}


	void Window::PollEvents() { glfwPollEvents(); }
	void Window::SwapBuffers() { glfwSwapBuffers(m_Raw); }
	bool Window::ShouldClose() const { return glfwWindowShouldClose(m_Raw); }


} // namespace Engine