#include "iostream"
#include <SFML/Graphics.hpp>

using namespace std;

const int windWidth = 700 , windHeigth = 300;


int main(){


	sf::RenderWindow window(sf::VideoMode(windWidth, windHeigth), "hello line");
	



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
