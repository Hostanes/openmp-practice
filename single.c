#include <omp.h>
#include <stdio.h>

int main() {

#pragma omp parallel
  {
#pragma omp single
    {
      printf("This is printed once by one thread\n");
    }

#pragma omp for
    for (int i = 0; i < 5; i++) {
      printf("%d\n", i);
    }
  }
}
