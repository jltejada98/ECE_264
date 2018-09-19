// ***
// *** Please modify this file, as indicated
// ***

#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "vector.h"

/*-------------------------------MODIFY BELOW THIS LINE-------------------------------*/

#ifdef TEST_MAIN 
int main(int argc, char * * argv)
{
  // input file will be specified from the terminal - test files are made available in inputs folder
  // check for missing input file/output file, if so, "return EXIT_FAILURE;"
  if (argc <= 2)
  {
    return EXIT_FAILURE;
  }

  // store the input file name in a variable, from argv[1]. For example, char* in_file = argv[1];
  // store the output file name in a variable, from argv[2]. For example, char* out_file = argv[2];
  char *input_file_name = argv[1];
  char *output_file_name = argv[2];

  // call numberOfElements(in_file) to obtain the number of elements in the file.
  int number_elements = numberOfElements(input_file_name);

  // allocate memory to store the numbers (initialize an array of structures)
  // check for malloc fail, if so, "return EXIT_FAILURE;"
  Vector *input_vector = malloc(number_elements * sizeof(Vector));

  if (input_vector == NULL)
  {
    return EXIT_FAILURE;
  }

  //call the fillVector(vector, count, in_file); and store the values from the file in the array of structures.
  fillVector(input_vector,number_elements,input_file_name);

  // printf("Unordered:\n");

  // for (int i = 0; i < number_elements; ++i)
  // {
  //   printf("%d %d %d\n",input_vector[i].x,input_vector[i].y,input_vector[i].z);
  // }

  //Use qsort() function, after defining the comparator() function.
  //ENSURE THE COMPARATOR FUNCTION IS USED TO SORT THE ARRAY OF STRUCTURES W.R.T. THE STRUCTURE VARIABLE "x".
  qsort(input_vector,number_elements,sizeof(Vector),cmp);  

  // printf("Ordered:\n");

  // for (int i = 0; i < number_elements; ++i)
  // {
  //   printf("%d %d %d\n",input_vector[i].x,input_vector[i].y,input_vector[i].z);
  // }

  //call the writeFile(vector,count, out_file); to save the sorted vector into the file.
  writeFile(input_vector, number_elements, output_file_name);

  free(input_vector);

  return EXIT_SUCCESS;
  }
#endif
