#include "iostream"
#include <SFML/Graphics.hpp>
#include "RotatingLine.h"

using namespace std;

const int windWidth = 700 , windHeigth = 300;

int main(){


	sf::RenderWindow window(sf::VideoMode(windWidth, windHeigth), "hello line");
	RotatingLine rotLine(sf::Vector2f(20.f, 20.f), sf::Vector2f(40.f, 40.f), sf::Vector2f(30.f, 30.f));
	
	rotLine.setRenderWindow(&window);
	
	rotLine.coutData();

	while(window.isOpen()){

		sf::Event event;
		while(window.pollEvent(event)){
				if(event.type == sf::Event::Closed){
					window.close();
				}

		
		}
		window.clear(sf::Color::White);
		rotLine.drawLine();
		window.display();
	}
}
