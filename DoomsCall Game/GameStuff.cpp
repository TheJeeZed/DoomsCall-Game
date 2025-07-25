#include "GameStuff.h"

Player::Player(float x = 0, float y = 0) :DynamicOBJ(x, y, 32, 64) {
	camera = sf::View(sf::View(sf::FloatRect(0.f, 0.f, 800.f, 600.f)));
	HP = 100;
	maxHP = 100;
	speed = 200;
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
void Player::handleInput(sf::Event& event) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		velocity.value.x = -speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		velocity.value.x = speed;
	}
	else {
		velocity.value.x = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isgrounded && !hitceiling) {
		velocity.value.y = -speed * 2;
		isgrounded = false;
	}
}
void Player::adjustCamera() {
	camera.setCenter(getPosition());
}
void Player::focusCamera(sf::RenderWindow& window) {
	window.setView(camera);
}