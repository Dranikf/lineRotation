#include "RotLineController.h"

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

	activePoint = new Point(initData->startPointPosition , initData->pointRadius);
	activePoint->setRenderWindow(rWindow);

	sf::Vector2f p1 = (initData->startPointPosition +  initData->point1StartPos), p2;
	
	if(initData->p2Length == 0)
		p2 = (initData->startPointPosition -  initData->point1StartPos);
	else
	{
		
		float p1Engle = calculateEngle(initData->point1StartPos);
		float p2Engle = p1Engle > 0 ? p1Engle - 3.14 : p1Engle + 3.14;

	} 

	line = new RotatingLine(p1, p2, initData->startPointPosition);
	line->setRenderWindow(rWindow);
}
