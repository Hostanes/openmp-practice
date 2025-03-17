#include <omp.h>
#include <stdio.h>
#define MAX_NUM 100

void print_Array(int *arr, int size){
  for(int i = 0; i < size;i++){
    printf("%d\n", arr[i]);
  }
}

int main() {

  int a[MAX_NUM];
  int b[MAX_NUM];
  int n = MAX_NUM;
  int i;
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

  printf("A\n");
  print_Array(a, n);
  printf("B\n");
  print_Array(b, n);
  
  
}
