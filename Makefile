CC      ?= gcc
CFLAGS  ?= -std=c89 -pedantic -Wall -Wextra
LDFLAGS ?=
LIBS    ?= -lkernel32 -luser32
PREFIX  ?= /usr/local

all: getclipboard setclipboard

getclipboard: getclipboard.c
	$(CC) $(CFLAGS) $? -o $@ $(LDFLAGS) $(LIBS)

setclipboard: setclipboard.c
	$(CC) $(CFLAGS) $? -o $@ $(LDFLAGS) $(LIBS)


install: install-getclipboard install-setclipboard

install-getclipboard: getclipboard
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp $< $(DESTDIR)$(PREFIX)/bin/

install-setclipboard: setclipboard
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp $< $(DESTDIR)$(PREFIX)/bin/

clean:
	rm -f setclipboard getclipboard

.PHONY: clean install install-getclipboard install-setclipboard

