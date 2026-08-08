#include "String.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

StringList *coletor = NULL;

int contaLength(char **data) {

    int dataLength = contaLinha(data);
    int length = 0;

    for (int i = 0; i < dataLength; i++) {
        for (int j = 0; data[i][j] != '\0'; j++) {
            length++;
        }
    }

    return length;
}

String *string(char **data) {

    if(coletor == NULL){
        coletor = stringList(50);
    }

    String *s = malloc(sizeof(String));

    s->data = escrita(data);

    s->length = contaLength(data);
    s->limite = s->length + (s->length / 3);

    //if (coletar) {
        addLixo(s);
   // }

    return s;
}

int contaLinha(char **lista) {

    if (lista == NULL) {
        return 0;
    }

    int linhas = 0;
    for (int i = 0; lista[i] != NULL; i++) {
        linhas++;
    }

    return linhas;
}

char *escrita(char **data) {

    int linha = contaLinha(data);
    char *s = malloc(contaLength(data) + 1);

    int p = 0;

    for (int i = 0; i < linha; i++) {
        int len = strlen(data[i]);

        for (int j = 0; j < len; j++) {
            s[p] = data[i][j];
            p++;
        }
    }

    s[p] = '\0';
    return s;
}

void println(String *string) {

    if (string != NULL) {
        printf("%s \n", string->data);
    } else {
        printf("null\n");
    }
}

void freeString(String **strings) {
    for (int i = 0; strings[i] != NULL; i++) {
        free(strings[i]->data); // libera o buffer de caracteres
        free(strings[i]);       // libera a struct
        strings[i] = NULL;      // evita dangling pointer
    }
}

void freeColetor() {
    if (coletor == NULL) return;

    int tamanho = coletor->size;

    for (int i = 0; i < coletor->length; i++) {
        if (coletor->list[i] != NULL) {
            free(coletor->list[i]->data);   // libera o buffer de caracteres
            free(coletor->list[i]);         // libera a struct String
            coletor->list[i] = NULL;
        }
    }

    free(coletor->list);  // libera o array de ponteiros
    coletor->list = NULL;

    free(coletor);        // libera a struct StringList
    coletor = stringList(tamanho);
}


void coletar(StringList *list) {
    for (int i = 0; i < list->length; i++) {
        addLixo(list->list[i]);
    }
}

void addLixo(String *string) {

    incrementStringList(coletor);

    coletor->list[coletor->length] = string;
    coletor->length++; // incrementa o contador
}

StringList *stringList(int initialSize) {

    StringList *arr = malloc(sizeof(StringList));
    arr->list = malloc(initialSize * sizeof(String *));
    arr->length = 0;         // começa vazio
    arr->size = initialSize; // capacidade inicial

    for (int i = 0; i < initialSize; i++) {
        arr->list[i] = NULL;
    }

    return arr;
}

void incrementStringList(StringList *list) {
    if (list == NULL) {
        return;
    }

    if (list->length < list->size) {
        return;
    }

    // calcula nova capacidade: atual + 1/3
    int novaCapacidade = list->size + (list->size / 3);

    // realoca o array de ponteiros
    String **novo = realloc(list->list, novaCapacidade * sizeof(String *));
    if (novo == NULL) {
        // se realloc falhar, não altera nada
        return;
    }

    list->list = novo;
    list->size = novaCapacidade;

    // inicializa os novos slots com NULL
    for (int i = list->length; i < list->size; i++) {
        list->list[i] = NULL;
    }
}
