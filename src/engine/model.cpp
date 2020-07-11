//
// Created by spounka on 17/06/2020.
//

#include "engine/graphics/model.hpp"

#include <iostream>

namespace SE::Graphics
{
	//TODO: MAKE THE IMPORTING / PROCESSING MULTI THREADED 1
	bool Model::importFile(const std::string& filePath)
	{
		Assimp::Importer importer;
		const aiScene* scene = importer.ReadFile(filePath,
			aiProcess_Triangulate |
				aiProcess_FlipUVs
		);
		if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
		{
			fprintf(stdout, "Error Occured Loading File %s: %s", filePath.c_str(), importer.GetErrorString());
			return false;
		}
		ProcessScene(scene->mRootNode, scene);
		return true;

	}
	Model::Model(const std::string& filePath, const Shader& s) : shader(s)
	{
		importFile(filePath);
	}

	void Model::ProcessScene(aiNode* node, const aiScene* pScene)
	{
		for (uint i = 0; i < node->mNumMeshes; i++)
		{
			auto* mesh = pScene->mMeshes[node->mMeshes[i]];
			meshes.push_back(ProcessMesh(pScene, mesh));
		}

		for (uint i = 0; i < node->mNumChildren; i++)
		{
			ProcessScene(node->mChildren[i], pScene);
		}
	}
	Mesh Model::ProcessMesh(const aiScene* scene, aiMesh* pMesh)
	{
		std::vector<Vertex> vertices;
		std::vector<uint> indices;
		for (uint i = 0; i < pMesh->mNumVertices; i++)
		{
			Vertex v;
			Vector3 pos;
			pos.x = pMesh->mVertices[i].x;
			pos.y = pMesh->mVertices[i].y;
			pos.z = pMesh->mVertices[i].z;
			v.position = pos;
			pos.x = pMesh->mNormals[i].x;
			pos.y = pMesh->mNormals[i].y;
			pos.z = pMesh->mNormals[i].z;
			v.normals = pos;

			Vector2 uv;
			if (pMesh->mTextureCoords[0])
			{
				uv.x = pMesh->mTextureCoords[0][i].x;
				uv.y = pMesh->mTextureCoords[0][i].y;
			}
			v.uvCoords = uv;

			vertices.push_back(v);
		}
		for (uint i = 0; i < pMesh->mNumFaces; i++)
		{
			aiFace face = pMesh->mFaces[i];
			for (uint j = 0; j < face.mNumIndices; j++)
			{
				indices.push_back(face.mIndices[j]);
			}
		}

		return Mesh(&vertices[0], vertices.size(), &indices[0], indices.size());
	}

	void Model::Draw()
	{
		for (auto& mesh : meshes)
		{
			mesh.Draw();
		}
	}

}