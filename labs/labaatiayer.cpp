  //Resuelve los requerimientos siguientes (crea todos los subprogramas que consideres
//necesarios ya sea procedimientos y/o funciones con el debido uso de parámetros).
//Emplea las primitivas de listas ubicadas en módulo 7.
//A partir de un valor dado por el usuario (cada requerimiento es independiente)
//a) Indicar el porcentaje de veces que aparece el valor dado en la lista con
//respecto al total de elementos.
//b) Modifica la operación de búsqueda ubicada en el código correspondiente a las
//primitivas de listas para que en lugar de un valor retorne un puntero que
//representa la ubicación del elemento que se recibe como parámetro.
//c) Eliminar todas las apariciones del valor en la lista.
//d) Insertar el valor ordenadamente en la lista en forma ascendente (observación:
//se trata de crear la lista desde cero en forma ordenada, no de aplicar un
//algoritmo de ordenamiento).
#include <iostream>
#include <ctime>
using namespace std;
// Elaborado por Lia Mendoza
int cantidad_veces = 0;
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

void eliminar(Nodo *&inicio, int valor)
{
   Nodo *mover, *anterior = NULL;

   if (listaVacia(inicio))
      cout << "Lista esta vacia" << endl;
   else
   {
      mover = inicio;
      while (mover != NULL && mover->dato != valor)
      {
         anterior = mover;
         mover = mover->prox;
      }
      if (mover == NULL)
         cout << "El elemento no existe en la lista " << endl;
      else
      {
         if (mover == inicio)
            inicio = inicio->prox;
         else
            //while ()
            {
               anterior->prox = mover->prox;
         delete mover;
            }
      }
   }
}

void insertarPrimero(Nodo *&inicio, int valor)
{
   Nodo *nuevo = crearNodo(valor);
   nuevo->prox = inicio;
   inicio = nuevo;
}

void buscarElementopt2(Nodo *inicio, int valor)
{
   Nodo *aux = inicio;
   bool encontrado = false;
   if (listaVacia(inicio))
      cout << "Lista vacia" << endl;
   else
   {
      while (aux != NULL)
      {
         if (aux->dato == valor)
         {
            cantidad_veces ++;
            cout << "El dato " << valor << " fue encontrado con exito, veces encontrado: "<<cantidad_veces<< endl;
            encontrado = true;
            aux = aux->prox;
         }
         else
            aux = aux->prox;
      }
      if (encontrado == false)
         cout << "Valor no encontrado en la lista " << endl;
   }
}
void buscarElemento(Nodo *inicio, int valor)
{
   Nodo *aux = inicio;
   bool encontrado = false;
   if (listaVacia(inicio))
      cout << "Lista vacia" << endl;
   else
   {
      while (aux != NULL && encontrado == false)
      {
         if (aux->dato == valor)
         {
            cout << "El dato " << valor << " fue encontrado con exito" << endl;
            cout<<"La direccion relacionada a este puntero es: "<<aux<<endl;
            encontrado = true;
         }
         else
            aux = aux->prox;
      }
      if (encontrado == false)
         cout << "Valor no encontrado en la lista " << endl;
   }
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
int cantidad;
void llenarlista(Nodo *&inicio, string mensaje)
    { 
    cout<<"indica cantidad de elementos a colocar en"<<mensaje;
    cin>>cantidad;
    srand((unsigned) time(nullptr));//esto es un inicializador de numeros aleatorios
    for (int i=0; i<cantidad;i++)
    {
        int valor=1 + rand()%10;
        insertarUltimo(inicio,valor);
    }
}

main()
{
   int opcion;
   cout<<"Incida que opcion desea:"<<endl;
   cout<<"1) Porcentaje de aparicion del valor"<<endl;
   cout<<"2) Printear puntero"<<endl;
   cout<<"3) Eliminar apariciones"<<endl;
   cout<<"4) insertar valor ordenado"<<endl;
   cout<<"5) Salir del programa"<<endl;
   cin>>opcion;
   Nodo *lista = NULL;
   int valor;
   llenarlista(lista,":");
   if (opcion==1)
   {  
      cout<<"Tu lista es:"<<endl;
      mostrarLista(lista);
      cout<<"Que elemento desea buscar de esta lista?: "<<endl;
      cin>>valor;
      buscarElementopt2(lista, valor);
      float promedio=(cantidad_veces*100)/cantidad;
      cout<<"El porcentaje de aparicion del valor "<<valor<<" es: "<<promedio<<"%"<<endl;
   };
   if (opcion==2){
      int puntero;
      mostrarLista(lista);
      cout<<"Cual es el puntero que desea buscar?: "<<endl;
      cin>>puntero;
      buscarElemento(lista, puntero);
   }
   if (opcion==3){
      mostrarLista(lista);
      int pepe;
      cout<<"Que elemento quieres eliminar en la lista?: ";
      cin>> pepe;
      eliminar(lista, pepe);
      cout<<"Los elementos restantes de la lista son";
      mostrarLista(lista);
   }   
   if (opcion==4){}
   else
      cout<<"Sale del programa";
}