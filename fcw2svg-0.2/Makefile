#---

CFLAGS	= -g -std=c99 -I. `pkg-config --cflags glib-2.0` -D_GNU_SOURCE
LDLIBS	= `pkg-config --libs glib-2.0`


MYPROGRAM=fcw2svg
MYINCLUDES='/usr/include/libxml2'
CC=clang++
SOURCE=fcw2svg.cpp Point.cpp CommonHeader.cpp Shape.cpp PointShape.cpp Huffman.cpp ShapeFactory.cpp UnknownShape.cpp Group.cpp Arc.cpp
OBJS=fcw2svg.o Arc.o Point.o Fcw.o CommonHeader.o Shape.o PointShape.o huffman.o ShapeFactory.o \
UnknownShape.o Line.o SvgDocument.o BasePath.o SvgElement.o Group.o Drawing.o Circle.o Label.o \
Path.o EllipticalArc.o SymbolDefinition.o StringSanitizer.o InfoBlock.o SymbolReference.o \
MultiPoly.o tinyxml.o tinystr.o tinyxmlerror.o tinyxmlparser.o Sheet.o InfoBlockFillDetails.o \
Ellipse.o

all: fcw2svg

fcw2svg: $(OBJS)
	$(CC) -v -arch x86_64 -I$(MYINCLUDES)  -L '/usr/lib' -l 'stdc++' -l 'xml2' $(OBJS) -o fcw2svg 

.cpp.o:
	$(CC) -c -arch x86_64 -I$(MYINCLUDES) -Wall -o $*.o $*.cpp

clean:
	rm -f fcw2svg *.o
