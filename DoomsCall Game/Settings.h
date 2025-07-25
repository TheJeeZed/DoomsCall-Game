#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

enum TextureType {PLAYER};

class Settings{
	static int length;
	static int height;
	static std::vector<sf::Texture> textures;
public:
	Settings();
	static int getLength();
	static int getHeight();
	static sf::Texture& getTexture(TextureType type);
};