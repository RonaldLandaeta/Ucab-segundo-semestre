#include <iostream>
using namespace std;
// Operaciones básicas de Pilas
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
void topmeta(Pila *&pila1)
{
    Pila *aux = nullptr;
    cout<<"Cual es el valor de n: "<<endl;
    int n;
    cin>>n;
    int contador=0;
    while (!PilaVacia(pila1))
    {
        while(contador < n)
        {
            Apilar(aux, Tope(pila1)->dato);
            contador ++;
            Desapilar(pila1);
        }
        Desapilar(pila1);
    }
    while (!PilaVacia(aux))
    {
        Apilar(pila1, Tope(aux)->dato);
        Desapilar(aux);
    }
    cout<<"Tu nueva pila es: ";
    mostrarPila(pila1);
}
main()
{
    Pila *pila1=nullptr;
    llenarPila(pila1);
    topmeta(pila1);
}