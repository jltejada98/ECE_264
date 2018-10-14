#include "hw10.h"
//modify the main() function
#ifdef TEST_MAINFUNC

int main(int argc, char **argv){
  // check the arguments
  if (argc != 3)
  {
    printf("Wrong Arguments\n");
    return;
  }
  // open the BMP file
  FILE *file_pointer;
  char *file_name = argv[1];

  file_pointer = fopen(file_name, "r");

  if (file_pointer == NULL)
  {
    return EXIT_FAILURE;
  }

  // convert to gray scale
  BMPImage grayscale_image;

  grayscale_image = ImgToGray(file_pointer);
	// check for error in converting to gray scale
  if (file_pointer == NULL)
  {
    return EXIT_FAILURE;
  }

	// write the gray image to file

	// free all the images
	return EXIT_SUCCESS;
}

#endif
