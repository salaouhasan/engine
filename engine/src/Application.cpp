#include "Engine/Application.h"
#include "Engine/Renderer.h"
#include <spdlog/spdlog.h>


namespace Engine {


	Application::Application() {
		// create a default window (Window encapsulates GLFW and GL context)
		m_Window = std::make_unique<Window>(1280, 720, "Engine Prototype");
	}


	Application::~Application() {}


	bool Application::Init() {
		if (!m_Window->Init()) {
			spdlog::error("Window initialization failed");
			return false;
		}


		// Initialize renderer and resources here
		if (!Renderer::Init()) {
			spdlog::error("Renderer init failed");
			return false;
		}


		m_Running = true;
		return true;
	}


	void Application::Run() {
		while (m_Running && !m_Window->ShouldClose()) {
			// Poll input and events
			m_Window->PollEvents();


			// Update scene / ECS here


			// Render frame
			Renderer::BeginFrame();
			Renderer::RenderFrame();
			Renderer::EndFrame();


			// Swap
			m_Window->SwapBuffers();
		}
	}


	void Application::Quit() {
		m_Running = false;
	}


} // namespace Engine