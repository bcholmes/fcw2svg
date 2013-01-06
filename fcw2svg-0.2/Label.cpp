#include <sstream>
#include <algorithm>
#include "Label.h"

namespace bcholmes {
	namespace fcw2svg {

		Label::Label(CommonHeader header, string text, Point location, short fontId, float height, short textFlags, short justification)
			: Shape(header), m_text(text), m_location(location), m_fontId(fontId), m_height(height), m_textFlags(textFlags), m_justification(justification) {
		};
		Label::Label(const Label& shape) 
			: Shape(shape), m_text(shape.m_text), m_location(shape.m_location), m_fontId(shape.m_fontId), m_height(shape.m_height), m_textFlags(shape.m_textFlags), m_justification(shape.m_justification) {
		}
		void Label::appendAsXml(SvgElement& parent, Drawing& drawing) {
			SvgElement element = parent.createElement("text");
			Point mapped = drawing.map(m_location);
			float x = mapped.getX();
			float y = mapped.getY();
			element.setAttribute("x", NumberUtil::formatFloat(x));
			element.setAttribute("y", NumberUtil::formatFloat(y));
/*
			Font font = drawing.getFont(this.fontId);
			if (font != null) {
				element.setAttribute("font-family", font.getName());
				element.setAttribute("font-size", NumberUtil::formatFloat(m_height));
			} else {
*/			
				element.setAttribute("font-family", "Sans");
				element.setAttribute("font-size", NumberUtil::formatFloat(m_height));
/*			} */
			if (isBold()) {
				element.setAttribute("font-weight", "bold");
			}
			if (isItalic()) {
				element.setAttribute("font-style", "italic");
			}
			if (isCentered()) {
				element.setAttribute("text-anchor", "middle");
				element.setAttribute("text-align", "center");
			}

			element.setAttribute("fill", m_header.getFillColor(drawing));
			element.setAttribute("stroke", "none");
		
			
			std::vector<std::string> lines;
			getLines(m_text, '\n', lines);
			for (int i = 0; i < lines.size(); i++) {
				string line = lines[i];
				if (isNotBlank(line)) {
					SvgElement tspan = element.createElement("tspan");
					tspan.setAttribute("x", NumberUtil::formatFloat(x));
					tspan.setAttribute("y", NumberUtil::formatFloat(y + (i) * m_height));
			
					tspan.setText(line);
					element.appendChild(tspan);
				}
			}
		
			parent.appendChild(element);
		}
		
		std::vector<std::string>& Label::getLines(const std::string& s, char delim, std::vector<std::string> &elems) {
    		std::stringstream ss(s);
    		std::string item;
    		while(std::getline(ss, item, delim)) {
    			replaceAll(item, "\r", "");
        		elems.push_back(item);
    		}
    		return elems;
		}

		bool Label::isNotBlank(std::string& str) {
			return str.size() > 0;
		}

		void Label::replaceAll(std::string& str, const std::string& from, const std::string& to) {
    		size_t start_pos = 0;
    		while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        		str.replace(start_pos, from.length(), to);
        		start_pos += to.length(); 
    		}
		}
		

		Shape* Label::from(CommonHeader header, TXT2* text) {
			Point point = Point::from(text->Text.Origin);
			return new Label(header, string(text->Text.TData), point, text->Text.Font, 
				text->Text.Hght, text->Text.TFlags, text->Text.Just);
		}
	}
}