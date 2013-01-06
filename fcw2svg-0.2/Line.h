#ifndef __LINE_H
#define __LINE_H

#include "BasePath.h"
#include "Point.h"
#include "CadApi.h"

namespace bcholmes {
	namespace fcw2svg {

		class Line : public BasePath {
			public:
				Line(CommonHeader header, Point start, Point end);
				Line(const Line& shape);
				~Line();

				virtual void assignId(SvgElement& element) { element.setAttribute("id", "Line-" + NumberUtil::formatInt(m_header.getTag())); };
				
				static Shape* from(CommonHeader header, LINE2* line2);
			};
	}
}

#endif