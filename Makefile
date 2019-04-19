include config.mk

floattexter: main.c config.h
	$(CC) $(CFLAGS) -o floattexter main.c

install: floattexter
	install floattexter $(BINDIR)/floattexter

clean:
	rm -f floattexter

.PHONY: install clean
