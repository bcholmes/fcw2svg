#include "SymbolDefinition.h"
#include "StringSanitizer.h"

namespace bcholmes {
	namespace fcw2svg {

		SymbolDefinition::SymbolDefinition(CommonHeader header, string name, int flags, Point3d low, Point3d high) 
			: Group(header), m_name(name), m_flags(flags), m_low(low), m_high(high) {
		};
		SymbolDefinition::SymbolDefinition(const SymbolDefinition& shape) 
			: Group(shape), m_name(shape.m_name), m_flags(shape.m_flags), m_low(shape.m_low), m_high(shape.m_high) {
		}
		
		Shape* SymbolDefinition::from(CommonHeader header, SYMDEF* symdef) {
			Point3d point1 = Point3d::from(symdef->Low);
			Point3d point2 = Point3d::from(symdef->Hi);
			return new SymbolDefinition(header, string(symdef->SName), symdef->Flags, point1, point2);
		}
		
		string SymbolDefinition::createSymbolName(string name) {
			return "Symbol-" + StringSanitizer::sanitize(name);
		}
		
		SvgElement SymbolDefinition::createGroupElement(SvgElement& parent) {
			SvgElement child = Group::createGroupElement(parent);
			child.setAttribute("id", createSymbolName(m_name));
			child.setAttribute("title", m_name);
			return child;
		}

	}
}