CFLAGS=-g -O3

all: ui

uimain.o: tokenizer.h
token.o: tokenizer.h
tokenize.o: tokenizer.h

ui: uimain.o token.o tokenize.o
	cc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o ui
