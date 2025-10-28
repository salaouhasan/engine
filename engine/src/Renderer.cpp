#include "Engine/Renderer.h"
#include "Engine/ForwardPlusRenderer.h"
#include <spdlog/spdlog.h>


namespace Engine {


	static ForwardPlusRenderer* s_ForwardPlus = nullptr;


	bool Renderer::Init() {
		spdlog::info("Initializing Renderer...");


		s_ForwardPlus = new ForwardPlusRenderer();
		if (!s_ForwardPlus->Init()) {
			spdlog::error("ForwardPlus init failed");
			return false;
		}


		return true;
	}


	void Renderer::BeginFrame() {
		// Any per-frame GPU setup
	}


	void Renderer::RenderFrame() {
		// In a more complex engine you'd select pipeline based on camera/settings
		s_ForwardPlus->Render();
	}


	void Renderer::EndFrame() {
		// GPU sync or profiling
	}


} // namespace Engine