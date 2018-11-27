//edit this file as required
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw18.h"

//Do Not Change this function
void PrintAnswer(ListNode* head, ListNode* min1, ListNode* min2)
{
	ListNode* temp = head;
	int i;
	while(temp!=NULL)
	{
		i = 0;
		while(i < head -> treenode->dimension)
		{
			if(i == 0)
				printf("(%d, ", temp->treenode->data[i]);
			else if(i == head -> treenode->dimension-1)
				printf("%d)\n", temp->treenode->data[i]);
			else
				printf("%d, ", temp->treenode->data[i]);
			i+=1;

		}
		temp = temp->next;
	}

	i = 0;
	while(i < head -> treenode->dimension)
	{
		if(i == 0)
			printf("(%d, ", min1->treenode->data[i]);
		else if(i == head -> treenode->dimension-1)
			printf("%d) <-> ", min1->treenode->data[i]);
		else
			printf("%d, ", min1->treenode->data[i]);
		i+=1;
	}

	i = 0;
	while(i < head -> treenode->dimension)
	{
		if(i == 0)
			printf("(%d, ", min2->treenode->data[i]);
		else if(i == head -> treenode->dimension-1)
			printf("%d)\n", min2->treenode->data[i]);
		else
			printf("%d, ", min2->treenode->data[i]);
		i+=1;
	}
}

/*
YOU CAN EDIT BELOW THIS COMMENT
*/

#ifdef TEST_MIN
void FindMin(ListNode* head)
{
	// find pair of ListNodes with least distance between them.
  ListNode *temp1 = head;
  ListNode *temp2 = temp1->next;
  ListNode *min1 = NULL;
  ListNode *min2 = NULL;

  //Determine First Distance Between temp's
  int current_dist =  FindDist(temp1->treenode, temp2->treenode);
  int min_dist = current_dist;

  while(temp1 != NULL)
  {
    while(temp2 != NULL)
    {
      current_dist = FindDist(temp1->treenode, temp2->treenode);
      
      if (current_dist <= min_dist)
      {
        min_dist = current_dist;
        min1 = temp1;
        min2 = temp2;
      }

      temp2 = temp2->next;
    }
    temp1 = temp1->next; //Continue to Analyze Next Element.
   
    if (temp1 != NULL) //Compare to following element.
    {
      temp2 = temp1->next;
    }
  }


	// call print Function
	// ENSURE the 2nd parameter of the print function (min1) is smaller than
	// the 3rd parameter (min2). 
	// Look at README, and expected output for more details.
  int i = 0;
  while(i < min1->treenode->dimension) 
  {
    if (min1->treenode->data[i] < min2->treenode->data[i])
    {
      PrintAnswer(head,min1,min2);
      i = min1->treenode->dimension;
    }
    else if (min2->treenode->data[i] < min1->treenode->data[i])
    {
      PrintAnswer(head,min2,min1);
      i = min1->treenode->dimension;
    }
    ++i;
  }

  return;
}
#endif


#ifdef TEST_DIST
int FindDist(TreeNode* x, TreeNode* y)
{
  //Find the euclidean distance between x->data and y->data
	// DO NOT FIND SQUARE ROOT (we are working with int)

  //Modified from HW04
  int sum = 0;
  int difference = 0;
  int treenode_dimension = x->dimension;

  //Iterates through all dimensions of 
  for (int i = 0; i < treenode_dimension; ++i)
  {
    difference = x->data[i] - y->data[i];
    sum = sum + difference * difference;
  }

	// return the distance
  return sum;
}
#endif


#ifdef TEST_CREATENODE
ListNode* CreateNode(int n, int dim, int* arr)
{
	//New Node Initialization
  ListNode *new_node = NULL;
  new_node = malloc(sizeof(ListNode));

  // check for malloc error
  if (new_node == NULL)
  {
    return NULL;
  }

  //Tree Node Initialization
  new_node->treenode = malloc(sizeof(TreeNode));

  //Check for Malloc Error
  if (new_node->treenode == NULL)
  {
    return NULL;
  }

	// initialize dim
  new_node->treenode->dimension = dim;

	// both left and right childern will be NULL
  new_node->treenode->left = NULL;
  new_node->treenode->right = NULL;

	// allocate memory for data
  new_node->treenode->data =  malloc(sizeof(int) * dim);
  
  //Set each element individually.
  for (int i = 0; i < dim; ++i)
  {
    new_node->treenode->data[i] = arr[i];
  }
  

  //Set next to NULL;
  new_node->next = NULL;

	// return a ListNode
  return new_node;
}
#endif


#ifdef TEST_LINKEDLISTCREATE
void LinkedListCreate(ListNode ** head, int n, int dim, FILE* fptr)
{
	//Create Array.
  int *arr = malloc(sizeof(int)*dim);

  //Check for malloc failure.
  if (arr == NULL)
  {
    return;
  }

  //Seeks Current Position of File Stream (Third Element)
  fseek(fptr, 0, SEEK_CUR + 2);

  //Initialize Array (First Row of Elements)
  for (int i = 0; i < dim; ++i)
  {
    fscanf(fptr, "%d", &arr[i]);
  }

  // read from file into an array, pass array to CreateNode
  // create temp node using CreateNode
  ListNode *temp_node = CreateNode(n, dim, arr);
  // assign temp to that node
  *head = temp_node;

  // use a loop to create nodes for the remaining elements of the list.
  for (int node_num = 1; node_num < n; ++node_num)
  {
    //Initialize array to be next row of elements (Works because file stream head is on next row of elements)
    for (int i = 0; i < dim; ++i)
    {
      fscanf(fptr, "%d", &arr[i]);
    }

    //Modified from HW12
    while((temp_node->next) != NULL)
    {
      temp_node = temp_node->next;
    }

    temp_node->next = CreateNode(n, dim, arr); //Create the Next Node (Index > 0)
  }

  //Free Memory for Array.
  free(arr);

  //Close File Pointer
  fclose(fptr);

  return;
}
#endif
