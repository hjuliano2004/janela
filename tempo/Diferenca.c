#define _POSIX_C_SOURCE 199309L
#include "Diferenca.h"
#include <time.h>

double decorrido(struct timespec inicio) {
    struct timespec fim;
    clock_gettime(CLOCK_MONOTONIC, &fim);

    time_t sec = fim.tv_sec - inicio.tv_sec;
    long nsec = fim.tv_nsec - inicio.tv_nsec;

    if (nsec < 0) {
        sec -= 1;
        nsec += 1000000000;
    }

    return sec + nsec / 1e9;
}
