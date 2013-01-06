#include <iostream>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
using namespace std;

#include "Point.h"
#include "huffman.h"
#include "Fcw.h"
#include "FilenameUtil.h"

using bcholmes::fcw2svg::Fcw;
using bcholmes::fcw2svg::FilenameUtil;

int DecodeFile(char *file, int dump) {
  size_t bsize = 0;
  void *decodebuf = NULL;

  struct stat statbuf;
  int res = 0;
  if (stat(file, &statbuf) != 0)
    {
      fprintf(stderr, "Cannot stat %s: %s\n", file, strerror(errno));
      exit(1);
    }

  FILE *stream = fopen(file, "rb");
  if (stream == NULL)
    {
      fprintf(stderr, "Failed to open file %s: %s\n", file, strerror(errno));
      exit(1);
    }

  unsigned char header[128];
  fseek(stream, 0, SEEK_SET);
  fread(header, 128, 1, stream);


  size_t fsize = statbuf.st_size;
  unsigned char *inbuf = (unsigned char *) malloc(fsize - 128);
  fseek(stream, 128, SEEK_SET);
  fread(inbuf, fsize - 128, 1, stream);
  fclose(stream);
 
 if (header[48])
    {
      printf("Compressed\n");

      Huff *huff = Huff::HuffDecodeBuffer(fsize - 128, inbuf);

      bsize = huff->outoffset;
      decodebuf = calloc(1, bsize);
      memcpy(decodebuf, huff->out, bsize);
      free(huff->out);
      delete huff;
      free(inbuf);
    }
  else
    {
      printf("Uncompressed\n");
      bsize = fsize - 128;
      decodebuf = calloc(1, bsize);
      memcpy(decodebuf, inbuf, bsize);
      free(inbuf);
    }
    
	if (bsize && decodebuf) {
		string fileName(file);
		string svgFileName = FilenameUtil::removeExtension(fileName) + ".svg";
		res = Fcw::decodeBuffer(fileName, svgFileName, bsize, (unsigned char*) decodebuf);
		free(decodebuf);
	}
	return res;
}

int main(int argc, char** argv) {

	int ch;
	int dump = 0;

	while ((ch = getopt(argc, argv, "d")) != EOF)
    	switch(ch)
      	{
      		case 'd':
			dump = 1;
			break;
      	}

	if (optind >= argc)
   	{
   		fprintf(stdout, "%s: [filename]\n", argv[0]);
	} else {
		DecodeFile(argv[optind], dump);
	}
	
	return 0;
}