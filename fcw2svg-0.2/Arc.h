#ifndef __ARC_H
#define __ARC_H

#include "BasePath.h"

namespace bcholmes {
	namespace fcw2svg {

		class Arc : public BasePath {
			private:
				float m_radius;
				float m_deltaAngle;
				bool m_sweepPositive;
			
				bool isLargeArc() {
					return m_deltaAngle > M_PI;
				}
			public:
				Arc(CommonHeader header, Point centre, float radius, float startAngle, float deltaAngle);
				Arc(const Arc& shape);
				virtual ~Arc() {};
				
				static Shape* from(CommonHeader header, ARC2* arc);
				static Point point(float angle, float radius, const Point& centre);
				
				string createPathNodes(Point startPoint, CoordinateSystem& drawing, bool alwaysShowFirstPoint);
				
				bool isClosed() { return false; }
				virtual bool isFillable() { return false; }
				bool isSweepPositive() { return m_sweepPositive; }
				virtual void assignId(SvgElement& element) { element.setAttribute("id", "Arc-" + NumberUtil::formatInt(m_header.getTag())); };
				virtual void reverse();
		};
	}
}

#endif