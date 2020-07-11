//
// Created by spounka on 17/06/2020.
//

#ifndef THEDEADWOODS_INCLUDE_MODEL_HPP_
#define THEDEADWOODS_INCLUDE_MODEL_HPP_

#include <string>
#include <vector>

#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

#include "glm/glm.hpp"
#include "glm/ext.hpp"

#include "mesh.hpp"

namespace SE::Graphics
{
	/**
	 * @brief Class for loading 3D model using ASSIMP
	 * 
	 */
	class Model
	{
		/**
		 * @privatesection
		 */
	  private:
	  	/**
	  	 * @brief std::vector containing all the sub meshes forming the final mesh
	  	 * @see Mesh
	  	 */
		std::vector<Mesh> meshes;

		/**
		 * @brief std::vector containing textures used by the mesh
		 * 
		 */
		std::vector<Texture> textures;	
		
		/**
		 * @brief Processes the mesh for sub meshes and textures
		 * 
		 * @param scene aiScene* the scene containing the mesh
		 * @param pMesh aiMesh* the actual mesh
		 * @return Mesh
		 */
		Mesh ProcessMesh(const aiScene* scene, aiMesh* pMesh);

		/**
		 * @brief 
		 * 
		 * @param filePath opens the file (3D model file) at filePath
		 * @return true if reading was successful
		 * @return false if an error occured
		 */
		bool importFile(const std::string& filePath);

		/**
		 * @brief loops through the scene for meshes
		 * 
		 * @param node the current node to process 
		 * @param pScene the scene which to look for nodes at
		 */
		void ProcessScene(aiNode* node, const aiScene* pScene);

	  public:
	  	/**
	  	 * @brief SE::Graphics::Shader object to use when drawing the mesh
	  	 * 
	  	 */
		Shader shader;
		
		/**
		 * @brief Construct a new Model object
		 * 
		 * @param filePath path to 3D model file
		 * @param s reference to a SE::Graphics::Shader object
		 */
		explicit Model(const std::string& filePath, const Shader& s);

		/**
		 * @brief Draws the mesh and all submeshes
		 * 
		 */
		void Draw();

	};
}

#endif //THEDEADWOODS_INCLUDE_MODEL_HPP_
