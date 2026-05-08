#include <iostream>
using namespace std;
// Eliminar duplicados de la Pila
// Elaborado por Lia Mendoza

struct Pila
{
    int dato;
    Pila *prox;
};

Pila *crearPila(int valor)
{
    Pila *nuevo = new Pila;
    nuevo->dato = valor;
    nuevo->prox = NULL;
    return nuevo;
}

bool PilaVacia(Pila *pila)
{
    return pila == NULL;
}

Pila *Tope(Pila *pila)
{
    if (!PilaVacia(pila))
        return pila;
    else
        return nullptr;
}

void Apilar(Pila *&pila, int valor)
{
    Pila *nuevo = crearPila(valor);
    nuevo->prox = pila;
    pila = nuevo;
}

void Desapilar(Pila *&pila)
{
    if (!PilaVacia(pila))
    {
        Pila *temp = pila;
        pila = pila->prox;
        delete temp;
    }
    else
    {
        cout << "Pila vacía, imposible desapilar" << endl;
    }
}

void mostrarPila(Pila *&pila)
{
    Pila *aux = nullptr;

    while (!PilaVacia(pila))
    {
        cout << Tope(pila)->dato << "  ";
        Apilar(aux, Tope(pila)->dato);
        Desapilar(pila);
    }
    while (!PilaVacia(aux))
    {
        Apilar(pila, Tope(aux)->dato);
        Desapilar(aux);
    }
}

void llenarPila(Pila *&pila)
{
    int cantidad, i, valor;
    cout << "Indica cantidad de elementos a ser colocados en la pila: ";
    cin >> cantidad;
    i = 0;
    while (i != cantidad)
    {
        cout << "Indica valor a colocar: ";
        cin >> valor;
        Apilar(pila, valor);
        i++;
    }
}

bool ExisteEnPila(Pila *&pila, int valor)
{
    bool existe = false;
    Pila *temp = nullptr;

    while (!PilaVacia(pila) && existe == false)
    {
        if (Tope(pila)->dato == valor)
            existe = true;
        Apilar(temp, Tope(pila)->dato);
        Desapilar(pila);
    }

    while (!PilaVacia(temp))
    {
        Apilar(pila, Tope(temp)->dato);
        Desapilar(temp);
    }
    return existe;
}


void EliminarDuplicados(Pila *&pila)
{
    Pila *aux = nullptr;
    int valor;

    while (!PilaVacia(pila))
    {
        valor = Tope(pila)->dato;
        if (!ExisteEnPila(aux, valor))
            Apilar(aux, valor);
        Desapilar(pila);
    }

    while (!PilaVacia(aux))
    {
        Apilar(pila, Tope(aux)->dato);
        Desapilar(aux);
    }
}

main()
{

    Pila *pila = NULL;

    llenarPila(pila);
    cout << "Contenido de la Pila original: " << endl;
    mostrarPila(pila);
    EliminarDuplicados(pila);
    cout <<"\nContenido de la Pila despues de eliminar duplicados: " << endl;
    mostrarPila(pila);
}