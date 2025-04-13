#include <omp.h>
#include <stdio.h>

#define MAX_NUM 1000000

int isPrime(int x) {
  for (int i = 2; i < x / 2; i++) {
    if (x % i == 0) {
      return 1;
    }
  }
  return 0;
}

int main() {

  int x[MAX_NUM];

  double start_time = omp_get_wtime();

#pragma omp parallel for 
  for (int i = 0; i < MAX_NUM; i++) {
    isPrime(i);
  }

  double end_time = omp_get_wtime();
  double time_taken = end_time - start_time;

  printf("time taken: %f\n", time_taken);
}
