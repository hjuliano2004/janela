#ifndef SETTS_H
#define SETTS_H

#include "Diferenca.h"
#include <time.h>

typedef struct {
    int id;                       // identificador único
    void (*callback)(void);
    struct timespec inicio;
    double intervalo;
    bool repete;
} SetTimer;


typedef struct{
    SetTimer** list;
    int length;
    int size;

}TimerList;

extern TimerList *temporizadores;

TimerList *timerList();

SetTimer *setInterval( void (*callback)(void), double intervalo);
SetTimer *setTimeOut(void (*callback)(void), double intervalo);
void clearAllIntervals();

TimerList *addTimer(TimerList *list, SetTimer *setTimer);

void rodar();

void repetidor(SetTimer *timer);

void clearInterval(SetTimer* setTimer);

#endif