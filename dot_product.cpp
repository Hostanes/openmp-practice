#include <stdio.h>

int main(int argc, char *argv[]) {
  double sum_serial, sum_parallel;
  double a[256], b[256];
  int status;
  int n = 256;
  int i;
  for (i = 0; i < n; i++) {
    a[i] = i * 0.5;
    b[i] = i * 2.0;
  }

  sum_parallel = 0;
#pragma omp parallel for reduction(+ : sum_parallel)
  for (i = 1; i <= n; i++) {
    sum_parallel = sum_parallel + a[i] * b[i];
  }

  sum_serial = 0;
  for (i = 1; i <= n; i++) {
    sum_serial = sum_serial + a[i] * b[i];
  }

  printf("difference between sums = %d\n", sum_serial - sum_parallel);
}
