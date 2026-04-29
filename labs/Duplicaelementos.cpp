#include <iostream>
using namespace std;
// Operaciones bÃ¡sicas de Pilas
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
        cout << "Pila vacÃ­a, imposible desapilar" << endl;
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
void duplicarPila(Pila *&pila)
{
    Pila *aux1=nullptr;
    Pila *aux2=nullptr;
    while (!PilaVacia(pila))
    {
        Apilar(aux1, Tope(pila)->dato);
        Apilar(aux2, Tope(pila)->dato);
        Desapilar(pila);
    }
    while (!PilaVacia(aux1)&&!PilaVacia(aux2))
    {
        Apilar(pila, Tope(aux1)->dato);
        Apilar(pila, Tope(aux2)->dato);
        Desapilar(aux1), Desapilar(aux2);
    }
}
int main()
{
    Pila *pila = nullptr;
    llenarPila(pila);
    cout << "Pila original: ";
    mostrarPila(pila);
    duplicarPila(pila);
    cout << "\nPila duplicada: ";
    mostrarPila(pila);
};