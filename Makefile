CFLAGS = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror

test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/ds.c src/ds.c src/ds.h
	@echo Compiling $@
	@cc $(CFLAGS) src/ds.c test/ds.c test/vendor/unity.c -o tests.out
	
