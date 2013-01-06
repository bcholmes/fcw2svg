#include "Sheet.h"
#include "StringSanitizer.h"

namespace bcholmes {
	namespace fcw2svg {

		Shape* Sheet::from(CommonHeader header, SHEET* sheet) {
			return new Sheet(header, sheet->Status, string(sheet->SName));
		}
		
		SvgElement Sheet::createGroupElement(SvgElement& parent) {
			SvgElement child = Group::createGroupElement(parent);
			child.setAttribute("inkscape:groupmode", "layer");
			child.setAttribute("inkscape:label", m_name);
			if (isHidden()) {
				child.setAttribute("style", "display: none;");
			}
			return child;
		}
		
		void Sheet::assignId(SvgElement& element) {
			string id = string("Sheet-") + StringSanitizer::sanitize(m_name);
			element.setAttribute("id", id);
		}
	}
}