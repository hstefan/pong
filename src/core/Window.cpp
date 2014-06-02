#include "gl_core_3_3.hpp"
#include "Window.hpp"
#include <iostream>

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

GLWindow::GLWindow(const std::string& title, int x, int y, int w, int h, Uint32 flags) 
	: Window(title, x, y, w, h, flags | SDL_WINDOW_OPENGL) {
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	_glContext = SDL_GL_CreateContext(_win);
	auto didLoad = gl::sys::LoadFunctions();
	if (didLoad) {
		std::cout << "OpenGL Context Loaded: OpenGL " << gl::sys::GetMajorVersion() << "." 
			<< gl::sys::GetMinorVersion() << std::endl;
	} else {
		std::cout << "OpenGL: " << didLoad.GetNumMissing() << std::endl;
	}
}

void GLWindow::swapBuffers() {
	SDL_GL_SwapWindow(_win);
}

} //namespace core
} //namespace core
