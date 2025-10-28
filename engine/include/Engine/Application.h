#pragma once


#include <memory>
#include "Window.h"


namespace Engine {


	class Application {
	public:
		Application();
		virtual ~Application();


		// Initialize the engine subsystems (window, renderer, resource manager)
		bool Init();


		// Run main loop
		void Run();


		// Quit request
		void Quit();


	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = false;
	};


} // namespace Engine