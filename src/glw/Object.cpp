#include "Object.hpp"

namespace hst {
namespace glw {

Object::Object()
	: _id(0) {
}

Object::Object(const GLuint& id) 
	: _id(id)  {
}

} //namespace glw
} //namespace hst
