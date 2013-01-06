#include "StringSanitizer.h"

namespace bcholmes {
	namespace fcw2svg {

		string StringSanitizer::sanitize(string name) {
			string alphanumeric("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz_-0123456789");
			string result;
			for (int i = 0; i < name.length(); i++) {
				char c = name[i];
				if (alphanumeric.find(c) != string::npos) {
					result += c;
				} else {
					result += "_";
				}
			}
			return result;
		}
	}
}

