// ***
// *** Please modify this file, as indicated
// ***

#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "sort.h"


void printArray(int * arr, int size)
{
  int ind;
  for (ind = 0; ind < size; ind ++)
    {
      fprintf(stdout, "%d\n", arr[ind]);
    }
}



//============================ONLY EDIT BELOW THIS COMMENT============================//
#ifdef TEST_COMP
int comparator(const void *a, const void *b) 
{ 
  //type cast both the parameters to the type const int*) a: 
	//FOR EXAMPLE: const int* ia = (const int *) a;
	const int *constant_a = (const int *)a; //Cast to type const int*)
	const int *constant_b = (const int *)b; //Cast to type const int*)
  int return_value = 0;

  //if parameter2 > parameter1; return -1
  //if parameter2 == parameter1; return 0
  //if parameter2 < parameter1; return 1

	if (constant_b > constant_a)
	{
		return_value =  -1;
	}
  else if (constant_b == constant_a)
  {
    return_value =  0;
  }
  else if (constant_b < constant_a)
  {
    return_value =  1;
  }

  return return_value;
} 
#endif


#ifdef TEST_COUNT
int countFromFile(char* file_name)
{
  FILE *file_pointer;
  int count = 0; //Counts number of integers in file using loop.
  
  // open file to read
  file_pointer = fopen(file_name, "r");

  // count the number of integers using a loop
  while(!feof(file_pointer))
  {
    ++count;
    printf("%d\n",count);
  }
  // at the end of the loop close file_pointer
  fclose(file_pointer);

  return count;
}
#endif

#ifdef TEST_FILL
void fillArray(int* arr, int count, char* file_name)
{
  FILE *file_pointer;
  int file_index = 0;
  // open file to read
  file_pointer = fopen(file_name, "r");

  //How to read the file?
	// run a loop, from index = 0 to "count", and use: fscanf(file_pointer, "%d", &arr[index]);
  for (file_index = 0; file_index < count; ++file_index)
  {
    fscanf(file_pointer, "%d", &arr[file_index]);
  }

  // at the end of the loop close file_pointer
  fclose(file_pointer);
  return;
}
#endif

#ifdef TEST_MAIN
int main(int argc, char * * argv)
{
  FILE *file_pointer; //Pointer to file header.
  char *file_name = argv[1]; //Stores file name.
  int number_elements = 0; //Stores number of elements in file.

  // use argv[1] to save the file name, you will use this file name to call the countFromFile(), and fillArray() functions
  //FOR EXAMPLE: char* file_name = argv[1];
  file_pointer = fopen(file_name,"r"); //Opens file.

  // input file will be specified from the terminal - test files are made available in inputs folder
  // check for missing input file, if so, "return EXIT_FAILURE;
  if(file_pointer == NULL)
  {
    return EXIT_FAILURE;
  }
  
  // call the countFromFile(file_name); and store the number of elements in the file.
  number_elements = countFromFile(file_name);

  // allocate memory to store the numbers (initialize an array)
  int *array = malloc(number_elements * sizeof(int));

  // check for malloc fail, if so, "return EXIT_FAILURE;"
  if (array == NULL)
  {
    return EXIT_FAILURE;
  }
  // call the fillArray(arr, count, file_name); and store the values from the file in the array.
  fillArray(array,number_elements,file_name);
  
  // Use qsort() function, after defining the comparator() function - "qsort (arr, count, sizeof(int), comparator);"
  qsort(array, number_elements, sizeof(int),comparator);

  // call the printArray() function provided to you.
  printArray(array, number_elements);

  fclose(file_pointer);

  return EXIT_SUCCESS;
}
#endif

