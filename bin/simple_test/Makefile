TARGET=simple_test

CC?=cc
CPPFLAGS+=-I../../include
CFLAGS?=-O2 -march=native
LDFLAGS+=-L../../lib/libbsd_auth
LIBS=-lbsd_auth

all: ${TARGET}

${TARGET}: ${TARGET}.o
	${CC} ${LDFLAGS} -o $@ $> ${LIBS}

.c.o:
	${CC} -c ${CPPFLAGS} ${CFLAGS} -o $@ $<

install:; @true
deinstall:; @true

clean:
	rm -f ${TARGET} ${TARGET}.core *.o

${TARGET}.o: ${TARGET}.c
