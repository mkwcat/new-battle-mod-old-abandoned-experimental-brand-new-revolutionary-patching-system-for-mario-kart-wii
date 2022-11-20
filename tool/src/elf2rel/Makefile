CC	= clang
COPTS	= -O2 -I.
CLIBS	=

all: elf2rel.cpp elf2rel.h
	$(CC) $(COPTS) -o ../../win32/elf2rel.exe elf2rel.cpp $(CLIBS) -Wno-deprecated-declarations

clean:
	rm -f ../../win32/elf2rel.exe
