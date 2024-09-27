# compiler flags.  -g for debug, -O3 for optimization

CFLAGS=-g -O3

all: tokenizer
	cc -o tokenizer $(CFLAGS) $(OBJS)

# headers: history.h, tokenizer.h
# files: tester.c, uimain.c, uimain.o

# Include file dependencis

tokenizer: uimain.o
	cc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o tokenizer

#run:tokenizer
#	./tokenizer
