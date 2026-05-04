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

void insertarPrimero(Nodo *&inicio, int valor)
{
    Nodo *nuevo = crearNodo(valor);
    nuevo->prox = inicio;
    inicio = nuevo;
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
                encontrado = true;
            }
            else
                aux = aux->prox;
        }
        if (encontrado == false)
        cout << "Valor no encontrado en la lista " << endl;
    }
}

int pedir_valor()
{
    int valor;
    cout << "Indica valor: ";
    cin >> valor;
    return valor;
}


// Elimina un valor dado en una lista la última de las veces que aparece en la lista. Ejemplo: 
// Se tiene  L1 ={3,44,55,3,4,5,6,3,8} y valor = 3 entonces L1 queda:   L1= {3,44,55,3,4,5,6,8} 
void eliminarUltimaRepeticion(Nodo *&inicio, int valor)
{
    Nodo *mover, *anterior = NULL, *ultimo = NULL;
    if (listaVacia(inicio))
        cout << "Lista esta vacia" << endl;
    else
    {
        mover = inicio;
        while (mover != NULL)
        {
            if (mover->dato == valor)
            {
                ultimo = mover;
            }
            anterior = mover;
            mover = mover->prox;
        }
        if (ultimo == NULL)
            cout << "El elemento no existe en la lista " << endl;
        else
        {
            if (ultimo == inicio)
            {
                inicio = inicio->prox;
                delete ultimo;
            }
            else
            {
                mover = inicio;
                while (mover != NULL && mover->prox != ultimo)
                {
                    mover = mover->prox;
                }
                if (mover != NULL)
                {
                    mover->prox = ultimo->prox;
                    delete ultimo;
                }
            }
        }
    }
}


// A partir de dos listas L1 y L2 eliminar de la lista L1 los elementos que son comunes con la 
// lista L2. Ejemplo: 
// L1 = {2,3,4,45,33,22,313,55} y L2={2,3,44,33,33,4,5,6,8,31} => L1={45,22,313,55}
void eliminarComunes(Nodo *&L1, Nodo *L2)
{
    Nodo *moverL2 = L2;
    while (moverL2 != NULL)
    {
        eliminar(L1, moverL2->dato);
        moverL2 = moverL2->prox;
    }
}

// Dada una lista enlazada de enteros, desarrolla un procedimiento que elimine todos los nodos 
// que se encuentran en posiciones que son múltiplos de un valor k dado por el usuario. 
// Ejemplo: Si L1={10, 20, 30, 40, 50, 60} y k=2, la lista resultante debe ser L={10, 30, 50}. 
void eliminarMultiplosDeK(Nodo *&inicio, int k)
{
    Nodo *mover = inicio, *anterior = nullptr;
    int pos = 1;
    if (listaVacia(inicio))
    {
        cout << "Lista esta vacia" << endl;
    }
    else
    {
    while (mover != NULL)
    {
        if (pos % k == 0)
        {
            if (mover == inicio)
            {
                inicio = inicio->prox;
                delete mover;
                mover = inicio;
            }
            else
            {
                anterior->prox = mover->prox;
                delete mover;
                mover = anterior->prox;
            }
        }
        else
        {
            anterior = mover;
            mover = mover->prox;
        }
        pos++;
    }
    }
}   

// Dada una lista enlazada de enteros realiza un procedimiento que determine la longitud de 
// la secuencia creciente más larga que contiene.  Ejemplo: 
// Si tenemos la lista: 3 5 11 2 9 15 10 9 9 19 22 24 18 
// En este caso la respuesta es 5 (secuencia: 9 9 19 22 24)  
void secuenciaCrecienteMasLarga(Nodo *inicio)
{
    if (listaVacia(inicio))
    {
        cout << "Lista esta vacia" << endl;
        return;
    }

    Nodo *mover = inicio;
    Nodo *inicioActual = inicio;
    Nodo *inicioMaximo = inicio;
    Nodo *finMaximo = inicio;
    int longitudActual = 1;
    int longitudMaxima = 1;

    while (mover->prox != NULL)//mientras no llegue al final de la lista
    {
        if (mover->dato <= mover->prox->dato)//si el dato actual es menor o igual al siguiente, entonces la secuencia sigue creciendo
        {
            longitudActual++;
        }
        else
        {
            if (longitudActual > longitudMaxima)//si la longitud actual es mayor a la máxima, entonces actualizo la máxima y guardo el inicio y fin de esa secuencia
            {
                longitudMaxima = longitudActual;
                inicioMaximo = inicioActual;
                finMaximo = mover;
            }
            longitudActual = 1;
            inicioActual = mover->prox;
        }
        mover = mover->prox;
    }

    if (longitudActual > longitudMaxima)//si la última secuencia es la más larga, entonces actualizo la máxima y guardo el inicio y fin de esa secuencia
    {
        longitudMaxima = longitudActual;
        inicioMaximo = inicioActual;
        finMaximo = mover;
    }

    cout << "La longitud de la secuencia creciente mas larga es: " << longitudMaxima << endl;
    cout << "Secuencia maxima consecutiva: ";
    for (Nodo *p = inicioMaximo; p != NULL; p = p->prox)//imprimo la secuencia desde el inicio máximo hasta el fin máximo
    {
        cout << p->dato;
        if (p == finMaximo)
            break;
        cout << " ";
    }
    cout << endl;
}

// Dada una lista dinámica simplemente enlazada con las estructuras vistas en clase: 
// Partiendo del inicio de la lista A hacia el fondo de la misma elimine, para cada número 
// en la lista, todos aquellos números que le siguen de manera inmediata y son sus múltiplos. 
// Ejemplo, Lista A: 
// (inicio) A -> 7 -> 3 -> 12 -> 15 -> 2 -> 9 -> 18 -> 6 -> 11 -> 27 -> NULL (fondo) 
// Respuesta: A -> 7- > 3 -> 2 -> 9 -> 6 -> 11 -> 27 -> NULL 
// Nota: No se pueden usar estructuras auxiliares. Debe escribir cualquier rutina utilizada. 
void eliminarMultiplosInmediatos(Nodo *&inicio)
{
    if (listaVacia(inicio))
    {
        cout << "Lista esta vacia" << endl;
        return;
    }
    Nodo *mover = inicio, *anterior = nullptr;
    while (mover != NULL)
    {
        while (mover->prox != NULL && mover->prox->dato % mover->dato == 0)
        {
            Nodo *temp = mover->prox;//guardo el nodo múltiplo
            mover->prox = temp->prox;//salto el nodo múltiplo, apuntando al siguiente del múltiplo
            cout << "Eliminando: " << temp->dato << endl;//imprimo el nodo que se va a eliminar
            delete temp;//elimino el nodo múltiplo
        }
        anterior = mover;
        mover = mover->prox;
    }
}

// Cree una rutina que recibe dos Listas Simplemente Enlazadas A y B se debe generar 
// una tercera C con la diferencia simétrica entre A y B sin elementos repetidos. 
// La diferencia simétrica está formada por todos los elementos de A que no se encuentren 
// en B, unidos con todos los elementos de B que no se encuentren en A. 
// Ejemplo: 
// Sean A = {1 ,2 ,3 ,4 ,5, 6 ,7} y B= {4 ,77 ,3 ,44 ,1 ,77} 
// Respuesta: C = {2 ,5 ,6 ,7 ,77 ,44}
void diferenciaSimetrica(Nodo *A, Nodo *B, Nodo *&C)
{
    Nodo *moverA = A;
    while (moverA != NULL)
    {
        bool encontrado = false;
        Nodo *moverB = B;
        while (moverB != NULL)
        {
            if (moverA->dato == moverB->dato)
            {
                encontrado = true;
                break;
            }
            moverB = moverB->prox;
        }
        if (!encontrado)
        {
            insertarUltimo(C, moverA->dato);
        }
        moverA = moverA->prox;
    }

    Nodo *moverB = B;
    while (moverB != NULL)
    {
        bool encontrado = false;
        Nodo *moverA = A;
        while (moverA != NULL)
        {
            if (moverB->dato == moverA->dato)
            {
                encontrado = true;
                break;
            }
            moverA = moverA->prox;
        }
        if (!encontrado)
        {
            insertarUltimo(C, moverB->dato);
        }
        moverB = moverB->prox;
    }
}

// Rotar los elementos de una lista k posiciones hacia la izquierda.  
void Desplazar (Nodo **p, int x){
Nodo *ax= *p,  *desp= *p;
while (x>0 && (*p)->prox){
*p = (*p)->prox;
x--;
if (x==0) ax->prox= nullptr;
ax=ax->prox;}

ax= *p;
while (ax && ax->prox){ax= ax->prox;}
ax->prox= desp;
}

main ()
{
}