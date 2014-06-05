#pragma once

#include "Object.hpp"

namespace hst {
namespace glw {

struct ArrayObject : public Object {
	ArrayObject();
	ArrayObject(GLenum usage, const GLvoid* data, int size);
	void upload(GLenum usage, const GLvoid* data, int size);
	void bind();
	void unbind();
};

} //namespace glw
} //namespace hst
