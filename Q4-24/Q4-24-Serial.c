#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// Define seed for random value generator
#define SEED 2

// Number of iterations
#define N 500000000

void RunSerialComputation ()
{
  int count = 0;
  double estPiValue;

  // Initialize randomizer with SEED
  srand (SEED);
  for (int i = 0; i < N; i++)
    {
      double x,y;

      // Generate random values
      x = (double)rand () / RAND_MAX;
      y = (double)rand () / RAND_MAX;

      // Check if it lies within circle
      if (x * x + y * y <= 1)
        {
          count++;
        }
    }

    // EStimate value of Count
  estPiValue = (4.0 * count) / N;
  
  printf ("Trails done: %d \n",N);
  printf ("Points inside circle: %d \n",count);
  printf ("Estimated value of pi: %lf\n", estPiValue);
}

int main ()
{
  // Clock object for getting time reference
  clock_t t;

  // Get clock time before processing
  t = clock ();

  // Run serial computation
  RunSerialComputation ();

  // Get time after processing
  t = clock () - t;

  // Get time in seconds
  double timeTaken = ((double)t) / CLOCKS_PER_SEC;
  printf ("Execution took %f seconds \n", timeTaken);
  return 0;
}


