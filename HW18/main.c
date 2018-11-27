// Edit this file as required
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw18.h"


#ifdef TEST_MAIN

//Function Declarations
void _helper_Destroy_Tree(TreeNode *tn);
void _helper_Destroy_LinkedList (ListNode *head_node);

void _helper_Destroy_LinkedList (ListNode *head_node)
{
  //Code Modified from HW15
  ListNode *temp_node;
  //Code Taken from ListDestroy() in Intermediate C Programming Textbook.
  while(head_node != NULL)
  {
    temp_node = head_node->next;
    _helper_Destroy_Tree(head_node->treenode);
    free(head_node);
    head_node = temp_node;
  }

  return;
}

void _helper_Destroy_Tree(TreeNode *tn)
{
  //Terminating Condition
  if (tn == NULL)
  {
    return;
  }
  _helper_Destroy_Tree(tn->left);
  _helper_Destroy_Tree(tn->right);
  free(tn->data);
  free(tn);

  return;
}


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

  ListNode *FindMin_list_head = list_head;
	// call FindMin
  FindMin(FindMin_list_head);

  //Remember to free memory.
  _helper_Destroy_LinkedList(list_head);
  //Close File Pointer
  fclose(fptr);

}
#endif
