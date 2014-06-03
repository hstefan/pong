#pragma once

namespace hst {
namespace util {

struct NonCopyable {
	NonCopyable(const NonCopyable&);
	NonCopyable& operator=(const NonCopyable&);
protected:
	inline NonCopyable() { }
};

} //nmaespace util
} //namespace hst
