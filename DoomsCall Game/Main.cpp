#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
	RenderWindow main(VideoMode(800, 600), "DOOMSCALL GAME");
	Event e;
	while (main.isOpen()) {
		while (main.pollEvent(e)) {

		}
	}
	return 0;
}
// eating break