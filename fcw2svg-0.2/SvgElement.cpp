#include "SvgElement.h"

using std::string;

namespace bcholmes {
	namespace fcw2svg {

		SvgElement SvgElement::createElement(string tagName) {
			TiXmlElement temp(tagName.c_str());
		
			TiXmlElement* element = (TiXmlElement*) m_elementNode->InsertEndChild(temp);
			return SvgElement(element);
		}
		
		void SvgElement::setAttribute(string name, string value) {
			m_elementNode->SetAttribute(name.c_str(), value.c_str());
		}
		
		void SvgElement::setText(string text) {
			TiXmlText textNode(text.c_str());
			m_elementNode->InsertEndChild(textNode);
		}
		
		void SvgElement::appendChild(SvgElement& child) {
		}
	}
}