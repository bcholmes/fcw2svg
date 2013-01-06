#include <stddef.h>
#include "InfoBlock.h"
#include "InfoBlockHeader.h"
#include "InfoBlockFillDetails.h"

namespace bcholmes {
	namespace fcw2svg {

		InfoBlock* InfoBlock::from(void* ptr) {
			IBHDR* header = (IBHDR*) ptr;
			switch (header->IType) {
				case IB_HDR:
					return InfoBlockHeader::from((HDR*) ptr);
				case IB_FSTYLE:
					return InfoBlockFillDetails::from((FSTYIB*) ptr);
				default:
					return NULL;
			}
		}
	}
}