#include "Path.h"

namespace bcholmes {
	namespace fcw2svg {

		Path::Path(CommonHeader header, char flags, char smootherType, char smootherResolution, 
					float startParm, float endParm) 
			: BasePath(header), m_flags(flags), m_smootherType(smootherType), 
			m_smootherResolution(smootherResolution), m_startParm(startParm), m_endParm(endParm) {
		};
		Path::Path(const Path& shape) 
			: BasePath(shape), m_flags(shape.m_flags), m_smootherType(shape.m_smootherType), 
			m_smootherResolution(shape.m_smootherResolution), m_startParm(shape.m_startParm), 
			m_endParm(shape.m_endParm)  {
		}

		string Path::createPathNodes(Point startPoint, CoordinateSystem& drawing, bool alwaysShowFirstPoint) {
			if (m_smootherType == SM_CB) {
				return createBezierFromCubicBSpline(startPoint, drawing, alwaysShowFirstPoint);
			} else {
				return BasePath::createPathNodes(startPoint, drawing, alwaysShowFirstPoint);
			}
		}


		string Path::createBezierFromCubicBSpline(const Point& point, CoordinateSystem& drawing, bool alwaysShowFirstPoint) {
			
			string initialPath;
			
			if (alwaysShowFirstPoint || !point.isApproximatelyEqual(getFirstPoint())) {
				initialPath = appendPointData("M", getFirstPoint(), drawing);;
			}

			for (int i = 1; i < m_points.size(); i++) {
			
				Point c1 = (m_points[i-1] * (2.0f / 3.0f)) + (m_points[i] * (1.0f / 3.0f));
				Point c2 = (m_points[i-1] * (1.0f / 3.0f)) + (m_points[i] * (2.0f / 3.0f));
				
				initialPath += appendPointData(" C ", c1, drawing);
				initialPath += appendPointData(" ", c2, drawing);
				initialPath += appendPointData(" ", calculateBezierEndpont(i), drawing);
			}
			return initialPath;
		}

		Point Path::calculateBezierEndpont(int index) {
			if (index == 0) {
				return m_points[0];
			} else if (index == m_points.size()-1) {
				return m_points[index];
			} else {
				Point b0 = m_points[index-1];
				Point b1 = m_points[index];
				Point b2 = m_points[index+1];
			
				Point s = (b0 * (1.0f / 6.0f)) + (b1 * (2.0f / 3.0f)) + (b2 * (1.0f / 6.0f));
				return s;
			}
		}

		
		Shape* Path::from(CommonHeader header, PATH2* path2) {
			Path* result = new Path(header, path2->Path.Flags, path2->Path.SmType,
				path2->Path.SRes, path2->Path.SParm, path2->Path.EParm);
				
			for (int i = 0; i < path2->Path.Count; i++) {
				result->m_points.push_back(Point::from(path2->Path.Nodes[i]));
			}
			return result;
		}
	}
}