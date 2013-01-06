#ifndef __POINTSHAPE_H
#define __POINTSHAPE_H

#include "Shape.h"
#include "Point.h"
#include "CadApi.h"

namespace bcholmes {
	namespace fcw2svg {

		class PointShape : public Shape {
			private:
				Point m_point;
			public:
				PointShape(CommonHeader header, Point point);
				PointShape(const PointShape& shape);
				~PointShape();
				
				static Shape* from(CommonHeader header, POINT2* point2);
			};
	}
}

#endif