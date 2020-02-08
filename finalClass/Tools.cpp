#include "Tools.h"

float calculateEngle(sf::Vector2f vecDirection, float length){

	float result = acos(vecDirection.x /length);
	result *= (vecDirection.y > 0) ? -1:1;	

	return result;

}

float calculateLength(sf::Vector2f vector){
	
	return sqrt(pow(vector.x, 2) + pow(vector.y, 2));

}

float calculateEngle(sf::Vector2f vecDirection){
	
	return calculateEngle(vecDirection , calculateLength(vecDirection));

}

sf::Vector2f calculatePosition(float engle, float radius){

	return sf::Vector2f(cos(engle) * radius , sin(engle) * radius);

}
