#include <math.h>
#include "Arc.h"

namespace bcholmes {
	namespace fcw2svg {

		Arc::Arc(CommonHeader header, Point centre, float radius, float startAngle, float deltaAngle) : BasePath(header) {
			m_radius = radius;
			m_deltaAngle = deltaAngle;
			m_sweepPositive = true;
			m_points.push_back(point(startAngle, radius, centre));
			m_points.push_back(point(startAngle + deltaAngle, radius, centre));
		};
		
		Arc::Arc(const Arc& shape) : BasePath(shape) {
			m_radius = shape.m_radius;
			m_deltaAngle = shape.m_deltaAngle;
			m_sweepPositive = shape.m_sweepPositive;

		}

		Shape* Arc::from(CommonHeader header, ARC2* arc) {
			Point centre = Point::from(arc->Arc.Circle.Center);
			float radius = arc->Arc.Circle.Radius;
			float startAngle = arc->Arc.SAng;
			float deltaAngle = arc->Arc.AngW;
			return new Arc(header, centre, radius, startAngle, deltaAngle);
		}
		
		string Arc::createPathNodes(Point point, CoordinateSystem& drawing, bool alwaysShowFirstPoint) {
			Point startPoint = drawing.map(getFirstPoint());
			Point endPoint = drawing.map(getLastPoint());
			
			string initialPath;
			
			if (alwaysShowFirstPoint || !point.isApproximatelyEqual(getFirstPoint())) {
				initialPath = "M " + NumberUtil::formatFloat(startPoint.getX()) + "," 
								+ NumberUtil::formatFloat(startPoint.getY());
			}
			
			return initialPath + " A " +  NumberUtil::formatFloat(m_radius) + "," 
				+ NumberUtil::formatFloat(m_radius) + " " 
				+ "0 " + (isLargeArc() ? "1" : "0")
				+ "," + (isSweepPositive() ? "0" : "1") + " " 
				+ NumberUtil::formatFloat(endPoint.getX()) + "," 
				+ NumberUtil::formatFloat(endPoint.getY()); 
		}
		
		Point Arc::point(float angle, float radius, const Point& centre) {
			return Point(centre.getX() + (float) (radius * cos(angle)), 
				centre.getY() + (float) (radius * sin(angle)));
		}
		
		void Arc::reverse() {
			BasePath::reverse();
			m_sweepPositive = !m_sweepPositive;
		}
	}
}