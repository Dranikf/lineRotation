#ifndef ROTLINECONTROLLER_H_
#define ROTLINECONTROLLER_H_ 

#include "Point.h"
#include "RotatingLine.h"
#include <forward_list>

struct RLC_initData{

	sf::Vector2f 		startPointPosition = sf::Vector2f(0 , 0); // координаты первого центра вращения
	sf::RenderWindow*	rWindow;
   	sf::Vector2f		point1StartPos= sf::Vector2f(-10.f, 0); // координаты первой из точек соответсвующих концам вращающейся линии
	float				p2Length = 0; // длинна от центра вращения до второй точки строящей вращ. линию
	float 				pointRadius = 4;
};

class RotLineController{

	private:
		RotatingLine* 			line = NULL;
		forward_list<Point *> 	points; // точки которые зарегистированы на карте (все кроме активной)
		Point * 				activePoint = NULL; // точка которая на данный момент является центром вращения для линнии
		sf::RenderWindow* rWindow;
	
	public:
		RotLineController(RLC_initData * initData);
		~RotLineController();

		void draw();
		void init(RLC_initData * initData);
		void release();

};

#endif
