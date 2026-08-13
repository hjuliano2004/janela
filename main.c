#define _XOPEN_SOURCE 500

#include "janela/Janela.h"
#include "string/String.h"
#include "tempo/Diferenca.h"
#include "tempo/Setts.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define s 1000000

// callback precisa ter a mesma assinatura que o setInterval espera
void spam(void *arg);

int main(void) {
    double FPS = s / 60.0;

    // passa NULL como argumento, já que não precisa
    setInterval(spam, NULL, 3);
    setTimeOut(spam, 0, 9);

    // Loop principal
    while (true) {
        usleep((useconds_t)FPS);
        rodar(); // sua função de renderização
    }

    return 0;
}

void spam(void *arg) {
    (void)arg; // evita warning de argumento não usado
    printf("mensagem a cada 3 segundos\n");
}