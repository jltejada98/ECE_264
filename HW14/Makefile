TARGET = hw14
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
CC = $(GCC) $(CFLAGS)

SRCS = main.c hw14.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --log-file

TESTFLAGS = -DTEST_MAIN -DTEST_CREATENODE -DTEST_LINKEDLISTCREATE -DTEST_SPLIT -DTEST_MERGE -DTEST_SORT -DLINKEDLIST

$(TARGET): $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o $(TARGET)

.c.o:
	$(CC) $(TESTFLAGS) -c $*.c

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind1.log ./$(TARGET) inputs/test1.txt  > output1
	$(VALGRIND)=./valgrind2.log ./$(TARGET) inputs/test2.txt > output2

#Added rule to test all files.
testall: test1 test2

test1: $(TARGET)
	./$(TARGET) inputs/test1.txt > output1
	diff output1 expected/expected1.txt

test2: $(TARGET)
	./$(TARGET) inputs/test2.txt > output2
	diff output2 expected/expected2.txt

clean:
	rm -f $(OBJS) $(TARGET) valgrind?.log output? 
