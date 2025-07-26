#pragma once

#include "Physics.h"

class Block {
protected:
	BlockType type;
public:
	BlockType getType();
};
class Air :public Block {
public:
	Air();
};
class Grass :public Block {
public:
	Grass();
};
class World {
	int row;
	int col;
public:
	std::vector<std::vector<Block*>> map;
	World();
	int getRow();
	int getCol();
};

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