// static_schedule.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>
#include <time.h>

#define N 16

int main() {

    // srand(time(0));

    int work_time[N];
    for (int i = 0; i < N; i++) {
        work_time[i] = rand() % 100;  // simulate varying work loads
    }

    omp_set_num_threads(8);

    printf("Static scheduling\n");
//Iterations take equal or predictable time
    #pragma omp parallel for schedule(static) shared(work_time)
    for (int i = 0; i < N; i++) {
        usleep(work_time[i] * 1000);
        printf("Thread %d processed iteration %d (work = %d ms)\n",
               omp_get_thread_num(), i, work_time[i]);
    }

    return 0;
}
