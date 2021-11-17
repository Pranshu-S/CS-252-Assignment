#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

#define SEED 7
unsigned int seed = 7;

#define N 500000000
int totalPts = 0;

double RandUint (long i)
{
  seed = seed * 1103515245 + 123456;
  return seed / (double)UINT_MAX;
}

void * Count (void *X)
{
  for (int i = 0; i < N; i++)
    {
      double x = (double)RandUint (i);
      double y = (double)RandUint (i);
      if (((x * x) + (y * y)) <= 1)
        {
          totalPts++;
        }
    }
  return NULL;
}

void EstimateParallel ()
{
  srand (SEED);
  pthread_t thread;
  pthread_create (&thread, NULL, &Count, NULL);
  pthread_join (thread, NULL);
  double estPiValue = (4.0 * totalPts) / N;
  printf ("Trials Done: %d \n",N);
  printf ("Points inside circle: %d \n",totalPts);
  printf ("Estimated value of pi: %lf\n",estPiValue);
}

int main ()
{
  clock_t t;
  t = clock ();
  EstimateParallel ();
  t = clock () - t;
  double timeTaken = ((double)t) / CLOCKS_PER_SEC;   
  printf ("Execution took %f\n", timeTaken);
  return 0;
}