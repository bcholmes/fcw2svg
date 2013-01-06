#include <math.h>
#include "Circle.h"

namespace bcholmes {
	namespace fcw2svg {

		Circle::Circle(CommonHeader header, Point centre, float radius) : BasePath(header), m_radius(radius), m_centre(centre) {
			m_points.push_back(Arc::point(0.0, m_radius, m_centre));
			m_points.push_back(Arc::point(0.0, m_radius, m_centre));
		};
		
		Circle::Circle(const Circle& shape) : BasePath(shape), m_radius(shape.m_radius), m_centre(shape.m_centre) {
		}

		Shape* Circle::from(CommonHeader header, CIR2* circle) {
			Point centre = Point::from(circle->Circle.Center);
			float radius = circle->Circle.Radius;
			return new Circle(header, centre, radius);
		}
		
		void Circle::appendAsXml(SvgElement& parent, Drawing& drawing) {
			SvgElement circle = parent.createElement("circle");
			assignId(circle);
			Point mapped = drawing.map(m_centre);
			circle.setAttribute("cx", NumberUtil::formatFloat(mapped.getX()));
			circle.setAttribute("cy", NumberUtil::formatFloat(mapped.getY()));
			circle.setAttribute("r", NumberUtil::formatFloat(m_radius));

			setStrokeAndFill(circle, drawing);
			parent.appendChild(circle);
		}
		
		
		string Circle::createPathNodes(Point point, CoordinateSystem& drawing, bool alwaysShowFirstPoint) {
		
			Point startPoint = drawing.map(getFirstPoint());
			
			string initialPath("");
			
			if (alwaysShowFirstPoint || !point.isApproximatelyEqual(getFirstPoint())) {
				initialPath += "M " + NumberUtil::formatFloat(startPoint.getX()) + "," 
								+ NumberUtil::formatFloat(startPoint.getY());
			}
			
			for (int i = 1; i <= 4; i++) {
				Point nextPoint = drawing.map(Arc::point((float) (M_PI * i / 2.0), m_radius, m_centre));
				initialPath += " A " + NumberUtil::formatFloat(m_radius) + "," +
					NumberUtil::formatFloat(m_radius) + " 0 0,0 " +
					NumberUtil::formatFloat(nextPoint.getX()) + "," + 
					NumberUtil::formatFloat(nextPoint.getY());
			}
			
			return initialPath; 
		}
	}
}