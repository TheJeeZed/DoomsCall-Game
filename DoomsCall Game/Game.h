#pragma once

#include "GameStuff.h"

class Renderer {
	static sf::Sprite player;
	static std::vector<sf::IntRect> blockrect;
	static sf::Sprite block;
public:
	Renderer();
	static void RenderPlayer(sf::RenderWindow& window, Player& play);
	static void RenderWorld(sf::RenderWindow& window, World& world);
};

class Game {
	Settings settings;
	Renderer renderer;
public:
	Game();
	void run();
};
