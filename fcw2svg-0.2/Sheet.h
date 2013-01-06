#ifndef __SHEET_H
#define __SHEET_H

#include <string>
#include "Group.h"
#include "CadApi.h"

using std::string;

namespace bcholmes {
	namespace fcw2svg {

		class Sheet : public Group {
			private:
				int m_status;
				string m_name;
			
			protected:
				virtual SvgElement createGroupElement(SvgElement& parent);
			public:
				Sheet(CommonHeader header, int status, string name) 
					: Group(header), m_status(status), m_name(name) {}
				Sheet(const Sheet& shape) 
					: Group(shape), m_status(shape.m_status), 
					m_name(shape.m_name) {}
				~Sheet() {}

				virtual void assignId(SvgElement& element);
				
				bool isHidden() { return (m_status & 0x02) == 0; } 
				
				static Shape* from(CommonHeader header, SHEET* sheet);
			};
	}
}

#endif