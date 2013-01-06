#ifndef __INFOBLOCKHEADER_H
#define __INFOBLOCKHEADER_H

#include "CadApi.h"
#include "Point3d.h"

namespace bcholmes {
	namespace fcw2svg {

		class InfoBlockHeader : public InfoBlock {
			private:
				Point3d m_low;
				Point3d m_high;
			public:
				InfoBlockHeader(char itype, Point3d low, Point3d high) 
					: InfoBlock(itype), m_low(low), m_high(high) {}
				InfoBlockHeader(const InfoBlockHeader& block) 
					: InfoBlock(block), m_low(block.m_low), m_high(block.m_high) {}
				virtual ~InfoBlockHeader() {}

				static InfoBlock* from(HDR* ptr) {
					Point3d low = Point3d::from(ptr->Low);
					Point3d high = Point3d::from(ptr->High);
				
					return new InfoBlockHeader(ptr->IType, low, high);
				}
				
				Point3d getLow() { return m_low; }
				Point3d getHigh() { return m_high; }
				
				float getWidth() { return m_high.getX() - m_low.getX(); }
				float getHeight() { return m_high.getY() - m_low.getY(); }
		};
	}
}

#endif