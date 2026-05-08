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
// void ordenarelementos(Nodo *&inicio)
// {   
//     Nodo *menor = inicio;
//     Nodo *cabeza = inicio;
//     Nodo *mover = inicio;
//     mover=mover->prox;
//     while (!listaVacia(inicio))
//     {
//         if (menor->dato > mover->dato)
//         {
//             menor=mover;
//             mover=mover->prox;
//             cout<<"Candela1"<<endl;
//             mostrarLista(inicio);
//         }
//         else
//         {
//             mover=mover->prox;
//             cout<<"Candela2"<<endl;
//             mostrarLista(inicio);
//         }
//         if (menor->dato<cabeza->dato)
//         {
//             int temp = cabeza->dato;
//             cabeza->dato=menor->dato;
//             menor->dato=temp;
//             cout<<"Candela3"<<endl;
//             mostrarLista(inicio);
//         }
//         if (menor->dato>=cabeza->dato)
//         {
//             menor=menor-prox;
//         }
//     }
// }
// Versión que PERMITE repetir claves
void insertarOrdenado(Nodo *&inicio, int valor) {
    Nodo *nuevo = crearNodo(valor);
    
    // Caso 1: Lista vacía o el valor es menor que el primero
    if (inicio == NULL || valor < inicio->dato) {
        nuevo->prox = inicio;
        inicio = nuevo;
    } 
    else {
        // Caso 2: Buscar la posición correcta en el medio o al final
        Nodo *mover = inicio;
        while (mover->prox != NULL && mover->prox->dato < valor) {
            mover = mover->prox;
        }
        nuevo->prox = mover->prox;
        mover->prox = nuevo;
    }
}
// Versión que NO PERMITE repetir claves
void insertarOrdenadoSinRepetir(Nodo *&inicio, int valor) {
    // Primero verificamos si el valor ya existe
    Nodo *aux = inicio;
    while (aux != NULL) {
        if (aux->dato == valor) {
            cout << "El valor " << valor << " ya existe (No se inserto)." << endl;
            return; 
        }
        aux = aux->prox;
    }

    // Si no existe, usamos la misma lógica de inserción
    Nodo *nuevo = crearNodo(valor);
    if (inicio == NULL || valor < inicio->dato) {
        nuevo->prox = inicio;
        inicio = nuevo;
    } else {
        Nodo *mover = inicio;
        while (mover->prox != NULL && mover->prox->dato < valor) {
            mover = mover->prox;
        }
        nuevo->prox = mover->prox;
        mover->prox = nuevo;
    }
}
void ordenarListaAscendente(Nodo *inicio) {
    if (inicio == NULL || inicio->prox == NULL) return; // Lista vacía o de un solo elemento
    bool intercambiado;
    Nodo *actual;
    Nodo *ultimoVerificado = NULL;
    do {
        intercambiado = false;
        actual = inicio;
        while (actual->prox != ultimoVerificado) {
            // Si el dato actual es mayor al siguiente, se intercambian
            if (actual->dato > actual->prox->dato) {
                int temp = actual->dato;
                actual->dato = actual->prox->dato;
                actual->prox->dato = temp;
                intercambiado = true;
            }
            actual = actual->prox;
        }
        // El último elemento ya quedó en su posición correcta
        ultimoVerificado = actual;
    } while (intercambiado); // Se repite hasta que no haya más intercambios
}
main ()
{
    Nodo *inicio = nullptr;
    llenarListaAleatoria(inicio,"l1");
    mostrarLista(inicio);
    ordenarListaAscendente(inicio);
    mostrarLista(inicio);

}