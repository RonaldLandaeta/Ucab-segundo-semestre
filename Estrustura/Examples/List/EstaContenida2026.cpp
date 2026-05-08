#include <iostream>
using namespace std;
// Elaborado por Lia Mendoza

struct Nodo
{
    int dato;
    Nodo *prox;
};

Nodo *crearNodo(int valor)
{
    Nodo *nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->prox = NULL;
    return nuevo;
}

bool listaVacia(Nodo *inicio)
{
    return inicio == NULL;
}

void mostrarLista(Nodo *inicio)
{
    Nodo *mover;

    if (!listaVacia(inicio))
    {
        mover = inicio;
        while (mover != NULL)
        {
            cout << mover->dato << "->";
            mover = mover->prox;
        }
        cout << "NULL" << endl;
    }
    else
        cout << "Lista esta vacia" << endl;
}

void insertarUltimo(Nodo *&inicio, int valor)
{
    Nodo *nuevo = crearNodo(valor);

    if (listaVacia(inicio))
    {
        inicio = nuevo;
    }
    else
    {
        Nodo *auxiliar = inicio;
        while (auxiliar->prox != NULL)
        {
            auxiliar = auxiliar->prox;
        }
        auxiliar->prox = nuevo;
    }
}

void llenarLista(Nodo *&inicio, string mensaje)
{
    int cantidad, i = 1, valor;
    cout << "Indica cantidad de nodos a ser colocados  en la " << mensaje;
    cin >> cantidad;
    while (i <= cantidad)
    {
        cout << "Indica valor: ";
        cin >> valor;
        insertarUltimo(inicio, valor);
        i++;
    }
}

bool estaContenida(Nodo *lista1, Nodo *lista2)
{
    if (listaVacia(lista1) || listaVacia(lista2))
    {
        cout << "Error una de las listas esta vacia " << endl;
        return false;
    }
    else
    {
        Nodo *l2 = lista2;

        while (l2 != NULL)
        {
            Nodo *l1 = lista1;
            Nodo *comienzo = l2;

            while (l1 != NULL && comienzo != NULL && l1->dato == comienzo->dato)
            {
                l1 = l1->prox;
                comienzo = comienzo->prox;
            }

            if (l1 == NULL)
                return true;

            l2 = l2->prox;
        }
    }
    return false;
}

main()
{
    Nodo *lista1 = NULL;
    Nodo *lista2 = NULL;

    llenarLista(lista1, "Lista 1: ");
    llenarLista(lista2, "Lista 2: ");
    cout << "Lista 1: " << endl;
    mostrarLista(lista1);
    cout << "Lista 2: " << endl;
    mostrarLista(lista2);
    if (estaContenida(lista1, lista2))
        cout << "La lista 1 esta contenida en la lista 2" << endl;
    else
        cout << "La lista 1  NO esta contenida en la lista 2" << endl;
}