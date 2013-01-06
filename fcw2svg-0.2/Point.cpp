#include "Point.h"
#include <stdlib.h>

namespace bcholmes {
	namespace fcw2svg {


		Point::Point(float x, float y) {
			this->x = x;
			this->y = y;
		}
		Point::Point(const Point& point) {
			this->x = point.x;
			this->y = point.y;
		}
		Point::~Point() {
		}

		Point Point::from(GPOINT2 point) {
			return Point(point.x, point.y);
		}
		
		float Point::absoluteValue(float x) const {
			if (x < 0) { 
				return -x;
			} else {
				return x;
			}
		}

		bool Point::isApproximatelyEqual(const Point& point) const {
			float deltaX = getX() - point.getX();
			float deltaY = getY() - point.getY();
			return absoluteValue(deltaX) <= 0.015 && 
				absoluteValue(deltaY) <= 0.015;
		}
	}
}