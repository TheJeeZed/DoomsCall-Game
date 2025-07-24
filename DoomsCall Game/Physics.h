#pragma once

#include <SFML/Graphics.hpp>

class Vector {
	sf::Vector2f value;
public:
	Vector(float x, float y);
	void setValue(sf::Vector2f value);
	void addAVector(sf::Vector2f other);
	sf::Vector2f getValue();
};

class OBJ {
	sf::FloatRect box;
public:
	OBJ(float x, float y, float w, float h);
	void setPosition(float x,float y);
	void setSize(float x,float y);
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
};

class DynamicOBJ:public OBJ {
	bool hitceiling;
	bool isgrounded;
	Vector velocity;
	Vector acceleration;
public:
	DynamicOBJ(float x, float y, float w, float h);
	void simulatePhysics();
};
