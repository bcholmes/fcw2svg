#ifndef __INFOBLOCKFILLDETAILS_H
#define __INFOBLOCKFILLDETAILS_H

#include <map>
#include <string>
#include "CadApi.h"
#include "InfoBlock.h"
#include "Paint.h"
#include "SvgElement.h"
#include "SymbolResolver.h"
#include "StringSanitizer.h"

using namespace std;

namespace bcholmes {
	namespace fcw2svg {

		class InfoBlockFillDetails : public InfoBlock {
			public:
				InfoBlockFillDetails(char itype) 
					: InfoBlock(itype) {}
				virtual ~InfoBlockFillDetails() {
					map <short,FillStyle*>::iterator i;
					for (i = m_styles.begin(); i != m_styles.end(); i++) {
						delete (*i).second;
					}
				}

				static InfoBlock* from(FSTYIB* ptr);
				
				class FillStyle {
					protected:
						char m_type;
						short m_id;
						string m_name;
						bool m_initialized;
					public:
						FillStyle(char type, short id, string name) 
							: m_type(type), m_id(id), m_name(name), m_initialized(false) {}
						virtual ~FillStyle() {}
					
						virtual void doInitialization(SvgElement& defs, SymbolResolver& symbolResolver,
							string color) {}
						virtual Paint initialize(SvgElement& defs, SymbolResolver& symbolResolver,
							string color) {
							
							if (!m_initialized) {
								m_initialized = true;
								doInitialization(defs, symbolResolver, color);
							}
							return Paint("");
						}
						bool isPattern() { return m_type == FS_PAT; }
						bool isSymbol() { return m_type == FS_SYM; }
						
						string getName() { return m_name; }
				};
				
				
				class SymbolFillStyle : public FillStyle {
					private:
						bool m_symbolResolved;
						string m_symbolName;
						
					public:
						SymbolFillStyle(char type, short id, string name, string symbolName) 
							: FillStyle(type, id, name), m_symbolResolved(false), 
							  m_symbolName(symbolName) {}
						virtual ~SymbolFillStyle() {}
					
						virtual void doInitialization(SvgElement& defs, SymbolResolver& symbolResolver,
							string color);
						virtual Paint initialize(SvgElement& defs, SymbolResolver& symbolResolver,
							string color);
						virtual string getSvgId(); 
				};
				
				class PatternFillStyle : public FillStyle {

					public:
						PatternFillStyle(char type, short id, string name) 
							: FillStyle(type, id, name) {}
						virtual ~PatternFillStyle() {}
						
						virtual Paint initialize(SvgElement& defs, SymbolResolver& symbolResolver,
							string color);
						string createId(string color);
				};
				
				FillStyle* getStyle(short styleId);
				
			private:
				map<short, FillStyle*> m_styles;
		};
	}
}

#endif