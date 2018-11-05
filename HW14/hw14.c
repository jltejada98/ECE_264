/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw14.h"


/********** Do Not modify the file above this line, you can modify below ***********/
#include <math.h>

#ifdef TEST_CREATENODE

Node * CreateNode(int val)
//val: value of the element of the node to be created
{
	// same as previous homeworks
  // Define a new variable of type Node
  // Initialize "next", and "value" appropriately 
  //Extracted from HW12
  // allocate memory for the new Node*
  Node *new_node = NULL;
  new_node = malloc(sizeof(Node));

  // check memory allocation fails
  if (new_node == NULL)
  {
    return NULL;
  }
  new_node->value = val;
  new_node->next = NULL;

  return new_node;  //return the newNode
}
#endif

#ifdef TEST_LINKEDLISTCREATE
//source: the head of the singly linkedlist.
//len: the length of the array.
//arr: the array with the contents of the input file.

void LinkedListCreate(Node * * source, int len, int* arr)
{
	// Refer HW13 and HW12
	// Tip: use CreateNode(arr[index])
  // This function is similar to the one in HW12.
  //Extracted from HW12
  // check if length is not negative
  if (len <= 0) //Check if < or <=
  {
    return;
  }

  // create linked list of length as 'length'

  Node *temp_node = *source; //Temporary array to seek the end of linked list.

  for (int linked_index = 1; linked_index < len; ++linked_index) //Creates the appropriate nodes.
  {
    while((temp_node->next) != NULL) //Goes to End of Linked List (Should we reset head to )
    {
      temp_node = temp_node->next;
    }
    temp_node->next = CreateNode(arr[linked_index]); //Inserts new node at the end of list.
  }

  return; // do not return anything
  // Tip: use CreateNode(arr[index])
}
#endif


#ifdef TEST_SPLIT
// source is the head of the list to be split.
// head1 is the head of the upper sub-list.
// head2 is the head of the lower sub-list.

void SpiltList(Node* source, Node** head1, Node** head2)
{
	// Refer HW13
  //Extracted from HW13
  // Find the mid point of the list.
  int length_source = 0;
  Node *temp_node_1 = source;
  while((temp_node_1->next) != NULL) //Goes to End of Linked List (Should we reset head to )
  {
    temp_node_1 = temp_node_1->next;
    ++length_source;
  }

  int mid_point = 0;

  if (!(length_source % 2))
  {
    mid_point = floor(length_source/2);
  }
  else
  {
    mid_point = length_source/2;
  }
  //in case of an even number of nodes, mid point will be floor(<num_elements>/2)
  //Example: 1,2,3,4
  // The list should split into 1,2 and 3,4
  //in case of an odd number of nodes, mid point will be <num_elements>/2
  //Example: 1,2,3,4,5
  // The list should split into 1,2,3 and 4,5.
  temp_node_1 = source;
  *head1 = source;

  for (int i = 0; i < (mid_point); ++i)
  {
    temp_node_1 = temp_node_1->next;
  }

  *head2 = temp_node_1->next;
  temp_node_1->next = NULL;
  // Tip: head1 will point to the source node.
  // Tip: head2 will point to the mid-point of the list.
  // Tip: Ensure you break the link between the sub-lists.

  return;
} 
#endif


#ifdef TEST_MERGE
// upper is the upper sub-list to be merged
// lower is the lower sub-list to be merged
Node* Merge(Node* upper, Node* lower) 
{ 
	// Check for the base cases. (When either sub-list is NULL)
  if (upper == NULL)
  {
    return(lower);
  }
  else if(lower == NULL)
  {
    return(upper);
  }
	
  Node *sorted_node = NULL;

  // Pick the larger between upper and lower, and recur appropriately.
	if ((upper->value) <= (lower->value))
  {
    sorted_node = upper;
    sorted_node->next = Merge(upper->next, lower);
  }
  else
  {
    sorted_node = lower;
    sorted_node->next = Merge(upper, lower->next);
  }

	// return the merged array
  return(sorted_node);
} 
#endif


#ifdef TEST_SORT
// source is the head of the list to for which MergeSort is to be performed.
void MergeSort(Node** source) 
{ 
	// Declare a node, to hold the current head of the source list.
	Node *current_head = *source;

  int length_source = 0;
  Node *temp_node = *source;
  while((temp_node->next) != NULL) //Goes to End of Linked List (Should we reset head to )
  {
    temp_node = temp_node->next;
    ++length_source;
  }

  // Check for the base case -- length 0 or 1
  // if so, return;
  if (length_source < 1)
  {
    return;
  }

  // Declare nodes, to hold the two the heads of the two sub-lists.
  Node *head1 = NULL;
  head1 = malloc(sizeof(Node));
  if (head1 == NULL)  //Check Memory allocation failure
  {
    return;
  }
  
  Node *head2 = NULL;
  head2 = malloc(sizeof(Node));
  if (head2 == NULL)  //Check Memory allocation failure
  {
    return;
  }
	  
	// Use SpiltList() to partition the list into sub lists.
	// This will partiton the source list, into two lists (As done in the previous homework)
  SpiltList(current_head, &head1, &head2);
	  
	// Recursively sort the sub-lists by calling MergeSort() on the upper and lower sub-lists.
	// MergeSort() is a recursive function, and MergeSort() needs to be called
	// on both sub-lists (obtained after partitioning)
  MergeSort(&head1);
  MergeSort(&head2);
	 
	// Merge the two sorted lists together, using the Merge()
  *source = Merge(head1, head2);

  return;
} 
#endif

