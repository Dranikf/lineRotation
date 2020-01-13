#include "RotatingLine.h"

using namespace std;

RotatingLine::RotatingLine(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f rotCenter){
  
    this->rotatingCenter = rotCenter;
  
    lineCol = sf::Color::Black;
	
	lineVert[0] = sf::Vertex(point1, lineCol);
	lineVert[1] = sf::Vertex(point2, lineCol);

	initRotCenShape();
	calculateEngles();
}
  
void RotatingLine::coutData(){
  
    cout << "point1 position: x = " << lineVert[0].position.x << " y = " << lineVert[0].position.y << endl;
    cout << "point2 position: x = " << lineVert[1].position.x << " y = " << lineVert[1].position.y << endl;
	cout << "color : r = " << (int)lineCol.r << " g = " << (int)lineCol.g << " b = " << (int)lineCol.b 
		  << " a = " << (int)lineCol.a	<<endl;
	coutRotCenData();
}

void RotatingLine::setRenderWindow(sf::RenderWindow * rWindow){

	this->rWindow = rWindow;

}

void RotatingLine::drawLine(){

	rWindow->draw(lineVert, 2 , sf::Lines);	

}

void RotatingLine::initRotCenShape(){

	rotCenterShape.setRadius(rotCenterRadius);
	rotCenterShape.setFillColor(rotCenterColor);
	rotCenterShape.setPosition(rotatingCenter.x - rotCenterRadius, rotatingCenter.y - rotCenterRadius);	

}

void RotatingLine::drawRotCenter(){
	
	
	rWindow->draw(rotCenterShape);	
	
}

void RotatingLine::coutRotCenData(){

	cout << "++++++++++++++rotation center data+++++++++++++++++++++" << endl;
    cout<< "rotation center: x = " << rotatingCenter.x<< " y = " << rotatingCenter.y  << endl;
	cout << "rotation center color: r = " << (int)rotCenterColor.r << " g = " << (int)rotCenterColor.g
		  << " b = " << (int)rotCenterColor.b<< " a = " << (int)rotCenterColor.a << endl;
	cout << "rotation center visualisation radius: " <<  rotCenterRadius  << endl;
	cout << "++++++++++++++rotation center data+++++++++++++++++++++" << endl;
}

void RotatingLine::calculateEngles(){

	sf::Vertex * spesCoords  = getPosToCenter();
//	engle1 = 
	
}

sf::Vertex * RotatingLine::getPosToCenter(){

	sf::Vertex result[2];
	return &result[0];		

}

void RotatingLine::addEngle(double radians){

	lineVert[0].position.x += cos(radians);
	lineVert[0].position.y += sin(radians);
	lineVert[1].position.x -= cos(radians);
	lineVert[1].position.y -= sin(radians);
}
