TARGET = hw10
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
CC = $(GCC) $(CFLAGS)

SRCS = hw10.c bmpfunc.c bmpimage.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --leak-check=full --log-file

TESTFLAGS = -DTEST_MAINFUNC -DTEST_FUNCGIVEN -DTEST_IMGTOGRAY -DTEST_HEADERVALID -DTEST_BMPOPENFILE -DTEST_BMPWRITEFUNC -DTEST_BMPFREEFUNC 

$(TARGET): $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o $(TARGET)

.c.o:
	$(CC) $(TESTFLAGS) -c $*.c

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind1.log ./hw10 exampleImages/RV.bmp output1.bmp
	$(VALGRIND)=./valgrind2.log ./hw10 exampleImages/RV2.bmp output2.bmp
	$(VALGRIND)=./valgrind3.log ./hw10 exampleImages/CondProb.bmp output3.bmp
	$(VALGRIND)=./valgrind4.log ./hw10 exampleImages/RV2Small.bmp output4.bmp

#Added rule to test all files.
testall: test1 test2 test3

test1: hw10
	./hw10 exampleImages/RV.bmp output1.bmp
	diff output1.bmp expectedImages/expectedRV.bmp

test2: hw10
	./hw10 exampleImages/RV2.bmp output2.bmp
	diff output2.bmp expectedImages/expectedRV2.bmp

test3: hw10
	./hw10 exampleImages/CondProb.bmp output3.bmp
	diff output3.bmp expectedImages/expectedCondProb.bmp

test4: hw10
	./hw10 exampleImages/RV2Small.bmp output4.bmp
	diff output4.bmp expectedImages/expectedRV2Small.bmp

clean:
	rm -f $(OBJS) $(TARGET) valgrind?.log header.imagesize output?.bmp 
