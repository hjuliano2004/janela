#include "Janela.h"
#include <X11/Xlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

double FPS;

// Função que cria uma janela e retorna o Display (conexão com o servidor X11)
Janela janela() {
    // Abre a conexão com o servidor gráfico X11
    Display *display = XOpenDisplay(NULL);
    if (display == NULL) {
        // Caso não consiga abrir o display, mostra erro e encerra o programa
        fprintf(stderr, "Não foi possível abrir o display\n");
        exit(1);
    }

    int screen = DefaultScreen(display); // Obtém o índice da tela padrão

    Window root = RootWindow(
        display, screen); // Obtém a janela raiz dessa tela (a "janela
                          // principal" que cobre todo o monitor)

    // Cria uma janela simples como filha da RootWindow
    // Posição (10,10), tamanho 800x600, borda de 1 pixel preta, fundo branco
    Window window = XCreateSimpleWindow(display, root, 10, 10, 800, 600, 1,
                                        BlackPixel(display, screen),
                                        WhitePixel(display, screen));

    // Define quais eventos essa janela deve receber:
    // - Expose: quando precisa ser redesenhada
    // - KeyPress: quando uma tecla é pressionada
    XSelectInput(display, window, ExposureMask | KeyPressMask);

    // Mapeia (exibe) a janela na tela
    XMapWindow(display, window);
    XFlush(display); // força envio dos comandos ao servidor X11

    // Retorna o Display (conexão com o servidor X11)

    Janela janela = {display, window, root};

    return janela;
}

bool eventosJanela( Janela janela) {

    XEvent evento;

    while (XPending(janela.display)) {
        XNextEvent(janela.display, &evento);

        switch (evento.type) {

        case KeyPress:
            return false;
            break;
        case Expose:
            /* XFillRectangle(
                 jnela.display, jnela.window,
                 DefaultGC(jnela.display, DefaultScreen(jnela.display)), 20,
                 20, 100, 50);*/

                 //não quero desenhar nada na janela por enquanto
            break;
        }
    }

    return true;
}

void mantem(Janela janela) {

    XEvent event;
    while (1) {
        XNextEvent(janela.display, &event);
        if (event.type == KeyPress) {
            break; // fecha ao pressionar uma tecla
        }
    }

    XCloseDisplay(janela.display);
}