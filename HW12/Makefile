TARGET = hw12
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
CC = $(GCC) $(CFLAGS)

SRCS = main.c hw12.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --log-file

TESTFLAGS = -DLINKEDLIST -DTEST_MAIN -DTEST_CREATENODE -DTEST_LINKEDLISTCREATE -DTEST_JOSEPHUS

$(TARGET): $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o $(TARGET)

.c.o:
	$(CC) $(TESTFLAGS) -c $*.c

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind1.log ./hw12 10 3 1 > output1
	$(VALGRIND)=./valgrind2.log ./hw12 10 4 2 > output2
	$(VALGRIND)=./valgrind3.log ./hw12 8 5 3 > output3
	$(VALGRIND)=./valgrind4.log ./hw12 8 9 1 > output4
	$(VALGRIND)=./valgrind5.log ./hw12 41 3 1 > output5
	$(VALGRIND)=./valgrind6.log ./hw12 100 3 20 > output6

#Added rule to test all files.
testall: test1 test2 test3 test4 test5 test6

test1: $(TARGET)
	./$(TARGET) 10 3 1 > output1
	diff output1 expected/expected1.txt

test2: $(TARGET)
	./$(TARGET) 10 4 2 > output2
	diff output2 expected/expected2.txt

test3: $(TARGET)
	./$(TARGET) 8 5 3 > output3
	diff output3 expected/expected3.txt

test4: $(TARGET)
	./$(TARGET) 8 9 1 > output4
	diff output4 expected/expected4.txt

test5: $(TARGET)
	./$(TARGET) 41 3 1 > output5
	diff output5 expected/expected5.txt

test6: $(TARGET)
	./$(TARGET) 100 3 20 > output6
	diff output6 expected/expected6.txt

clean:
	rm -f $(OBJS) $(TARGET) valgrind?.log output? 
