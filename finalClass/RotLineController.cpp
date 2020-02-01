#include "RotLineController.h"

float defaultPointRadius = 5; // радиус точки по умолчанию

RotLineController::RotLineController(sf::Vector2f startPointPosition){

	
	activePoint = new Point(startPointPosition , defaultPointRadius);

}


RotLineController::~RotLineController(){ 
		delete activePoint;
}

void RotLineController::draw(){

	activePoint->draw();

}
