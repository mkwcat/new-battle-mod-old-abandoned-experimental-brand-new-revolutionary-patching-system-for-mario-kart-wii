CC	= clang
COPTS	= -O4 -I.
CLIBS	=

all: lzx.c
	$(CC) $(COPTS) -o ../../win32/lzx.exe lzx.c $(CLIBS) -Wno-deprecated-declarations

clean:
	rm -f ../../win32/lzx.exe
