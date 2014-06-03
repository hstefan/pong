#pragma once

#include <string>
#include <set>
#include "gl_core_3_3.hpp"
#include "Object.hpp"

namespace hst {
namespace glw {

struct Program : public Object {
	Program();
	~Program();	
	bool attach_shader(GLuint s);
	void detach_shader(GLuint s);
	bool link();
	std::string info_log();
private:
	std::set<GLuint> _shaders;
};

} //namespace glw
} //namespace hst
