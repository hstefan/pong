#pragma once

#include <istream>
#include <string>
#include "gl_core_3_3.hpp"
#include "Object.hpp"

namespace hst {
namespace glw {

struct Shader : public Object {
	Shader(GLenum type);
	Shader(GLenum type, std::istream& stream);
	~Shader();
	bool compile();
	void source(std::istream& stream);
	std::string info_log() const;
};

} //namespace glw
} //namespace hst
