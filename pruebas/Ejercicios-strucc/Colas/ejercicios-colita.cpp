#include <iostream>
using namespace std;
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
// Operaciones básicas de Colas
// Elaborado por Lia Mendoza

struct Cola
{
   int dato;
   Cola *prox;
};

Cola *crearCola(int valor)
{
   Cola *nuevo = new Cola;
   nuevo->dato = valor;
   nuevo->prox = NULL;
   return nuevo;
}

bool ColaVacia(Cola *col)
{
   return col == NULL;
}

Cola *PrimeroCola(Cola *col)// es el tope o la direccion de memoria del primer numero de la cola
{
   if (!ColaVacia(col))
      return col;
   else
      return nullptr;
}

void Encolar(Cola *&col, int valor)// insertar ultimo
{
   Cola *nuevo = crearCola(valor);
   if (ColaVacia(col))
   {
      col = nuevo;
   }
   else
   {
      Cola *auxiliar = col;
      while (auxiliar->prox != NULL)
      {
         auxiliar = auxiliar->prox;
      }
      auxiliar->prox = nuevo;
   }
}

void Desencolar(Cola *&col)
{
   if (!ColaVacia(col))
   {
      col = col->prox;
   }
   else
      cout << "Cola vacia imposible desencolar " << endl;
}

void mostrarCola(Cola *&cola)
{
   Cola *colaAux = nullptr;

   if (ColaVacia(cola))
   {
      cout << "La cola esta vacia" << endl;
   }
   else
   {
      while (!ColaVacia(cola))
      {
         int dato = PrimeroCola(cola)->dato;
         cout << dato << "  ";
         Encolar(colaAux, dato);
         Desencolar(cola);
      }

      while (!ColaVacia(colaAux))
      {
         Encolar(cola, PrimeroCola(colaAux)->dato);
         Desencolar(colaAux);
      }
      cout << endl;
   }
}

void llenarCola(Cola *&col)
{
   int cantidad, i, valor;
   cout << "Indica cantidad de elementos a ser colocados en la Cola: ";
   cin >> cantidad;
   i = 0;
   while (i != cantidad)
   {
      cout << "Indica valor a colocar: ";
      cin >> valor;
      Encolar(col, valor);
      i++;
   }
}

void juntarcolas(Cola *&col1,Cola *&col2,Cola *&col3)
{
   while (!ColaVacia(col1) || !ColaVacia(col2))
   {
      if (!ColaVacia(col1))
      {
         int datoA =PrimeroCola(col1)->dato;
         Encolar(col3, datoA);
         Desencolar(col1);
      }
      if (!ColaVacia(col2))
      {
         int datoB = PrimeroCola(col2)->dato;
         Encolar(col3, datoB);
         Desencolar(col2);
      }
   }
   
}
// Desarrolla un procedimiento que permita invertir los N primeros 
// elementos de una cola. Ejemplo: C={1,2,3,4,5,6,7,8,9} y N = 5 
// CInverN= {5,4,3,2,1,6,7,8,9}
void invertirnumeros(Cola *&cola, int x)
{
   if (ColaVacia(cola) || x<=0)
   {return;}
   Pila *aux = nullptr;
   for (int i=1;i<=x;i++)
   {
      Apilar(aux, PrimeroCola(cola)->dato);
      Desencolar(cola);
   }
   Cola *auxcola = nullptr;
   while (!PilaVacia(aux))
   {
      Encolar(auxcola,Tope(aux)->dato);
      Desapilar(aux);
   }
   while (!ColaVacia(cola))
   {
      Encolar(auxcola,PrimeroCola(cola)->dato);
      Desencolar(cola);
   }
   cola = auxcola;
}
main()
{
   Cola *cola = nullptr;
   llenarCola(cola);
   mostrarCola(cola);
   invertirnumeros(cola,3);
   mostrarCola(cola);
}