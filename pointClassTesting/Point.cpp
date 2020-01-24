#include "Point.h"

Point::Point(sf::Vector2f position, float radius){

	this->position = position;
	this->radius = radius;
	//this->color = DefaultPointsColor;

}

void Point::coutData(){

	cout << "+++++++++++++++++++++++++++++" << endl;
	cout << "position : x = " << position.x << "y = " << position.y << endl;
	cout << "radius: " << radius << endl;
	cout << "color: r = " << (int)color.r << " g = "  << (int)color.g << " b = " << (int)color.b << " a = " << (int)color.a  << endl;
	cout << "+++++++++++++++++++++++++++++" << endl;

}
