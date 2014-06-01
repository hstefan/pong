#pragma once

#define RANGE(c) begin(c),end(c)

struct SDL_Rect;
namespace hst {
namespace util {

template <class T>
T clamp(T n, T lower, T upper) {
	if (n > upper)
		return upper;
	else if (n < lower)
		return lower;
	else
		return n;
}

bool insideRect(const SDL_Rect& rect, int x, int y);
} //namespace util
} //namespace hst
