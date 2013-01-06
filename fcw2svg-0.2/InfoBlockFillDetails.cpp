#include <sstream>
#include "InfoBlockFillDetails.h"
#include "NumberUtil.h"

using namespace std;

namespace bcholmes {
	namespace fcw2svg {
	
		InfoBlock* InfoBlockFillDetails::from(FSTYIB* ptr) {
		
			InfoBlockFillDetails* result = new InfoBlockFillDetails(ptr->IType);
			int versionNumber = ptr->IBVer;
			
			FSTY* style = ptr->FS;
			while (style->RLen > 0) {

				char* details = ((char*) style) + style->dofst;
			
				if (style->fstype == FS_PAT) {
				
					PatternFillStyle* fill = new PatternFillStyle(style->fstype, 
						style->ID, style->fsname);
					result->m_styles.insert ( pair<short,FillStyle*>(style->ID,fill));
					
				} else if (style->fstype == FS_SYM) {
					SYMSTY* symsty = (SYMSTY*) details;
				
					SymbolFillStyle* fill = new SymbolFillStyle(style->fstype, 
						style->ID, style->fsname, symsty->symname);
					result->m_styles.insert ( pair<short,FillStyle*>(style->ID,fill));
				}
			
			
				char* temp = (char*) style;
				temp += style->RLen;
				style = (FSTY*) temp;
			}
		
			return result;
		}
	
	
		InfoBlockFillDetails::FillStyle* InfoBlockFillDetails::getStyle(short styleId) {
			 map<short,FillStyle*>::iterator i = m_styles.find(styleId);
			 return i == m_styles.end() ? NULL : i->second;
		}
		void InfoBlockFillDetails::SymbolFillStyle::doInitialization(SvgElement& defs, 
				SymbolResolver& symbolResolver, string color) {
			
			SymbolDefinition* definition = symbolResolver.findSymbol(m_symbolName);
			if (definition != NULL) {
			
				SvgElement pattern = defs.createElement("pattern");
				pattern.setAttribute("height", NumberUtil::formatFloat(definition->getHeight()));
				pattern.setAttribute("width", NumberUtil::formatFloat(definition->getWidth()));
				string id = getSvgId();
				pattern.setAttribute("id", id);
				pattern.setAttribute("patternUnits", "userSpaceOnUse");
	
				SvgElement use = pattern.createElement("use");
				string translate("translate(");
				translate += NumberUtil::formatFloat(-definition->getLow().getX()) + ","
					+ NumberUtil::formatFloat(definition->getHigh().getY()) + ")";
				use.setAttribute("transform", translate);
				use.setAttribute("xlink:href", string("#") + 
					SymbolDefinition::createSymbolName(definition->getName()));
				m_symbolResolved = true;
			}
			
		}

		Paint InfoBlockFillDetails::SymbolFillStyle::initialize(SvgElement& defs, 
				SymbolResolver& symbolResolver, string color) {
			FillStyle::initialize(defs, symbolResolver, color);
			return m_symbolResolved ? Paint(string("url(#") + getSvgId() + ")") : Paint("yellow");
		}
		
		
		string InfoBlockFillDetails::SymbolFillStyle::getSvgId() {
			std::stringstream result;
			result << "SymbolPattern-" << m_id << "-" << StringSanitizer::sanitize(getName());
			return result.str();
		}
		
		Paint InfoBlockFillDetails::PatternFillStyle::initialize(SvgElement& defs, 
				SymbolResolver& symbolResolver, string color) {
				
			if (m_id == 0) {
				return Paint("none");
			} else if (m_id == 1) {
				return Paint(color);
			} else {
				return Paint("yellow");
			}
		}
		
		string InfoBlockFillDetails::PatternFillStyle::createId(string color) {
			string colorHex = color[0] == '#' ? color.substr(1) : color;
			return string("BrushPattern-") + StringSanitizer::sanitize(getName()) + "-" 
				+ NumberUtil::formatInt(m_id) + "-color-" + colorHex;
		}
		
	}
}