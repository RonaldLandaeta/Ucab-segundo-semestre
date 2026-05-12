#include <iostream>
using namespace std;
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

Cola *PrimeroCola(Cola *col)
{
   if (!ColaVacia(col))
      return col;
   else
      return nullptr;
}

void Encolar(Cola *&col, int valor)
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
      cout << "La cola está vacía" << endl;
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

void llenarCola(Cola *&col, string mensaje)
{
   int cantidad, i, valor;
   cout << "Indica cantidad de elementos a ser colocados en "<<mensaje;
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


void IntercalarColas(Cola *c1, Cola *c2, Cola *&resultado) {
    while (!ColaVacia(c1) || !ColaVacia(c2)) {
        if (!ColaVacia(c1)) {
            Encolar(resultado, PrimeroCola(c1)->dato);
            Desencolar(c1);
        }
        if (!ColaVacia(c2)) {
            Encolar(resultado, PrimeroCola(c2)->dato);
            Desencolar(c2);
        }
    }
}

main()
{
   Cola *cola1 = NULL, *cola2=NULL, *Resul=NULL;
   llenarCola(cola1,"Cola 1: ");
   llenarCola(cola2,"Cola 2: ");
   cout<<"Contenido de la Cola 1: "<<endl;
   mostrarCola(cola1);
   cout<<"Contenido de la Cola 2: "<<endl;
   mostrarCola(cola2);
   IntercalarColas(cola1,cola2,Resul);
   cout<<"Contenido de la Cola intercalada: "<<endl;
   mostrarCola(Resul);
}