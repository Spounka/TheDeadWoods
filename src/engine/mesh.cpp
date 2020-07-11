//
// Created by spounka on 18/06/2020.
//

#include "engine/graphics/mesh.hpp"
#include <iostream>

namespace SE::Graphics
{
	Mesh::Mesh(Vertex* vertices, uint32_t numVerts, unsigned int* indices, uint32_t numIndices)
	{
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, numVerts * sizeof(Vertex), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(Vector3)));
		glEnableVertexAttribArray(1);

		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(Vector3) + sizeof(Vector2)));
		glEnableVertexAttribArray(2);

		this->numIndices = numIndices;

		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices * sizeof(unsigned int), indices, GL_STATIC_DRAW);

		glBindVertexArray(0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

	}
	void Mesh::Draw()
	{
		
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_INT, nullptr);
	}
}
