#ifndef __LABEL_H
#define __LABEL_H

#include <vector>
#include <string>
#include "Shape.h"
#include "Point.h"
#include "CadApi.h"

using std::string;

namespace bcholmes {
	namespace fcw2svg {

		class Label : public Shape {
			private:
				string m_text;
				Point m_location;
				short m_fontId;
				float m_height;
				short m_textFlags;
				short m_justification;
				
			public:
				Label(CommonHeader header, string text, Point location, short fontId, float height, short textFlags, short justification);
				Label(const Label& shape);
				virtual ~Label() {}

				virtual void appendAsXml(SvgElement& element, Drawing& drawing);
				virtual void assignId(SvgElement& element) { element.setAttribute("id", "Text2d-" + NumberUtil::formatInt(m_header.getTag())); };
				bool isStroke() { return false; }
				bool isBold() { return (m_textFlags & TS_BOLD) != 0; }
				bool isItalic() { return (m_textFlags & TS_ITALIC) != 0; }
				bool isCentered() {
					return m_justification == 1 || m_justification == 4 || m_justification == 7 || m_justification == 13; 
				}

				static std::vector<std::string>& getLines(const std::string& s, char delim, std::vector<std::string> &elems);
				static void replaceAll(std::string& str, const std::string& from, const std::string& to);
				static bool isNotBlank(std::string& str);
				static Shape* from(CommonHeader header, TXT2* text);
			};
	}
}

#endif