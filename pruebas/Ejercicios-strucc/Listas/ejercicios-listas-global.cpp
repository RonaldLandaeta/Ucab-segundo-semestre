// "5. Se tiene una lista simplemente enlazada, se desea eliminar varios nodos según un i que aumenta de forma exponencial en base a 2, el algoritmo debe detenerse cuando no sea posible seguir eliminando en la lista (5pts)."
#include <iostream>
#include <ctime>
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
};
void llenarListaAleatoria(Nodo *&inicio, string mensaje)
{
    int cantidad;
    cout << "Indica cantidad de elementos a colocar en " << mensaje;
    cin >> cantidad;
    srand((unsigned)time(nullptr));
    for (int i = 0; i < cantidad; i++)
    {
        int valor = 1 + rand() % 50;
        insertarUltimo(inicio, valor);
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
void ElimExp(Nodo *p)
{
    Nodo *aux= p, *elim=nullptr;
    int i= 2, cont= 1;
    while (aux!=nullptr && aux->prox!=nullptr){
        if (cont+1 == i)
        {
            elim= aux->prox;
            aux->prox= elim ->prox;
            delete elim;
            i *= 2;
        }
        aux= aux->prox;
        cont ++;
    }
}
// Elimina un valor dado en una lista la última de las veces que aparece en la lista. Ejemplo: 
// Se tiene  L1 ={3,44,55,3,4,5,6,3,8} y valor = 3 entonces L1 queda:   L1= {3,44,55,3,4,5,6,8} 
void eliminarUltimaRepeticion(Nodo *&inicio, int valor)
{
    Nodo *mover, *ultimo = NULL;
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
    Nodo *mover = inicio;
    while (mover != NULL)
    {
        while (mover->prox != NULL && mover->prox->dato % mover->dato == 0)
        {
            Nodo *temp = mover->prox;//guardo el nodo múltiplo
            mover->prox = temp->prox;//salto el nodo múltiplo, apuntando al siguiente del múltiplo
            cout << "Eliminando: " << temp->dato << endl;//imprimo el nodo que se va a eliminar
            delete temp;//elimino el nodo múltiplo
        }
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
// Agregar un elemento X a una lista después de un valor N dado por el usuario. Ejemplo:  
// L1= {1,33,7,22,1,4,5} N=7, X=777 => L1={1,33,7,777,22,1,4,5} . Realizar las validaciones 
// pertinentes.   
void imprimirInvertido(Nodo *inicio) {
    // Caso Base: Si llegamos al final del "tren"
    if (inicio == NULL) {
        return;
    }

    // Llamada recursiva: Avanzamos hasta el final antes de imprimir
    imprimirInvertido(inicio->prox);

    // Al regresar de la recursión, imprimimos de atrás hacia adelante
    cout << inicio->dato << " ";
}
// Omarlistas17.cpp; 1) Dada una lista  
// 1.1) Inserte un valor X dado: 
// 1.1.1) Por la cabeza de la lista 
// 1.1.2) Por el final de la lista 
// 1.1.3) Ordenadamente (en forma ascendente) 
// 1.1.4) Luego de un valor Z dado (si no existe Z no se 
// inserta) 
// Cada una de estas rutinas tiene dos versiones: una que permite 
// repetir claves y otra que no lo permite
void insertarOrdenado(Nodo *&lista, int valor)
{
    Nodo *insertar=crearNodo(valor);
    Nodo *aux=lista;
    Nodo *anterior=lista;
    aux = aux->prox;
    if (anterior->dato>insertar->dato)
    {
        insertarPrimero(lista,valor);
        return;
    }
    while (!listaVacia(aux))
    {
        if (insertar->dato<aux->dato)
        {
            anterior->prox=insertar;
            insertar->prox=aux;
            return;
        }
        anterior=aux;
        aux=aux->prox;
    }
    insertarUltimo(lista,valor);
    
}
void buscarElementEinsercardps(Nodo *inicio, int valor)
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
                cout<<"Que valor desea insertar despues del nodo encontrado: ";
                int k;
                cin>>k;
                Nodo *nuevo = crearNodo(k);
                nuevo->prox = aux->prox;
                aux->prox = nuevo;
                encontrado = true;
            }
            else
                aux = aux->prox;
        }
        if (encontrado == false)
        cout << "Valor no encontrado en la lista " << endl;
    }
}
// Omarlista2.cpp 1.2) Elimine un valor X dado en la lista: 
// 1.2.3) Todas las veces que se encuentra en la lista
void eliminartodos(Nodo *&inicio, int valor)
{
    Nodo *anterior = inicio;
    Nodo *aux = inicio->prox;
    while (!listaVacia(aux))
    {
        if (aux->dato==valor)
        {
            Nodo *temp = aux;
            aux = aux->prox;
            anterior->prox=aux;
            delete temp;
        }
        else
        {
            anterior = aux;
            aux = aux->prox;
        }
    }
    if (inicio->dato==valor)
    {
        Nodo *temp = inicio;
        inicio = inicio->prox;
        delete temp;
    }
    
}
// Omarlistas3.cpp 1.3) Busque un valor X dado en una lista  
// 1.3.1) Devuelva True/False  
// 1.3.2) Cuantas veces aparece en la lista 
// 1.3.3) El apuntador a la casilla en la cual se encuentra. 
int buscarElementoveces(Nodo *inicio, int valor)
{
    Nodo *aux = inicio;
    int contador = 0;
    if (listaVacia(inicio))
        cout << "Lista vacia" << endl;
    else
    {
        while (aux != NULL)
        {
            if (aux->dato == valor)
            {
                contador ++;
            }
                aux = aux->prox;
        }
    } return contador;
};
Nodo *buscarElementoPuntero(Nodo *inicio, int valor)
{
    Nodo *aux = inicio;
    if (listaVacia(inicio))
    {
        cout << "Lista vacia" << endl;
        return nullptr;
    }
    else
    {
        while (aux != NULL)
        {
            if (aux->dato == valor)
            {
                cout << "El dato " << valor << " fue encontrado con exito. "<<"En el puntero: "<<aux<< endl;
                return aux;
                
            }
            else
                aux = aux->prox;
        }
        cout << "Valor no encontrado en la lista " << endl;
        return nullptr;
    }
}
// Omarlistas4.cpp 1.4) Elimine en la lista todos los números (no se permiten 
// estructuras  auxiliares)  
// 1.4.1) Impar que contiene  
// 1.4.2) Primos que contiene  
// 1.4.3) Que no tienen un dígito par  (375,  591, …) 
// 1.4.4) Que contienen al menos dos dígitos par (278,…) 
// 1.4.5) Todos los números repetidos: 
// 1.4.6.1) Dejando sólo la primera ocurrencia  
// 1.4.6.2) Dejando sólo la última ocurrencia 
// 1.4.6) Elimine los valores que se encuentran en las casillas 
// de posición par.
void eliminarimpar(Nodo *&lista)
{
    Nodo *aux=lista->prox;
    Nodo *anterior=lista;
    if (lista->dato%2==1)
    {
        Nodo *temp=anterior;
        anterior=aux;
        aux=aux->prox;
        lista=anterior;
        delete temp;
    }
    while (anterior->prox!=nullptr)
    {
        if (aux->dato%2==1)
        {
            Nodo *temp = lista;
            aux=aux->prox;
            anterior->prox=aux;
            delete temp;
        }
        else
        {
            anterior=aux;
            aux=aux->prox;
        }
    }
}
int Primo(int x)
{
	if (x<2) return 0;
	for (int i= 2; i<x;i++)
    {
		if (x%i==0);
        return 0;
	}return 1;
}
void eliminarPrimos(Nodo *&inicio)
{
    Nodo *anterior=inicio;
    Nodo *mover=inicio->prox;
    while (anterior!=nullptr)
    {
        if (Primo(anterior->dato)==0)
        {
            Nodo *temp=mover;
            mover=mover->prox;
            
        }
    }
    
}
int SoloImparparte2(int x){
	for (int i= x; i>0; i/=10){
		if ((i%10)%2==0)return 0;
        x/=10;}
    return 1;}
void eliminarimpare(Nodo *&inicio)
{
    Nodo *mover = inicio->prox;
    Nodo *anterior=inicio;
    while (!listaVacia(mover))
    {
        if (SoloImparparte2(mover->dato))
        {
            Nodo *temp = mover;
            mover = mover->prox;
            anterior->prox=mover;
            delete temp;
        }
        else
        {
            anterior = mover;
            mover= mover->prox;
        }
        
    }
    if (SoloImparparte2(inicio->dato))
    {
        Nodo *temp = inicio;
        inicio=inicio->prox;
        delete temp;
    }
    
}
int min2pares (int x)
{
    int contador = 0;
    while (x>0)
    {
        if (x%10%2==0)
        {
            contador++;
        }
        x/=10;
    }
    if (contador <=1)return 0;
    else return 1;
}
void eliminarmin2pares (Nodo *&inicio)
{
    Nodo *mover = inicio->prox;
    Nodo *anterior=inicio;
    while (!listaVacia(mover))
    {
        if (min2pares(mover->dato))
        {
            Nodo *temp = mover;
            mover = mover->prox;
            anterior->prox=mover;
            delete temp;
        }
        else
        {
            anterior = mover;
            mover= mover->prox;
        }
        
    }
    if (min2pares(inicio->dato))
    {
        Nodo *temp = inicio;
        inicio=inicio->prox;
        delete temp;
    }
    
}
int buscarocurrencias( Nodo *inicio, int x)
{
    Nodo *mover = inicio;
    int contador = 0;
    while (!listaVacia(mover))
    {
        if (mover->dato == x)
        {   
            contador++;
        }
        mover = mover->prox;
    }
    return contador;
}
void dejarprimeraocurriencia (Nodo *inicio,int x)
{
    Nodo *mover = inicio->prox;
    Nodo *anterior = inicio;
    while (anterior!=nullptr && anterior->dato!=x)
    {
        anterior = mover;
        mover = mover->prox;
    }
    while (mover!= nullptr)
    {
        if (mover->dato==x)
        {
            Nodo *temp = mover;
            mover = mover->prox;
            anterior->prox=mover;
            delete temp;
        }
        else
        {
            anterior = mover;
            mover= mover->prox;
        }
    }
    
}
void dejarprimeraocupremiun(Nodo *inicio)
{
    Nodo *aux = inicio;
    while (aux!=nullptr)
    {
        dejarprimeraocurriencia(aux,aux->dato);
        aux=aux->prox;
    }
}
// 1) Dada una listaA simplemente enlazada que contiene números enteros positivos (sin usar
// estructuras auxiliares):
// 1.1 Elimine los números con sólo dígitos impar y deje los números primos al final
int SoloImpar(int x){
	for (int i= x; i>0; i/=10){
		if ((i%10)%2==0)return 0;
	} return 1;
}
int Primos(int x){
	if (x<2) return 0;
	for (int i= 2; i<x; i ++){
		if (x%i== 0) return 0;
	} return 1;
}
void digitosimpares (Nodo *&inicio)
{
    Nodo *anterior = inicio;
    Nodo *mover = inicio->prox;
    while (mover!=nullptr)
    {
        if (SoloImpar(mover->dato)==1)
        {
            Nodo *temp = mover;
            mover=mover->prox;
            anterior->prox=mover;
            delete temp;
        }
        else
        {
            anterior=mover;
            mover=mover->prox;
        }
    }
    if (SoloImpar(inicio->dato)==1)
    {
        Nodo *temp = inicio;
        inicio = inicio->prox;
        delete temp;
    }
}
void moverprimos (Nodo *&lista)
{
    if (listaVacia(lista))return;
    Nodo *aux = lista;
    int contador = 0;
    while (!listaVacia(aux))
    {
        contador++;
        aux=aux->prox;
    }
    aux = lista;
    while (!listaVacia(aux) && contador>0)
    {
        if (Primos(aux->dato)==1)
        {
            int temp = aux->dato;
            aux=aux->prox;
            eliminar(lista,temp);
            insertarUltimo(lista,temp);
        }
        else
        {
            aux=aux->prox;
        }
        contador--;
    }
    
}
// 16. Tareas domésticas: Diseña un programa para ayudar a administrar las tareas domésticas, 
// donde cada tarea tenga un nombre, descripción y estado (pendiente, en progreso, 
// completada). Implementa procedimientos y/o funciones para agregar nuevas tareas, marcar 
// tareas como completadas y mostrar todas las tareas pendientes en el hogar. Determina el 
// porcentaje de tareas completadas, en progreso y pendientes.

// Omarlistas5.cpp 1.5) Voltee la lista de, al menos, dos maneras distintas (no se 
// permiten estructuras auxiliares). 

// Desarrolla una función que determine si el contenido de una lista de caracteres es un 
// palíndromo (se lee igual de izquierda a derecha que de derecha a izquierda). 

// 15. Biblioteca de Libros: Crea un programa para manejar una biblioteca de libros. Cada libro 
// debe tener un título, un autor y un número de ISBN. Debes proporcionar operaciones para 
// agregar nuevos libros, buscar libros por autor (mostrando en pantalla cada libro 
// encontrado) y eliminar libros por su ISBN. 
// La idea es que modifiques el “struct nodo” y te acostumbres a trabajar con varios campos 
// de distintos tipos de datos.

// 16. Tareas domésticas: Diseña un programa para ayudar a administrar las tareas domésticas, 
// donde cada tarea tenga un nombre, descripción y estado (pendiente, en progreso, 
// completada). Implementa procedimientos y/o funciones para agregar nuevas tareas, marcar 
// tareas como completadas y mostrar todas las tareas pendientes en el hogar. Determina el 
// porcentaje de tareas completadas, en progreso y pendientes.

// void Elimreps (lista *p){
// 	if (!(*p) || !((*p)->prox)) return;
// 	lista *ax= *p, *ax2, *t;
// 	while (ax){
// 		ax2= ax->prox;
// 		while(ax2){
// 			if (ax2->prox->valor== ax->valor){*t= ax2->prox;
// 				ax2->prox= t->prox;
// 				delete t;
// 			else ax2= ax2->prox;
// 		} if (ax->prox->valor == ax->valor){
// 			t= ax->prox; ax->prox= t->prox;
// 			delete t;}
// 		ax= ax->prox;
// 	}
// }
// void ElimNocurr (pila **p, int x, int n){
// 	int y, res= 0;
// 	if (!(Vacio(*p))){
// 		y= Tope(*p);
// 		Desapilar(p);
// 		res= ElimNocurr(p, x, n);
// 		if (y== x && res < n) return (res + 1);
// 		Apilar(p, y);
// 		return res;
// 	} return 0;
// }
// void ElimTodos (pila **p, int x){
// 	int y;
// 	if (!(Vacio(*p))){
// 		y= Tope (*p);
// 		Desapilar(p);
// 		ElimTodos(p, x);
// 		if (y != x) Apilar(p, y);
// 	}
// }
// void ElimReps (pila **p)
// 	int y;
// 	if (!(Vacio(*p))){
// 		y= Tope(*p);
// 		Desapilar(p);
// 		ElimTodos(p, y);
// 		ElimReps(p);
// 		Apilar(p,y);
// 	}
// }
// void ElimPosPar(lista *p){
// 	lista *ax= p, *t;
// 	while (ax && ax->prox){
// 		t= ax->prox;
// 		ax->prox= t->prox;
// 		delete t;
// 		ax= ax->prox;
// 	}
// }
main()
{
    Nodo *lista = nullptr;
    llenarListaManual(lista,"l1");
    mostrarLista(lista);
    int c;
    cout<<"Dime el numeor papi"<<endl;
    cin>>c;
    cout<<"El numeor de veces que aparece el numero es"<<endl;
    dejarprimeraocurriencia(lista,c);
    mostrarLista(lista);
    
}

