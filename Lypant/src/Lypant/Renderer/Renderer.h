#pragma once

#include "lypch.h"
#include "VertexArray.h"
#include "RenderCommand.h"
#include "Lypant/Camera/PerspectiveCamera.h"
#include "Shader.h"
#include "glm/glm.hpp"
#include "Lypant/Light/Light.h"

namespace lypant
{
	class Renderer
	{
	public:
		friend class Application;

		static void BeginScene(const std::shared_ptr<PerspectiveCamera>& camera, const std::vector<std::shared_ptr<Light>>& lights);
		static void EndScene();
		static void Submit(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& shader, const glm::mat4& modelMatrix);
	private:
		static void Init();
		static void Shutdown();
		static void OnWindowResize(uint32_t width, uint32_t height);
	private:
		struct SceneData
		{
			std::vector<std::shared_ptr<Light>> Lights;
			std::shared_ptr<PerspectiveCamera> Camera;
			std::unique_ptr<UniformBuffer> LightUniformBuffer;
			char* LightBuffer;
		};

		static SceneData s_SceneData;
	};
}
