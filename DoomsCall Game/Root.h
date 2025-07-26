#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

const int TILE_SIZE = 8;
const int GLOBAL_SCALE = 1;

class Settings;

class Vector;
class OBJ;
class DynamicOBJ;

class Block;
class Air;
class Grass;
class World;
class Player;

class Renderer;
class Game;

enum TextureType {NO_TEXTURE,PLAYER,BLOCK };
enum BlockType { AIR, GRASS };