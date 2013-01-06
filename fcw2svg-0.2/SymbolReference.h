#ifndef __SYMBOLREFERENCE_H
#define __SYMBOLREFERENCE_H

#include "Group.h"
#include "Point3d.h"
#include "CadApi.h"
#include "TableMatrix.h"

namespace bcholmes {
	namespace fcw2svg {

		class SymbolReference : public Group {
			private:
				string m_name;
				Point3d m_low;
				Point3d m_high;
				TableMatrix m_matrix;
			public:
				SymbolReference(CommonHeader header, string name, Point3d low, 
					Point3d high, TableMatrix matrix);
				SymbolReference(const SymbolReference& other);
				~SymbolReference() {}

				virtual void appendAsXml(SvgElement& element, Drawing& drawing);
				virtual void assignId(SvgElement& element) { element.setAttribute("id", "SymbolReference-" + NumberUtil::formatInt(m_header.getTag())); };
				
				static Shape* from(CommonHeader header, SYMREF* symref);
			};
	}
}

#endif