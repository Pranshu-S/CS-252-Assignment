#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define SEED 7
#define N 500000000

void RunSerialComputation ()
{
  int count = 0;
  double estPiValue;
  srand (SEED);
  for (int i = 0; i < N; i++)
    {
      double x,y;
      x = (double)rand () / RAND_MAX;
      y = (double)rand () / RAND_MAX;
      if (x * x + y * y <= 1)
        {
          count++;
        }
    }
  estPiValue = (4.0 * count) / N;
  printf ("Trails done: %d \n",N);
  printf ("Points inside circle: %d \n",count);
  printf ("Estimated value of pi: %lf\n", estPiValue);
}

int main ()
{
  clock_t t;
  t = clock ();
  RunSerialComputation ();
  t = clock () - t;
  double timeTaken = ((double)t) / CLOCKS_PER_SEC;
  printf ("Execution took %f \n", timeTaken);
  return 0;
}


