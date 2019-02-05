#include "hw10.h"
//modify the main() function
#ifdef TEST_MAINFUNC

int main(int argc, char **argv){
  // check the arguments
  if (argc != 3)
  {
    printf("Wrong arguments\n");
    return EXIT_FAILURE;
  }

  // open the BMP file
  FILE *file_pointer; //File Pointer used to check for correct name.
  char *file_name = argv[1];

  file_pointer = fopen(file_name, "r");

  if (file_pointer == NULL)
  {
    printf("Error opening BMP file\n");
    return EXIT_FAILURE;
  }

  BMPImage *original_image = BMP_Open(file_name);

  // convert to gray scale
  BMPImage *gray_image = ImgToGray(original_image);
	// check for error in converting to gray scale
  if (gray_image == NULL)
  {
    return EXIT_FAILURE;
  }  

	// write the gray image to file
  BMP_Write(argv[2],gray_image);

	// free all the images
  BMP_Free(original_image);
  BMP_Free(gray_image);


  fclose(file_pointer); 
	return EXIT_SUCCESS;
}

#endif
