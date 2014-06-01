#pragma once

#include <string>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_events.h>

namespace hst {
namespace core {

struct Window {
	Window(const std::string& title, int width, int height, Uint32 flags);
	Window(const std::string& title, int x, int y, int w, int h, Uint32 flags);
	~Window();

	const int width;
	const int height;
	SDL_Window* raw();
	bool poolEvent(SDL_Event& evt);
private:
	SDL_Window* _win;
};

} //namespace core 
} //namespace hst
