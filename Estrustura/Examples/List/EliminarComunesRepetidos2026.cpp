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
        anterior->prox = mover->prox;
      delete mover;
    }
  }
}

int pedir_valor()
{
  int valor;
  cout << "Indica valor: ";
  cin >> valor;
  return valor;
}

void llenarListaManual(Nodo *&inicio, string mensaje)
{
  int cantidad;
  cout << "Indica cantidad de elementos a colocar en la " << mensaje;
  cin >> cantidad;
  for (int i = 0; i < cantidad; i++)
  {
    insertarUltimo(inicio, pedir_valor());
  }
}

bool existe(Nodo *inicio, int valor)
{
  Nodo *aux = inicio;
  while (aux != NULL)
  {
    if (aux->dato == valor)
      return true;
    aux = aux->prox;
  }
  return false;
}

void eliminarOcurrencias(Nodo *&inicio, int valor)
{
  while (existe(inicio, valor))
  {
    eliminar(inicio, valor);
  }
}

int eliminarComunes(Nodo *&inicio1, Nodo *&inicio2)
{
  int contador = 0;
  Nodo *actual = inicio1;

  while (actual != NULL)
  {
    int valorABuscar = actual->dato;

    if (existe(inicio2, valorABuscar))
    {
      contador++;
      // Eliminamos todas las ocurrencias o apariciones de los elementos comunes en ambas listas
      eliminarOcurrencias(inicio1, valorABuscar);
      eliminarOcurrencias(inicio2, valorABuscar);
      actual = inicio1; // reiniciamos el puntero actual porque al eliminar se pierde su posicion
    }
    else
    {
      actual = actual->prox;
    }
  }
  return contador;
}

main()
{
  Nodo *L1 = nullptr, *L2 = nullptr;
  llenarListaManual(L1, " Lista 1: ");
  llenarListaManual(L2, " Lista 2: ");

  cout << "\nLista 1: ";
  mostrarLista(L1);
  cout << "Lista 2: ";
  mostrarLista(L2);

  int total = eliminarComunes(L1, L2);

  cout << "\nTotal comunes eliminados: " << total << endl;
  cout << "Listas después de la eliminación: " << endl;
  cout << "Lista 1 : ";
  mostrarLista(L1);
  cout << "Lista 2 : ";
  mostrarLista(L2);
}