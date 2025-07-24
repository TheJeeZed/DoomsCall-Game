#pragma once

#include "Physics.h"

class Player :public DynamicOBJ {
	int HP;
	int maxHP;
	sf::View camera;
public:
	Player(float x, float y);
	int getHP();
	int getMaxHP();
	sf::View& getCamera();
	void adjustCamera();
	void focusCamera(sf::RenderWindow& window);
};