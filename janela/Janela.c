#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "Janela.h"

// Função que cria uma janela e retorna o Display (conexão com o servidor X11)
Janela janela(){
    // Abre a conexão com o servidor gráfico X11
    Display *display = XOpenDisplay(NULL);
    if (display == NULL){
        // Caso não consiga abrir o display, mostra erro e encerra o programa
        fprintf(stderr, "Não foi possível abrir o display\n");
        exit(1);
    }

    int screen = DefaultScreen(display); // Obtém o índice da tela padrão

    Window root = RootWindow(display, screen); // Obtém a janela raiz dessa tela (a "janela principal" que cobre todo o monitor)

    // Cria uma janela simples como filha da RootWindow
    // Posição (10,10), tamanho 800x600, borda de 1 pixel preta, fundo branco
    Window window = XCreateSimpleWindow(display, root,
                                        10, 10, 800, 600, 1,
                                        BlackPixel(display, screen),
                                        WhitePixel(display, screen));

    // Define quais eventos essa janela deve receber:
    // - Expose: quando precisa ser redesenhada
    // - KeyPress: quando uma tecla é pressionada
    XSelectInput(display, window, ExposureMask | KeyPressMask);

    // Mapeia (exibe) a janela na tela
    XMapWindow(display, window);

    // Retorna o Display (conexão com o servidor X11)

    Janela janela = {display, window, root};

    return janela;
}

void mantem(Janela janela){

    XEvent event;
    while (1) {
        XNextEvent(janela.display, &event);
        if (event.type == KeyPress){
            break; // fecha ao pressionar uma tecla
        }
    }

    XCloseDisplay(janela.display);
}