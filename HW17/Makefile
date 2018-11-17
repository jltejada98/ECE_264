TARGET = hw17
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
CC = $(GCC) $(CFLAGS)

SRCS = main.c bst.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --log-file

TESTFLAGS = -DTEST_MAIN  -DTEST_CREATEBST -DTEST_DIST -DTEST_PRINT

$(TARGET): $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o $(TARGET)

.c.o:
	$(CC) $(TESTFLAGS) -c $*.c

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind1.log ./$(TARGET) inputs/test1.txt > output1
	$(VALGRIND)=./valgrind2.log ./$(TARGET) inputs/test2.txt > output2
	$(VALGRIND)=./valgrind3.log ./$(TARGET) inputs/test3.txt > output3
	$(VALGRIND)=./valgrind4.log ./$(TARGET) inputs/test4.txt > output4
	$(VALGRIND)=./valgrind5.log ./$(TARGET) inputs/test5.txt > output5
	$(VALGRIND)=./valgrind6.log ./$(TARGET) inputs/test6.txt > output6

#Added rule to test all files.
testall: test1 test2 test3 test4 test5 test6 test7

test1: $(TARGET)
	./$(TARGET) inputs/test1.txt > output1
	diff output1 expected/expected1.txt

test2: $(TARGET)
	./$(TARGET) inputs/test2.txt  > output2
	diff output2 expected/expected2.txt

test3: $(TARGET)
	./$(TARGET) inputs/test3.txt > output3
	diff output3 expected/expected3.txt

test4: $(TARGET)
	./$(TARGET) inputs/test4.txt > output4
	diff output4 expected/expected4.txt

test5: $(TARGET)
	./$(TARGET) inputs/test5.txt > output5
	diff output5 expected/expected5.txt

test6: $(TARGET)
	./$(TARGET) inputs/test6.txt > output6
	diff output6 expected/expected6.txt

test7: $(TARGET)
	./$(TARGET) inputs/test7.txt > output7
	diff output7 expected/expected7.txt

clean:
	rm -f $(OBJS) $(TARGET) valgrind?.log output?
