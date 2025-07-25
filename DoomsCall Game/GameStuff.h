#pragma once

#include "Physics.h"

class Player :public DynamicOBJ {
	int HP;
	int maxHP;
	sf::View camera;
	float speed;
public:
	Player(float x, float y);
	int getHP();
	int getMaxHP();
	void handleInput(sf::Event& event);
	sf::View& getCamera();
	void adjustCamera();
	void focusCamera(sf::RenderWindow& window);
};