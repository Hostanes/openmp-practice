#include <omp.h>
#include <stdio.h>

int main() {

#pragma omp parallel sections
  {
#pragma omp section
    {
      printf("section 1\n");
    }
#pragma omp section
    {
      printf("section 2\n");
    }
#pragma omp section
    {
      printf("section 3\n");
    }

  }
}
