#ifndef PLAYLIST_H
#define PLAYLIST_H


typedef struct nodo {
    char cancion[100];
    struct nodo *next;
    struct nodo *prev;
} nodo;


typedef struct {
    nodo *head;
    nodo *tail;
    int cnt;
} lista;


void initialize(lista *l);
int empty(lista *l);


void insertarInicio(char *c, lista *l);
void insertarFinal(char *c, lista *l);


void eliminarInicio(lista *l, char *resultado);
void eliminarFinal(lista *l, char *resultado);


void mostrar(lista *l);


#endif
