#ifndef __SHAPEFACTORY_H
#define __SHAPEFACTORY_H

#include "Shape.h"

namespace bcholmes {
	namespace fcw2svg {

		class ShapeFactory {
			public:
				static Shape* createShape(CommonHeader header, unsigned char* ptr);
		};
	}
}

#endif