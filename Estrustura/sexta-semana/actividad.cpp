//Primitivas:
//Crear pila
//apilar 
//desapilar
//tope
//Pila Vacia
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
//char significa que se va a colocar un caracter, en este caso el plato
//hay platos de porcelana y de carton, por lo que se colocara una letra para cada uno, por ejemplo P para porcelana y C para carton
void Fregar(Pila *&pila)
{
    char platos;
    while (!PilaVacia(pila))
    {
        if (Tope(pila)->platos=="P")
        {
            cout<<"Si tienes que fregar"<<endl;
            return;
        }
        Desapilar(pila);
    }cout<<"No tienes que fregar"<<endl;
}
int main()
{
    Pila *platos = nullptr;
    llenarPila(platos);
    mostrarPila(platos);
    Fregar(platos);
}

