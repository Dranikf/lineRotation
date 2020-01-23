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
		float 				engle[2];
		float 				ro[2];	
		// polar+++++++++++++++++++++++++++

		sf::Vector2f 			spesCoords[2];// coords where rotCenter is (0;0)

		void calculateEngles(); // calculate engles by rotCenter and positions
		void calculateRo();
		void calPosToCenterer();	//calculate spesCoords	
		void calculatePositions();
		
		void calPosByEngRo(int index); // calculate points positions by engle (index of calculating point)

    public:
        RotatingLine(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f rotCenter);
        void drawLine();
		void setRenderWindow(sf::RenderWindow * rWindow);

		// доворот углов********************
		void addEngle1(double radians);
		void addEngle2(double radians);
		// доворот углов********************

		void add1PointX(float val);
		void add1PointY(float val);
		void add2PointX(float val);
		void add2PointY(float val);

        void coutData();
	   	//rotatingCenter+++++++++++++++++++	
		void drawRotCenter();
		void coutRotCenData();
		void setRotCenPos(sf::Vector2f rotCen);
		//rotatingCente++++++++++++++++++++
  
};
