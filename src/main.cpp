#include <SDL2/SDL.h>
#include "game/Game.hpp"

int main(int, char**) {
	SDL_Init(SDL_INIT_EVERYTHING);
	hst::game::Game g;
	g.run();
	SDL_Quit();
	return 0;
}
