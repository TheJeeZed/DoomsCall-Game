#include "Game.h"

sf::Sprite Renderer::player;

Renderer::Renderer() {
	player.setTexture(Settings::getTexture(PLAYER));
}
void Renderer::RenderPlayer(sf::RenderWindow& window, Player& play) {
	player.setPosition(play.getPosition());
	window.draw(player);
}

Game::Game() {
	
}
void Game::run() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "DOOMSCALL GAME");
	sf::Event e;
	sf::RectangleShape shape;
	
	shape.setPosition(100, 100);
	shape.setSize(sf::Vector2f(1000,1000));
	shape.setFillColor(sf::Color(sf::Color::Red));
	Player player(150, -150);
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
		player.simulatePhysics(shape, delta);
		player.adjustCamera();
		player.focusCamera(window);
		window.draw(shape);
		Renderer::RenderPlayer(window, player);
		window.display();
	}
}