/* Rutinas básicas */
#include "queue.h"

void initialize(queue *q)
{
    q -> cnt = 0;  // La cuenta de una cola comienza en 0.
    q -> head = NULL; // La cabeza de la cola comienza en Nulo.
    q -> tail = NULL; // La parte trasera de la cola comienza en Nulo.
}

data dequeue(queue *q)
{
    data d;
    elem *p;

    d = q -> head -> d; // El dato es el que está almacenado en la cabeza de la cola.
    p = q -> head; // El elemento p es la cabeza de la cola.
    q -> head = q -> head -> next; //Cuando desencolamos la cabeza, la nueva cabeza debe ser el siguiente elemento en la cola al que apuntaba la cabeza que desencolamos.
    q -> cnt--; //Bajamos el contador de la cola una unidad.
    free(p); //Liberamos el espacio ocupado por la cabeza desencolada.
    return d; //Vamos a ver lo que estaba guardado en la cabeza desencolada.
}

void enqueue(data d, queue *q)
{
    elem *p;    // Declaramos un apuntador a un espacio donde reservar un objeto de tipo "elem" (elemento de una cola)

    p = malloc(sizeof(elem)); // Encontramos una ubicación en la memoria con suficiente espacio para almacenar un objeto de tipo "elemento" y se la pasamos al apuntador p.

    p -> d = d; // El dato d (una de las componentes del elemento apuntado por p) lo rellenamos con el dato que tenemos en los argumentos de la función "enqueue".

    p -> next = NULL; // El apuntador al "siguiente elemento de la cola" lo iniciamos en nulo, porque en este momento no sabemos si la cola está vacía o no.

    if (!empty(q)) {
        q -> tail -> next = p; // Si la cola no estaba vacía, entonces hacemos que su último elemento antes de encolar ahora apunte como "siguiente" al nuevo elemento que estamos encolando.

        q -> tail = p; // Actualizamos el apuntador al último elemento de la cola.
    } 
    else {
        q -> head = q -> tail = p; // Si la cola está vacía, ambos apuntadores head y tail adoptan lo que el apuntador p contiene.
    }
    q -> cnt++; //Aumentamos la cuenta del apuntador
}

data head(const queue *q)
{
    return q -> head -> d; // Retornamos el dato guardado en el primer elemento de la cola
}

boolean empty(const queue *q)
{
    return ((boolean) (q -> cnt == EMPTY));
}

boolean full(const queue *q)
{
    return ((boolean) (q -> cnt >= 6)); // Comparamos la cuenta actual contra el máximo permitido (FULL)
}

/* --- INICIO DE MODIFICACIONES PARA EL SISTEMA DE COMANDAS --- */

/* 1. Definimos los platillos posibles con enum */
enum Menu {
    HAMBURGUESA = 1,
    PIZZA = 2,
    TACOS = 3,
    ENSALADA = 4
};

/* 2. Arreglo para traducir el número del enum a texto para el usuario */
const char *nombres_platillos[] = {
    "Vacio",        // Indice 0 (no se usa)
    "Hamburguesa",  // Indice 1
    "Pizza",        // Indice 2
    "Tacos",        // Indice 3
    "Ensalada"      // Indice 4
};

int main(void)
{
    int opcion;
    data platillo; 
    queue comandas;

    initialize(&comandas); // Inicializamos la cola de comandas

    printf("--- SISTEMA DE COMANDAS ---\n");

    // Bucle principal del sistema
    while (1) {
        printf("\nAcciones disponibles:\n");
        printf("[1] Recibir comanda (enqueue)\n");
        printf("[2] Servir platillo (dequeue)\n");
        printf("[3] Consultar siguiente platillo (head)\n");
        printf("[4] Salir\n");
        printf("Elige una accion: ");
        
        // Si el usuario ingresa algo que no es un número, evitamos que se trabe
        if (scanf("%d", &opcion) != 1) {
            while(getchar() != '\n'); // Limpiamos el buffer
            continue; 
        }

        switch (opcion) {
            case 1: // Enqueue
                if (!full(&comandas)) {
                    printf("\nMenu: 1.Hamburguesa | 2.Pizza | 3.Tacos | 4.Ensalada\n");
                    printf("Ingresa el numero del platillo a ordenar (1-4): ");
                    
                    if (scanf("%u", &platillo) == 1 && platillo >= HAMBURGUESA && platillo <= ENSALADA) {
                        enqueue(platillo, &comandas);
                        printf("-> Comanda anotada: %s.\n", nombres_platillos[platillo]);
                    } else {
                        printf("-> ERROR: Platillo no existe en el menu.\n");
                    }
                } else {
                    printf("-> ERROR: La cola de ordenes esta llena.\n");
                }
                break;
                
            case 2: // Dequeue
                if (!empty(&comandas)) {
                    platillo = dequeue(&comandas);
                    printf("-> Sirviendo: %s. !Que lo disfrute!\n", nombres_platillos[platillo]);
                } else {
                    printf("-> No hay ordenes pendientes por servir.\n");
                }
                break;
                
            case 3: // Head
                if (!empty(&comandas)) {
                    platillo = head(&comandas);
                    printf("-> El siguiente platillo en la fila es: %s\n", nombres_platillos[platillo]);
                } else {
                    printf("-> La cola de comandas esta vacia en este momento.\n");
                }
                break;
                
            case 4: // Salir
                printf("Cerrando el sistema...\n");
                return 0;
                
            default:
                printf("-> Opcion no reconocida. Intenta de nuevo.\n");
        }
    }
    return 0;
}
