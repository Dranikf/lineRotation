#include "iostream"
#include <SFML/Graphics.hpp>
#include "RotLineController.h"

using namespace std;

const int windWidth = 700 , windHeigth = 300;

int main(){

	sf::RenderWindow window(sf::VideoMode(windWidth, windHeigth), "hello line");

	RotLineController rlController(sf::Vector2f(20, 20));	

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
		cout<< "hello 1" << endl;
		rlController.draw();	
		cout << "hello 2" << endl;
		window.display();
	}
}
