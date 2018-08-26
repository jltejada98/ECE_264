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

  int unsorted_array_boundary = 0; //Stores the index of the last element of the unsorted section of the array.
  int unsorted_array_index = 0; //Stores the index currently cycled through the unsorted section of array.
  int minimum_index = 0; //Stores minimum index of unsorted array.
  int temporary_store = 0; //Stores the value of the minimum 

  for (unsorted_array_boundary = 0; unsorted_array_boundary < size - 1; ++unsorted_array_boundary) //Increments index of sorted array.
  
    minimum_index = unsorted_array_boundary; //Sets the current element as minimum.

    for (unsorted_array_index = unsorted_array_boundary + 1; unsorted_array_index < size - 1; ++unsorted_array_index) //Checks if current element is the minimum element in the array.
    {
      if(arr[unsorted_array_index] < arr[minimum_index]) //If any other element in the unsorted array is the minumum, set its index to the new minimum index.
      {
        minimum_index = unsorted_array_index;
      }
    }

    if(minimum_index = unsorted_array_boundary) //Once the minimum element in the unsorted array is found, set its index to the last element in the sorted section of the array.
    {
      temporary_store = arr[minimum_index];
      arr[minimum_index] = arr[unsorted_array_boundary];
      arr[unsorted_array_boundary] = temporary_store;
    }
  }

  
  // call checkOrder to see whether this function correctly sorts the
  // elements
  if (checkOrder(arr, size) == false)
    {
      fprintf(stderr, "checkOrder returns false\n");
    }
}
#endif
