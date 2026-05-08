#include <iostream>
using namespace std;

struct Nodo
{
    int dato;
    Nodo *prox;
};

main()
{
    Nodo *Primero, *n;
    Primero = NULL;
    n = new Nodo;
    n->dato = 3;
    n->prox = NULL;
    Primero = n;
    n = new Nodo;
    n->dato = 5;
    n->prox = NULL;
    Primero->prox = n;
    n = new Nodo;
    n->dato = 20;
    n->prox = NULL;
    Primero->prox->prox = n;

    Nodo *actual;

    actual = Primero;
    while (actual != NULL)
    {
        cout << actual->dato << "->";
        actual = actual->prox;
    }
    cout << "NULL" << endl;

    // este es un ejemplo donde se elimina un nodo
    Nodo *anterior = NULL, *borrar;

    actual = Primero;

    while (actual != NULL)
    {
        if (actual->dato == 5)
        {
            borrar = actual; // guardas el nodo que vas a eliminar

            if (actual == Primero)
            {  // caso que el elemento a borrar sea el primero de la lista
                Primero = actual->prox; // este es el unico caso donde vas a mover el puntero primero
                actual = Primero;       // actual pasa a ubicarse en el nuevo inicio de la lista
            }
            else
            {  // si el elemento a borrar esta en cualquier posicion
                anterior->prox = actual->prox; // se hace el puente de conexion antes de entre los nodos para no perder la lista
                actual = actual->prox;         // actual se queda ubicado en el siguiente elemento de la lista y permite eliminar
                                               // mas números 5 si existieran
            }

            delete borrar; // borras definitivamente el nodo de la memoria
        }
        else
        {
            // Solo avanzamos el anterior si NO borramos nada
            anterior = actual;
            actual = actual->prox;
        }
    }

    actual = Primero;
    while (actual != NULL)
    {
        cout << actual->dato << "->";
        actual = actual->prox;
    }
    cout << "NULL";     

}