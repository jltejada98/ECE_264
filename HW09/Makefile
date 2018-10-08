TARGET = shuf
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
CC = $(GCC) $(CFLAGS)

SRCS = main.c utility.c shuffle.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --log-file

TESTFLAGS = -DTEST_MAIN -DTEST_RSHUF -DTEST_SHUF -DTEST_DIV -DTEST_INTER

$(TARGET): $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o $(TARGET)

.c.o:
	$(CC) $(TESTFLAGS) -c $*.c

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind1.log ./shuf 2 2 output1
	$(VALGRIND)=./valgrind2.log ./shuf 4 3 output2
	$(VALGRIND)=./valgrind3.log ./shuf 7 2 output3

#Added rule to test all files.
testall: test1 test2 test3

test1: shuf
	./shuf 2 2 | sort > output1
	diff output1 expected/expected1

test2: shuf
	./shuf 4 3 | sort > output2
	diff output2 expected/expected2

test3: shuf
	./shuf 7 2 | sort > output3
	diff output3 expected/expected3

clean:
	rm -f $(OBJS) $(TARGET) valgrind?.log output? 
