#include "Group.h"

namespace bcholmes {
	namespace fcw2svg {

		Group::~Group() {
			for (int i = 0; i < m_sublist.size(); i++) {
				Shape* shape = m_sublist[i];
				delete shape;
			}
		}
		
		void Group::appendAsXml(SvgElement& parent, Drawing& drawing) {
			if (!m_sublist.empty()) {
				SvgElement child = createGroupElement(parent);
				parent.appendChild(child);
				for (int i = 0; i < m_sublist.size(); i++) {
					Shape * shape = m_sublist[i];
					shape->appendAsXml(child, drawing);
				}
			}
		}
		
		Shape* Group::from(CommonHeader header, PART* part) {
			return new Group(header);
		}
		
		SvgElement Group::createGroupElement(SvgElement& parent) {
			SvgElement child = parent.createElement("g");
			assignId(child);		
			return child;
		}
	}
}