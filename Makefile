include config.mk

floattexter: main.c config.h
	$(CC) $(CFLAGS) -o floattexter main.c

install: floattexter
	cp ./floattexter $(PREFIX)/bin/floattexter

clean:
	rm -fv floattexter
