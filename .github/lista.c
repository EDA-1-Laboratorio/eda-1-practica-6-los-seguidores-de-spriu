#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"


void initialize(lista *l) {
    l->head = NULL;
    l->tail = NULL;
    l->cnt = 0;
}


int empty(lista *l) {
    return l->head == NULL;
}


//Insertar al inicio
void insertarInicio(char *c, lista *l) {
    nodo *p = (nodo*) malloc(sizeof(nodo));
    strcpy(p->cancion, c);


    p->prev = NULL;
    p->next = l->head;


    if (!empty(l))
        l->head->prev = p;
    else
        l->tail = p;


    l->head = p;
    l->cnt++;
}


//Insertar al final
void insertarFinal(char *c, lista *l) {
    nodo *p = (nodo*) malloc(sizeof(nodo));
    strcpy(p->cancion, c);


    p->next = NULL;
    p->prev = l->tail;


    if (!empty(l))
        l->tail->next = p;
    else
        l->head = p;


    l->tail = p;
    l->cnt++;
}


//Eliminar inicio
void eliminarInicio(lista *l, char *resultado) {
    nodo *p = l->head;


    strcpy(resultado, p->cancion);


    l->head = p->next;


    if (l->head != NULL)
        l->head->prev = NULL;
    else
        l->tail = NULL;


    free(p);
    l->cnt--;
}


//Eliminar final
void eliminarFinal(lista *l, char *resultado) {
    nodo *p = l->tail;


    strcpy(resultado, p->cancion);


    l->tail = p->prev;


    if (l->tail != NULL)
        l->tail->next = NULL;
    else
        l->head = NULL;


    free(p);
    l->cnt--;
}


// Mostrar playlist
void mostrar(lista *l) {
    nodo *aux = l->head;


    while (aux != NULL) {
        printf("\n%s\n", aux->cancion);
        aux = aux->next;
    }
}


int main() {
    lista l;
    int op;
    char cancion[100];
    char eliminada[100];


    initialize(&l);


    do {
        printf("\n--- PLAYLIST ---\n");
        printf("1. Agregar al inicio\n");
        printf("2. Agregar al final\n");
        printf("3. Eliminar inicio\n");
        printf("4. Eliminar final\n");
        printf("5. Mostrar playlist\n");
        printf("6. Salir\n");
        printf("Opcion: ");
        scanf("%d", &op);
        getchar(); // limpiar buffer


        switch(op) {


            case 1:
                printf("\nNombre de la cancion: ");
                fgets(cancion, 100, stdin);
                cancion[strcspn(cancion, "\n")] = 0;
                insertarInicio(cancion, &l);
                break;


            case 2:
                printf("\nNombre de la cancion: ");
                fgets(cancion, 100, stdin);
                cancion[strcspn(cancion, "\n")] = 0;
                insertarFinal(cancion, &l);
                break;


            case 3:
                if (!empty(&l)) {
                    eliminarInicio(&l, eliminada);
                    printf("\nEliminada: %s\n", eliminada);
                } else {
                    printf("\nPlaylist vacia\n");
                }
                break;


            case 4:
                if (!empty(&l)) {
                    eliminarFinal(&l, eliminada);
                    printf("\nEliminada: %s\n", eliminada);
                } else {
                    printf("\nPlaylist vacia\n");
                }
                break;


            case 5:
                mostrar(&l);
                break;


            case 6:
                printf("\nSaliendo...\n");
                break;


            default:
                printf("\nOpcion invalida\n");
        }


    } while (op != 6);


    return 0;
}
