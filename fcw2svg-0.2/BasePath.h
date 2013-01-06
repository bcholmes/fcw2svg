#ifndef __BASEPATH_H
#define __BASEPATH_H

#include <vector>
#include <string>

#include "Shape.h"
#include "Point.h"
#include "CadApi.h"
#include "Drawing.h"
#include "SvgElement.h"

using std::vector;
using std::string;

namespace bcholmes {
	namespace fcw2svg {

		class BasePath : public Shape {
			protected:
				vector<Point> m_points;
				virtual SvgElement createPathElement(SvgElement& parent, Drawing& drawing);
				void appendAsXml(SvgElement& parent, Drawing& drawing);
				virtual string appendPointData(string command, Point point, CoordinateSystem& drawing);

			public:
				BasePath(CommonHeader header);
				BasePath(const BasePath& shape);
				virtual ~BasePath() {}
				virtual bool isClosed() { return false; }
				virtual bool isReversible() { return true; }
				virtual void reverse();
				virtual Point getFirstPoint() { return m_points[0]; }
				virtual Point getLastPoint() { return m_points[m_points.size()-1]; }
				virtual string createPathNodes(Point point, CoordinateSystem& drawing, bool alwaysShowFirstPoint);
				virtual bool isBasePath() { return true; }
		};
	}
}

#endif