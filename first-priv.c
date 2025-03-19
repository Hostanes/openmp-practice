

#include <omp.h>
#include <stdio.h>

int main() {

  int i, vtest = 10, n = 20;
#pragma omp parallel for private(i) firstprivate(vtest) shared(n)
  for (i = 0; i < n; i++) {
    printf("thread %d: initial value = %d\n", omp_get_thread_num(), vtest);
    vtest = i;
  }
  printf("value after loop = %d\n", vtest);
}
