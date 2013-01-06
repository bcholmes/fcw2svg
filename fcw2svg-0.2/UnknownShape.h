#ifndef __UNKNOWNSHAPE_H
#define __UNKNOWNSHAPE_H

#include "Shape.h"
#include "CadApi.h"

namespace bcholmes {
	namespace fcw2svg {

		class UnknownShape : Shape {
			public:
				UnknownShape(CommonHeader header);
				UnknownShape(const UnknownShape& shape);
				virtual ~UnknownShape();
				
				static Shape* from(CommonHeader header);
		};
	}
}

#endif