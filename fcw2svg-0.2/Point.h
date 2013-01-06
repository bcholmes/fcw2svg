#ifndef __POINT_H
#define __POINT_H

#include "CadApi.h"

namespace bcholmes {
	namespace fcw2svg {

		class Point {
	
			private:
				float x;
				float y;
				float absoluteValue(float x) const;
			public:
				Point(float x, float y);
				Point(const Point& point);
				~Point();
				float getX() const { return this->x; }
				float getY() const { return this->y; }
				static Point from(GPOINT2 point);
				bool isApproximatelyEqual(const Point& point) const;
				
				Point operator+(const Point& point) { return Point(this->x + point.x, this->y + point.y); }
				Point operator*(float m) { return Point(this->x * m, this->y * m); }

				static Point origin() { return Point(0, 0); }
		};

	}
}

#endif