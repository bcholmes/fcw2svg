#ifndef __POINT3D_H
#define __POINT3D_H

#include "CadApi.h"

namespace bcholmes {
	namespace fcw2svg {

		class Point3d {
	
			private:
				float m_x;
				float m_y;
				float m_z;
			public:
				Point3d(float x, float y, float z) : m_x(x), m_y(y), m_z(z) {}
				Point3d(const Point3d& point) : m_x(point.m_x), m_y(point.m_y), m_z(point.m_z) {}
				~Point3d() {}
				float getX() const { return this->m_x; }
				float getY() const { return this->m_y; }
				float getZ() const { return this->m_z; }
				static Point3d from(GPOINT3 point) { return Point3d(point.x, point.y, point.z); }
		};

	}
}

#endif