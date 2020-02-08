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
	
	p2 = calcPoint2Position(initData);	

	line = new RotatingLine(p1, p2, initData->startPointPosition);
	line->setRenderWindow(rWindow);
}

sf::Vector2f  RotLineController::calcPoint2Position(RLC_initData * initData){

	sf::Vector2f result;
	
	if(initData->p2Length == 0)
		result = (initData->startPointPosition -  initData->point1StartPos);
	else
	{
		
		float p1Engle = calculateEngle(initData->point1StartPos);
		float resultEngle = p1Engle > 0 ? p1Engle - 3.14 : p1Engle + 3.14;
		sf::Vector2f tempPos = calculatePosition(resultEngle, initData->p2Length);
		result.x = initData->startPointPosition.x + tempPos.x; result.y = initData->startPointPosition.y - tempPos.y;

	}

	return result;
}
