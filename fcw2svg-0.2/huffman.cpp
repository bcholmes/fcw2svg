#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "huffman.h"

#define BRANCH_NODE(a, b, c) {1, b, c, 0},
#define LEAF_NODE(a, b) { 0, 0, 0, b },

  struct Decode {
    int branch, left, right, value;
  };   

struct Decode tree1[] = {
  #include "treedef.1"
};

struct Decode tree2[] = {
  #include "treedef.2"
};


int GetBit(Huff *h)
{
  if (h->offset >= h->size)
    return -1;
  int res = h->in[h->offset] >> h->bit;
  res &= 0x01;
#ifdef DebugHuff
  printf(".%d", res);
#endif
  h->bit++;
  if (h->bit == 8)
    {
      h->bit = 0;
      h->offset++;
    }
  return res;
}

int GetNBits(Huff *h, int n)
{
  int res = 0;
  for (int i = 0; i < n; i++)
    res |= GetBit(h) << i;
  return res;
}

unsigned char GetByte(Huff *h)
{
  unsigned char res = ((GetBit(h) << 0) |
		       (GetBit(h) << 1) |
		       (GetBit(h) << 2) |
		       (GetBit(h) << 3) |
		       (GetBit(h) << 4) |
		       (GetBit(h) << 5) |
		       (GetBit(h) << 6) |
		       (GetBit(h) << 7));
  return res;
}


int HuffDecode(Huff *h, struct Decode* d, int node)
{
  if (d[node].branch == 0)
    return d[node].value;
  int bit = GetBit(h);
  return HuffDecode(h, d, bit ? d[node].right : d[node].left);
}

/* ----------------------------------------------------------------------
--
-- HuffDecodeBuffer
--
---------------------------------------------------------------------- */
Huff * Huff::HuffDecodeBuffer(size_t size, unsigned char *inbuf)
{
  int M[256];

//  int p1 = inbuf[0];
  int p2 = inbuf[1];

  M[0] = 7;
  for (int k = 1; k < 256; k++)
    M[k] = M[k-1] + (1 << (k-1));

  Huff *huff = new Huff();
  huff->in = inbuf + 2;
  huff->size = size - 2;

  huff->outmax = 4096;
  huff->out = (unsigned char*) calloc(1, huff->outmax);

  int encoded;
  while (((encoded = GetBit(huff)) >= 0))
    {
//      int byte = huff->offset;
//      int bit = huff->bit;
      if (encoded)
	{
	  int len;
	  int l1 = HuffDecode(huff, tree1, 0);
	  if (l1 <= 7)
	    {
	      len = l1 + 2;
	    }
	  else
	    {
	      int l2 = GetNBits(huff, l1 - 7);
	      len = l2 + M[l1 - 7] + 2;
	    }


	  int d1 = HuffDecode(huff, tree2, 0);
	  int d2;

	  if (len == 2)
	    {
	      d1 <<= 2;
	      d2 = GetNBits(huff, 2);
	    }
	  else
	    {
	      d1 <<= p2;
	      d2 = GetNBits(huff, p2);
	    }

	  int dist = (d1 | d2) + 1;
	  int j;
	  if (huff->outoffset + len >= huff->outmax)
	    {
	      huff->outmax += 4096;
	      huff->out = (unsigned char*) realloc(huff->out, huff->outmax);
	      assert(huff->out);
	    }
	  for (j = 0; j < len; j++)
	    huff->out[huff->outoffset + j] = huff->out[huff->outoffset - dist + j];
	  huff->outoffset += j;
	}
      else
	{
	  if (huff->outoffset >= huff->outmax)
	    {
	      huff->outmax += 4096;
	      huff->out = (unsigned char*) realloc(huff->out, huff->outmax);
	      assert(huff->out);
	    }
	  huff->out[huff->outoffset] = GetByte(huff);
#ifdef DebugHuff
	  printf("@%04x/%d %02hhx Plain byte @ %04x %02hhx\n", byte, bit, huff->in[byte],
		 huff->outoffset, huff->out[huff->outoffset]);
#endif
	  huff->outoffset++;		 
	}
    }
    
	return huff;
}
