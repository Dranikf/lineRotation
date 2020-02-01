#include "Tools.h"

float calculateEngle(sf::Vector2f vecDirection, float length){

	float result = acos(vecDirection.x /length);
	result *= (vecDirection.y > 0) ? -1:1;	

	return result;

}
