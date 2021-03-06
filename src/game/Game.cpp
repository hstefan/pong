#include "Game.hpp"
#include "util/util.hpp"
#include "gl_core_3_3.hpp"
#include <SDL2/SDL.h>

namespace hst {
namespace game {

Game::Game() 
	: _win("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL), _ren(nullptr) {
	_ren = SDL_CreateRenderer(_win.raw(), 0, 0);
}

void Game::run() {
	bool running = true;
	const int fps = 60;
	SDL_Event evt;
	while (running) {
		auto starting_time = SDL_GetTicks();
		while (SDL_PollEvent(&evt)) {
			if (evt.type == SDL_KEYDOWN) {
				running = evt.key.keysym.sym != SDLK_ESCAPE;
			}
			if (evt.type == SDL_QUIT) {
				running = false;
			}
		}
		update();
		preRender();
		render();
		_win.swapBuffers();
		SDL_RenderPresent(_ren);
		auto elapsed_time = SDL_GetTicks() - starting_time;
		SDL_Delay(hst::util::clamp(1000U / fps - elapsed_time, 0U, 1000U / fps));
	}
}

void Game::update() {
}

void Game::render() {
	gl::ClearColor(0.f, 0.f, 0.f, 1.f);
	gl::Clear(gl::COLOR_BUFFER_BIT);
}

void Game::preRender() {
}

} //namespace game
} //namespace hst
