#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

//***** YOU NEED TO MODIFY main() FUNCTION BELOW *******//
#ifdef TEST_MAIN

void _helperDestroy(treeNode *tn);

int main(int argc, char **argv)
{
  // 1. Check for number of arguments. If less than 2, do not proceed further.
  if (argc < 2)
  {
    return EXIT_FAILURE;
  }

  // 2. The program should create a binary search tree from the numbers in input file. The input file 
  // 	also contains a number for search query at the end. 
  
  FILE *fptr = fopen(argv[1], "r");
  
  if (fptr == NULL)
  {
    return EXIT_FAILURE;
  }

  // 3. The input file has one number per line. If there are 'n' lines in the file, the first n-1 numbers 
  // 	are the elements of the binary search tree and the nth line is the search query. 
  // NOTE: n is not given to you. 

  //Determine number of values in input file.
  int value;
  int number_lines = 0;
  while(fscanf(fptr, "%d", &value) == 1)
  {
    ++ number_lines;
  }

  // 4. Create an array of the first n-1 numbers and store the last number in a variable. 
  
  //Allocate memory for Tree
  int *arr_tree = malloc(sizeof(int) * (number_lines - 1));
  int search_query;
  
  if (arr_tree == NULL)
  {
    return EXIT_FAILURE;
  }

  //Initialize Array.
  fseek(fptr, 0, SEEK_SET);
  int index = 0;
  while(index < (number_lines - 1))
  {
    if (fscanf(fptr, "%d", &arr_tree[index]) != 1) //Check for Fscanf Failure.
    {
      return EXIT_FAILURE;
    }
    ++index;
  }

  //Obtain Seach_Query
  fscanf(fptr, "%d", &search_query);
  fclose(fptr);

  // 5. Create a Binary Search Tree. It takes four arguments:
  // 	1. The array
  // 	2. the first element of the array
  // 	3. start index (index of first element of the array)
  // 4. end index ( index of last element of the array)

  treeNode * head_tree = CreateBST(arr_tree, arr_tree[0], 0, (number_lines - 1));

  // 6. Print the created tree in Inorder fashion. Quick check if you have created the tree right: the output of
  // 	will be a sorted array of numbers. 
  BinaryTreeInOrderPrint(head_tree);

  // 7. Compute the distance of the 'search query' node by passing it to the function.
  int distance_search_query = FindDistance(head_tree, search_query, 0);
  // 8. Use PrintDistance() function to print the distance of the node from the root node in the right format.
  PrintDistance(distance_search_query);
  // 9. Free all memory.
  free(arr_tree);
  _helperDestroy(head_tree);

}
#endif
