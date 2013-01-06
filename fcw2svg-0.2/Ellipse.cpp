#include "Ellipse.h"

using std::string;

namespace bcholmes {
	namespace fcw2svg {

		Shape* Ellipse::from(CommonHeader header, ELP2* ellipse) {
			return new Ellipse(header, Point::from(ellipse->Elp.Circle.Center), 
				ellipse->Elp.Circle.Radius, ellipse->Elp.Ecc, ellipse->Elp.Incl);
		}
		
		void Ellipse::appendAsXml(SvgElement& parent, Drawing& drawing) {
			SvgElement element = parent.createElement("ellipse");
			assignId(element);
			Point mapped = drawing.map(m_centre);
			element.setAttribute("cx", NumberUtil::formatFloat(mapped.getX()));
			element.setAttribute("cy", NumberUtil::formatFloat(mapped.getY()));
			element.setAttribute("rx", NumberUtil::formatFloat(m_radius));
			element.setAttribute("ry", NumberUtil::formatFloat(m_radius * m_eccentricity));

			if (m_inclination != 0) {
				element.setAttribute("transform", "rotate(" + NumberUtil::formatFloat((float) (m_inclination * 180.0 / M_PI)) + ")");
			}
			setStrokeAndFill(element, drawing);
			parent.appendChild(element);
		}
		
		string Ellipse::createPathNodes(Point point, CoordinateSystem& drawing, bool alwaysShowFirstPoint) {
			string path("");
			Point startPoint = drawing.map(getFirstPoint());
			path += "M " + NumberUtil::formatFloat(startPoint.getX()) + "," 
						+ NumberUtil::formatFloat(startPoint.getY());
		
			for (int i = 1; i <= 4; i++) {
				Point nextPoint = drawing.map(EllipticalArc::point((float) (M_PI * i / 2.0),  m_radius, m_centre,m_eccentricity));
				path += " A " + NumberUtil::formatFloat(m_radius) + "," 
						+ NumberUtil::formatFloat(m_radius * m_eccentricity)
						+ NumberUtil::formatFloat(m_inclination) + " 0,0 "
						+ NumberUtil::formatFloat(nextPoint.getX()) + ","
						+ NumberUtil::formatFloat(nextPoint.getY());
			}
		
			path += " Z ";
			return path;
		}
	}
}