#include "MultiPoly.h"

namespace bcholmes {
	namespace fcw2svg {

		Shape* MultiPoly::from(CommonHeader header, MPOLY2* mpoly) {
			return new MultiPoly(header, mpoly->MFlags);
		}
		
		void MultiPoly::appendAsXml(SvgElement& parent, Drawing& drawing) {
			if (!m_sublist.empty()) {
				SvgElement child = parent.createElement("path");
				assignId(child);
				
				string d = getPathCoordinates(drawing);
				child.setAttribute("d", d);
				setStrokeAndFill(child, drawing);
				parent.appendChild(child);
			}
		}
		
		string MultiPoly::getPathCoordinates(Drawing& drawing) {
			string d = "";
			Point start = Point::origin();
			bool isFirstPath = true;
			vector<SubPath*> subpaths;
			assembleSubPaths(subpaths);
			
			for (int i = 0; i < subpaths.size(); i++) {
				SubPath* subPath = subpaths[i];

				for (int j = 0; j < subPath->getElements().size(); j++) {
					BasePath* basePath = subPath->getElements()[j];
					
					d += (" " + basePath->createPathNodes(start, drawing, isFirstPath));
					isFirstPath = false;
					start = basePath->getLastPoint();
					
				}
				delete subPath;
			}
			
			return d;
		}
		
		
		void MultiPoly::assembleSubPaths(vector<SubPath*>& subPaths) {
		
			for (int i = 0; i < m_sublist.size(); i++) {
				Shape* shape = m_sublist[i];
				if (shape->isBasePath()) {
					subPaths.push_back(new SubPath((BasePath*) shape));
				}
			}
			
			bool done = false;
			vector<SubPath*> revised;
			OrganizationPhase phase = INITIAL;
			
			while (!done) {

				revised.clear();
			
				int originalSize = subPaths.size();
				
				organize(phase, subPaths, revised);
				if (revised.size() == 1) {
					done = true;
				} else if (revised.size() == originalSize) {
					if (phase == INITIAL) {
						phase = REVERSE;
					} else {
						done = true;
					}
				}
				
			
				subPaths.clear();
				for (int i = 0; i < revised.size(); i++) { 
					subPaths.push_back(revised[i]);
				}
			}
		
		}
		
		void MultiPoly::organize(OrganizationPhase phase, vector<MultiPoly::SubPath*>& original,
			vector<MultiPoly::SubPath*>& revised) {

			while (!original.empty()) {
				MultiPoly::SubPath* current = original[0];
				original.erase(original.begin());
				bool joined = false;
				
				if (!current->isClosed()) {

					for (int i = 0; i < original.size(); i++) {
						SubPath* subPath = original[i];
						
						if (subPath->isClosed()) {
							// leave it alone
						} else if (current->getFirstPoint().isApproximatelyEqual(subPath->getLastPoint())) {
							subPath->join(current);
							joined = true;
							break;
						} else if (phase == REVERSE &&
								subPath->isReversible() &&
								current->getFirstPoint().isApproximatelyEqual(subPath->getFirstPoint())) {
							subPath->reverse();
							subPath->join(current);
							joined = true;
							break;
						} else if (phase == REVERSE &&
								current->isReversible() &&
								subPath->getLastPoint().isApproximatelyEqual(current->getLastPoint())) {
							current->reverse();
							subPath->join(current);
							joined = true;
							break;
						}
					}
				}

				if (joined) {
					delete current;
				} else {
					revised.push_back(current);
				}
			}
		}
	
		void MultiPoly::SubPath::reverse() {
			if (isReversible()) {
				vector<BasePath*> temp;
				for (int i = 0; i < m_elements.size(); i++) {
					temp.push_back(m_elements[i]);
				}
				m_elements.clear();
				for (int i = temp.size()-1; i >= 0; i--) {
					temp[i]->reverse();
					m_elements.push_back(temp[i]);
				}
			}
		}		
	}
}