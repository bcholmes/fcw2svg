#ifndef __PATH_H
#define __PATH_H

#include "BasePath.h"
#include "Point.h"
#include "CadApi.h"

namespace bcholmes {
	namespace fcw2svg {

		class Path : public BasePath {
			private:
				char m_flags;
				char m_smootherType;
				char m_smootherResolution;
				float m_startParm;
				float m_endParm;
				
				string createBezierFromCubicBSpline(const Point& startPoint, CoordinateSystem& drawing, bool alwaysShowFirstPoint);
				Point calculateBezierEndpont(int index); 
			public:
				Path(CommonHeader header, char flags, char smootherType, char smootherResolution, 
					float startParm, float endParm);
				Path(const Path& shape);
				virtual ~Path() {};

				virtual string createPathNodes(Point startPoint, CoordinateSystem& drawing, bool alwaysShowFirstPoint);
				virtual void assignId(SvgElement& element) { element.setAttribute("id", "Path-" + NumberUtil::formatInt(m_header.getTag())); };
				
				virtual bool isClosed() { return (m_flags & 0x80) != 0; }
				virtual bool isFilled() { return (m_flags & 0x40) != 0 ||
					(BasePath::isFilled() && isClosed()); }
				
				static Shape* from(CommonHeader header, PATH2* path2);
			};
	}
}

#endif