#include <iostream>
#include <ctime>
using namespace std;
// Elaborado por Lia Mendoza

// Dada una lista eliminar los elementos que se encuentren duplicados en forma consecutiva
// Ejemplo: L1 = {3, 3, 5, 4, 4, 3, 7} despues de eliminar queda como L1 = {3, 5, 4, 3, 7}

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

int pedir_valor()
{
    int valor;
    cout << "Indica valor: ";
    cin >> valor;
    return valor;
}

void llenarListaManual(Nodo *&inicio, string mensaje)
{
    int cantidad;
    cout << "Indica cantidad de elementos a colocar en la " << mensaje;
    cin >> cantidad;
    for (int i = 0; i < cantidad; i++)
    {
        insertarUltimo(inicio, pedir_valor());
    }
}

void eliminarDuplicadosConsecutivos(Nodo *&inicio)
{
    if (listaVacia(inicio) || inicio->prox == NULL)
        cout << " Error La lista se encuentra vacia o posee un solo elemento " << endl;
    else
    {
        Nodo *actual = inicio, *aBorrar;
        while (actual != NULL && actual->prox != NULL)
        {
            if (actual->dato == actual->prox->dato)
            {
                aBorrar = actual->prox;
                actual->prox = aBorrar->prox;
                delete aBorrar;
            }
            else
                actual = actual->prox;
        }
    }
}

main()
{
    Nodo *inicio = NULL;

    llenarListaManual(inicio, "lista: ");
    cout << "\nLista original:\n";
    mostrarLista(inicio);
    eliminarDuplicadosConsecutivos(inicio);
    cout << "\nLista despues de eliminar duplicados consecutivos:\n";
    mostrarLista(inicio);
}