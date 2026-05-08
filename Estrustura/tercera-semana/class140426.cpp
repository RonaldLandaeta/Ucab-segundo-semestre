// a partir de una lista simplemente enlazada, elimina todos los elementos que se encuentran fuera de un rango dado por el usuario
// "||" esto significa "o"
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
};

void eliminarfueraderango(Nodo *&inicio, int min_rango, int max_rango) 
    {
        Nodo *actual=inicio, *aeliminar;
    while (actual != NULL)
    { if (actual->dato<min_rango || actual->dato>max_rango)
        {
        aeliminar=actual;
        eliminar(inicio, aeliminar->dato);
        }
    actual=actual->prox; 
    }
};
main ()
    {Nodo *lista1=NULL; int liminf,limsup;
        {
            insertarUltimo(lista1, 5);
            insertarUltimo(lista1, 10);
            insertarUltimo(lista1, 11);
            insertarUltimo(lista1, 1);
            insertarUltimo(lista1, 2);
            insertarUltimo(lista1, 4);
            insertarUltimo(lista1, 7);
            insertarUltimo(lista1, 9);
            cout<<"indica limite indefior del rango: ";
            cin>>liminf;
            cout<<"indica limite superior del rango: ";
            cin>>limsup;
            cout<<"Contenido de la lista antes de eliminar "<<endl;
            mostrarLista(lista1);
            eliminarfueraderango(lista1,liminf,limsup);
            cout<<"contenido de la lista despues de eliminar: ";
            if (!listaVacia(lista1))// ese "!" es una negacion, si no es lista vacia, muetrala
                mostrarLista(lista1);
            else
            cout<<"Lista quedo vacia"<< endl;
        }
    }