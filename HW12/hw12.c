/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw12.h"

#ifdef LINKEDLIST

// Do not modify the below program, we are using ifdef block for
// ease of grading. Please include this flag in your Makefile
void LinkedListPrint(Node * head)
{

	Node *temp = head;

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


/********** Do Not modify the file above this line, you should modify below ***********/
#ifdef TEST_CREATENODE

Node * CreateNode(int value)
{
	// allocate memory for the new Node*
  Node *new_node = NULL;
  new_node = malloc(sizeof(Node));

	// check memory allocation fails
  if (new_node == NULL)
  {
    return NULL;
  }
  new_node->value = value;
  new_node->next = NULL;

  return new_node;
}
#endif

#ifdef TEST_LINKEDLISTCREATE
// 1. head: the head of the singly linkedlist.
// 2. length: the length of the singly linkedlist.

// This function creates and initializes a singly linkedlist with length as 'length'(input argument),
// The values of the nodes within the singly linkedlist will be the same as array indddices.
// For example, if the singly linkedlist length is 4, the value of the nodes will be 0 1 2 3
void LinkedListCreate(Node * * head, int length)
{
	// check if length is not negative
	if (length <= 0) //Check if < or <=
  {
    return;
  }

  // create linked list of length as 'length'

  Node *temp_node = *head; //Temporary array to seek the end of linked list.

  for (int linked_index = 1; linked_index < length; ++linked_index) //Creates the appropriate nodes.
  {
    while((temp_node->next) != NULL) //Goes to End of Linked List (Should we reset head to )
    {
      temp_node = temp_node->next;
    }
    temp_node->next = CreateNode(linked_index); //Inserts new node at the end of list.
  }

  return; // do not return anything
}
#endif



#ifdef TEST_JOSEPHUS

// 1. head: the head of the singly linkedlist.
// 2. k : this variable will be used for counting if count = k, the element will be out.
// 3. elemDivisible : this variable will be used for printing. When the number of
//    remaining nodes in linked list is divisible by elemDivisible then you should 
//    print the remaining LinkedList with print functin provided to you.

// This function should solve the josephus problem using the singly linkedlist.

void Josephus(Node ** head, int k, int elemDivisible)
{
	// implement the algorithm here
  int number_remaining = 0; //Counts the number of eliminated elements
  int counter = 0; //Counts up to k elements in the array.
  Node *temp_node_current = *head; //Points to the previous of the currently counted element.
  Node *temp_node_previous = *head; //Points to the currently counted element.

  //Determine length of linked list to then determine how many elements are alive.
  int linked_list_length = 1;
  while((temp_node_previous->next) != NULL) //Goes to End of Linked List (Should we reset head to )
  {
    temp_node_previous = temp_node_previous->next;
    ++linked_list_length;
  }

  number_remaining = linked_list_length;

  //Continues to eliminate elements as long as the number remaining is less than elemDivisble.
  while(number_remaining > 1)
  {
    while(counter < k)
    {
      if (temp_node_previous->next == NULL)
      {
        temp_node_previous = *head;
        temp_node_current = temp_node_previous->next;
      }
      else if (temp_node_current->next == NULL)
      {
        
        temp_node_previous = temp_node_current;
        temp_node_current = *head;
      }
      else
      {
        temp_node_previous = temp_node_previous->next;
        temp_node_current = temp_node_current->next;
      }
      ++counter;
    }

    //Deletion Process
    if (temp_node_current->value == (*head)->value)
    {
      *head = temp_node_current->next;
      free(temp_node_current); // remember to free the memory of the nodes
      temp_node_current = *head;
      --number_remaining;
      counter = 0;
    }
    else
    {
      temp_node_previous->next = temp_node_current->next;
      free(temp_node_current); // remember to free the memory of the nodes
      temp_node_current = temp_node_previous->next;
      --number_remaining;
      counter = 0;
    }

    if (!(number_remaining % elemDivisible))
    {
      LinkedListPrint(*head);
    }
  }
  
	
	
  return;
}

#endif
