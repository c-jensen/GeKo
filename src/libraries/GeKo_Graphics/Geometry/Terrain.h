#pragma once

#include <GeKo_Graphics/Geometry/Geometry.h>
#include <time.h>
#include <iostream>

/**The terrain class will provide a terrain, which will be generated with a hight map. Just juse the 
constructor and give it the height map.*/
class Terrain : public Geometry {


public:

	Terrain(std::string filename, float resolution, float interval);

	~Terrain();

	void loadHeightmap(std::string filename);

	glm::vec3 calculateNormal(int x, int z);

	float getHeight(glm::vec2 position);

	float getResolutionX();
	float getResolutionY();

protected:
	std::vector<float> m_height;
	int m_resolutionX, m_resolutionY;

	float **m_heightMap;

	float m_interval, m_resolution;
};