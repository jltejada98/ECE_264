#include "hw11.h"
//Modify this file

#ifdef TEST_MAIN

int main(int argc, char **argv){
  // check the arguments - please read readme about validity of arguments
  if (argc != 5)
  {
    printf("Wrong arguments\n");
    return EXIT_FAILURE;
  }
  
  FILE *input_file_pointer; //File Pointer used to check for correct name.
  char *input_file_name = argv[1];
  char *output_file_name = argv[2];
  int radius = (int) strtol(argv[3],NULL,10);
  int epsilon = (int) strtol(argv[4],NULL, 10);

  //Check First Input
  input_file_pointer = fopen(input_file_name, "r");
  if (input_file_pointer == NULL)
  {
    printf("Error opening BMP file\n");
    return EXIT_FAILURE;
  }

  // check radius and epsilon values -  read readme for the validity of argument. Question: How do we check radius and epsilon.
  if ((radius < 0) || (epsilon < 0 ))
  {
    printf("Wrong inputs\n");
    return EXIT_FAILURE;
  }

  // open the BMP file
  BMPImage *original_image = BMP_Open(input_file_name);

  // convert to gray scale
  BMPImage *gray_image = ImgToGray(original_image);

	// check for error in converting to gray scale
   if (gray_image == NULL)
  {
    BMP_Free(original_image);
    BMP_Free(gray_image);
    return EXIT_FAILURE;
  }  

  // call adaptive threshold function
  BMPImage *adapted_image = AdaptiveThresholding(gray_image, radius, epsilon); //Check for Error.

  // check for errors after calling adaptive threshold
  if (adapted_image == NULL)
  {
    BMP_Free(original_image);
    BMP_Free(gray_image);
    BMP_Free(adapted_image);
    return EXIT_FAILURE;
  } 

	// write the adaptive threshold image to file
  BMP_Write(output_file_name,adapted_image); //If file write fails, free memory and return EXIT_FAILURE, done within function.

  // free all the images
  BMP_Free(original_image);
  BMP_Free(gray_image);
  BMP_Free(adapted_image);


  fclose(input_file_pointer); 

	return EXIT_SUCCESS;
}

#endif
