#include "GameStuff.h"

Vector gravity(0.f, 800.0f);

BlockType Block::getType(){
	return type;
}

Air::Air() {
	type = AIR;
}

Grass::Grass() {
	type = GRASS;
}

World::World() {
	row = 100;
	col = 100;
	map.resize(row);
	for (int i = 0; i < row; i++) {
		map[i].resize(col);
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (i + j > row) {
				map[i][j] = new Grass;
			}
			else {
				map[i][j] = new Air;
			}
		}
	}
}
int World::getRow() {
	return row;
}
int World::getCol() {
	return col;
}

void DynamicOBJ::simulatePhysics(World& world, float deltatime) {
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
		for (int i = 0; i < world.getRow(); i++) {
			for (int j = 0; j < world.getCol(); j++) {
				if (futurebounds.intersects(sf::FloatRect(TILE_SIZE * j, TILE_SIZE * i, TILE_SIZE, TILE_SIZE)) && world.map[i][j]->getType()) {
					movement.x = 0;
				}
			}
		}
	}
	if (movement.y != 0.f) {
		sf::FloatRect futurebounds = getBounds();
		futurebounds.top += movement.y;
		for (int i = 0; i < world.getRow(); i++) {
			for (int j = 0; j < world.getCol(); j++) {
				if (futurebounds.intersects(sf::FloatRect(TILE_SIZE * j, TILE_SIZE * i, TILE_SIZE, TILE_SIZE)) && world.map[i][j]->getType()) {
					if (movement.y > 0) {
						isgrounded = true;
					}
					else {
						hitceiling = true;
					}
					movement.y = 0;
				}
			}
		}
	}
	setPosition(getPosition().x + movement.x, getPosition().y + movement.y);
}
		
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