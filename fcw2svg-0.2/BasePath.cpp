#include <iostream>
#include "BasePath.h"
#include "NumberUtil.h"

using std::string;

namespace bcholmes {
	namespace fcw2svg {


		BasePath::BasePath(CommonHeader header) : Shape(header) {
		}
		BasePath::BasePath(const BasePath& path) : Shape(path) {
			for (int i = 0; i < path.m_points.size(); i++) {
				this->m_points.push_back(path.m_points[i]);
			}
		}
		void BasePath::appendAsXml(SvgElement& parent, Drawing& drawing) {
			SvgElement child = createPathElement(parent, drawing);
			parent.appendChild(child);
		}
		
		SvgElement BasePath::createPathElement(SvgElement& parent, Drawing& drawing) {
			SvgElement path = parent.createElement("path");
			assignId(path);
			
			path.setAttribute("d", createPathNodes(Point::origin(), drawing, true));
			setStrokeAndFill(path, drawing);
			return path;
		}
		string BasePath::createPathNodes(Point startPoint, CoordinateSystem& drawing, bool alwaysShowFirstPoint) {
			string result = "";
			if (alwaysShowFirstPoint || !startPoint.isApproximatelyEqual(getFirstPoint())) {
				result += appendPointData("M", getFirstPoint(), drawing);
			}
		
			for (int i = 1; i < m_points.size(); i++) {
				result += appendPointData(" L", m_points[i], drawing);
			}
			
			if (isClosed()) {
				result += " Z";
			}
			return result;
		}
		
		string BasePath::appendPointData(string command, Point point, CoordinateSystem& drawing) {
			Point mapped = drawing.map(point);
			return command + NumberUtil::formatFloat(mapped.getX()) + ","
				+ NumberUtil::formatFloat(mapped.getY());
		}
		
		void BasePath::reverse() {
			vector<Point> temp;
			for (int i = m_points.size()-1; i >= 0; i--) {
				temp.push_back(m_points[i]);
			}
			m_points.clear();
			for (int i = 0; i < temp.size(); i++) {
				m_points.push_back(temp[i]);
			}
		}
	}
}