#ifndef __PAINT_H
#define __PAINT_H

#include <string>

using std::string;

namespace bcholmes {
	namespace fcw2svg {

		class Paint {
			private:
				string m_fillStyle;
			public:
				Paint(string fillStyle) : m_fillStyle(fillStyle) {}
				Paint(const Paint& other) : m_fillStyle(other.m_fillStyle) {}
				virtual ~Paint() {}

				string toSvgReference() { return m_fillStyle; }
		};
	}
}

#endif