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

void analizarlista(Nodo *inicio)
{
    Nodo *mover = inicio;
    int suma = 0, contador = 0;
    float promedio = 0;
    if (listaVacia(inicio))
    {
        cout << "Error lista vacia " << endl;
    }
    else
    {
        while (mover != NULL)
        {
            suma += mover->dato;
            contador++;
            mover = mover->prox;
        }
        promedio = suma / contador;

        cout << "\n ---- Estadísticas de la lista ----" << endl;
        cout << "Suma total de los elementos: " << suma << endl;
        cout << "Cantidad total de nodos: " << contador << endl;
        cout << "Promedio de los valores: " << promedio << endl;
        cout << "------------------------------------" << endl;
    }
}

int pedir_valor()
{
    int valor;
    cout << "Indica valor: ";
    cin >> valor;
    return valor;
}

main()
{
    Nodo *Primero = nullptr;
    int cantidad, i = 1;
    cout << "Indica cantidad de nodos a ser colocados: ";
    cin >> cantidad;
    while (i <= cantidad)
    {
        insertarUltimo(Primero, pedir_valor());
        i++;
    }
    cout<<"Elementos de la lista: ";
    mostrarLista(Primero);
    analizarlista(Primero);

}