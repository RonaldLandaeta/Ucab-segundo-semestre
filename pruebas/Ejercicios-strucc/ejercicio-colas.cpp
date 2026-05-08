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
main()
{
   Cola *col1 = nullptr;
   Cola *col2 = nullptr;
   Cola *col3 =nullptr;
   llenarCola(col1);
   llenarCola(col2);
   mostrarCola(col1);
   mostrarCola(col2);
   juntarcolas(col1,col2,col3);
   mostrarCola(col3);
}