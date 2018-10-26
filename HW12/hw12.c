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

  Node *temp = *head; //Temporary array to seek the end of linked list.

  for (int linked_index = 1; linked_index < length; ++linked_index) //Creates the appropriate nodes.
  {
    while((temp->next) != NULL) //Goes to End of Linked List (Should we reset head to )
    {
      temp = temp->next;
    }
    temp->next = CreateNode(linked_index); //Inserts new node at the end of list.
  }
  LinkedListPrint(*head);
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
  // int number_eliminated = 0; //Counts the number of eliminated elements
  // int counter = 1; //Counts up to k elements in the array.
  // int index = 0; //Counts number of eliminated elements.

  // while(number_eliminated < elemDivisible)
  // {
    
  // }

	// remember to free the memory of the nodes
	// print the linked list using our function when number of nodes remaining is divisible by elemDivisible
  return;
}

#endif
