#ifndef __SVGDOCUMENT_H
#define __SVGDOCUMENT_H

#include <string>
#include "SvgElement.h"
#include "tinyxml.h"

using std::string;

namespace bcholmes {
	namespace fcw2svg {

		class SvgDocument {
	
			private:
				TiXmlDocument m_document;
				TiXmlElement* m_rootElement;
				TiXmlElement* m_defsElement;

			public:
				SvgDocument();
				~SvgDocument();
				
				void writeFile(string fileName);
				
				SvgElement getDocumentElement() { return SvgElement(m_rootElement); }
				SvgElement getDefsElement() { return SvgElement(m_defsElement); }
		};

	}
}

#endif