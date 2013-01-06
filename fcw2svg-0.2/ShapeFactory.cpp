#include "ShapeFactory.h"
#include "CadApi.h"
#include "PointShape.h"
#include "Arc.h"
#include "Line.h"
#include "UnknownShape.h"
#include "Group.h"
#include "Circle.h"
#include "Label.h"
#include "Path.h"
#include "EllipticalArc.h"
#include "SymbolDefinition.h"
#include "SymbolReference.h"
#include "MultiPoly.h"
#include "Sheet.h"
#include "Ellipse.h"

namespace bcholmes {
	namespace fcw2svg {

		Shape* ShapeFactory::createShape(CommonHeader header, unsigned char* ptr) {
		
			switch (header.getType()) {
			
				case ET_POINT2: // 1
					return PointShape::from(header, (POINT2*) ptr);
				case ET_LINE2: // 2
					return Line::from(header, (LINE2*) ptr);
				case ET_PATH2: // 3
					return Path::from(header, (PATH2*) ptr);
				case ET_TEXT2: // 5
					return Label::from(header, (TXT2*) ptr);
				case ET_CIR2: // 6
					return Circle::from(header, (CIR2*) ptr);
				case ET_ARC2: // 7
					return Arc::from(header, (ARC2*) ptr);
				case ET_ELP2: // 8
					return Ellipse::from(header, (ELP2*) ptr);
				case ET_ELA2: // 9
					return EllipticalArc::from(header, (ELA2*) ptr);
				case ET_PART:
					return Group::from(header, (PART*) ptr);
				case ET_MPOLY2:
					return MultiPoly::from(header, (MPOLY2*) ptr);
				case ET_SHEET:
					return Sheet::from(header, (SHEET*) ptr);
				case ET_SYMDEF:
					return SymbolDefinition::from(header, (SYMDEF*) ptr);
				case ET_SYMREF:
					return SymbolReference::from(header, (SYMREF*) ptr);
				default:
					return UnknownShape::from(header);
			}
		}
	}
}