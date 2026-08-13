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
void spam();
int main() {

    double FPS = s/60;

    //setInterval(spam, 3);

    // Loop principal
    while (true) {
        usleep(FPS);
        rodar();
    }


    return 0;
}

void spam(){
    printf("mensagem a cada 3 segundos\n");
}