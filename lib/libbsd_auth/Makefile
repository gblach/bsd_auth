TARGET=libbsd_auth.so

CC?=cc
CPPFLAGS+=-I../../include
CFLAGS?=-O2 -march=native
CFLAGS+=-fPIC
LDFLAGS+=
LIBS=-lutil

all: ${TARGET}

${TARGET}: auth_subr.o authenticate.o ../../openbsd-compat/openbsd-compat.o
	${CC} -shared ${LDFLAGS} -o $@ $> ${LIBS}

.c.o:
	${CC} -c ${CPPFLAGS} ${CFLAGS} -o $@ $<

install: ${TARGET}
	install ${TARGET} /usr/lib
	gzip -k9f *.3
	mv *.3.gz /usr/share/man/man3

deinstall:
	rm -f /usr/lib/${TARGET}
	rm -f /usr/share/man/man3/auth_subr.3.gz
	rm -f /usr/share/man/man3/authenticate.3.gz

clean:
	rm -f *.so *.o

auth_subr.o: auth_subr.c ../../include/bsd_auth.h ../../openbsd-compat/openbsd-compat.h
authenticate.o: authenticate.c ../../include/bsd_auth.h ../../openbsd-compat/openbsd-compat.h
