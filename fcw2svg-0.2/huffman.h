#include <stdint.h>

class Huff {
	public:
		int32_t outoffset, outmax;
		unsigned char *in;
		int offset;
		int bit;
		int size;
		unsigned char *out;

		static Huff * HuffDecodeBuffer(size_t size, unsigned char *inbuf);
		
};



