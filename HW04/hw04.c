// There are some parts in the file that you need to modify, Please do
// not modify everything

// Modify only between the block which mentions what to modiy
// ===== DO NOT MODIFY BELOW THIS ======
#include "hw04.h"
  
void cleanup (FILE * fpin)
{
  fclose (fpin);
}  

// read the data, return true if success, false if fail
bool readData (FILE * fpin, DataPoint * *dp, int nval, int dim)
{
  int niter, diter;
  for (niter = 0; niter < nval; niter++)
    {
      for (diter = 0; diter < dim; diter++)
	{
	  if (fscanf (fpin, "%d", &dp[niter]->data[diter]) == 0)
	    {
	      return false;
	    }
	}
    }
  return true;
}

 
// write the output centroids to the file
// check for all the NULL before calling this function, it does not check
void writeCentroids (const char *filename, Centroid * *centroids, int kval)
{
  FILE * fpout = fopen (filename, "w");
  if (fpout == NULL)
    {
      fprintf (stderr, "File %s, cannot be open\n", filename);
      exit (1);
    }
  int kiter;
  // sort the centroids for ease of grading
  qsort (centroids, kval, sizeof (Centroid *), Centroid_cmp);
  for (kiter = 0; kiter < kval; kiter++)
    {
      Centroid_print (centroids[kiter], fpout);
    }
  fclose (fpout);
}

  
//===== DO NOT MODIFY ABOVE THIS ======

// Complete the below functions only, do not modify any other function.
  
#ifdef TEST_DIST
// distance - funtion to get the distance between present centroid and datapoint
// @param DataPoint * - pointer to DataPoint structure from which distance needs to be calculated (DataPoint is a type.)
// @param Centroid * - pointer to Centroid struct from which distance is being calculated (Centroid is a type.)
long long int
distance (const DataPoint * datapoint, const Centroid * centroid)
{
  // since this is for comparison only, there is no need to call sqrt
  long long int sum = 0;	// must initialize to zero
  int datapoint_dimension = datapoint->dimension; //Get Dimension from Datapoint and stores the dimension of the datapoint value.
  long long int difference = 0; //Stores the difference between the datapoint and centroid data.
  int index_dimension_dp = 0; //Iterates through all datapoint indecies.

  for(index_dimension_dp = 0; index_dimension_dp < datapoint_dimension; ++index_dimension_dp)
  {
    difference = datapoint->data[index_dimension_dp] - centroid->data[index_dimension_dp]; 
    sum = sum + difference * difference;
  }

  // find Euclidean distance and then return 'sum' without calling sqrt
	return sum;
}

#endif	
   
#ifdef TEST_CLOSESTCENTROID
  
// for a data point, find the closest centroid
// 1. calculate the distance between the data point and the first
// centroid, set it to the minimum distance
// 2. go through the other centroids and calculate distance from each.
// 3. Keep on updating minimum distance and index value of the
// centroid from which the distance is smaller than previously seen,
int closestCentroid (int kval, DataPoint * datapoint, Centroid * *centroids)
{
  int mindex = 0; //index of the closest centroid 
  // Please note that return value of distance is long long int, so initialize the values with the same type
  int index_dimension_ct = 0; //Stores the index of the centroid array of pointers.
  long long int current_distance = 0; //Stores the distance from the datapoint to the current centroid being analyzed.
  long long int minimum_distance = distance(datapoint, centroids[index_dimension_ct]); //Sets the minimum diatnce to be the distance to the first centroid.
  // go through each centroid and find the distance
  // keep track of minimum difference and index of centroid which has the smallest distance

  for (index_dimension_ct = 0; index_dimension_ct < kval; ++index_dimension_ct) //Determine which index to start.
  {
    current_distance = distance(datapoint, centroids[index_dimension_ct]);

    if(current_distance < minimum_distance)
    {
      minimum_distance = current_distance;
      mindex = index_dimension_ct;
    }
  }

   return mindex;
}

#endif	
    
#ifdef TEST_KMEAN

// kmean - function which finds the k clusters in the data set
// kval - # of clusters (Equal to number of centroids?)
// nval - # of datapoints
// datapoints - array of datapoints
// centroids - array of centroids
//
// return the total distances of datapoints from their centroids
void kmean (int kval, int nval, DataPoint * *datapoints, Centroid * *centroids)
{
  int index_dimension_ct = 0; //Stores the index of the centroid array of pointers.
  int index_dimension_dp = 0; //Stores the index of the datapoint array of pointers.
  int random_cluster = 0; //Stores the Random cluster that a data point will be assigned.
  int minimum_index = 0; //Stores the index of the current minimum distance from a datapoint to a centroid.
  int current_cluster = 0; //Stores the cluster of the current data point.
  int convergence_true = 0; //Stores a value of 1 when the convergence condition is met.

  // reset all centroids
  for (index_dimension_ct = 0; index_dimension_ct < kval; ++index_dimension_ct)
  {
    Centroid_reset(centroids[index_dimension_ct]);
  }

	// initialize each data point to a cluster between 0 and kval - 1
  for (index_dimension_dp = 0; index_dimension_dp < nval; ++index_dimension_dp)
  {
    random_cluster = (rand() % kval);
    datapoints[index_dimension_dp]->cluster = random_cluster;
    Centroid_addPoint (centroids[random_cluster], datapoints[index_dimension_dp]);
  }

	// find the centroid for initial random assignment of datapoints
	for (index_dimension_ct = 0; index_dimension_ct < kval; ++index_dimension_ct)
  {
    Centroid_findCenter(centroids[index_dimension_ct]);
  }

	// Now start the loop till convergence is met - (Please see README for understanding kmean algorithm convergence condition)
	// 
	// 1. for each data point, find the index of the centroid that is the closest
	// 2. store that index in DataPoint's structure's cluster value.
	// 3. reset all the centroids
	// 4. go through each datapoint again and add this datapoint to its centroid using Centroid_addPoint function
	// 5. find the new centroid for each cluster by calling Centroid_findCenter 

  while(convergence_true == 0)
  {
    convergence_true = 1;

    for (index_dimension_dp = 0; index_dimension_dp < nval; ++index_dimension_dp)
    {
      minimum_index = closestCentroid(kval, datapoints[index_dimension_dp],centroids);

      if (minimum_index != datapoints[index_dimension_dp]->cluster)
      {
        convergence_true = 0;
      }

      datapoints[index_dimension_dp]->cluster = minimum_index;
    }

    for (index_dimension_ct = 0; index_dimension_ct < kval; ++index_dimension_ct)
    {
      Centroid_reset(centroids[index_dimension_ct]);
    }

    for (index_dimension_dp = 0; index_dimension_dp < nval; ++index_dimension_dp)
    {
      current_cluster = datapoints[index_dimension_dp]->cluster;
      Centroid_addPoint(centroids[current_cluster], datapoints[index_dimension_dp]); 
    }

    for (index_dimension_ct = 0; index_dimension_ct < kval; ++index_dimension_ct)
    {
      Centroid_findCenter(centroids[index_dimension_ct]);
    }
  
  }

}
 
#endif	
  
/*===== DO NOT MODIFY BELOW THIS ======*/ 
int
main (int argc, char * *argv)
{
  
  // argv[1]: name of input file
  // argv[2]: value of k/ number of centroids
  // argv[3]: name of output file
  if (argc < 4)
    {
      fprintf (stderr, "argc is %d, not 4\n", argc);
      return EXIT_FAILURE;
    }
   
  // opening file to read the data points from
  FILE * fpin = fopen (argv[1], "r");
  if (fpin == NULL)
    {
      fprintf (stderr, "fopen %s fail\n", argv[1]);
      return EXIT_FAILURE;
    }
   
  // convert long to int
  int kval = (int) strtol (argv[2], NULL, 10);
  if (kval <= 0)
    {
      fprintf (stderr, "kval is %d, must be positive\n", kval);
      return EXIT_FAILURE;
    }
  // control the random number sequence
  int randseed = 1729;	// any integer will do, DO NOT CHANGE
  srand (randseed);
    
  // getting number of datapoints
  int nval;
  fscanf (fpin, "%d", &nval);
  if (nval < kval)
    {
      fprintf (stderr, "nval= %d must be greater than kval = %d\n", nval,
	       kval);
      cleanup (fpin);
      return EXIT_FAILURE;
    }
   
  // getting dimensions of the data from the file
  int dim;
  fscanf (fpin, "%d", &dim);
  if (dim < 2)
    {
      fprintf (stderr, "nval= %d must be greater than kval = %d\n", nval,
	       kval);
      cleanup (fpin);
      return EXIT_FAILURE;
    }
    
  // allocate memory for the data points
  DataPoint * *datapoint_array = DataPoint_createArray (nval, dim);
  if (datapoint_array == NULL)
    {
      printf ("Error in creating datapoint array\n");
      cleanup (fpin);
      return EXIT_FAILURE;
    }
  
  // allocate memory for array of centroids
  Centroid * *centroids = Centroid_createArray (kval, dim);	
  if (centroids == NULL)
    {
      printf ("Error in creating centroids array\n");
      DataPoint_freeArray (datapoint_array, nval);
      cleanup (fpin);
      return EXIT_FAILURE;
    }
   
  // read the data from the file
  if (readData (fpin, datapoint_array, nval, dim) == false)
    {
      printf ("Error in reading data array\n");
      cleanup (fpin);
      DataPoint_freeArray (datapoint_array, nval);
      return EXIT_FAILURE;
    }
     
  // calling kmean function to find the cetroids
  kmean (kval, nval, datapoint_array, centroids);

	//writing those centroids to the file
  writeCentroids (argv[3], centroids, kval);
  // free all the allocated spaces
  DataPoint_freeArray (datapoint_array, nval);
  Centroid_freeArray (centroids, kval);
  cleanup (fpin);
  return EXIT_SUCCESS;
}


