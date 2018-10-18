TARGET = hw11
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
CC = $(GCC) $(CFLAGS)

SRCS = hw11.c bmpfunc.c bmpimage.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --leak-check=full --log-file

TESTFLAGS = -DTEST_MAIN -DTEST_HEADERVALID -DTEST_BMPOPENFILE -DTEST_WRITEFUNC -DTEST_BMPFREEFUNC -DTEST_FUNCGIVEN -DTEST_IMGTOGRAY -DTEST_ADAPTIVETHRESHOLDING

$(TARGET): $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o $(TARGET)

.c.o:
	$(CC) $(TESTFLAGS) -c $*.c

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind1.log ./hw11 exampleImages/RV.bmp output1.bmp 5 2
	$(VALGRIND)=./valgrind2.log ./hw11 exampleImages/RV2.bmp output2.bmp 3 2
	$(VALGRIND)=./valgrind3.log ./hw11 exampleImages/CondProb.bmp output3.bmp 1 2 
	$(VALGRIND)=./valgrind4.log ./hw11 exampleImages/RV2Small.bmp output4.bmp 11 2

#Added rule to test all files.
testall: test1 test2 test3

test1: hw11
	./hw11 exampleImages/RV.bmp output1.bmp 5 2
	diff output1.bmp expectedImages/expectedRV.bmp

test2: hw11
	./hw11 exampleImages/RV2.bmp output2.bmp 3 2
	diff output2.bmp expectedImages/expectedRV2.bmp

test3: hw11
	./hw11 exampleImages/CondProb.bmp output3.bmp 1 2
	diff output3.bmp expectedImages/expectedCondProb.bmp

test4: hw11
	./hw11 exampleImages/RV2Small.bmp output4.bmp 11 2
	diff output4.bmp expectedImages/expectedRV2Small.bmp

clean:
	rm -f $(OBJS) $(TARGET) valgrind?.log header.imagesize output?.bmp 
