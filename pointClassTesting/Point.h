#ifndef POINTS_H
#define POINTS_H

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Point{

	private:
		sf::Vector2f 	position;
		float 			radius;
		sf::Color		color;

	public: 
		
		Point(sf::Vector2f position, float radius);
		void coutData();
};

#endif
