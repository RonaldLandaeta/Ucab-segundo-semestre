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

bool numeroParejo(Nodo *inicio)
{
    Nodo *mover = inicio;
    int digito = 0, sumapares = 0, sumaimpares = 0;
    while (mover != NULL)
        {
            digito = mover->dato;
            if (digito % 2 == 0)
                sumapares += digito;
            else
                sumaimpares += digito;
            mover = mover->prox;
        }
        return sumapares == sumaimpares;
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
    cout << "Elementos de la lista: ";
    mostrarLista(Primero);
    if (!listaVacia(Primero)){ 
       bool resultado = numeroParejo(Primero);
       if (resultado)
          cout << "El numero es parejo ";
       else
          cout << "El numero no es parejo";
    }    
}