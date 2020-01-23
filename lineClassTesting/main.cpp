#include "iostream"
#include <SFML/Graphics.hpp>
#include "RotatingLine.h"

using namespace std;

const int windWidth = 700 , windHeigth = 300;

sf::Clock mClock;

const float rotationSpeed = 0.5;

int main(){


	sf::RenderWindow window(sf::VideoMode(windWidth, windHeigth), "hello line");
	RotatingLine rotLine(sf::Vector2f(20.f, 20.f), sf::Vector2f(70.f, 70.f), sf::Vector2f(30.f, 30.f));
	
	rotLine.setRenderWindow(&window);
	
	rotLine.coutData();

	bool Qc = false, Ec = false;
	sf::Time tempTime;

	while(window.isOpen()){

		sf::Event event;
		while(window.pollEvent(event)){
				if(event.type == sf::Event::Closed){
					window.close();
				}

				if (event.type == sf::Event::KeyReleased){
					if (event.key.code == sf::Keyboard::Q) Qc = false;
					if (event.key.code == sf::Keyboard::E) Ec = false;

	           }

				if (event.type == sf::Event::KeyPressed){

					if (event.key.code == sf::Keyboard::Q){
						if(Qc == false ){mClock.restart(); Qc = true;}
						tempTime = mClock.getElapsedTime();
						rotLine.addEngle1(tempTime.asSeconds() * rotationSpeed);
						rotLine.addEngle2(tempTime.asSeconds() * rotationSpeed);
						mClock.restart();
					}
					if (event.key.code == sf::Keyboard::E){
						if(Ec == false ){mClock.restart(); Ec = true;}
						tempTime = mClock.getElapsedTime();
						rotLine.addEngle1(-tempTime.asSeconds() * rotationSpeed);
						rotLine.addEngle2(-tempTime.asSeconds() * rotationSpeed);
						mClock.restart();
					}

					rotLine.coutData();


				}

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
					rotLine.setRotCenPos((sf::Vector2f)sf::Mouse::getPosition(window));					
				}

		
		}
		window.clear(sf::Color::White);
		rotLine.drawLine();
		rotLine.drawRotCenter();
		window.display();
	}
}
