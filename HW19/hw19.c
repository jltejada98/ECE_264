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
	// Use a loop to average the data from the two parameters (x and y).
	// EXAMPLE
	// Average x->treenode.data[0] and y->treenode.data[0] to new->treenode.data[0]
	// Average x->treenode.data[1] and y->treenode.data[1] to new->treenode.data[1]
	// and so on
	int number_dimensions = x->dimension;
  int *average_array = malloc(sizeof(int) * number_dimensions);

  for (int i = 0; i < number_dimensions; ++i)
  {
    average_array[i] = (x->data[i] + y->data[i]) / 2;
  }

  // Create a new node
  // new -> treenode.left should be x
  // new -> treenode.right should be y
  // x -> treenode.data should be less than y -> treenode.data (refer to README)
  // new -> treenode.data = averaged data.

  ListNode *new_node = CreateNode(0, number_dimensions, average_array);
  new_node->treenode->left = x;
  new_node->treenode->right = y;

	// Return the new node
  return new_node;
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
//Helper Function Declarations and Definitions
ListNode * _helper_Search_Unlink_Node(ListNode *search, ListNode *head);
int _helper_Equal_Nodes(ListNode *node1, ListNode *node2);

ListNode * _helper_Search_Unlink_Node(ListNode *search, ListNode *head)
{
  //Searches for the first node within the list.
  ListNode *temp_previous = head;
  ListNode *temp_current = temp_previous->next;

  //Search for fuse1, fuse2, unlink from list.
  while((temp_current != NULL) && !(_helper_Equal_Nodes(temp_current, search)))
  {
    temp_previous = temp_previous->next;
    temp_current = temp_current->next;
  }
  
  //Unlinking node, does not free.
  temp_previous->next = temp_current->next;

  return(head);
}

int _helper_Equal_Nodes(ListNode *node1, ListNode *node2)
{
  int equal = 1;
  int number_dimensions = node1->treenode->dimension;
  int index = 0;

  while((index < number_dimensions) && (node1->treenode->data[index] == node2->treenode->data[index]))
  {
    ++index;
  }

  if (node1->treenode->data[index] != node2->treenode->data[index])
  {
    equal = 0;
  }

  return equal;
}


ListNode* Fuse(ListNode* head, ListNode* fuse1, ListNode* fuse2)
{
	// Create a new ListNode element using findCentroid function.
  // The new->treenode.data will hold the averaged values of the two parameters' data (fuse1, and fuse2)
  ListNode *new_node = FindCentroid(fuse1->treenode, fuse2->treenode);
  
  // Add the new ListNode to the list.
  //ListNode *temp_head = head; //Stores the head Before Changing.
  //Decided to insert centroid node at Begging
  new_node->next = head;
  head = new_node;

	// remove the fuse1 and fuse2 from the list. (Do NOT free)
  // Unlink fuse1 and fuse 2 from the list. 
  head = _helper_Search_Unlink_Node(fuse1, head);
  head = _helper_Search_Unlink_Node(fuse2, head);

  return head; // you may want to return head from this function (depending on your implementation)
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
  //Variables
  ListNode *temp1 = *head;
  ListNode *temp2 = temp1->next;
  ListNode *min1 = NULL;
  ListNode *min2 = NULL;

  //Determining Number of Nodes
  int number_nodes = 1;
  while(temp1->next != NULL)
  {
    temp1 = temp1->next;
    ++number_nodes;
  }

  temp1 = *head;

  int number_remaining = number_nodes;

  while(number_remaining > 1) // repeat till one node is remaining.
  {
    //Modified from HW18
    //Re assign values to prevent segmentation fault.
    temp1 = *head;
    temp2 = temp1->next;
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

    // call print function
    int i = 0;
    while(i < min1->treenode->dimension) //Ensures second parameter is smaller than third parameter.
    {
      if (min1->treenode->data[i] < min2->treenode->data[i])
      {
        PrintAns(*head,min1,min2);
        *head = Fuse(*head, min1, min2); // fuse the two nodes into one node.
        --number_remaining;
        i = min1->treenode->dimension;
      }
      else if (min2->treenode->data[i] < min1->treenode->data[i])
      {
        PrintAns(*head,min2,min1);
        *head = Fuse(*head, min2, min1); // fuse the two nodes into one node.
        --number_remaining;
        i = min1->treenode->dimension;
      }
      ++i;
    }
    //Free min1/min2
    free(min1);
    free(min2);
  
  } //End of repeat till one node remaining.

  return;
}

#endif


