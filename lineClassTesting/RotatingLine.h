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
		void initRotCenShape();
		// rotatingCenter+++++++++++++++++++
		
		// polar+++++++++++++++++++++++++++
		float 				engle1 = 0 , engle2 = 0;
		float 				ro1 , ro2;
		// polar+++++++++++++++++++++++++++

		Vector2f 			spesCoords[2];// coords where rotCenter is (0;0)

		void calculateEngles(); // calculate engles by rotCenter and positions
		void calculateRo();
		void calPosToCenterer();	//calculate spesCoords	

    public:
        RotatingLine(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f rotCenter);
        void drawLine();
		void setRenderWindow(sf::RenderWindow * rWindow);
		void addEngle(double radians);

		void add1PointX(float val);
		void add1PointY(float val);
		void add2PointX(float val);
		void add2PointY(float val);

        void coutData();
	   	//rotatingCenter+++++++++++++++++++	
		void drawRotCenter();
		void coutRotCenData();
		//rotatingCente++++++++++++++++++++
  
};
