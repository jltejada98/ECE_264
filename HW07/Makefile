# ***
# *** Makefile Created by Jose Luis Tejada
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 
VAL = valgrind --tool=memcheck --leak-check=full --verbose

TESTFALGS = -DTEST_MERGE -DTEST_MERGESORT -DTEST_MERGESSORT -DTEST_RECURSIVESHUFFLE

SRCS = main.c
OBJS = $(SRCS:%.c=%.o)

hw07: $(OBJS) 
	$(GCC) $(TESTFALGS) $(OBJS) -o hw07

#Added Rule to test all files
testall: test1 test2 test3 test4
	
testmemory: $(TARGET) # Test memory leaks for all inputs and outputs
	$(VAL) --log-file=memcheck1.txt ./hw07 Input/Test1 Output1
	$(VAL) --log-file=memcheck2.txt ./hw07 Input/Test2 Output2
	$(VAL) --log-file=memcheck3.txt ./hw07 Input/Test3 Output3

.c.o: 
	$(GCC) $(TESTFALGS) -c $*.c 

test1: hw07 #run diff between output1 and expected/expected1
	./hw07 Input/Test1 Output1
	diff Output1 Expected/Expected1

test2: hw07 #run diff between output2 and expected/expected2
	./hw07 Input/Test2 Output2
	diff Output2 Expected/Expected2
	
test3: hw07 #run diff between output3 and expected/expected3
	./hw07 Input/Test3 Output3
	diff Output3 Expected/Expected3
	 
test4: hw07 #run diff between output4 and expected/expected4
	./hw07 Input/Test4 Output4
	diff Output4 Expected/Expected4

clean: # remove all machine generated files (Check for output file extension)
	rm -f hw07 *.o memcheck?.txt Output?
