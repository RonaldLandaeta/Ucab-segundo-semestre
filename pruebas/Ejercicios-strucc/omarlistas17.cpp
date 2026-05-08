// 1) Dada una lista  
// 1.1) Inserte un valor X dado: 
// 1.1.1) Por la cabeza de la lista 
// 1.1.2) Por el final de la lista 
// 1.1.3) Ordenadamente (en forma ascendente) 
// 1.1.4) Luego de un valor Z dado (si no existe Z no se 
// inserta) 
// Cada una de estas rutinas tiene dos versiones: una que permite 
// repetir claves y otra que no lo permite.
#include <iostream>
#include <ctime>
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
}
void llenarListaAleatoria(Nodo *&inicio, string mensaje)   
{
    int cantidad;
    cout << "Indica cantidad de elementos a colocar en " << mensaje;
    cin >> cantidad;
    srand((unsigned)time(nullptr));
    for (int i = 0; i < cantidad; i++)
    {
        int valor = 1 + rand() % 50;
        insertarUltimo(inicio, valor);
    }
}
void ordenarelementos(Nodo *&inicio)
{   
    Nodo *menor = inicio;
    Nodo *cabeza = inicio;
    Nodo *mover = inicio;
    mover=mover->prox;
    while (!listaVacia(inicio))
    {
        if (menor->dato > mover->dato)
        {
            menor=mover;
            mover=mover->prox;
            cout<<"Candela1"<<endl;
            mostrarLista(inicio);
        }
        else
        {
            mover=mover->prox;
            cout<<"Candela2"<<endl;
            mostrarLista(inicio);
        }
        if (menor->dato<cabeza->dato)
        {
            int temp = cabeza->dato;
            cabeza->dato=menor->dato;
            menor->dato=temp;
            cout<<"Candela3"<<endl;
            mostrarLista(inicio);
        }
        if (menor->dato>=cabeza->dato)
        {
            menor=menor->prox;
        }
        
    }
    
}
main ()
{
    Nodo *inicio = nullptr;
    llenarListaAleatoria(inicio,"l1");
    mostrarLista(inicio);
    ordenarelementos(inicio);
    mostrarLista(inicio);

}