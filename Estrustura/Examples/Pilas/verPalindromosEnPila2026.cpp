#include <iostream>

using namespace std;

struct Pila
{
    char dato;
    Pila *prox;
};

Pila *crearPila(char valor)
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

void Apilar(Pila *&pila, char valor)
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
}

Pila *Tope(Pila *pila)
{
    if (!PilaVacia(pila))
        return pila;
    else
        return nullptr;
}

void Palindromo()
{
    Pila *pilaReversa = NULL;
    Pila *pilaAuxiliar = NULL;
    Pila *pilaDerecha = NULL;
    char caracter;
    string palabra = "";
    bool esPalindromo = true;

    cout << "Ingrese una palabra (presione Enter para finalizar): ";

    while (cin.get(caracter) && caracter != '\n')
    {
        palabra += caracter;
        Apilar(pilaReversa, caracter);
        Apilar(pilaAuxiliar, caracter);
    }

    while (!PilaVacia(pilaAuxiliar)) // ojo con este ciclo aquí invertimos el orden y lo dejamos en pilaDerecha
    {
        Apilar(pilaDerecha, Tope(pilaAuxiliar)->dato);
        Desapilar(pilaAuxiliar);
    }

    // Comparamos ambas pilas
    // Si la palabra es "RADAR":
    // pilaReversa: R -> A -> D -> A -> R
    // pilaDerecha: R -> A -> D -> A -> R

    while (!PilaVacia(pilaReversa) && !PilaVacia(pilaDerecha) && esPalindromo == true)
    {
        if (Tope(pilaReversa)->dato != Tope(pilaDerecha)->dato)
            esPalindromo = false;

        Desapilar(pilaReversa);
        Desapilar(pilaDerecha);
    }

    if (esPalindromo)
        cout << "La palabra " << palabra << " ES un palindromo." << endl;
    else
        cout << "La palabra " << palabra << " NO es un palindromo." << endl;

    // Limpiamos la memoria a fin de no dejar nodos ocupando espacio, en un examen no es obligatorio hacerlo a menos que afecte tus resultados.
    while (!PilaVacia(pilaReversa))
        Desapilar(pilaReversa);
    while (!PilaVacia(pilaDerecha))
        Desapilar(pilaDerecha);
}

main()
{
    Palindromo();
}