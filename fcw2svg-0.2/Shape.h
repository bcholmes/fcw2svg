#ifndef __SHAPE_H
#define __SHAPE_H

#include "CommonHeader.h"
#include "Drawing.h"
#include "SvgElement.h"
#include "NumberUtil.h"

namespace bcholmes {
	namespace fcw2svg {

		class Shape {
			protected:
				CommonHeader m_header;
			public:
				Shape(CommonHeader header);
				Shape(const Shape& shape);
				virtual ~Shape();
				
				CommonHeader getHeader() { return this->m_header; }
				virtual bool isSymbolDefinition() { return false; }
				int getType() { return m_header.getType(); }
				virtual void appendAsXml(SvgElement& element, Drawing& drawing) {}
				virtual void assignId(SvgElement& element) { element.setAttribute("id", "Shape-" + NumberUtil::formatInt(m_header.getTag())); };
				virtual bool isGroup() { return false; }
				virtual bool isFillable() { return true; }
				void setStrokeAndFill(SvgElement& element, Drawing& drawing);
				bool isSvgFill();
				virtual bool isFilled() { return m_header.isFilled(); }
				virtual bool isStroke() { return true; }
				virtual bool isBasePath() { return false; }
		};

	}
}

#endif