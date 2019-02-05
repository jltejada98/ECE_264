TARGET = hw21
CFLAGS =  -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
GCC = gcc $(CFLAGS)

SRCS = main.c decode.c list.c tree.c utility.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --log-file

TESTFLAGS = -DTEST_READHEADER -DTEST_DECODE -DTEST_MERGELIST -DDO_NOT_MODIFY

$(TARGET): $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o $(TARGET)

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind1.log ./$(TARGET) input/input1.bin > output1.txt
	$(VALGRIND)=./valgrind2.log ./$(TARGET) input/input2.bin > output2.txt
	$(VALGRIND)=./valgrind3.log ./$(TARGET) input/input3.bin > output3.txt
	$(VALGRIND)=./valgrind4.log ./$(TARGET) input/input4.bin > output4.txt
	$(VALGRIND)=./valgrind5.log ./$(TARGET) input/input5.bin > output5.txt
	$(VALGRIND)=./valgrind6.log ./$(TARGET) input/input6.bin > output6.txt
	$(VALGRIND)=./valgrind7.log ./$(TARGET) input/input7.bin > output7.txt
	$(VALGRIND)=./valgrind8.log ./$(TARGET) input/input8.bin > output8.txt

#Added rule to test all files.
testall: test1 test2 test3 test4 test5 test6 test7 test8 

test1: $(TARGET)
	./$(TARGET) input/input1.bin > output1.txt
	diff -i -w output1.txt expected/expected1.txt

test2: $(TARGET)
	./$(TARGET) input/input2.bin  > output.txt2
	diff -i -w output2.txt expected/expected2.txt

test3: $(TARGET)
	./$(TARGET) input/input3.bin > output3.txt
	diff -i -w output3.txt expected/expected3.txt

test4: $(TARGET)
	./$(TARGET) input/input4.bin > output4.txt
	diff -i -w output4.txt expected/expected4.txt

test5: $(TARGET)
	./$(TARGET) input/input5.bin > output5.txt
	diff -i -w output5.txt expected/expected5.txt

test6: $(TARGET)
	./$(TARGET) input/input6.bin > output6.txt
	diff -i -w output6.txt expected/expected6.txt

test7: $(TARGET)
	./$(TARGET) input/input7.bin > output7.txt
	diff -i -w output7.txt expected/expected7.txt

test8: $(TARGET)
	./$(TARGET) input/input8.bin > output8.txt
	diff -i -w output8.txt expected/expected8.txt

clean:
	rm -f $(OBJS) $(TARGET) valgrind?.log output?.txt
