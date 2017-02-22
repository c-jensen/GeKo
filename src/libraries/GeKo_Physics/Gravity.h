#pragma once
#include <glm/ext.hpp>
///A class to add gravity to a scene
/** Through gravity things and objects can fall down to the plane. This is made possible through adding a constant vector to the modelmatrix.*/
class Gravity
{
public:
	Gravity();

	~Gravity();

	///Returns a changed modelMatrix
	/**The modelmatrix of an object will be changed so the object seems to fall down by gravitation*/
	glm::mat4 addGravity(glm::mat4 modelMatrix);

	glm::vec3 getGravity();
	void setGravity(glm::vec3 newGravity);


protected:
	glm::vec3 m_gravity;

	
};

