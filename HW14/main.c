/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw14.h"


#ifdef LINKEDLIST
// Do not modify this function, we are using this within ifdef block for
// ease of grading.
void LinkedListPrint(Node * * source)
{

	Node *temp = * source;

	while(temp!=NULL)
	{
		if(temp->next!=NULL)
		{
			printf("%d,",temp->value);
		}
		else
		{
			printf("%d",temp->value);
		}
		temp=temp->next;
	}
	printf("\n");
}
#endif

/****************** DO NOT Modify this file above this line *************************/

// Modify the following function
#ifdef TEST_MAIN

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

	// use fscanf to read the file for its contents.
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

	// create head node, which corresponds to the head of the linked-list.
  Node * head_node = NULL;
  head_node = malloc(sizeof(Node));
  //Check Memory allocation failure
  if (head_node == NULL)
  {
    return EXIT_FAILURE;
  }
	
  head_node->value = integer_array[0]; //Assign initial value to be first integer.
  head_node->next = NULL; //Assigns the next value to be null.

	// You must now use the appropriate function to construct the remaining list.
  LinkedListCreate(&head_node, number_integers,integer_array);

	// call MergerSort() function for final output.
	// This will call a recursive function.
	// The input list will be divided into two sub-lists recursively,
	// Then the contents of the sub-lists are compared and merged back to form the
	// sorted output list.
  MergeSort(&head_node);
	// use the provided function to print the final list.
	LinkedListPrint(&head_node);
	// Tip: Check for memory errors.

	return EXIT_SUCCESS;
}

#endif
