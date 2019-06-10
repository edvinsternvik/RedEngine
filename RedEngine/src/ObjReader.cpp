#include "ObjReader.h"

namespace objReader {
	void parseObjFile(std::string filePath, modelData* mData) {
		int vertIndex[3] = { 0, 0, 0 }; //0:positions, 1:normals, 2:uvs

		std::vector<vertex> verticies;

		std::ifstream ifs(filePath);
		std::string line;
		if (ifs.is_open()) {
			while (std::getline(ifs, line)) {
				if (line[0] == 'v') {
					int type;
					switch (line[1]) {
						case ' ': type = 0; break;
						case 't': type = 1; break;
						case 'n': type = 2; break;
						default: type = -1;  break;
					}
					if (type != -1) {
						std::stringstream ss(line);
						std::string word;
						std::vector<float> data;

						std::getline(ss, word, ' '); // Get rid of text in begining
						while (std::getline(ss, word, ' ')) {
							data.push_back(std::atof(word.c_str()));
						}

						if (verticies.size() < vertIndex[type] + 1) verticies.resize(vertIndex[type] + 1);

						if (type == 0) verticies[vertIndex[0]].positions = glm::vec3(data[0], data[1], data[2]);
						if (type == 1) verticies[vertIndex[1]].uvs = glm::vec2(data[0], data[1]);
						if (type == 2) verticies[vertIndex[2]].normals = glm::vec3(data[0], data[1], data[2]);
						vertIndex[type]++;
					}
				}
				if (line[0] == 'f' && line[1] == ' ') {
					std::stringstream ss(line);
					std::string word;
					int iteration = 0;
					std::getline(ss, word, ' '); // Get rid of text in begining
					while (std::getline(ss, word, ' ')) {
						std::stringstream ss2(word);
						std::vector<int> data;
						while (std::getline(ss2, word, '/')) {
							data.push_back(std::atoi(word.c_str()));
						}
						//maybe add indexing
						if (mData->indexData.size() == 0) mData->indexData.push_back(0);
						else mData->indexData.push_back(mData->indexData.back() + 1);

						vertex temp(verticies[data[0] - 1].positions, verticies[data[2] - 1].normals, verticies[data[1] - 1].uvs);
						mData->vertexData.push_back(temp);
					}

				}
			}
			ifs.close();
		}
		else {
			gameEngineDebug("COULD NOT OPEN MODEL FILE: " + filePath);
		}
	}
}