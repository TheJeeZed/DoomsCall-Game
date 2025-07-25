#include "Physics.h"

Vector gravity(0.f, 800.0f);

Vector::Vector(float x = 0,float y = 0) {
	value.x = x;
	value.y = y;
}
void Vector::setValue(sf::Vector2f value) {
	this->value = value;
}
void Vector::addAVector(sf::Vector2f other) {
	value += other;
}
sf::Vector2f Vector::getValue() {
	return value;
}

OBJ::OBJ(float x, float y, float w, float h) {
	box.left = x;
	box.top = y;
	box.width = w;
	box.height = h;
}
void OBJ::setPosition(float x, float y) {
	box.left = x;
	box.top = y;
}
void OBJ::setSize(float x, float y) {
	box.width = x;
	box.height = y;
}
sf::Vector2f OBJ::getPosition() {
	return box.getPosition();
}
sf::Vector2f OBJ::getSize() {
	return box.getSize();
}
sf::FloatRect OBJ::getBounds() {
	return box;
}

DynamicOBJ::DynamicOBJ(float x = 0, float y = 0, float w = 0, float h = 0):OBJ(x,y,w,h){
	isgrounded = false;
	hitceiling = false;
}
void DynamicOBJ::simulatePhysics(sf::RectangleShape& shape, float deltatime) {
	if (isgrounded || hitceiling) {
		velocity = Vector(velocity.value.x, 0);
	}
	else {
		velocity.addAVector(gravity.value * deltatime);
	}
	isgrounded = false;
	hitceiling = false;

	sf::Vector2f movement = velocity.value * deltatime;
	if (movement.x != 0.f) {
		sf::FloatRect futurebounds = getBounds();
		futurebounds.left += movement.x;
		if (futurebounds.intersects(shape.getGlobalBounds())) {
			movement.x = 0;
		}
	}
	if (movement.y != 0.f) {
		sf::FloatRect futurebounds = getBounds();
		futurebounds.top += movement.y;
		if (futurebounds.intersects(shape.getGlobalBounds())) {
			if (movement.y > 0) {
				isgrounded = true;
			}
			else {
				hitceiling = true;
			}
			movement.y = 0;
		}
	}
	setPosition(getPosition().x + movement.x, getPosition().y + movement.y);
}

