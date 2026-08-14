#define _XOPEN_SOURCE 500

#include "jnela/Janela.h"
#include "string/String.h"
#include "tempo/Diferenca.h"
#include "tempo/Setts.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <poll.h>

#define s 1000000

// callback precisa ter a mesma assinatura que o setInterval espera
void spam(void *arg);

int main(void) {

    Janela *janela = newJanela();
    sWayland *wayland = newWayland();
    Nos *nos = newNos(janela, wayland, "janela de teste");

    double FPS = s / 60;

    // passa NULL como argumento, já que não precisa
    setInterval(spam, NULL, 3);
    setTimeOut(spam, 0, 9);


    int fd = wl_display_get_fd(wayland->display);
    struct pollfd pfd;
    pfd.fd = fd;
    pfd.events = POLLIN;

    /* Loop principal: processa eventos pendentes, timers e aguarda eventos com timeout */
    while (1) {
        wl_display_dispatch_pending(wayland->display);
        rodar();
        wl_display_flush(wayland->display);

        int timeout_ms = 16; /* ~60Hz */
        int ret = poll(&pfd, 1, timeout_ms);
        if (ret < 0) break;
        if (ret > 0) {
            if (pfd.revents & POLLIN) {
                if (wl_display_dispatch(wayland->display) == -1) break;
            }
        }
    }




    return 0;
}

void spam(void *arg) {
    (void)arg; // evita warning de argumento não usado
    printf("mensagem a cada 3 segundos\n");
}