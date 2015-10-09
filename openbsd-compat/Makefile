TARGET=openbsd-compat.o

CC?=cc
CPPFLAGS+=
CFLAGS?=-O2 -march=native
CFLAGS+=-fPIC

all: ${TARGET}

.c.o:
	${CC} -c ${CPPFLAGS} ${CFLAGS} -o $@ $<

install:; @true
deinstall:; @true

clean:
	rm -f *.o

openbsd-compat.o: openbsd-compat.c openbsd-compat.h
