// ***
// *** You MUST modify this file
// ***

#include "josephus.h"
#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_JOSEPHUS
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails,
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }

  // initialize all elements

  int index = 0; //Iterates through all Indecies to Initialize them to their respective index location.
  for(index = 0; index < n; ++index)
  {
    arr[index] = index;
  }
  // counting to k,
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked

  index = 0; //Used to iterate through indexes in the array.
  int counter = 1; //Counts up to k elements in the array.
  int number_eliminated = 0; //Counts number of eliminated elements.

  while(number_eliminated < (n - 1))
  {
    if(arr[index] == -1) //Check if element is eliminated.
    {
      ++index; //Skip from checking.
    }
    else //If element is not eliminated
    {
      if (counter < k) //If counter is less than k, increment counter and index.
      {
        ++counter;
        ++index;
      }
      else //Otherwise eliminate element.
      {
        printf("%d\n", arr[index]);
        arr[index] = -1;
        ++number_eliminated;
        ++index;
        counter = 1;
      }
    }

    if (index >= n) //If Index is greater than number of elements.
    {
      index = 0;
    }
  
  }


  // print the last one
  for(index = 0; index < n; ++index)
  {
    if(arr[index] != -1)
    {
      printf("%d\n", arr[index]);
    }
  }

  // release the memory of the array
  free (arr);
}
#endif
