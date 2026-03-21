/* Una implementación de cola circular mediante un arreglo */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define    EMPTY    0
#define    FULL     10 // Tamaño para la cola circular

typedef    unsigned int     data;
typedef    enum {FALSO, VERDADERO}   boolean;

struct c_queue {
    data  items[FULL];   // Arreglo fijo para los datos
    int   head;           // La cabeza de la cola
    int   tail;           // La parte trasera de la cola
    int   cnt;            // Cuenta los elementos de la cola
};

typedef    struct c_queue        c_queue;

/* Operaciones básicas de colas circulares */
void        initialize_c(c_queue *q);
void        enqueue_c(data d, c_queue *q);
data        dequeue_c(c_queue *q);
boolean     empty_c(const c_queue *q);
boolean     full_c(const c_queue *q);
