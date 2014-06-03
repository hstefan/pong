#include "Shader.hpp"
#include "util/util.hpp"
#include <vector>

namespace hst {
namespace glw {

Shader::Shader(GLenum type) {
	_id = gl::CreateShader(type);
}

Shader::Shader(GLenum type, std::istream& stream)
	: Shader(type) {
	source(stream);
}

Shader::~Shader() {
}

bool Shader::compile() {
	gl::CompileShader(_id);
	GLint status;
	gl::GetShaderiv(_id, gl::COMPILE_STATUS, &status);
	return status != gl::FALSE_;
}

void Shader::source(std::istream& stream) {
	auto content = std::string { std::istreambuf_iterator<char>(stream),
		std::istreambuf_iterator<char>() };
	auto raw = content.c_str();
	gl::ShaderSource(_id, 1, &raw, nullptr);
}

std::string Shader::info_log() const {
	GLint len;
	gl::GetShaderiv(_id, gl::INFO_LOG_LENGTH, &len);
	std::vector<GLchar> buff(len + 1);
	gl::GetProgramInfoLog(_id, len, nullptr, &(buff[0]));
	return std::string { RANGE(buff) };
}

} //namespace glw
} //namespace hst
