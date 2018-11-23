// Edit this file as required
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw18.h"


//#ifdef TEST_MAIN
int main(int argc, char * * argv)
{
	// check for input error
  if (argc < 2)
  {
    return EXIT_FAILURE;
  }

	// open the file
  // input file is in argv[1]
  FILE *fptr = fopen (argv[1], "r");

  if (fptr == NULL)
  {
    return EXIT_FAILURE;
  }

  // n is the first element in the file
  int number_elements = 0;
  fscanf(fptr, "%d", &number_elements);

	// dim is the second element in the file
  int number_dimensions = 0;
  fscanf(fptr, "%d", &number_dimensions);

	// the rest of the data in the file are the datapoints.
  ListNode *list_head;

	// call LinkedListCreate
  LinkedListCreate(&list_head, number_elements, number_dimensions, fptr);

	// call FindMin
  FindMin(list_head);

  //Remember to free memory.

}
#endif
