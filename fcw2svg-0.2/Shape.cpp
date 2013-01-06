#include <iostream>
#include "Shape.h"
#include "NumberUtil.h"
#include "Paint.h"

using namespace std;

namespace bcholmes {
	namespace fcw2svg {

		Shape::Shape(CommonHeader header) :
			m_header(header) {
		};
		Shape::Shape(const Shape& shape) {
			this->m_header = shape.m_header;
		}
		
		Shape::~Shape() {
		}
		
		void Shape::setStrokeAndFill(SvgElement& element, Drawing& drawing) {
			if (m_header.isFilledLine()) {
				element.setAttribute("fill", "none");
			} else if (isSvgFill() && isFillable()) {
				Paint fill = drawing.getFillStyle(m_header.getFillStyle(), m_header.getFillColor(drawing));
				element.setAttribute("fill", fill.toSvgReference());
				element.setAttribute("fill-rule", "evenodd");
			} else {
				element.setAttribute("fill", "none");
			}

			if (isStroke()) {
				if (m_header.isFilledLine()) {
					Paint fill = drawing.getFillStyle(m_header.getFillStyle(), m_header.getFillColor(drawing));
					element.setAttribute("stroke", fill.toSvgReference());
					element.setAttribute("stroke-width", NumberUtil::formatFloat(m_header.getStrokeWidth()));
				} else if (m_header.getStrokeWidth() != 0) {
					Paint fill = drawing.getFillStyle(m_header.getFillStyle(), m_header.getStrokeColor(drawing));
					element.setAttribute("stroke", fill.toSvgReference());
					element.setAttribute("stroke-width", NumberUtil::formatFloat(m_header.getStrokeWidth()));
				} else if (m_header.isOutlinePresent() && isFilled()) {
					Paint fill = drawing.getFillStyle(m_header.getFillStyle(), m_header.getStrokeColor(drawing));
					element.setAttribute("stroke", fill.toSvgReference());
					element.setAttribute("stroke-width", NumberUtil::formatFloat(drawing.getBaseStroke()) + "px");
				} else if (m_header.isOutlinePresent()) {
					element.setAttribute("stroke", m_header.getStrokeColor(drawing));
					element.setAttribute("stroke-width", NumberUtil::formatFloat(drawing.getBaseStroke()) + "px");
				} else {
					element.setAttribute("stroke", "none");
				}
			}
		}
		
		bool Shape::isSvgFill() {
			return isFilled() && m_header.getStrokeWidth() == 0;
		}
	}
}