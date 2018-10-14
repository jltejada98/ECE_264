// ***
// *** You MUST modify this file, only the ssort function
// ***

#include "sort.h"
#include <stdio.h>
#include <stdbool.h>

static bool checkOrder(int * arr, int size)
// a static function is visible only in this file
// This function returns true if the array elements are
// in the ascending order.
// false, otherwise
{
  int ind;
  for (ind = 0; ind < (size - 1); ind ++)
    {
      if (arr[ind] > arr[ind + 1])
	{
	  return false;
	}
    }
  return true;
}

#ifdef TEST_SORT
void ssort(int * arr, int size)
{
  // This function has two levels of for
  // The first level specifies which element in the array
  // The second level finds the smallest element among the unsorted
  // elements
  // After finding the smallest element among the unsorted elements,
  // swap it with the element of the index from the first level

  int sorted_array_boundary = 0; //Stores the index of the last element of the sorted section of the array.
  int unsorted_array_index = 0; //Stores the index currently cycled through the unsorted section of array.
  int minimum_index = 0; //Stores the index of the currently smallest number in the unsorted array.
  int temporary_store = 0; //Stores the value of the minimum 

  for (sorted_array_boundary = 0; sorted_array_boundary < size - 1; ++sorted_array_boundary) //Iterates through all elements of the array, increasing the sorted list.
  {  
    minimum_index = sorted_array_boundary;

    for (unsorted_array_index = sorted_array_boundary + 1; unsorted_array_index <= size - 1; ++unsorted_array_index)
    {
      if(arr[unsorted_array_index] < arr[minimum_index])
      {
        minimum_index = unsorted_array_index;
      }
    }

    temporary_store = arr[sorted_array_boundary];
    arr[sorted_array_boundary] = arr[minimum_index];
    arr[minimum_index] = temporary_store;

  }
  
  // call checkOrder to see whether this function correctly sorts the
  // elements
  if (checkOrder(arr, size) == false)
  {
    fprintf(stderr, "checkOrder returns false\n");
  }

}
#endif
