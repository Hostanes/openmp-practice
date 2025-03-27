#include <omp.h>
#include <stdio.h>

#define SIZE 500000

double run_add(int num_threads, int c[SIZE]) {

  int a[SIZE];
  int b[SIZE];

  for (int i = 0; i < SIZE; i++) {
    a[i] = i * 5;
    b[i] = i * 2;
  }

  omp_set_num_threads(num_threads);

  double start_time = omp_get_wtime();

#pragma omp parallel for
  for (int i = 0; i < SIZE; i++) {
    c[i] = a[i] + b[i];
  }

  double end_time = omp_get_wtime();

  double time_taken = end_time - start_time;

  return time_taken;
}

int main() {

  int c1[SIZE];
  int c2[SIZE];

  double time_taken_serial = run_add(1, c1);
  double time_taken_parallel = run_add(6, c2);

  int count = 0;
  for (int i = 0; i < SIZE; i++) {
    if (c1[i] - c2[i] != 0) {
      printf("ERROR not equal values\n");
      printf("count: %d\n", count);
      return -1;
    }
    count++;
  }

  printf("Values equal\n");

  printf("time taken serial:%f\n", time_taken_serial);
  printf("time taken parallel:%f\n", time_taken_parallel);
}
