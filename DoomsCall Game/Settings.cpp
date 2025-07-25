#include "Settings.h"

int Settings::length = 800;
int Settings::height = 600;
std::vector<sf::Texture> Settings::textures;

Settings::Settings() {
	sf::Texture texture;
	if (!texture.loadFromFile("assets/player.png")) {
		return;
	}
	textures.push_back(texture);
	
}
int Settings::getLength() {
	return length;
}
int Settings::getHeight() {
	return height;
}
sf::Texture& Settings::getTexture(TextureType type) {
	return textures[type];
}