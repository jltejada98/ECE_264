#include "bmpfunc.h"
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#ifdef TEST_FUNCGIVEN

int RGB2Gray(unsigned char red, unsigned char green, unsigned char blue){
	// this is a commonly used formula
	int gray = 0.2989 * red + 0.5870 * green + 0.1140 * blue;
	return gray;
}

#endif

//Modify below this line and use code from HW10 for IMGTOGRAY()

#ifdef TEST_IMGTOGRAY

BMPImage * ImgToGray(BMPImage * image){
	// use code from your HW10
  // int width = (image->header).width;
  // int height = (image->header).height;

  // allocate space for the image
  BMPImage *gray_image = malloc((image->header).size);
  // the image has the same size
  // therefore the header has to stay the same
  // check for memory allocation failure 
  if (gray_image == NULL)
  {
    BMP_Free(gray_image);
    return NULL;
  }
  
  //gray_image can be the name of the new image memory allotment
  gray_image->header = image->header;
  
  //Assign the the imagesize as height * width
  (gray_image->header).imagesize = image->header.imagesize;
  
  //check for data allocation failure using :
  gray_image->data = malloc(sizeof(unsigned char)*(gray_image->header).imagesize);

  if(gray_image->data == NULL)
  {
    BMP_Free(gray_image);
    return NULL;
  }
  
  int pixel=0;
  int gray_val = 0;
  //Run loop for all pixels using height and width
  while(pixel < (gray_image->header).imagesize)
  {
    //convert each pixel of all channels to gray using the given RGB2GRAY function
    gray_val = RGB2Gray(image -> data[pixel+2],image -> data[pixel + 1], image -> data[pixel]);
    //assign values to all pixels of gray_image for each channel
    gray_image->data[pixel+2] = gray_val;
    gray_image->data[pixel+1] = gray_val;
    gray_image->data[pixel] = gray_val;
    pixel+=3; //to move on to the next 3 channel combination
  }

  //return the result
  return gray_image;
}

#endif

//Write your own code for Adaptive Thresholding Function
//#ifdef TEST_ADAPTIVETHRESHOLDING

BMPImage * AdaptiveThresholding(BMPImage * grayImage, int radius, int epsilon){
 	// allocate space for the image
  BMPImage * adaptive = malloc((grayImage->header).size);
	// the image has the same size(height and width)
	// therefore the header has to stay the same
	adaptive->header = grayImage->header;
  grayImage->header.imagesize = grayImage->header.imagesize;
	
  if ((adaptive->data = malloc(sizeof(unsigned char)*(adaptive->header).imagesize)) == NULL) {
		fprintf(stderr, "Error allocating memory\n");
		free(adaptive);
		return NULL;
	}

	int pixel_outer_loop=0;
	//Run a nested loop for all elements using height and width
  for (int row = 0; row < (adaptive->header).height; ++row)
  {
    for (int col = 0; col < (adaptive->header).width; ++col)
    {
      //Find the maximum of top row, b)ottom rpw, left column and right column using radius
      int toprow = MAX(0, row-radius);
      int bottomrow = MIN((adaptive->header).height-1, row+radius);
      int leftcol = MAX(0, col-radius);
      int rightcol = MIN((adaptive->header).width-1, col+radius);

      //Calculate the average of all pixels
      int sum_neighborhood = 0; //Holds the value of the sum.
      int counter_neighborhood = 0; //Holds the number of pixels in neighborhood being read.
      int average_epsilon = 0; //Holds average value of neighborhood pixels.
      int pixel_inner_loop = 0;

      //Run loop from toprow to bottom row
      for (int row2 = toprow; row2 < bottomrow; ++row2)
      {
        //Inside which run a loop from left column to right column
        for (int col2 = leftcol; col2 < rightcol; ++col2)
        {
          //calculate the location of each pixel using (row2*width + col2)*3;
          pixel_inner_loop = (row2*(adaptive->header).width + col2)*3;
          //add all data values at every location point in data.
          sum_neighborhood += grayImage->data[pixel_inner_loop +2] + grayImage->data[pixel_inner_loop +1] +grayImage->data[pixel_inner_loop];
          //keep a counter for averaging
          ++counter_neighborhood;
        }
      }

      //Outside the second nested loop: 
      //calculate average (using int)
      average_epsilon = sum_neighborhood / counter_neighborhood;
      //check if average_epsilon is greater than grayImage->data[at that pixel point]
      int pixel_outer_loop = (row*(adaptive->header).width + col)*3;
      if (average_epsilon > grayImage->data[pixel_outer_loop] )
      {
        //then assign adaptive thresholding image data as 0(black) for data value at pixel, pixel+1, pixel+2
        grayImage->data[pixel_outer_loop + 2] = 0;
        grayImage->data[pixel_outer_loop + 1] = 0;
        grayImage->data[pixel_outer_loop] = 0;
      }
      else // else if average is lower then color shall be white(255) for data value at pixel, pixel+1, pixel+
      {
        grayImage->data[pixel_outer_loop + 2] = 255;
        grayImage->data[pixel_outer_loop + 1] = 255;
        grayImage->data[pixel_outer_loop] = 255;
      }
    }
  }
          
  //return the image after adaptive thresholding
  return(adaptive);
}


#endif
