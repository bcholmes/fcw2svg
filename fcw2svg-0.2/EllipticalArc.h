#ifndef __ELLIPTICALARC_H
#define __ELLIPTICALARC_H

#include "BasePath.h"

namespace bcholmes {
	namespace fcw2svg {

		class EllipticalArc : public BasePath {
			private:
				float m_radius;
				float m_eccentricity;
				float m_inclination;
				float m_deltaAngle;
				bool m_sweepPositive;
			
				bool isLargeArc() {
					return m_deltaAngle > M_PI;
				}
			public:
				EllipticalArc(CommonHeader header, Point centre, float radius, float eccentricity, 
					float incliniation, float startAngle, float deltaAngle);
				EllipticalArc(const EllipticalArc& shape);
				virtual ~EllipticalArc() {};
				
				static Shape* from(CommonHeader header, ELA2* arc);
				static Point point(float angle, float radius, Point centre, float eccentricity);
				
				string createPathNodes(Point startPoint, CoordinateSystem& drawing, bool alwaysShowFirstPoint);
				
				bool isClosed() { return false; }
				bool isFillable() { return false; }
				bool isSweepPositive() { return m_sweepPositive; }
				virtual void assignId(SvgElement& element) { 
					element.setAttribute("id", "EllipticalArc-" + 
						NumberUtil::formatInt(m_header.getTag())); };
				virtual void reverse();

		};
	}
}

#endif