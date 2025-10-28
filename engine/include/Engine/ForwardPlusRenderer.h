#pragma once
#include <vector>
#include <glm/glm.hpp>


namespace Engine {


	struct Light {
		glm::vec4 position_radius; // x,y,z = pos, w = radius
		glm::vec4 color_intensity; // rgb = color, a = intensity
	};


	class ForwardPlusRenderer {
	public:
		ForwardPlusRenderer();
		~ForwardPlusRenderer();


		bool Init();
		void Render();


	private:
		// GPU buffers: SSBOs for lights and tile/cluster lists
		unsigned int m_LightSSBO = 0;
		unsigned int m_LightIndexSSBO = 0;
		unsigned int m_LightGridSSBO = 0;


		int m_ScreenW = 1280;
		int m_ScreenH = 720;


		// Tile config
		const int TILE_SIZE = 16; // tweakable


		// demo list of lights stored on CPU to upload each frame
		std::vector<Light> m_Lights;


		// helper methods
		void UploadLights();
		void RunLightCulling();
		void DrawOpaque();
	};


} // namespace Engine