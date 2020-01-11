#include "RotatingLine.h"

using namespace std;

RotatingLine::RotatingLine(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f rotCenter){
  
    this->point1 = point1;
    this->point2 = point2;
    this->rotatingCenter = rotCenter;
  
    this->lineCol = sf::Color::Black;
}
  
void RotatingLine::coutData(){
  
    cout << "point1 position: x = " << point1.x << " y = " << point1.y << endl;
    cout << "point2 position: x = " << point2.x << " y = " << point2.y << endl;
    cout<< "rotation center: x = " << rotatingCenter.x<< " y = " << rotatingCenter.y  << endl;
	cout << "color : r = " << (int)lineCol.r << " g = " << (int)lineCol.g << " b = " << (int)lineCol.b 
		  << " a = " << (int)lineCol.a	<<endl;
}

void RotatingLine::setRenderWindow(sf::RenderWindow * rWindow){

	his->rWindow = rWindow;

}
