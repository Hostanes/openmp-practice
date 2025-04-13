#include <omp.h>
#include <stdio.h>

int main() {

  int counter = 0;

#pragma omp parallel for
  for (int i = 0; i < 100; i++) {
#pragma omp critical
    {
      counter++; // Thread-safe increment
    }
  }

  printf("counter %d\n", counter);
}
