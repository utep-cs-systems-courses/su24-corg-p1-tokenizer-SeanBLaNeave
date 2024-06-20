CFLAGS=-g -O3

all: ui

uimain.o: tokenizer.h history.h
token.o: tokenizer.h
tokenize.o: tokenizer.h
history.o: history.h

ui: uimain.o token.o tokenize.o history.o
	cc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o ui
