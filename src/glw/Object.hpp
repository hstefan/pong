#pragma once

#include "gl_core_3_3.hpp"
#include "util/NonCopyable.hpp"

namespace hst {
namespace glw {

struct Object : private util::NonCopyable {
	Object();
	Object(const GLuint& id);
protected:
	GLuint  _id;
};

} //namespace glw
} //namespace hst
