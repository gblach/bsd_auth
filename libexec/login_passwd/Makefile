TARGET=login_passwd

CC?=cc
CPPFLAGS+=-I../../include -DPASSWD
CFLAGS?=-O2 -march=native
LDFLAGS+=-L../../lib/libbsd_auth
LIBS=-lbsd_auth -lcrypt

all: ${TARGET}

${TARGET}: login.o login_passwd.o
	${CC} ${LDFLAGS} -o $@ $> ${LIBS}

.c.o:
	${CC} -c ${CPPFLAGS} ${CFLAGS} -o $@ $<

install: ${TARGET}
	install -m 4755 ${TARGET} /usr/libexec
	gzip -k9f ${TARGET}.8
	mv ${TARGET}.8.gz /usr/share/man/man8

deinstall:
	rm -f /usr/libexec/${TARGET}
	rm -f /usr/share/man/man8/${TARGET}.8.gz

clean:
	rm -f ${TARGET} *.o

login.o: login.c ../../openbsd-compat/openbsd-compat.h
login_passwd.o: login_passwd.c
