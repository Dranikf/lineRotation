#include "RotatingLine.h"
#include <math.h>

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
	cout << "engle1 = " <<engle1 << " " << "engle2 = " << engle2 << endl;
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

	sf::Vector2f * spesCoords = new sf::Vector2f[2];
   	calPosToCenterer();

	cout << spesCoords[0].x << " " << spesCoords[0].y  << endl;
	cout << spesCoords[1].x << " " << spesCoords[1].y  << endl;

	engle1 = acos(spesCoords[0].x /(sqrt(pow(spesCoords[0].x, 2) + pow(spesCoords[0].y , 2))));		
	engle1 *= (spesCoords[0].y > 0) ? -1:1;// в случае, если Y положительный, надо домножить на -1 

	engle2 = acos(spesCoords[1].x /(sqrt(pow(spesCoords[1].x, 2) + pow(spesCoords[1].y , 2))));
	engle2 *= (spesCoords[1].y > 0) ? -1:1;// аналогично первой точке

	cout << engle1 << endl;
	cout << engle2 << endl;

	delete [] spesCoords;
}

void  RotatingLine::calPosToCenterer(sf::Vector2f * position){

	spesCoords[0] = lineVert[0].position - rotatingCenter;
	spesCoords[1] = lineVert[1].position - rotatingCenter;

}

void RotatingLine::addEngle(double radians){

	lineVert[0].position.x += cos(radians);
	lineVert[0].position.y += sin(radians);
	lineVert[1].position.x -= cos(radians);
	lineVert[1].position.y -= sin(radians);
}
	
void RotatingLine::add1PointX(float val){lineVert[0].position.x += val;calculateEngles();}
void RotatingLine::add1PointY(float val){lineVert[0].position.y += val;calculateEngles();}

void RotatingLine::add2PointX(float val){lineVert[1].position.x += val;calculateEngles();}
void RotatingLine::add2PointY(float val){lineVert[1].position.y += val;calculateEngles();}

void RotatingLine::calculateRo(){
	ro1 = 

}
