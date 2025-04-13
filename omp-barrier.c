#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// DONT DEFINE TOO HIGH OR YOU WILL CRASH!!!!!
#define MAX_NUM 100000

void print_Array(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d\n", arr[i]);
  }
}

int main() {

  int n = MAX_NUM;
  int i;

  int **a = malloc(MAX_NUM * sizeof *a);
  for (i = 0; i < MAX_NUM; i++)
    a[i] = malloc(MAX_NUM * sizeof *a[i]);

  int **b = malloc(MAX_NUM * sizeof *b);
  for (i = 0; i < MAX_NUM; i++)
    b[i] = malloc(MAX_NUM * sizeof *b[i]);

  clock_t t = clock();

#pragma omp parallel shared(n, b, a) private(i)
  {
#pragma omp for
    for (i = 0; i < n; i++) {
      *a[i] = i + n;
    }

#pragma omp for
    for (i = 0; i < n; i++) {
      *b[i] = n * 2;
    }
  }

  t = clock() - t;
  double time_taken = ((double)t) / CLOCKS_PER_SEC;
  printf("CLOCKS_PER_SEC: %f\n", (double)CLOCKS_PER_SEC);
  printf("%f seconds\n", time_taken);

  for (i = 0; i < MAX_NUM; i++)
    free(a[i]);
  for (i = 0; i < MAX_NUM; i++)
    free(b[i]);

  // Uncomment the following lines if you want to print the arrays (not
  // recommended for large n) printf("A\n"); print_Array(a, n); printf("B\n");
  // print_Array(b, n);

  return 0;
}
