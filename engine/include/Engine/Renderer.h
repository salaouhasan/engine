#pragma once


namespace Engine {


	class Renderer {
	public:
		static bool Init();
		static void BeginFrame();
		static void RenderFrame();
		static void EndFrame();
	};


} // namespace Engine