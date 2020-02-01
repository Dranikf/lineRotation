#ifndef POINTS_H
#define POINTS_H

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Point{

	private:
		sf::Vector2f 		position;
		float 				radius;
		sf::Color			color;

		sf::CircleShape 	shape;
		sf::RenderWindow*	rWindow;

		void 				initShape();

	public: 
		
		Point(sf::Vector2f position, float radius);
		void coutData();
		void setRenderWindow(sf::RenderWindow * rWindow);
		void draw();
		void draw(sf::RenderWindow * rWindow);

		sf::Vector2f getPosition();
};

#endif
