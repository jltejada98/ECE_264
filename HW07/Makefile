# ***
# *** Makefile Created by Jose Luis Tejada
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 
VAL = valgrind --tool=memcheck --leak-check=full --verbose

TESTFALGS = -DTEST_MERGE -DTEST_MERGESORT -DTEST_MERGESSORT

SRCS = main.c
OBJS = $(SRCS:%.c=%.o)

hw07: $(OBJS) 
	$(GCC) $(TESTFALGS) $(OBJS) -o hw07

#Added Rule to test all files
testall: test1 test2 test3
	
testmemory: $(TARGET)# Test memory leaks for all inputs and outputs
	$(VAL) --log-file=memcheck1.txt ./hw07 input/Test1 output1
	$(VAL) --log-file=memcheck2.txt ./hw07 input/Test2 output2
	$(VAL) --log-file=memcheck3.txt ./hw07 input/Test3 output3

.c.o: 
	$(GCC) $(TESTFALGS) -c $*.c 

test1: hw07 #run diff between output1.bin and expected/expected1.bin
	./hw07 input/Test1 output1
	diff output1 expected/expected1

test2: hw07 #run diff between output2.bin and expected/expected2.bin
	./hw07 input/Test2 output2
	diff output2 expected/expected2
	
test3: hw07 #run diff between output3.bin and expected/expected3.bin
	./hw07 input/Test3 output3
	diff output3 expected/expected3
	 
clean: # remove all machine generated files (Check for output file extension)
	rm -f hw07 *.o memcheck?.txt output?
