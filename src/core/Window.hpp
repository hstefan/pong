#pragma once

#include <string>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_events.h>

namespace hst {
namespace core {

struct Window {
	Window(const std::string& title, int width, int height, Uint32 flags);
	Window(const std::string& title, int x, int y, int w, int h, Uint32 flags);
	virtual ~Window();

	const int width;
	const int height;
	SDL_Window* raw();
	bool poolEvent(SDL_Event& evt);
	void swapBuffers();
protected:
	SDL_Window* _win;
};

struct GLWindow : public Window {
	GLWindow(const std::string& title, int x, int y, int w, int h, Uint32 flags);
	void swapBuffers();
private:
	SDL_GLContext _glContext;
};
} //namespace core 
} //namespace hst
