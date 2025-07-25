#pragma once

#include "Settings.h";

class Vector {
public:
	sf::Vector2f value;
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
	sf::FloatRect getBounds();
};

class DynamicOBJ:public OBJ {
protected:
	bool hitceiling;
	bool isgrounded;
	Vector velocity;
	Vector acceleration;
public:
	DynamicOBJ(float x, float y, float w, float h);
	void simulatePhysics(sf::RectangleShape& shape,float deltatime);
};
