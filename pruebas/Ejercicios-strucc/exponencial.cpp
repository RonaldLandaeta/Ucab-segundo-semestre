// "5. Se tiene una lista simplemente enlazada, se desea eliminar varios nodos según un i que aumenta de forma exponencial en base a 2, el algoritmo debe detenerse cuando no sea posible seguir eliminando en la lista (5pts)."
#include <iostream>
using namespace std;
// Elaborado por Lia Mendoza
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

// void eliminarexponencial (Nodo *lista)
// {
//     Nodo *anterior = nullptr;
//     Nodo  *mover = lista;
//     int contador = 1;
//     int i = 1;
//     while (mover != NULL)
//     {
//         i = i*2;
//         while (contador < i)
//         {
//             contador ++;
//             if (contador == i)
//             {
//                 anterior= lista;
//                 Nodo *temp = mover;
//                 anterior->prox=temp->prox;
//                 delete temp;
//             }
//         }
//     }
// }
void ElimExp(Nodo *p)
{
    Nodo *aux= p, *elim=nullptr;
    int i= 2, cont= 1;
    while (aux!=nullptr && aux->prox!=nullptr){
        if (cont+1 == i)
        {
            elim= aux->prox;
            aux->prox= elim ->prox;
            delete elim;
            i *= 2;
        }
        aux= aux->prox;
        cont ++;
    }
}

main()
{
    Nodo *lista = nullptr;
    insertarUltimo(lista,1);
    insertarUltimo(lista,2);
    insertarUltimo(lista,3);
    insertarUltimo(lista,4);
    insertarUltimo(lista,5);
    insertarUltimo(lista,6);
    insertarUltimo(lista,7);
    insertarUltimo(lista,8);
    insertarUltimo(lista,9);
    insertarUltimo(lista,10);
    mostrarLista(lista);
    ElimExp(lista);
    mostrarLista(lista);
    cout<<"Patata"<<endl;

}