#include "iostream"
#include <SFML/Graphics.hpp>


class RotatingLine{
    private:
		sf::Vertex			lineVert[2];
        sf::Vector2f    	rotatingCenter;
        sf::Color      		lineCol;
		sf::RenderWindow*	rWindow = NULL;
  
    public:
        RotatingLine(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f rotCenter);
        void drawLine();
		void setRenderWindow(sf::RenderWindow * rWindow);
  
        void coutData();
  
};
