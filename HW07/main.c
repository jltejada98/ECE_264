//You must modify specific portions of this file

/* After completion of code check for FLAGS:
TEST_MERGE
TEST_MERGESORT
TEST_MERGESSORT
The three flags must be defined for grading*/

#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>

#ifdef TEST_MERGE

/* The merge(arr, l, m, r) is key process that assumes that arr[l..m] and 
arr[m+1..r] are sorted and merges the two sorted sub-arrays into one.*/

void merge(int arr[], int l, int m, int r) 
{ 
 /* int l defines the start index of the left sub array
  int r defines the end index of the right sub array, if the length of array is n, then r=n-1
  int m can be defined as (l+r)/2 or l+(r-l)/2, use the later to avoid overflow
  m is the endpoint of the left sub array.
  For example- an array of size 5 has start index l= 0, and end index r= 4,
  Therefore, m = 2
  */

  int n1 = m - l + 1; //The number of elements in the left sub array
  int n2 =  r - m; //The number of elements in the right sub array

  //create temporary arrays dynamically to help with sorting
  int *L=malloc(sizeof(* L) * n1); 
  int *R=malloc(sizeof(* R) * n2); 
  /* NOTE:
  L[] is the left sub array
  R[] is the right sub array
  L[] is different from l. l is the starting index of left sub array.
  R[] is different from r. r is the ending index for the right sub array.
  Please do not be confused */

  //WRITE YOUR CODE BELOW THIS 

  //Initialize variables
  int index_L = 0; //Stores index of array L
  int index_R = 0; //Stores index of array R
  
  //1.Copy data to temp arrays L[] and R[] from arr[]
  for (index_L = l; index_L <= m; ++index_L) //Copies Data to L[] from arr[]
  {
    L[index_L - l] = arr[index_L];
  }

  for (index_R = m + 1; index_R <= r; ++index_R) //Copies Data to R[] from arr[]
  {
    R[index_R - m - 1] = arr[index_R];
  }

  // Compare Elements
  index_L = 0; //Reset Values of L/R indexes. 
  index_R = 0;
  int index_arr = l; //Stores index of arr.

  while ((index_L < n1) && (index_R < n2)) //Orders elements of L/R arrays until either index has reached end of array.
  {
    if (L[index_L] >= R[index_R]) //2. Merge the temp arrays back into arr[l..r]
    {
      arr[index_arr] = R[index_R];  
      ++index_arr;
      ++index_R;
    }
    else if (L[index_L] < R[index_R])
    {
      arr[index_arr] = L[index_L];
      ++index_arr;
      ++index_L;
    }
  }

  //3. Copy the remaining elements of L[], check if there are any 
  for (int i = index_L; i < n1; ++i)
  {
    arr[index_arr] = L[i];
    ++index_arr;
  }
  
  //4. Copy the remaining elements of R[], check if there are any 
  for (int i = index_R; i < n2; ++i)
  {
    arr[index_arr] = R[i];
    ++index_arr;
  }
  free(L);
  free(R);

  return;
 //DO not modify below this line until specified in comments
}
#endif

#ifdef TEST_MERGESSORT

/* Merge Sort uses recursion to call itself. Thus, efficiently dividing the array into two halves.
Then it must sort each half individually and finally join them back together using merge() into a single sorted array*/ 

void mergeSort(int arr[], int l, int r) 
{ 
 /* int l defines the start index of the left sub array
  int r defines the end index of the right sub array
  int m has to be defined as (l+r)/2 or l+(r-l)/2, use the later to avoid overflow
  m will represent the endpoint of the left sub array.
  For example- an array of size 6 has start index l= 0, and end index r= 5,
  Therefore, m = 2*/
  
  //MODIFY THE CODE BELOW THIS LINE
  int m = 0; //Stores Midpoint of Array

  //1. SET CONDITION for RECURSION
  if (l < r)
  {
    m = l+(r-l)/2;
    mergeSort(arr,l,m); //2. Sort first half arr[l..m]
    mergeSort(arr,m+1, r); //3. Sort second half arr[m+1..r]
    merge(arr,l,m,r); //4. Use the merge() function to arrange in order
  }

  return;
  //DO not modify below this line until specified in comments
} 
#endif

int main(int argc, char * * argv)
{
  // read input file
  if (argc != 3)
  {
    fprintf(stderr, "need the name of input and output file\n");
    return EXIT_FAILURE;
  }
  // open file to read
  FILE * fptr = fopen(argv[1], "r"); 
  if (fptr == NULL)
  {
    fprintf(stderr, "fopen fail\n");
    // do not fclose (fptr) because fptr failed
    return EXIT_FAILURE;
  }
  // count the number of integers
  int value;
  int count = 0;
  while (fscanf(fptr, "%d", & value) == 1)
  {
    count ++;
  }
  // allocate memory to store the numbers
  int * arr = malloc(sizeof(int) * count);
  if (arr == NULL) // malloc fail
  {
    fprintf(stderr, "malloc fail\n");
    fclose (fptr);
    return EXIT_FAILURE;
  }
  // return to the beginning of the file
  fseek (fptr, 0, SEEK_SET);
  int ind = 0;
  while (ind < count)
  {
    if (fscanf(fptr, "%d", & arr[ind]) != 1)
  {
    fprintf(stderr, "fscanf fail\n");
    fclose (fptr);
    free (arr);
    return EXIT_FAILURE;
  }
    ind ++;
  }
  fclose(fptr);

  #ifdef TEST_MERGESORT

  // modify here between ifdef and endif
  // do not modify anywhere else in this function
  // call mergesort function and provide the correct arguments (Hint: array, start index, end index)
  mergeSort(arr,0,count - 1);
  #endif

  // int i;
   /* open the file for writing*/
  FILE * fp = fopen(argv[2], "w"); 
  if (fp == NULL)
  {
   fprintf(stderr, "fopen fail\n");
   // do not fclose (fp) because fp failed
   return EXIT_FAILURE;
  }
  for (ind = 0; ind < count; ind ++)
  {
    fprintf (fp,"%d\n", arr[ind]);
  }

  fclose (fp);
  free (arr);

  return EXIT_SUCCESS;
}
