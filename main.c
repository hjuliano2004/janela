#define _POSIX_C_SOURCE 199309L
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

int main() {
    Janela jnela = janela();

    String *frase = string((char *[]){"olá mundo!", NULL});
    println(frase);

    struct timespec ultimoFrame;//guarda o tempo de cada frame
    clock_gettime(CLOCK_MONOTONIC, &ultimoFrame);

    bool rodando = true;
    int sec = 0;
    double milisec = 0;

    
    XEvent evento;
    while (rodando) {
        while (XPending(jnela.display)) {
            XNextEvent(jnela.display, &evento);
            if (evento.type == KeyPress) {
                rodando = false;
            }
        }

        usleep(s / 60);

        milisec += decorrido(ultimoFrame);
        clock_gettime(CLOCK_MONOTONIC, &ultimoFrame);//atualiza o valor do ultimo frame

        if (milisec == 1 || milisec > 1) {

            sec++;
            milisec = -1;

            printf("segundo: %d\n", sec);
        }
    }

    XCloseDisplay(jnela.display);
    return 0;
}