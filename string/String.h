#ifndef STRING_H
#define STRING_H

typedef struct{
    char *data; // array de ponteiros para palavras / array de char
    int length;      // número de pedaços
    int limite;     // capacidade máxima do array

}String;

    
typedef struct{
    String** list;
    int length;
    int size;
}StringList;

extern StringList *coletor;

String* string(char **data);

int contaLength(char **data);

int contaLinha(char **lista);

char* escrita(char **data);

void println(String* string);

void freeString(String** string);

void freeColetor();
void addLixo(String* string);

void coletar(StringList *list);

StringList* stringList(int initialSize);
void incrementStringList(StringList *list);


#endif