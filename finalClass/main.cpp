#include "iostream"
#include <SFML/Graphics.hpp>
#include "RotLineController.h"

using namespace std;

const int windWidth = 700 , windHeigth = 300;

int main(){

	sf::RenderWindow window(sf::VideoMode(windWidth, windHeigth), "final comlition");
	
	RLC_initData initer;
	initer.startPointPosition = sf::Vector2f(50.f, 50.f);
	initer.rWindow = &window;
	initer.point1StartPos = sf::Vector2f(-10.f , 0.f);
	initer.p2Length = 100;

	RotLineController rlController(&initer);	

	while(window.isOpen()){

		sf::Event event;
		while(window.pollEvent(event)){
				if(event.type == sf::Event::Closed){
					window.close();
				}

				if (event.type == sf::Event::KeyReleased){

			        }

				if (event.type == sf::Event::KeyPressed){

					if (event.key.code == sf::Keyboard::Q){
					}
					if (event.key.code == sf::Keyboard::E){
					}


				}

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				}

		
		}



		window.clear(sf::Color::White);
		rlController.draw();	
		window.display();
	}
}
