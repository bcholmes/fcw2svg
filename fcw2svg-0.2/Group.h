#ifndef __GROUP_H
#define __GROUP_H

#include <vector>
#include "Shape.h"
#include "CadApi.h"
#include "NumberUtil.h"

using std::vector;

namespace bcholmes {
	namespace fcw2svg {

		class Group : public Shape {
			protected:
				vector<Shape *> m_sublist;
			
				virtual SvgElement createGroupElement(SvgElement& parent);
			public:
				Group(CommonHeader header) : Shape(header) {}
				Group(const Group& shape) : Shape(shape) {}
				~Group();
				
				vector<Shape *>* getSublist() { return &m_sublist; }
				void appendAsXml(SvgElement& parent, Drawing& drawing);
				virtual void assignId(SvgElement& element) { element.setAttribute("id", "Group-" + NumberUtil::formatInt(getHeader().getTag())); };
				virtual bool isGroup() { return true; }
				
				static Shape* from(CommonHeader header, PART* part);
		};
	}
}

#endif