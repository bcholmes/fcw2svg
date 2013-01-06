#ifndef __SYMBOLRESOLVER_H
#define __SYMBOLRESOLVER_H

#include <string>
#include "SymbolDefinition.h"

using std::string;

namespace bcholmes {
	namespace fcw2svg {

		class SymbolResolver {
			public:
				SymbolResolver() {}
				~SymbolResolver() {}

				virtual SymbolDefinition* findSymbol(const string& name) = 0;
			};
	}
}

#endif