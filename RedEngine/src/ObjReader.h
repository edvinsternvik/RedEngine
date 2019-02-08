#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <glm/glm.hpp>
#include "Debug.h"

namespace objReader {

	struct vertex {
		glm::vec3 positions;
		glm::vec3 normals;
		glm::vec2 uvs;

		vertex() {}
		vertex(glm::vec3 pos, glm::vec3 norm, glm::vec2 uv) : positions(pos), normals(norm), uvs(uv) {}
	};

	struct modelData {
		std::vector<vertex> vertexData;
		std::vector<unsigned int> indexData;
	};

	void parseObjFile(std::string filePath, modelData* mData);
}