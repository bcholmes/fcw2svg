#ifndef __STRINGSANITIZER_H
#define __STRINGSANITIZER_H

#include <string>

using std::string;

namespace bcholmes {
	namespace fcw2svg {

		class StringSanitizer {
			private:
				StringSanitizer() {}
			public:
				~StringSanitizer() {}

				static string sanitize(string name);
			};
	}
}

#endif