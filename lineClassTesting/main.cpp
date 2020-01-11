#include "iostream"
#include <SFML/Graphics.hpp>

using namespace std;

const int windWidth = 700 , windHeigth = 300;

class rotatingLine{
	private:
		sf::Vector2f 	point1, point2;
		sf::Vector2f 	rotatingCenter;
		sf::Color 		lineCol;

	public:
		rotatingLine(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f rotCenter);
		void drawLine();

		void coutData();

};


rotatingLine::rotatingLine(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f rotCenter){

	this->point1 = point1;
	this->point2 = point2;
	this->rotatingCenter = rotCenter;

	this->lineCol = sf::Color::Black;
}

void rotatingLine::coutData(){

	cout << "point1 position: x = " << point1.x << " y = " << point1.y << endl;
	cout << "point2 position: x = " << point2.x << " y = " << point2.y << endl;
	cout<< "rotation center: x = " << rotatingCenter.x<< " y = " << rotatingCenter.y  << endl;
	cout << "color: r = " << lineCol.Red << " g = " << lineCol.g << " b = " << lineCol.b << "a = " << lineCol.a  << endl;
}

int main(){


	sf::RenderWindow window(sf::VideoMode(windWidth, windHeigth), "hello line");
	rotatingLine rotLine(sf::Vector2f(20.f, 20.f), sf::Vector2f(40.f, 40.f), sf::Vector2f(30.f, 30.f));

	rotLine.coutData();

	while(window.isOpen()){

		sf::Event event;
		while(window.pollEvent(event)){
				if(event.type == sf::Event::Closed){
					window.close();
				}

		
		}
		window.clear(sf::Color::Black);
		window.display();
	}
}
