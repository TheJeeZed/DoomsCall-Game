#include "Physics.h"

Vector gravity(0.f, 8.0f);

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

DynamicOBJ::DynamicOBJ(float x = 0, float y = 0, float w = 0, float h = 0):OBJ(x,y,w,h){
	isgrounded = false;
	hitceiling = false;
}
void DynamicOBJ::simulatePhysics() {

}

