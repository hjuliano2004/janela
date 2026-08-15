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

#define s 1000// representa 1 segundo

// callback precisa ter a mesma assinatura que o setInterval espera
void spam(void *arg);
void teste(void *arg);

int main(void) {

    Janela *janela = newJanela();
    sWayland *wayland = newWayland();
    Nos *nos = newNos(janela, wayland, "janela de teste");//a declaração explicita da variavel não é obrigatória

    int fps = s/60;

    // passa NULL como argumento, já que não precisa
    setInterval(spam, NULL, 3);
    setInterval(teste, NULL, 3);


    /* Loop principal: processa eventos pendentes, timers e aguarda eventos com timeout */
    while (1) {
        wl_display_dispatch_pending(wayland->display);
        rodar();
        wl_display_flush(wayland->display);

        if(controleCiclo(wayland, fps)){break;}//força o controle dos frames porsegundo 


        calculoFps();
    }




    return 0;
}

void spam(void *arg) {
    (void)arg; // evita warning de argumento não usado
    printf("mensagem a cada 3 segundos\n");
}

void teste(void *arg){
    (void)arg;

    printf("FPS: %.0f\n", ciclo->FPS);
}

