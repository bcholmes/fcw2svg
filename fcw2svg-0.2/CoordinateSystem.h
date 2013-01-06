#ifndef __COORDINATESYSTEM_H
#define __COORDINATESYSTEM_H

#include "Point.h"

namespace bcholmes {
	namespace fcw2svg {

		class CoordinateSystem {
			public:
				CoordinateSystem() {}
				CoordinateSystem(const CoordinateSystem& system) {}
				virtual ~CoordinateSystem() {}
				
				virtual Point map(Point point) { return point; }
				virtual float mapX(float x) { return x; }
				virtual float mapY(float y) { return y; }
		};
	}
}

#endif