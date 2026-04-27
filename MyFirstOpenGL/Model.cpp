#include "Model.h"
#include <iostream>

Model::Model(const std::vector<float>& vertex, const std::vector<float>& uvs, const std::vector<float>& normals)
{
	// Calculem la quantitat de vertex que tindré
	this->numVertex = vertex.size() / 3;

	// Generem el VAO i VBO
	glGenVertexArrays(1, &this->VAO);
	glGenBuffers(1, &this->VBO);

	// Definim el VAO com a actiu
	glBindVertexArray(this->VAO);

	// Definim el VBO de les posicions com acitu i passem les dades
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, vertex.size() * sizeof(float), vertex.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	// Activem l'atribut 0
	glEnableVertexAttribArray(0);

	//Desvinculo els VAO i VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);


}

void Model::Render() const
{
	glBindVertexArray(this->VAO);
	glDrawArrays(GL_TRIANGLES, 0, numVertex / 3);
	glBindVertexArray(0);
}
