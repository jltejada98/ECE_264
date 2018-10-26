/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw12.h"



/****************** DO NOT Modify this file above this line *************************/

// Modify the following function
#ifdef TEST_MAIN

int main(int argc, char **argv)
{
	// if argc < 4 then return EXIT_FAILURE
  if (argc < 4)
  {
    return EXIT_FAILURE;
  }

	// argv[1] - length of linked list
  int linked_list_length = strtol(argv[1], NULL, 10);
	// argv[2] - value of k as mentioned in josephus algorithm
  int k = strtol(argv[2], NULL, 10);
	// argv[3] - value of elemDivisible
  int elemDivisible = strtol(argv[3], NULL, 10);
	
  // create head node
  Node * head_node = NULL;
  head_node = malloc(sizeof(Node));
  //Check Memory allocation failure
  if (head_node == NULL)
  {
    return EXIT_FAILURE;
  }

  //Initializes the begging of the list.
  head_node->value = 0; //Assigns the initial value to be 0.
  head_node->next = NULL; //Assigns the next value to be null.

	// create Linked list with length as argv[1]
	LinkedListCreate(&head_node, linked_list_length);

  // run josephus
	Josephus(&head_node, k, elemDivisible);


  // free the head node
	free(head_node);
  return EXIT_SUCCESS;
}

#endif
