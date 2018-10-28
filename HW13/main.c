/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw13.h"

/****************** DO NOT Modify this file above this line *************************/

// Modify the following function
//#ifdef TEST_MAIN

int main(int argc, char **argv)
{
	// if argc is less than 2 then, return EXIT_FAILURE
  if (argc < 2)
  {
    return EXIT_FAILURE;
  }

	// input file is specified through the Makefile.
	// open file to read
  FILE *file_pointer;
  char *file_name = argv[1];
  file_pointer = fopen(file_name, "r");

	// check for fopen fail. If so, return EXIT_FAILURE
  if (file_pointer == NULL)
  {
    return EXIT_FAILURE;
  }
	
	// count the number of integers in the file.
  int number_integers = 0;
  int value = 0;

  while(fscanf(file_pointer, "%d", &value) == 1)
  {
    ++number_integers;
  }

	// allocate memory to store the numbers
  int * integer_array = malloc(sizeof(int) * number_integers);
	// check for malloc fail, if so, return EXIT_FAILURE
  if (integer_array == NULL)
  {
    fclose(file_pointer);
    return EXIT_FAILURE;
  }
	
  //Return to begging of file
  fseek (file_pointer, 0, SEEK_SET);

	// use fscanf to read the file, and store its contents into an integer_array.
  fseek (file_pointer, 0, SEEK_SET);
  int index = 0;

  while (index < number_integers)
  {
    if (fscanf(file_pointer, "%d", & integer_array[index]) != 1)
    {
      fclose (file_pointer);
      free (integer_array);
      return EXIT_FAILURE;
    }
    index ++;
  }

  fclose(file_pointer);

	// create head node to store the head of the linked list.
  Node * head_node = NULL;
  head_node = malloc(sizeof(Node));
  //Check Memory allocation failure
  if (head_node == NULL)
  {
    return EXIT_FAILURE;
  }

  head_node->value = integer_array[0]; //Assign initial value to be first integer.
  head_node->next = NULL; //Assigns the next value to be null.

	// call the appropriate function to create the rest of the linked list, with the values of the integer_array.
  LinkedListCreate(&head_node, number_integers,integer_array);
	// Divide is a function to break the lists into smaller sublists.
		// You are supposed to find the mid-point of the list, and then break the list into two lists.
		// Then the sub-lists are broken down further into smaller sub-lists.
		// Refer to the example in the README
  Divide(&head_node);


	// Tip: check for memory errors.
  free(head_node);
	return EXIT_SUCCESS;
}

#endif
