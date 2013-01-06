#ifndef __FILENAMEUTIL_H
#define __FILENAMEUTIL_H

#include <string>

using std::string;

namespace bcholmes {
	namespace fcw2svg {

		class FilenameUtil {
			public:
				static string removeExtension(const string& filename) {
				
					int index = filename.find_last_of('.');
					if (index != string::npos) {
						return filename.substr(0, index);
					} else {
						return filename;
					}
				}
			};
	}
}

#endif