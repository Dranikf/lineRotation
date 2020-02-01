#ifndef ROTLINECONTROLLER_H_
#define ROTLINECONTROLLER_H_ 

#include "Point.h"
#include "RotatingLine.h"
#include <forward_list>

class RotLineController{

	private:
		RotatingLine* 			line;
		forward_list<Point *> 	points; // точки которые зарегистированы на карте (все кроме активной)
		Point * 				activePoint; // точка которая на данный момент является центром вращения для линнии

	
	public:
		RotLineController(sf::Vector2f startPointPosition);
		~RotLineController();

		void draw();

};

#endif
