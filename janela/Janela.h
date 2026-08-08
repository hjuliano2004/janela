
#ifndef JANELA_H
#define JANELA_H


#include <X11/Xlib.h>
#include <stdbool.h>


typedef struct{
    Display* display;
    Window window;
    Window root;

}Janela;

Janela janela();

extern double FPS;

void mantem(Janela janela);

bool eventosJanela(Janela janela);



#endif