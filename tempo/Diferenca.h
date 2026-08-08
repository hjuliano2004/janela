#ifndef DIFERENCA_H
#define DIFERENCA_H

#include <time.h>
#include <stdbool.h>


double decorrido(struct timespec tempo);
bool espera(double espera, struct timespec *inicio);
void setInterval(void (*callback)(void), struct timespec *inicio, double intervalo);


#endif