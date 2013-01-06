#include <string>
#include <iostream>
#include "SymbolReference.h"
#include "SymbolDefinition.h"

using std::string;
using namespace std;

namespace bcholmes {
	namespace fcw2svg {

		SymbolReference::SymbolReference(CommonHeader header, string name, Point3d low, 
					Point3d high, TableMatrix matrix) 
			: Group(header), m_name(name), m_low(low), m_high(high), m_matrix(matrix) {
		}
		SymbolReference::SymbolReference(const SymbolReference& other) 
			: Group(other), m_name(other.m_name), m_low(other.m_low), 
			m_high(other.m_high), m_matrix(other.m_matrix) {
		}
		
		Shape* SymbolReference::from(CommonHeader header, SYMREF* ref) {
			string name(ref->SName);
			Point3d point1 = Point3d::from(ref->Low);
			Point3d point2 = Point3d::from(ref->Hi);
			TableMatrix matrix = TableMatrix::from(ref->TMat);
			return new SymbolReference(header, name, point1, point2, matrix);
		}
		
		void SymbolReference::appendAsXml(SvgElement& parent, Drawing& drawing) {
			SvgElement element = parent.createElement("use");
			assignId(element);
			element.setAttribute("xlink:href", "#" + SymbolDefinition::createSymbolName(m_name));
		
			string matrixTransform = "matrix(" + 
				NumberUtil::formatFloat(m_matrix.m_m11) + " " +
				NumberUtil::formatFloat(-m_matrix.m_m12) + " " +
				NumberUtil::formatFloat(-m_matrix.m_m21) + " " +
				NumberUtil::formatFloat(m_matrix.m_m22) + " " +
				NumberUtil::formatFloat(drawing.mapX(m_matrix.m_m41)) + " " +
				NumberUtil::formatFloat(drawing.mapY(m_matrix.m_m42)) + ")";
		
			element.setAttribute("transform", matrixTransform);
			element.setAttribute("color", m_header.getFillColor(drawing));
			parent.appendChild(element);
		}

	}
}