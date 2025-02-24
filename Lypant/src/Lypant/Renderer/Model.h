#pragma once

#include "lypch.h"
#include "Mesh.h"
#include <glm/glm.hpp>

struct aiScene;
struct aiNode;
struct aiMesh;

namespace lypant
{
	class Model
	{
	public:
		Model(const std::string& path);
		void ProcessNode(aiNode* node, const aiScene* scene);
		void ProcessMesh(aiMesh* mesh, const aiScene* scene);

		inline const std::vector<Mesh>& GetMeshes() const { return m_Meshes; }
	private:
		struct Vertex
		{
			glm::vec3 Position;
			glm::vec3 Normal;
			glm::vec2 TexCoord;
		};
	private:
		std::vector<Mesh> m_Meshes;
		std::string m_Path;
	};
}
