//Agregar un elemento a una lista en forma ordenada (observación: no se trata de desarrollar un algoritmo de ordenamiento, sino de modificar la primitiva Insertar para que al crear la lista se haga de forma ordenada)
#include <iostream>
using namespace std;

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

void eliminar(Nodo *&inicio, int valor)
{
    Nodo *mover, *anterior = NULL;

    if (listaVacia(inicio))
    cout << "Lista esta vacia" << endl;
    else
    {
        mover = inicio;
        while (mover != NULL && mover->dato != valor)
        {
            anterior = mover;
            mover = mover->prox;
        }
        if (mover == NULL)
            cout << "El elemento no existe en la lista " << endl;
        else
        {
            if (mover == inicio)
                inicio = inicio->prox;
            else
                anterior->prox = mover->prox;
            delete mover;
        }
    }
}

void insertarPrimero(Nodo *&inicio, int valor)
{
    Nodo *nuevo = crearNodo(valor);
    nuevo->prox = inicio;
    inicio = nuevo;
}

void buscarElemento(Nodo *inicio, int valor)
{
    Nodo *aux = inicio;
    bool encontrado = false;
    if (listaVacia(inicio))
        cout << "Lista vacia" << endl;
    else
    {
        while (aux != NULL && encontrado == false)
        {
            if (aux->dato == valor)
            {
                cout << "El dato " << valor << " fue encontrado con exito" << endl;
                encontrado = true;
            }
            else
                aux = aux->prox;
        }
        if (encontrado == false)
        cout << "Valor no encontrado en la lista " << endl;
    }
}

void insertarOrdenado(Nodo *&inicio, int valor)
{
    Nodo *nuevo = crearNodo(valor);
    Nodo *anterior = NULL;
    Nodo *actual = inicio;

    while (actual != NULL && actual->dato < valor)
    {
        anterior = actual;
        actual = actual->prox;
    }

    if (anterior == NULL)
    {
        nuevo->prox = inicio;
        inicio = nuevo;
    }
    else
    {
        anterior->prox = nuevo;
        nuevo->prox = actual;
    }
}

int main()
{
    Nodo *inicio = NULL;
    insertarOrdenado(inicio, 5);
    insertarOrdenado(inicio, 3);
    insertarOrdenado(inicio, 8);
    insertarOrdenado(inicio, 1);
    cout << "Lista ordenada: ";
    mostrarLista(inicio);
    return 0;
}