#pragma once

#include "GameStuff.h"

class Renderer {
	static sf::Sprite player;
public:
	Renderer();
	static void RenderPlayer(sf::RenderWindow& window, Player& play);
};

class Game {
	Settings settings;
	Renderer renderer;
public:
	Game();
	void run();
};
