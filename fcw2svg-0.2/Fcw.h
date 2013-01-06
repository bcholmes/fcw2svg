#ifndef __FCW_H
#define __FCW_H

#include <string>
#include <stack>
#include <vector>

#include "Shape.h"
#include "InfoBlock.h"
#include "InfoBlockHeader.h"
#include "SymbolResolver.h"

using std::string;
using std::vector;
using std::stack;

namespace bcholmes {
	namespace fcw2svg {

		class Fcw :  public SymbolResolver {
			private:
				string m_fileName;
				string m_svgFileName;
				stack<vector<Shape*> *> m_stack;
				vector<Shape*> m_entities;
				InfoBlock* m_infoBlocks[18];
				
			public:
				class SymbolCoordinateSystem : public CoordinateSystem {
					public:
						SymbolCoordinateSystem() {}
						SymbolCoordinateSystem(const SymbolCoordinateSystem& other) {}
						virtual ~SymbolCoordinateSystem() {}
				
						virtual Point map(Point point) { return Point(point.getX(), -point.getY()); }
						virtual float mapX(float x) { return x; }
						virtual float mapY(float y) { return -y; }
				};
			
				class SvgCoordinateSystem : public CoordinateSystem {
					private:
						Point3d m_low;
						Point3d m_high;
					public:
						SvgCoordinateSystem(Point3d low, Point3d high) 
							: m_low(low), m_high(high) {}
						SvgCoordinateSystem(const SvgCoordinateSystem& other) 
							: m_low(other.m_low), m_high(other.m_high) {}
						virtual ~SvgCoordinateSystem() {}
				
						virtual Point map(Point point) { 
							return Point(mapX(point.getX()), mapY(point.getY())); 
						}
						virtual float mapX(float x) { return x - m_low.getX(); }
						virtual float mapY(float y) { return m_high.getY() - y; }
				};
			
				Fcw(string fileName, string svgFileName);
				~Fcw();

				void startSubList();
				void endSubList();

				void addEntity(void* entity);
				void addInfoBlock(void* infoBlock);
				
				InfoBlockHeader* getInfoBlockHeader() { return (InfoBlockHeader*) m_infoBlocks[IB_HDR]; }
				
				static int decodeBuffer(string file, string outputFile, size_t bsize, unsigned char * b);

				void toSvg();
				virtual SymbolDefinition* findSymbol(const string& name);
				Paint getFillStyle(SvgElement& defs, short fillStyle, string color); 
		};
	}
}

#endif