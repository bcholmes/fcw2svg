#ifndef __SYMBOLDEFINITION_H
#define __SYMBOLDEFINITION_H

#include <string>
#include "Group.h"
#include "Point3d.h"
#include "CadApi.h"

using std::string;

namespace bcholmes {
	namespace fcw2svg {

		class SymbolDefinition : public Group {
			private:
				string m_name;
				int m_flags;
				Point3d m_low;
				Point3d m_high;
			protected:
				SvgElement createGroupElement(SvgElement& parent);
			public:
				SymbolDefinition(CommonHeader header, string name, int flags, Point3d low, Point3d high);
				SymbolDefinition(const SymbolDefinition& shape);
				virtual ~SymbolDefinition() {}

				virtual void assignId(SvgElement& element) {}
				virtual bool isSymbolDefinition() { return true; }
				string getName() { return m_name; }
				
				float getWidth() { return m_high.getX() - m_low.getX(); }
				float getHeight() { return m_high.getY() - m_low.getY(); }
				
				Point3d getLow() { return m_low; }
				Point3d getHigh() { return m_high; }
				
				static string createSymbolName(string name);
				static Shape* from(CommonHeader header, SYMDEF* symdef);
			};
	}
}

#endif