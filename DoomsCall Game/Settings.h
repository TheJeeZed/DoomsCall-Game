#pragma once

#include "Root.h";



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