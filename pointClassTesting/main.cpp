#include <iostream>
#include <SFML/Graphics.hpp>
#include "Point.h"

using namespace std;

const int windWidth = 700 , windHeigth = 300;

extern sf::Color DefaultPointsColor;

int main(){


	sf::RenderWindow window(sf::VideoMode(windWidth, windHeigth), "hello line");
	
	//DefaultPointsColor = sf::Color::Blue;
	Point p1(sf::Vector2f(20.f , 20.f), 10);
	p1.coutData();

	while(window.isOpen()){

		sf::Event event;
		while(window.pollEvent(event)){
				if(event.type == sf::Event::Closed){
					window.close();
				}

		
		}


		window.clear(sf::Color::White);
		window.display();
	}
}
