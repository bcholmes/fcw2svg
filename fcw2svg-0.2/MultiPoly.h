#ifndef __MULTIPOLY_H
#define __MULTIPOLY_H

#include <vector>
#include "BasePath.h"
#include "Point.h"
#include "CadApi.h"
#include "Group.h"

using std::vector;

namespace bcholmes {
	namespace fcw2svg {

		enum OrganizationPhase { INITIAL, REVERSE };

		class MultiPoly : public Group {
			public:
				MultiPoly(CommonHeader header, short multiPolyFlags) : Group(header), m_multiPolyFlags(multiPolyFlags) {}
				MultiPoly(const MultiPoly& other) : Group(other), m_multiPolyFlags(other.m_multiPolyFlags) {}
				~MultiPoly() {}

				virtual void assignId(SvgElement& element) { element.setAttribute("id", "MultiPoly-" + NumberUtil::formatInt(m_header.getTag())); };
				void appendAsXml(SvgElement& parent, Drawing& drawing);
				string getPathCoordinates(Drawing& drawing);
				static Shape* from(CommonHeader header, MPOLY2* mpoly);
				
				class SubPath {
					private:
						vector<BasePath *> m_elements;
						bool m_closed;
					public:
						SubPath(BasePath* basePath) {
							m_elements.push_back(basePath);
							m_closed = basePath->isClosed();
						}
						
						Point getFirstPoint() { return m_elements[0]->getFirstPoint(); }
						Point getLastPoint() {return m_elements[m_elements.size()-1]->getLastPoint(); }
						bool isClosed() { return m_closed; }
						bool isReversible() {
							bool result = true;
							for (int i = 0; i < m_elements.size(); i++) {
								result &= m_elements[i]->isReversible();
							}
							return result;
						}
						vector<BasePath*>& getElements() { return m_elements; }
						void reverse();
						void join(SubPath* subPath) {
							for (int i = 0; i < subPath->m_elements.size(); i++) {
								m_elements.push_back(subPath->m_elements[i]);
							}
						}
						
				};
			private:
				short m_multiPolyFlags;
				void organize(OrganizationPhase phase, vector<MultiPoly::SubPath*>& original,
					vector<MultiPoly::SubPath*>& revised);
				void assembleSubPaths(vector<SubPath*>& subPaths);
		};
	}
}

#endif