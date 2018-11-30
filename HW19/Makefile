TARGET = hw19
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
GCC = gcc $(CFLAGS)

SRCS = main.c hw19.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --log-file

TESTFLAGS = -DTEST_MAIN -DTEST_CREATENODE -DTEST_LINKEDLISTCREATE -DTEST_DIST -DTEST_CENT -DTEST_FUSE -DTEST_CLUSTER

$(TARGET): $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o $(TARGET)

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind1.log ./$(TARGET) inputs/test1.txt > output1
	$(VALGRIND)=./valgrind2.log ./$(TARGET) inputs/test2.txt > output2
	$(VALGRIND)=./valgrind3.log ./$(TARGET) inputs/test3.txt > output3
	$(VALGRIND)=./valgrind4.log ./$(TARGET) inputs/test4.txt > output4
	$(VALGRIND)=./valgrind5.log ./$(TARGET) inputs/test5.txt > output5
	$(VALGRIND)=./valgrind6.log ./$(TARGET) inputs/test6.txt > output6
	$(VALGRIND)=./valgrind7.log ./$(TARGET) inputs/test7.txt > output7
	$(VALGRIND)=./valgrind8.log ./$(TARGET) inputs/test8.txt > output8
	$(VALGRIND)=./valgrind9.log ./$(TARGET) inputs/test9.txt > output9
	$(VALGRIND)=./valgrind10.log ./$(TARGET) inputs/test10.txt > output10

#Added rule to test all files.
testall: test1 test2 test3 test4 test5 test6 test7 test8 test9 test10

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

test8: $(TARGET)
	./$(TARGET) inputs/test8.txt > output8
	diff output8 expected/expected8.txt

test9: $(TARGET)
	./$(TARGET) inputs/test9.txt > output9
	diff output9 expected/expected9.txt

test10: $(TARGET)
	./$(TARGET) inputs/test10.txt > output10
	diff output10 expected/expected10.txt

clean:
	rm -f $(OBJS) $(TARGET) valgrind?.log valgrind1?.log output? output1?
