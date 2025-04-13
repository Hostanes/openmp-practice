// guided_schedule.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>

#define N 16

int main() {
    int work_time[N];
    for (int i = 0; i < N; i++) {
        work_time[i] = rand() % 100;
    }

    omp_set_num_threads(4);

    printf("Guided scheduling\n");
//Large loop with decreasing load, Starts with large chunks, shrinks over time, Balances load with lower overhead than dynamic
    #pragma omp parallel for schedule(guided) shared(work_time)
    for (int i = 0; i < N; i++) {
        usleep(work_time[i] * 1000);
        printf("Thread %d processed iteration %d (work = %d ms)\n",
               omp_get_thread_num(), i, work_time[i]);
    }

    return 0;
}
