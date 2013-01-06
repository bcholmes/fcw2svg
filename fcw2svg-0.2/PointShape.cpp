#include "PointShape.h"

namespace bcholmes {
	namespace fcw2svg {

		PointShape::PointShape(CommonHeader header, Point point) 
			: Shape(header), m_point(point) {
		};
		PointShape::PointShape(const PointShape& shape) 
			: Shape(shape), m_point(shape.m_point) {
		}
		PointShape::~PointShape() {
		}
		
		Shape* PointShape::from(CommonHeader header, POINT2* point2) {
			Point point = Point::from(point2->Point);
			return new PointShape(header, point);
		}
	}
}