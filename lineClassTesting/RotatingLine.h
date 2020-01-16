#include "iostream"
#include <math.h>
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
		float 				rotCenterRadius = 4;
		float 				engle1 = 0 , engle2 = 0;

		void initRotCenShape();
		// rotatingCenter+++++++++++++++++++
		void calculateEngles(); // calculate engles by rotCenter and positions
		void getPosToCenter(sf::Vector2f * position);	//returns  points in coords where rotCenter is (0;0)	

    public:
        RotatingLine(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f rotCenter);
        void drawLine();
		void setRenderWindow(sf::RenderWindow * rWindow);
		void addEngle(double radians);

        void coutData();
	   	//rotatingCenter+++++++++++++++++++	
		void drawRotCenter();
		void coutRotCenData();
		//rotatingCente++++++++++++++++++++
  
};
