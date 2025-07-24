#include "GameStuff.h"

Player::Player(float x = 0, float y = 0):DynamicOBJ(x,y,32,64) {
	camera.setViewport(sf::FloatRect(0.f,0.f,800.f,600.f));
	HP = 100;
	maxHP = 100;
}
int Player::getHP() {
	return HP;
}
int Player::getMaxHP() {
	return maxHP;
}
sf::View& Player::getCamera() {
	return camera;
}
void Player::adjustCamera() {
	camera.setCenter(getPosition());
}
void Player::focusCamera(sf::RenderWindow& window) {
	window.setView(camera);
}