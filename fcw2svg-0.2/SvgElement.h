#ifndef __SVGELEMENT_H
#define __SVGELEMENT_H

#include <string>
#include "tinyxml.h"

using std::string;

namespace bcholmes {
	namespace fcw2svg {

		class SvgElement {
	
			private:
				TiXmlElement* m_elementNode;

			public:
				SvgElement(TiXmlElement* elementNode) : m_elementNode(elementNode) {};
				SvgElement(const SvgElement& element) : m_elementNode(element.m_elementNode) {};
				~SvgElement() {};
				
				SvgElement createElement(string tagName);
				void setAttribute(string name, string value);
				void appendChild(SvgElement& child);
				void setText(string text);
		};

	}
}

#endif