#include "Game.h"

sf::Sprite Renderer::player;
std::vector<sf::IntRect> Renderer::blockrect;
sf::Sprite Renderer::block;

Renderer::Renderer() {
	player.setTexture(Settings::getTexture(PLAYER));
	blockrect.push_back(sf::IntRect(0, 0, 0, 0));
	for (int i = 0; i < 1; i++) {
		blockrect.push_back(sf::IntRect(TILE_SIZE * i, TILE_SIZE, TILE_SIZE, TILE_SIZE));
	}
	block.setTexture(Settings::getTexture(BLOCK));
}
void Renderer::RenderPlayer(sf::RenderWindow& window, Player& play) {
	player.setPosition(play.getPosition());
	window.draw(player);
}
void Renderer::RenderWorld(sf::RenderWindow& window, World& world) {
	for (int i = 0; i < world.getRow(); i++) {
		for (int j = 0; j < world.getCol(); j++) {
			BlockType t = world.map[i][j]->getType();
			if (t) {
				block.setTextureRect(blockrect[t]);
				block.setPosition(TILE_SIZE * j, TILE_SIZE * i);
				window.draw(block);
			}
		}
	}
}

Game::Game() {
	
}
void Game::run() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "DOOMSCALL GAME");
	sf::Event e;
	Player player(150, -150);
	World world;
	std::cout << "A";
	sf::Clock clock;
	while (window.isOpen()) {
		float delta = clock.restart().asSeconds();
		while (window.pollEvent(e)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.close();
			}
		}
		window.clear();
		player.handleInput(e);
		player.simulatePhysics(world, delta);
		player.adjustCamera();
		player.focusCamera(window);
		Renderer::RenderWorld(window, world);
		Renderer::RenderPlayer(window, player);
		window.display();
	}
}