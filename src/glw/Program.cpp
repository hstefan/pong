#include "Program.hpp"
#include "util/util.hpp"
#include <vector>

namespace hst {
namespace glw {

Program::Program()
	: _shaders() {
	_id = gl::CreateProgram();
}

Program::~Program() {
	gl::DeleteProgram(_id);
}

bool Program::attach_shader(GLuint s) {
	auto ret = _shaders.insert(s);
	if (ret.second) {
		gl::AttachShader(_id, s);
	}
	return ret.second;
}

void Program::detach_shader(GLuint s) {
	_shaders.erase(s);
	gl::DetachShader(_id, s);
}

bool Program::link() {
	gl::LinkProgram(_id);
	GLint status;
	gl::GetProgramiv(_id, gl::LINK_STATUS, &status);
	return status != gl::FALSE_;
}

std::string Program::info_log() {
	GLint len;
	gl::GetProgramiv(_id, gl::INFO_LOG_LENGTH, &len);
	std::vector<GLchar> buff(len + 1);
	gl::GetProgramInfoLog(_id, len, nullptr, &(buff[0]));
	return std::string(RANGE(buff));
}

} //namespace glw
} //namespace hst
