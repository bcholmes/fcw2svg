#ifndef __INFOBLOCK_H
#define __INFOBLOCK_H

namespace bcholmes {
	namespace fcw2svg {

		class InfoBlock {
			private:
				char m_type;
			public:
				InfoBlock(char itype) : m_type(itype) {}
				InfoBlock(const InfoBlock& block) : m_type(block.m_type) {}
				virtual ~InfoBlock() {}
				
				int getType() { return m_type; }

				static InfoBlock* from(void * ptr);
			};
	}
}

#endif