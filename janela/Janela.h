
#ifndef JANELA_H
#define JANELA_H


#include <X11/Xlib.h>


typedef struct{
    Display* display;
    Window window;
    Window root;

}Janela;

Janela janela();
void mantem(Janela janela);



#endif