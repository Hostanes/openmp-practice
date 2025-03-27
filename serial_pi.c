#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  long long totalPoints = 1000000000LL; // number of points
  long long insideCircle = 0;
  double x, y;

  // Seed the random number generator
  srand(time(NULL));
  omp_set_num_threads(1);

  double start_time = omp_get_wtime();

#pragma omp parallel for private(x, y) reduction(+ : insideCircle)
  for (long long i = 0; i < totalPoints; i++) {
    // Generate random point in [-1,1] x [-1,1]
    x = (double)rand() / RAND_MAX * 2.0 - 1.0;
    y = (double)rand() / RAND_MAX * 2.0 - 1.0;
    if (x * x + y * y <= 1.0)
      insideCircle++;
  }
  double pi = 4.0 * insideCircle / totalPoints;

  double end_time = omp_get_wtime();
  double time_taken = end_time - start_time;
  printf("time taken; %f\n", time_taken);

  printf("Estimated Pi = %f\n", pi);
  return 0;
}
