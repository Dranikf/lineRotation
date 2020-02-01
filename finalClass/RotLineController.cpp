#include "RotLineController.h"

float defaultPointRadius = 5; // радиус точки по умолчанию

RotLineController::RotLineController(RLC_initData * initData){

	init(initData);

}


RotLineController::~RotLineController(){ 
	release();
}

void RotLineController::release(){

	if(activePoint != NULL)	delete activePoint;
	if(line != NULL) delete line;

}

void RotLineController::draw(){

	activePoint->draw();
	line->drawLine();	

}

void RotLineController::init(RLC_initData * initData){

	rWindow = initData->rWindow;

	activePoint = new Point(initData->startPointPosition , defaultPointRadius);
	activePoint->setRenderWindow(rWindow);

	sf::Vector2f p1 = (initData->startPointPosition +  initData->point1StartPos), p2;
	
	if(initData->p2Length == 0)
		p2 = (initData->startPointPosition -  initData->point1StartPos);

	line = new RotatingLine(p1, p2, initData->startPointPosition);
	line->setRenderWindow(rWindow);
}
