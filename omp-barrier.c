#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 1000000

void print_Array(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d\n", arr[i]);
  }
}

int main() {

  int a[MAX_NUM];
  int b[MAX_NUM];
  int n = MAX_NUM;
  int i;

  clock_t t = clock();

#pragma omp parallel shared(n, b, a) private(i)
  {
#pragma omp for
    for (i = 0; i < n; i++) {
      a[i] = i + n;
    }

#pragma omp for
    for (i = 0; i < n; i++) {
      b[i] = n * 2;
    }
  }

  t = clock() - t;
  double time_taken = ((double)t) / CLOCKS_PER_SEC;
  printf("CLOCKS_PER_SEC: %f\n", (double)CLOCKS_PER_SEC);
  printf("%f seconds\n", time_taken);

  // Uncomment the following lines if you want to print the arrays (not
  // recommended for large n) printf("A\n"); print_Array(a, n); printf("B\n");
  // print_Array(b, n);

  return 0;
}
