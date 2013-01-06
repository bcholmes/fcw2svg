#include <math.h>
#include "EllipticalArc.h"

namespace bcholmes {
	namespace fcw2svg {

		EllipticalArc::EllipticalArc(CommonHeader header, Point centre, float radius, 
			float eccentricity, float inclination, float startAngle, float deltaAngle) 
			: BasePath(header), m_radius(radius), m_eccentricity(eccentricity), 
			m_inclination(inclination) {
			m_deltaAngle = deltaAngle;
			m_sweepPositive = true;
			m_points.push_back(point(startAngle, radius, centre, eccentricity));
			m_points.push_back(point(startAngle + deltaAngle, radius, centre, eccentricity));
		};
		
		EllipticalArc::EllipticalArc(const EllipticalArc& shape) : BasePath(shape), 
			m_radius(shape.m_radius), m_eccentricity(shape.m_eccentricity), 
			m_inclination(shape.m_inclination), m_deltaAngle(shape.m_deltaAngle),
			m_sweepPositive(shape.m_sweepPositive) {
		}

		Shape* EllipticalArc::from(CommonHeader header, ELA2* arc) {
			Point centre = Point::from(arc->Ela.Elp.Circle.Center);
			float radius = arc->Ela.Elp.Circle.Radius;
			float eccentricity = arc->Ela.Elp.Ecc;
			float inclination = arc->Ela.Elp.Incl;
			float startAngle = arc->Ela.SAng;
			float deltaAngle = arc->Ela.AngW;
			return new EllipticalArc(header, centre, radius, eccentricity, inclination, 
				startAngle, deltaAngle);
		}
		
		string EllipticalArc::createPathNodes(Point point, CoordinateSystem& drawing, bool alwaysShowFirstPoint) {
			Point startPoint = drawing.map(getFirstPoint());
			Point endPoint = drawing.map(getLastPoint());
			
			string initialPath;
			
			if (alwaysShowFirstPoint || !point.isApproximatelyEqual(getFirstPoint())) {
				initialPath = "M " + NumberUtil::formatFloat(startPoint.getX()) + "," 
								+ NumberUtil::formatFloat(startPoint.getY());
			}
			
			return initialPath + " A " +  NumberUtil::formatFloat(m_radius) + "," 
				+ NumberUtil::formatFloat(m_radius * m_eccentricity) + " " 
				+ NumberUtil::formatFloat(m_inclination) + " " + (isLargeArc() ? "1" : "0")
				+ "," + (isSweepPositive() ? "0" : "1") + " " 
				+ NumberUtil::formatFloat(endPoint.getX()) + "," 
				+ NumberUtil::formatFloat(endPoint.getY()); 
		}
		
		Point EllipticalArc::point(float angle, float radius, Point centre, float eccentricity) {
			float x;
			float y;
			float a = fmod(angle, (float) (M_PI * 2.0));
			if (a > 3.0f * M_PI / 2.0f) {
				x = (float) cos(atan(tan(2 * M_PI - a) / eccentricity));
				y = - (float) sin(atan(tan(2 * M_PI - a) / eccentricity));
			} else if (a > M_PI) {
				x = - (float) cos(atan(tan(a - M_PI) / eccentricity));
				y = - (float) sin(atan(tan(a - M_PI) / eccentricity));
			} else if (a > M_PI / 2.0f ) {
				x = - (float) cos(atan(tan(M_PI - a) / eccentricity));
				y = (float) sin(atan(tan(M_PI - a) / eccentricity));
			} else {
				x = (float) cos(atan(tan(a) / eccentricity));
				y = (float) sin(atan(tan(a) / eccentricity));
			}
			return Point(centre.getX() + x * radius, centre.getY() + y * radius * eccentricity);
		}
		
		void EllipticalArc::reverse() {
			BasePath::reverse();
			m_sweepPositive = !m_sweepPositive;
		}
		
	}
}