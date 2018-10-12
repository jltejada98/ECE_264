# ***
# *** Please modify this file as required
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 
VAL = valgrind --tool=memcheck --leak-check=full --verbose

TESTFALGS = -DTEST_MAIN -DTEST_COMP -DTEST_FILL -DTEST_WRITE -DTEST_COUNT

SRCS = main.c vector.c
OBJS = $(SRCS:%.c=%.o)
TARGET = hw06


hw06: $(OBJS) 
	$(GCC) $(TESTFALGS) $(OBJS) -o hw06
	
testmemory: $(TARGET) # Test memory leaks for all inputs and outputs
	$(VAL) --log-file=memcheck1.txt ./hw06 inputs/test1.bin output1.bin
	$(VAL) --log-file=memcheck2.txt ./hw06 inputs/test2.bin output2.bin
	$(VAL) --log-file=memcheck3.txt ./hw06 inputs/test3.bin output3.bin

#Added Rule to test all files
testall: test1 test2 test3

.c.o: 
	$(GCC) $(TESTFALGS) -c $*.c 

test1: hw06 #run diff between output1.bin and expected/expected1.bin
	./hw06 inputs/test1.bin output1.bin
	diff output1.bin expected/expected1.bin

test2: hw06 #run diff between output2.bin and expected/expected2.bin
	./hw06 inputs/test2.bin output2.bin
	diff output2.bin expected/expected2.bin
	
test3: hw06 #run diff between output3.bin and expected/expected3.bin
	./hw06 inputs/test3.bin output3.bin
	diff output3.bin expected/expected3.bin
	
clean: # remove all machine generated files (Check whether it is the proper way to remove bin and machine generated files.)
	rm -f hw06 *.o output?.bin memcheck?.txt