/* Una implementación de cola mediante una lista doblemente ligada */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define    EMPTY    0
#define    FULL     10000

typedef    unsigned int     data;
typedef    enum {FALSO, VERDADERO}   boolean;

struct elem {          // Un elemento en la cola
    data         d;
    struct elem  *next;
    struct elem  *prev;      // Apuntador al elemento anterior
};

typedef    struct elem           elem;

struct queue {
    int         cnt;      // Cuenta de los elementos de la cola
    elem        *head;    // Apuntador 'head' de la cola
    elem        *tail;    // Apuntador 'tail' de la cola
};

typedef    struct queue          queue;

/* Operaciones básicas de colas doblemente ligadas */
void        initialize(queue *q);
void        enqueue(data d, queue *q);
data        dequeue(queue *q);
boolean     empty(const queue *q);
boolean     full(const queue *q);
