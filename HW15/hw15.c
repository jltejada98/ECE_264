/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw15.h"

#ifdef LINKEDLIST
// Do not modify this function.
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
			printf("%d\n",temp->value);
		}
		temp=temp->next;
	}
}
#endif


/********** Do Not modify the file above this line, you can modify below ***********/
#ifdef TEST_CREATENODE

Node * CreateNode(int val)
{
	/*
	Create a new Node with `value` set to `val`. Set `next` to NULL.
	*/

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

  return new_node;

}
#endif

#ifdef TEST_LINKEDLISTCREATE

void LinkedListCreate(Node ** head, char* name)
{
	/*
	Create a linked list from the input file referenced by `name`.
	*/

  FILE * fptr = fopen(name, "r");
  if (fptr == NULL) //Check for fopen failure.
  {
    return;
  }

  Node *temp_node = *head; //Temporary array to seek the end of linked list.
  int value;//Stores the value of the node to be added.

  fseek(fptr, 0, SEEK_CUR); //Seeks current position of file stream.

  while(fscanf(fptr, "%d", &value) == 1) //Remember that fscanf has already scanned first element.
  {
    //Modified from HW12.
    while((temp_node->next) != NULL)
    {
      temp_node = temp_node->next;
    }
    temp_node->next = CreateNode(value);
  }

  fclose(fptr);

  return;
}
#endif

#ifdef TEST_REMOVED
//This function will remove repetitions of a linked list value.

void RemoveDuplicate(Node *headRef)
{
	/*
	This function will remove repetitions from the linked list referenced by headRef.
	Each time we check for a new Node in the linked list, we will check if it is distinct from
	the Nodes already present in the list ( upto the previous Node).
	So for each occurrence after its first, we will be deleting that node.
	To delete a node: we will map the next Node of the previous Node to the Node after the current Node.
	Print the linked list after all repetitions have been removed. Use the function given to you for priniting.
	*/

  //Code Modified from HW12
  Node *checked_value = headRef;
  Node *temp_node_previous = headRef;
  Node *temp_node_current = headRef->next;

  //Determine length of linked list for looping.
  while(checked_value->next != NULL) //Checks all values in Linked List.
  {
    while(temp_node_current->next != NULL) //Checks that all values are not 
    {
      if (checked_value->value == temp_node_current->value) //If the Checked Value is equal to the Current value, delete the node.
      {
        temp_node_previous->next = temp_node_current->next;
        free(temp_node_current);
        temp_node_current = temp_node_previous->next;
      }
      else
      {
        temp_node_current = temp_node_current->next;
        temp_node_previous = temp_node_previous->next;
      }
    }
    //Check if Last Value is a duplicate
    if (checked_value->value == temp_node_current->value) //If the Checked Value is equal to the Current value, delete the node.
    {
      free(temp_node_current);
      temp_node_previous->next = NULL;
    }

    checked_value = checked_value->next; //Check Next Value
    temp_node_previous = checked_value; //Set previous node to new checked value.
    temp_node_current = temp_node_previous->next; //Change current node appropriately.
  }

  return;
}
#endif
