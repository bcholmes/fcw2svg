#include "CommonHeader.h"

namespace bcholmes {
	namespace fcw2svg {

		CommonHeader::CommonHeader(const CommonHeader& header) {
			this->size = header.size;
			this->type = header.type;
			this->flags = header.flags;
			this->flags2 = header.flags2;
			this->color = header.color;
			this->color2 = header.color2;
			this->thick = header.thick;
			this->plane = header.plane;
			this->layer = header.layer;
			this->lineStyle = header.lineStyle;
			this->groupId = header.groupId;
			this->fillStyle = header.fillStyle;
			this->width = header.width;
			this->m_tag = header.m_tag;
		};
		CommonHeader CommonHeader::from(CSTUFF* cstuff) {
			CommonHeader header;
			header.size = cstuff->ERLen;
			header.type = cstuff->EType;
			header.flags = (header.size > 6) ? cstuff->EFlags : 0;
			header.flags2 = (header.size > 7) ? cstuff->EFlags2 : 0;
			header.color = (header.size > 8) ? cstuff->EColor : 0;
			header.color2 = (header.size > 9) ? cstuff->EColor2 : 0;
			header.thick = (header.size > 10) ? cstuff->EThick : 0;
			header.plane = (header.size > 11) ? cstuff->WPlane : 0;
			header.layer = (header.size > 13) ? cstuff->ELayer : 0;
			header.lineStyle = (header.size > 15) ? cstuff->ELStyle : 0;
			header.groupId = (header.size > 17) ? cstuff->GroupID : 0;
			header.fillStyle = (header.size > 19) ? cstuff->EFStyle : 0;
			header.width = (header.size > 23) ? cstuff->LWidth : 0;
			header.m_tag = (header.size > 27) ? cstuff->Tag : 0;
			return header;
		};
		
		bool CommonHeader::isFilled() {
			if (isTrivialFilledLine()) {
				return false;
			} else {
				return this->fillStyle != 0;
			}
		}
	}
}