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
	cout << "engle[0] = " <<engle[0] << " " << "engle[1] = " << engle[1] << endl;
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

	calculateRo();


	engle[0] = acos(spesCoords[0].x /ro[0]);		
	engle[0] *= (spesCoords[0].y > 0) ? -1:1;// в случае, если Y положительный, надо домножить на -1 

	engle[1] = acos(spesCoords[1].x /ro[1]);
	engle[1] *= (spesCoords[1].y > 0) ? -1:1;// аналогично первой точке

}

void  RotatingLine::calPosToCenterer(){

	spesCoords[0] = lineVert[0].position - rotatingCenter;
	spesCoords[1] = lineVert[1].position - rotatingCenter;

}

void RotatingLine::addEngle1(double radians){
	
	engle[0] += radians;
	if (engle[0] > 3.14) engle[0] =  (-6.28) + engle[0]; 
	if (engle[0] < -3.14) engle[0] = 6.28 + engle[0];
	calPosByEngRo(0);	

}

void RotatingLine::addEngle2(double radians){

	engle[1] += radians;
	if (engle[1] > 3.14) engle[0] =  (-6.28) + engle[0];         
    if (engle[1] < -3.14) engle[0] = 6.28 + engle[0];
	calPosByEngRo(1);

}
	
void RotatingLine::add1PointX(float val){lineVert[0].position.x += val;calculateEngles();}
void RotatingLine::add1PointY(float val){lineVert[0].position.y += val;calculateEngles();}

void RotatingLine::add2PointX(float val){lineVert[1].position.x += val;calculateEngles();}
void RotatingLine::add2PointY(float val){lineVert[1].position.y += val;calculateEngles();}

void RotatingLine::calculateRo(){

	calPosToCenterer();

	ro[0] = sqrt(pow(spesCoords[0].x, 2) + pow(spesCoords[0].y ,2));
	ro[1] = sqrt(pow(spesCoords[1].x, 2) + pow(spesCoords[1].y ,2));

}

void RotatingLine::calPosByEngRo(int index){

	calculateRo();

	lineVert[index].position.y = rotatingCenter.y - (sin(engle[index]) * ro[index]);
	lineVert[index].position.x = rotatingCenter.x + (cos(engle[index]) * ro[index]);
	cout << lineVert[index].position.x << endl;

}


void RotatingLine::setRotCenPos(sf::Vector2f rotCen){
	rotatingCenter = rotCen;
	initRotCenShape();
	calculateEngles();
}

