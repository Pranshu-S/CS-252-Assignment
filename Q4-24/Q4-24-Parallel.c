#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

// Seed value for Linear congruential generator for generating output between 0 and 1
unsigned int seed = 2;

// Number of iterations
#define N 500000000
int totalPts = 0;

// Random Number generator
double RandUint ()
{
  // Linear Congruential Generator
  seed = seed * 1103515245 + 123456;
  return seed / (double)UINT_MAX;
}

// Function for parallel processing
void * Count (void *X)
{
  // Iterations
  for (int i = 0; i < N; i++)
    {
      // Generate random numbers
      double x = (double)RandUint ();
      double y = (double)RandUint ();

      // Check if value falls inside the circle.
      if (((x * x) + (y * y)) <= 1)
        {
          //Increase value of count
          totalPts++;
        }
    }
  return NULL;
}

// Function for parallel processing
void EstimateParallel ()
{
  // Declare thread object
  pthread_t thread;

  // Assign the function Count a thread for parallel processing
  pthread_create (&thread, NULL, &Count, NULL);

  // WAit for thread to give an output and terminate
  pthread_join (thread, NULL);

  // Estimate value of Pi
  double estPiValue = (4.0 * totalPts) / N;

  printf ("Trials Done: %d \n",N);
  printf ("Points inside circle: %d \n",totalPts);
  printf ("Estimated value of pi: %lf\n",estPiValue);
}

int main ()
{
  // Clock object
  clock_t t;

  // Get value of clock before processing
  t = clock ();

  // Start Parallel processing
  EstimateParallel ();

  // Get value of time after processing
  t = clock () - t;

  // Get time taken in seconds
  double timeTaken = ((double)t) / CLOCKS_PER_SEC;   
  printf ("Execution took %f seconds\n", timeTaken);
  return 0;
}