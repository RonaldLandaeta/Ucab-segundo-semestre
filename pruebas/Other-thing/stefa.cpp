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

// main()
// {

//     Pila *pila = NULL;

//     llenarPila(pila);
//     cout << "Contenido de la Pila original: " << endl;
//     mostrarPila(pila);
//     cout << endl;
//     Desapilar(pila);
//     cout << "Contenido de la Pila despues de desapilar: " << endl;
//     mostrarPila(pila);
//     cout << endl;
//     Apilar(pila, 555);
//     cout << "Contenido de la Pila luego de apilar un elemento: " << endl;
//     mostrarPila(pila);
// }

int tope( Pila *p)
{
/* Devuelve el valor tope de la pila si no es vacia */
if (!(PilaVacia(p))) return p->dato;
return 0;
};
void elimparcial(Pila *&pila, int x)
{
    Pila *aux= nullptr;
    while(!PilaVacia(pila)){
        Apilar(*&aux, tope(pila)); Desapilar(pila);
    }
    int pos= 1;
    while (!PilaVacia(aux)){ int valor= tope(aux);
        if ((pos% 2== 0) && (valor % x==0)) {
            Desapilar(aux);}
        else {
            Apilar(pila, valor); Desapilar(aux);
        }
        pos ++;
    };
};

int main()
{
    Pila *pila = NULL;
    Apilar(pila, 27);
    Apilar(pila, 11);
    Apilar(pila, 6);
    Apilar(pila, 18);
    Apilar(pila, 9);
    Apilar(pila, 2);
    Apilar(pila, 15);
    Apilar(pila, 12);
    Apilar(pila, 3);
    Apilar(pila, 7);
elimparcial (pila, 3);
mostrarPila(pila);


}