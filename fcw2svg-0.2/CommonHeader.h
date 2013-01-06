#ifndef __COMMONHEADER_H
#define __COMMONHEADER_H

#include <string>
#include "Drawing.h"
#include "CadApi.h"

namespace bcholmes {
	namespace fcw2svg {

		class CommonHeader {

			private: 
				int size;
				unsigned char type;
				char flags;
				char flags2;
				int color;
				int color2;
				unsigned char thick;
				short plane;
				short layer;
				short lineStyle;
				short groupId;
				short fillStyle;
				float width;
				int m_tag;
				
			public:
				CommonHeader() {}
				CommonHeader(const CommonHeader& header);
				static CommonHeader from(CSTUFF* cstuff);
				int getType() { return this->type; }
				int getSize() { return this->size; }
				bool isInfoBlockType() { return this->type == 0; }
				bool isSubListMarker() { return this->size == 5; }
				int getTag() { return this->m_tag; }
				bool isFilledLine() { return isSolidFill() && this->width > 0; }
				bool isSolidFill() { return this->fillStyle == 1; }
				float getStrokeWidth() { return this->width; }
				bool isOutlinePresent() { return (this->flags2 & 0x01) == 0; }
				bool isFilled();
				bool isTrivialFilledLine() { return isFilledLine() && (color == color2); }
				std::string getStrokeColor(Drawing& drawing) { return drawing.getColor(this->color); }
				std::string getFillColor(Drawing& drawing) { 
					return isCurrentColor()  ? std::string("currentColor") : drawing.getColor(this->color2); 
				}
				short getFillStyle() { return fillStyle; }
				bool isCurrentColor() { return (flags & 0x08) != 0; }

		};
	}
}

#endif