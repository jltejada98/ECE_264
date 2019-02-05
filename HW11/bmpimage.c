#include "bmpimage.h"
//Include your own code from HW10 and modify this file
#ifdef TEST_HEADERVALID

int Is_BMPHeader_Valid(BMPHeader* header, FILE *fptr) {
	// use code from HW10
  // Make sure this is a BMP file -  magic number
  if (header->type != 0x4d42)
  {
    return FALSE;
  }

  // skip the two unused reserved fields

  // check the offset from beginning of file to image data
  // essentially the size of the BMP header
  // BMP_HEADER_SIZE for this exercise/assignment
  // printf("header->offset %d\n",header->offset); (What to do with this print statement?)
  if (header->offset != BMP_HEADER_SIZE)
  {
    return FALSE;
  }
  
  // check the DIB header size == DIB_HEADER_SIZE
  if (header->DIB_header_size != DIB_HEADER_SIZE)
  {
    return FALSE;
  }

  // Make sure there is only one image plane
  if (header->planes != 1)
  {
    return FALSE;
  }

  // Make sure there is no compression
  if (header->compression != FALSE)
  {
    return FALSE;
  }

  // skip the test for xresolution, yresolution
  
  // ncolours and importantcolours should be 0
  if (header->ncolours !=0)
  {
    return FALSE;
  }

  if (header->importantcolours != 0)
  {
    return FALSE;
  }

  // Make sure we are getting 24 bits per pixel
  // only for this assignment
  if (header->bits != 24)
  {
    return FALSE;
  }

  // extra check for file size, image size
  // based on bits, width, and height
  // check out the link: https://en.wikipedia.org/wiki/BMP_file_format#Pixel_storage

  // if (header->imagesize != header->bits * header->width * header->height)
 //  {
 //    return FALSE;
 //  }

 //  if (header->size != header->bits * header->width * header->height + BMP_HEADER_SIZE)
 //  {
 //    return FALSE;
 //  }

  return TRUE;

}

#endif

#ifdef TEST_BMPOPENFILE

BMPImage *BMP_Open(const char *filename) {
  // use code from HW10
  //open file
  //read file
  FILE *fptr = fopen(filename,"r");
  
  //Allocate memory for BMPImage*;
  BMPImage *bmpImage = (BMPImage *)malloc(sizeof(BMPImage));
  //check for memory allocation errors
  if (bmpImage == NULL)
  {
    return NULL;
  }
  
  //Read the first 54 bytes of the source into the header
  int read_size = fread(&(bmpImage->header), sizeof(BMPHeader), 1, fptr);
  
  //check if the header is valid
  if (read_size != 1)
  {
    BMP_Free(bmpImage);
    return NULL;
  }
  
  if (Is_BMPHeader_Valid(&(bmpImage->header), fptr) != TRUE)
  {
    BMP_Free(bmpImage);
    return NULL;
  }


  // Allocate memory for image data
  bmpImage->data = (unsigned char *)malloc(sizeof(unsigned char)*((int)((bmpImage->header).imagesize)));
  //check error
  if (bmpImage->data == NULL)
  {
    BMP_Free(bmpImage);
    return NULL;
  }

  // read in the image data
  int read_data = fread(bmpImage->data, sizeof(unsigned char), (int)((bmpImage->header).imagesize), fptr); 
  //check for error while reading
  if (read_data != (int)(bmpImage->header).imagesize)
  {
    BMP_Free(bmpImage);
    return NULL;
  }

  fclose(fptr);
  return bmpImage;
}
#endif


#ifdef TEST_WRITEFUNC

int BMP_Write(const char * outfile, BMPImage* image){
	// use code from HW10
  FILE *fptr = NULL;
  fptr = fopen(outfile, "w");
  //open file and check for error
  if (fptr == NULL)
  {
    return 0;
  }
  //check error for writing
  if (fwrite(&(image->header), sizeof(BMPHeader),1, fptr) != 1)
  {
    fclose(fptr);
    return 0;
  }

  // write and check for image data:(fwrite(image->data, sizeof(unsigned char), (image->header).imagesize, fptr) != (image->header).imagesize) 

  if (fwrite(image->data, sizeof(unsigned char), (image->header).imagesize, fptr) != (image->header).imagesize)
  {
    fclose(fptr);
    return 0;
  }
  
  fclose(fptr);
  return TRUE;
}

#endif



/* The input argument is the BMPImage pointer. The function frees memory of
 * the BMPImage.
 */
#ifdef TEST_BMPFREEFUNC
void BMP_Free(BMPImage* image) {
  //Used Code from HW10
  //free image if image is true
  if(image != NULL)
  {
    if (image->data != NULL)
    {
      free(image->data);
    }
    free(image);
  }

  return;

}

#endif
