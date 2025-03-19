
#include <omp.h>
#include <stdio.h>

int main() {
  int i = 0;
  int n = 10;
  int a;
#pragma omp parallel for private(i) lastprivate(a)
// #pragma omp parallel for lastprivate(i) lastprivate(a)
  for (i = 0; i < n; i++) {
    a = i + 1;
    printf("Thread %d has a value of a = %d for i = %d\n", omp_get_thread_num(),
           a, i);
  } /*-- End of parallel for --*/

  printf("After parallel for: i = %d , a = %d\n", i, a);
}
