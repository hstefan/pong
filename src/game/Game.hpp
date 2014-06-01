#pragma once

#include "core/Window.hpp"

struct SDL_Renderer;

namespace hst {
namespace game {

struct Game {
	static const int FPS = 60;
	static const int WIDTH = 640;
	static const int HEIGHT = 480;
	Game();
	void update();
	void render();
	void preRender();
	void run();
private:
	core::Window _win;
	SDL_Renderer* _ren;
};

} //namespace game
} //namespace hst
