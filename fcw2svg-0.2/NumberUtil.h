#ifndef __NUMBERUTIL_H
#define __NUMBERUTIL_H

#include <stdio.h>
#include "CadApi.h"

namespace bcholmes {
	namespace fcw2svg {

		class NumberUtil {
	
			public:
				static string formatFloat(float f) {
					char buffer[50];
					sprintf(buffer, "%.2f", f);
					string result(buffer);
					return result;
				};
				static string formatInt(int i) {
					char buffer[50];
					sprintf(buffer, "%d", i);
					string result(buffer);
					return result;
				};
				
		};
	}
}

#endif