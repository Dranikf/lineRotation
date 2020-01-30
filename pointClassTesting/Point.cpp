#include "Point.h"

sf::Color DefaultPointsColor = sf::Color::Blue;

Point::Point(sf::Vector2f position, float radius){

	this->position = position;
	this->radius = radius;
	this->color = DefaultPointsColor;

	initShape();
}

void Point::coutData(){

	cout << "+++++++++++++++++++++++++++++" << endl;
	cout << "position : x = " << position.x << " y = " << position.y << endl;
	cout << "radius: " << radius << endl;
	cout << "color: r = " << (int)color.r << " g = "  << (int)color.g << " b = " << (int)color.b << " a = " << (int)color.a  << endl;
	cout << "+++++++++++++++++++++++++++++" << endl;

}

void Point::initShape(){

	shape.setRadius(radius);
	shape.setFillColor(color);
	shape.setPosition(position);

}

void Point::setRenderWindow(sf::RenderWindow * rWindow){

	this->rWindow = rWindow;

}

void Point::draw(){

	rWindow->draw(shape);

}

sf::Vector2f Point::getPosition(){ return position;}
