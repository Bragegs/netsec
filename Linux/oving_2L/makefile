CC=gcc
CFLAGS=-O2 -march=native 
DEPS=fargeskrift.h 
DEPS2=fargeskrift.o

.PHONY: all clean install

.SUFFIXES:


all: fargedemo fargetest fargerikt

%.o: %.c $(DEPS)
	$(CC) -c $(CFLAGS) $< -o $@

%: %.o $(DEPS) $(DEPS2)
	$(CC) -o $@ $< $(DEPS2) 


clean:
	rm -f *.o fargedemo fargetest fargerikt

install: fargedemo fargetest fargerikt
	cp fargedemo fargetest fargerikt /usr/local/bin/
