// 2) Dadas dos listas A y B de enteros (sin estructuras auxiliares) 
// 2.1) Comparando ambas listas:  
// 2.1.1) Cuente los elementos comunes  
// 2.1.2) Cuente los elementos comunes una sola vez 
// (excepción: necesita una estructura auxiliar!)  
// 2.1.2) Borre en A todas las veces que aparezca u elemento 
// común con B (es decir, que deje de ser común. ¿Esta 
// repetido en B?) 
// 2.2) Determine si alguna de las dos listas está incluida en la otra 
// 2.3) Para cada valor de B determine cuántos y cuáles elementos 
// de A son sus múltiplos. 
// 2.4) Inserte los valores de A en B de manera intercalada: un 
// elemento de B, luego uno de A y así sucesivamente hasta vaciar 
// A. Se parte de la cabeza de ambas listas. 
#include <iostream>
#include <ctime>
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
bool impares(int valor)
{
    if (valor %2==0) return false;
    else return true;
}
void imparesalfinal (Pila *&pila)
{
    Pila *aux1=nullptr;
    Pila *aux2=nullptr;
    while (!PilaVacia(pila))
    {
        if (impares(Tope(pila)->dato))
        {
            Apilar(aux2,Tope(pila)->dato);
            Desapilar(pila);
        }
        else
        {
            Apilar(aux1,Tope(pila)->dato);
            Desapilar(pila);
        }
    }
    while (!PilaVacia(aux1))
    {
        Apilar(aux2,Tope(aux1)->dato);
        Desapilar(aux1);
    }
    pila = aux2;
}
void moverXposiciones(Pila *&A,Pila *&B)
{
    Pila *aux = nullptr;
    int posiciones;
    while (!PilaVacia(B))
    {
        while (!PilaVacia(A))
        {
            posiciones=Tope(A)->dato;
            posiciones--;
            
        }
    }
}
main ()
{
    Pila *pila=nullptr;
    llenarPila(pila);
    cout<<"Primera pila"<<endl;
    mostrarPila(pila);
    cout<<" "<<endl;
    imparesalfinal(pila);
    cout<<"Segunda pila"<<endl;
    mostrarPila(pila);
}