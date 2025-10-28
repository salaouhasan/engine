#pragma once


#include <string>
struct GLFWwindow;


namespace Engine {


	class Window {
	public:
		Window(int width, int height, const std::string& title);
		~Window();


		bool Init();
		void PollEvents();
		void SwapBuffers();
		bool ShouldClose() const;


	private:
		int m_Width, m_Height;
		std::string m_Title;
		GLFWwindow* m_Raw = nullptr;
	};


}