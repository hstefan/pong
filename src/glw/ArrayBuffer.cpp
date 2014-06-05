#include "ArrayBuffer.hpp"

namespace hst {
namespace glw {

ArrayObject::ArrayObject() {
	gl::GenBuffers(1, &_id);
}

ArrayObject::ArrayObject(GLenum usage, const GLvoid* data, int size)
	: ArrayObject() {
	upload(usage, data, size);
}

void ArrayObject::upload(GLenum usage, const GLvoid* data, int size) {
	gl::BindBuffer(gl::ARRAY_BUFFER, _id);
	gl::BufferData(gl::ARRAY_BUFFER, size, data, usage);
	gl::BindBuffer(gl::ARRAY_BUFFER, 0);
}

void ArrayObject::bind() {
	gl::BindBuffer(gl::ARRAY_BUFFER, _id);
}

void ArrayObject::unbind() {
	gl::BindBuffer(gl::ARRAY_BUFFER, 0);
}

} //namsepace glw
} //namespace hst
