

#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

  int TID = 0;
  time_t bt1;
  time_t t1, t2;

#pragma omp parallel private(TID)
  {
    TID = omp_get_thread_num();
    if (TID < omp_get_num_threads() / 2)
      system("sleep 3");
    bt1 = time(NULL);
    printf("Thread %d before barrier at %s \n", omp_get_thread_num(),
           ctime(&t1));
#pragma omp barrier
    t2 = time(NULL);
    printf("Thread %d after barrier at %s \n", omp_get_thread_num(),
           ctime(&t2));
  } /*-- End of parallel region --*/
}
