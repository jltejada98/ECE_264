/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw15.h"

/****************** DO NOT Modify this file above this line *************************/

// Modify the following function
#ifdef TEST_MAIN

int main(int argc, char **argv)
{
	// Check for the right number of input arguments. 
  if (argc <= 1)
  {
    return EXIT_FAILURE;
  }
  // input argv[1] contains the name of the input file.
  FILE *fptr =  fopen(argv[1], "r");

  if (fptr == NULL)
  {
    return EXIT_FAILURE;
  }

	//Initialize a linked list Node and use the file name from input arguments to create a linked list
	int head_value;
  fscanf(fptr, "%d", &head_value); //Determines the first value of input file.

  //Allocates memory for Node.
  Node *head_node = NULL;
  head_node = malloc(sizeof(Node));

  if (head_node == NULL)
  {
    return EXIT_FAILURE;
  }

  head_node->value = head_value;
  head_node->next = NULL;

  LinkedListCreate(&head_node, argv[1]);

  fclose(fptr);

  //Remove all duplicates in the linked list created above.
  RemoveDuplicate(head_node);

  //Print List with no duplicate elements.
  LinkedListPrint(head_node);

	// release memory
  Node *temp_node;
  //Code Taken from ListDestroy() in Intermediate C Programming Textbook.
  while(head_node != NULL)
  {
    temp_node = head_node->next;
    free(head_node);
    head_node = temp_node;
  }
}

#endif
