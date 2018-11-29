// You can modify this file.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw19.h"

// DO NOT MODIFY THIS FUNCTION
void PrintAns(ListNode* head, ListNode* min1, ListNode* min2)
{
	int i;
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
MODIFY BELOW THIS COMMENT
*/


#ifdef TEST_CENT
ListNode* FindCentroid(TreeNode* x, TreeNode* y)
{
	// Create a new node
	// new -> treenode.left should be x
	// new -> treenode.right should be y
	// x -> treenode.data should be less than y -> treenode.data (refer to README)
	
	// Use a loop to average the data from the two parameters (x and y).
	/*
	EXAMPLE
	Average x->treenode.data[0] and y->treenode.data[0] to new->treenode.data[0]
	Average x->treenode.data[1] and y->treenode.data[1] to new->treenode.data[1]
	and so on
	*/

	// Return the new node
}
#endif


#ifdef TEST_DIST
int FindDist(TreeNode* x, TreeNode* y)
{
	//Extracted from HW18
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


#ifdef TEST_FUSE
ListNode* Fuse(ListNode* head, ListNode* fuse1, ListNode* fuse2)
{

	// Create a new ListNode element using findCentroid function.
	// The new->treenode.data will hold the averaged values of the two parameters' data (fuse1, and fuse2)
	// add the new ListNode to the list.
	// remove the fuse1 and fuse2 from the list. (Do NOT free)
	// you may want to return head from this function (depending on your implementation)
}
#endif


#ifdef TEST_CREATENODE
ListNode* CreateNode(int n, int dim, int* arr)
{
  //Extracted from HW18
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
  //Extracted from HW18
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

  return;
}
#endif

#ifdef TEST_CLUSTER
void MakeCluster(ListNode** head)
{
  //Determine Number of Nodes
  ListNode *temp1 = head;
  ListNode *temp2 = temp1->next;
  ListNode *min1 = NULL;
  ListNode *min2 = NULL;
  int number_nodes = 0;



  //Extracted from HW18

  //Determine First Distance Between temp's
  int current_dist =  FindDist(temp1->treenode, temp2->treenode);
  int min_dist = current_dist;

  while(temp1 != NULL)// Walk through the linked list.
  {
    while(temp2 != NULL)
    {
      current_dist = FindDist(temp1->treenode, temp2->treenode); // find pair of nodes with minimum distance.
      
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
	// fuse the two nodes into one node.

	// call print function
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

	// repeat till one node is remaining.

  return;
}
#endif


