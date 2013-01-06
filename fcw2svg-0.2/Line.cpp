#include "Line.h"

namespace bcholmes {
	namespace fcw2svg {

		Line::Line(CommonHeader header, Point start, Point end) 
			: BasePath(header) {
			m_points.push_back(start);
			m_points.push_back(end);
		};
		Line::Line(const Line& shape) 
			: BasePath(shape) {
		}
		Line::~Line() {
		}
		
		Shape* Line::from(CommonHeader header, LINE2* line2) {
			Point point1 = Point::from(line2->Line.p1);
			Point point2 = Point::from(line2->Line.p2);
			return new Line(header, point1, point2);
		}
	}
}