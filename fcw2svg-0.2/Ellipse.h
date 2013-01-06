#ifndef __ELLIPSE_H
#define __ELLIPSE_H

#include "BasePath.h"
#include "Point.h"
#include "CadApi.h"
#include "EllipticalArc.h"

namespace bcholmes {
	namespace fcw2svg {

		class Ellipse : public BasePath {
			private:
				Point m_centre;
				float m_radius;
				float m_eccentricity;
				float m_inclination;
			public:
				Ellipse(CommonHeader header, Point centre, float radius, float eccentricity, float inclination) 
					: BasePath(header), m_centre(centre), m_radius(radius), 
					m_eccentricity(eccentricity), m_inclination(inclination) {
					
					m_points.push_back(EllipticalArc::point(0.0f, m_radius, m_centre, m_eccentricity));
					m_points.push_back(EllipticalArc::point(0.0f, m_radius, m_centre, m_eccentricity));
				}
				Ellipse(const Ellipse& shape) 
					: BasePath(shape), m_centre(shape.m_centre), m_radius(shape.m_radius), 
					m_eccentricity(shape.m_eccentricity), m_inclination(shape.m_inclination) {}
				~Ellipse() {}

				virtual void assignId(SvgElement& element) { element.setAttribute("id", "Ellipse-" + NumberUtil::formatInt(m_header.getTag())); };
				
				static Shape* from(CommonHeader header, ELP2* ellipse);
				string createPathNodes(Point startPoint, CoordinateSystem& drawing, bool alwaysShowFirstPoint);
				void appendAsXml(SvgElement& parent, Drawing& drawing);
				virtual bool isClosed() { return true; }
			};
	}
}

#endif