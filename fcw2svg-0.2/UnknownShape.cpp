#include "UnknownShape.h"

namespace bcholmes {
	namespace fcw2svg {

		UnknownShape::UnknownShape(CommonHeader header) 
			: Shape(header) {
		};
		UnknownShape::UnknownShape(const UnknownShape& shape) 
			: Shape(shape) {
		}
		UnknownShape::~UnknownShape() {
		}
		
		Shape* UnknownShape::from(CommonHeader header) {
			return new UnknownShape(header);
		}
	}
}