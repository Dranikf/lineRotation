#include <iostream>
#include <SFML/Graphics.hpp>
#include "Point.h"

using namespace std;

const int windWidth = 700 , windHeigth = 300;

extern sf::Color DefaultPointsColor;

int main(){


	sf::RenderWindow window(sf::VideoMode(windWidth, windHeigth), "hello point");
	
	//DefaultPointsColor = sf::Color::Red;
	Point p1(sf::Vector2f(20.f , 30.f), 10);
	p1.coutData();
	p1.setRenderWindow(&window);

	cout << p1.getPosition().x << "" << p1.getPosition().y << endl;

	while(window.isOpen()){

		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                p1.setPosition((sf::Vector2f)sf::Mouse::getPosition(window));    
            }

				
		}


		window.clear(sf::Color::White);
		
		p1.draw(&window);

		window.display();
	}
}
