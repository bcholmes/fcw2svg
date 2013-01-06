#include "SvgDocument.h"

using std::string;

namespace bcholmes {
	namespace fcw2svg {

		SvgDocument::SvgDocument() {
		
			TiXmlElement rootElement("svg");
			rootElement.SetAttribute("version", "1.1");
			rootElement.SetAttribute("xmlns", "http://www.w3.org/2000/svg");
			rootElement.SetAttribute("xmlns:xlink", "http://www.w3.org/1999/xlink");
			rootElement.SetAttribute("xmlns:inkscape", "http://www.inkscape.org/namespaces/inkscape");

			m_rootElement = (TiXmlElement*) m_document.InsertEndChild(rootElement);

			TiXmlElement defsElement("defs");					
  			m_defsElement = (TiXmlElement*) m_rootElement->InsertEndChild(defsElement);
		};
		SvgDocument::~SvgDocument() {
		}
		void SvgDocument::writeFile(string fileName) {
			m_document.SaveFile( fileName.c_str() );
		}
	}
}