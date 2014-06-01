#pragma once

#include <ostream>

namespace hst {
namespace gfx {

template <class T>
struct Rect;
template <class T>
struct Point;

typedef Rect<int> RectI;
typedef Rect<float> RectF;
typedef Point<int> PointI;
typedef Point<float> PointF;

template <class T>
std::ostream& operator<<(std::ostream& stream, const Rect<T>& rect);
template <class T>
std::ostream& operator<<(std::ostream& stream, const Point<T>& point);

template <class T>
Rect<T> makeRect(const Point<T>& topLeft, const Point<T>& bottomRight);
template <class T>
Rect<T> makeRect(T x, T y, T w, T h);
template <class T>
Point<T> makePoint(T x, T y);
template <class T>
bool insideRect(const Point<T>& p, const Rect<T>& r);

template <class T>
struct Rect {
	T x, y, w, h;
};

template <class T>
struct Point {
	T x, y;
};

template <class T>
std::ostream& operator<<(std::ostream& stream, const Rect<T>& rect) {
	stream << "rect(x:" << rect.x << ",y:" << rect.y << ",w:" << rect.w << ",h:" << rect.h << ")";
	return stream;
}
template <class T>
std::ostream& operator<<(std::ostream& stream, const Point<T>& point) {
	stream << "point(" << point.x << "," << point.y << ")";
	return stream;
}

template <class T>
Rect<T> makeRect(const Point<T>& topLeft, const Point<T>& bottomRight) {
	return makeRect(topLeft.x, topLeft.y, bottomRight.x - topLeft.x, bottomRight.y - topLeft.y);
}

template <class T>
Rect<T> makeRect(T x, T y, T w, T h) {
	return Rect<T> { x, y, w, h };
}

template <class T>
Point<T> makePoint(T x, T y) {
	return Point<T> { x, y };
}

template <class T>
bool insideRect(const Point<T>& p, const Rect<T>& r) {
	return (p.x >= r.x && p.y >= r.y) && (p.x <= (r.x + r.w) && p.y <= (r.y + r.h));
}

} //namespace core
} //namespace hst
