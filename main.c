#define _XOPEN_SOURCE 500

#include "janela/Janela.h"
#include "string/String.h"
#include "tempo/Diferenca.h"
#include <X11/Xlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define s 1000000

void spam();

int main() {

    FPS = (double)s / 60.0;

    Janela jnela = janela();

    String *frase = string((char *[]){"olá mundo!", NULL});
    println(frase);

    //struct timespec ultimoFrame; // guarda o tempo de cada frame
    //clock_gettime(CLOCK_MONOTONIC, &ultimoFrame);

    struct timespec esperando;
    clock_gettime(CLOCK_MONOTONIC, &esperando);

    while (eventosJanela(jnela)) {
        usleep(FPS);

        //clock_gettime(CLOCK_MONOTONIC,  &ultimoFrame); // atualiza o valor do ultimo frame

        setInterval(spam, &esperando, 5);

    }

    XCloseDisplay(jnela.display);
    return 0;
}

void spam(){
    printf("spama a cada 5 segundos\n");
}