#include <omp.h>
#include <stdio.h>
#include <sys/time.h>

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

  static double t_begin = 0.0;
  static int sec = -1;
  struct timeval val;
  if (sec < 0) {
    sec = val.tv_sec;
  }
  t_begin = (val.tv_sec - sec) + (1.0e-6 * val.tv_usec);

  // struct timeval tvalBefore, tvalAfter;
  // gettimeofday(&tvalBefore, NULL);

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

  static double t_end = 0.0;
  sec = -1;
  if (sec < 0) {
    sec = val.tv_sec;
  }
  t_end = (val.tv_sec - sec) + (1.0e-6 * val.tv_usec);

  // gettimeofday(&tvalBefore, NULL);

  // printf("A\n");
  // print_Array(a, n);
  // printf("B\n");
  // print_Array(b, n);

  printf("Time taken %0.4f", t_end - t_begin);

  // printf("Time in seconds: %0.3f seconds\n",
  //        (float)(tvalAfter.tv_sec - tvalBefore.tv_sec));
}
