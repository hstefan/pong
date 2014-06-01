#include "Window.hpp"

namespace hst {
namespace core {

Window::Window(const std::string& title, int w, int h, Uint32 flags) 
	: Window(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, flags) {
}

Window::Window(const std::string& title, int x, int y, int w, int h, Uint32 flags) 
	: width(w), height(h), _win(nullptr) {
	_win = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);
}

Window::~Window() {
	SDL_DestroyWindow(_win);
}

SDL_Window* Window::raw() {
	return _win;
}

} //namespace core
} //namespace core
