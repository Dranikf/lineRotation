#include "iostream"
#include <SFML/Graphics.hpp>


class RotatingLine{
    private:
		sf::Vertex			lineVert[2];
        sf::Color      		lineCol;
		sf::RenderWindow*	rWindow = NULL;
  
		// rotatingCenter+++++++++++++++++++
        sf::Vector2f    	rotatingCenter;
		sf::CircleShape		rotCenterShape;
		sf::Color			rotCenterColor = sf::Color::Red;
		double 				rotCenterRadius = 4;

		void initRotCenShape();
		// rotatingCenter+++++++++++++++++++
		
    public:
        RotatingLine(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f rotCenter);
        void drawLine();
		void setRenderWindow(sf::RenderWindow * rWindow);

        void coutData();
	   	//rotatingCenter+++++++++++++++++++	
		void drawRotCenter();
		void coutRotCenData();
		//rotatingCente++++++++++++++++++++
  
};
