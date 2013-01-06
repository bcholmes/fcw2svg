#ifndef __CIRCLE_H
#define __CIRCLE_H

#include "BasePath.h"
#include "Arc.h"

namespace bcholmes {
	namespace fcw2svg {

		class Circle : public BasePath {
			private:
				float m_radius;
				Point m_centre;

			public:
				Circle(CommonHeader header, Point centre, float radius);
				Circle(const Circle& shape);
				virtual ~Circle() {};
				
				static Shape* from(CommonHeader header, CIR2* arc);
				
				virtual string createPathNodes(Point point, CoordinateSystem& drawing, bool alwaysShowFirstPoint);
				
				bool isClosed() { return true; }
				virtual void assignId(SvgElement& element) { element.setAttribute("id", "Circle-" + NumberUtil::formatInt(m_header.getTag())); };
				virtual void appendAsXml(SvgElement& element, Drawing& drawing);

		};
	}
}

#endif