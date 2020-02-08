#ifndef TOOLS_H
#define TOOLS_H

#include <SFML/Graphics.hpp>
#include <math.h>

float calculateEngle(sf::Vector2f, float);
float calculateLength(sf::Vector2f);
float calculateEngle(sf::Vector2f);
sf::Vector2f calculatePosition(float engle, float radius);

#endif
