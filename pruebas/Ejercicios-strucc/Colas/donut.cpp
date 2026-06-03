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
// 1) Desarrolla una función que divida una cola en dos colas, una con la primera mitad de los elementos 
// y otra con la segunda mitad. 
void dividir_cola(Cola *&pata)
{
    int elementos = 0;
    Pila *aux=nullptr;
    Cola *colaux=nullptr;
    while (pata!=nullptr)
    {
        Apilar(aux,PrimeroCola(pata)->dato);
        Desencolar(pata);
        elementos++;
    }
    float mitad_elementos=elementos/2;
    while (mitad_elementos!=0)
    {
        Encolar(colaux,Tope(aux)->dato);
        Desapilar(aux);
        mitad_elementos--;
    }
    while (aux!=nullptr)
    {
        Encolar(pata,Tope(aux)->dato);
        Desapilar(aux);
    }
    cout<<"La primera mitad de la cola es: "<<endl;
    mostrarCola(pata);
    cout<<"La segunda mitad es:"<<endl;
    mostrarCola(colaux);
}
// 2) Escribir un procedimiento que reemplace todos los elementos de un valor dado en una cola con 
// otro valor especificado, ambos valores proporcionados por el usuario. 
void remplazar(Cola *&pata,int remplazar,int remplazo)
{
    Pila *aux=nullptr;
    Pila *acomodar=nullptr;
    while (pata!=nullptr)
    {
        if (PrimeroCola(pata)->dato==remplazar)
        {
            PrimeroCola(pata)->dato=remplazo;
            Apilar(aux,PrimeroCola(pata)->dato);
            Desencolar(pata);
        }
        else
        {
            Apilar(aux,PrimeroCola(pata)->dato);
            Desencolar(pata);
        }
    }
    while (aux!=nullptr)
    {
        Apilar(acomodar,Tope(aux)->dato);
        Desapilar(aux);
    }
    while (acomodar!=nullptr)
    {
        Encolar(pata,Tope(acomodar)->dato);
        Desapilar(acomodar);
    }
    cout<<"El elemento: "<<remplazar<<". Fue sustituido por el elemento: "<<remplazo<<endl;
    cout<<"A continuacion la Cola remplazada:"<<endl;
    mostrarCola(pata);
}
// 3) Dadas dos colas, elabora un procedimiento o función que permita fusionar dichas colas a partir 
// de un elemento inicial y otro elemento final de la primera cola (validar que existan) desde la mitad 
// de la segunda cola. Ejemplo: 
// Cola1 = {1,2,3,4,5,6,7,8,9,10} Elemento inicial = 5, Elemento final=9 
// Cola2 = {11,22,33,44,55,66}  
// Cola fusionada= {11,22,33,5,6,7,8,9,44,55,66}
// 1. CORRECCIÓN EN EL DIVISOR:
// Tu función vaciaba la cola para siempre. Para arreglarlo, usamos una cola auxiliar 
// que guarde los datos temporalmente y luego los regrese a la "pata" original.
float divisor_de_colas(Cola *&pata)
{
    int elementos = 0;
    Cola *copia = nullptr; // <--- Línea nueva para salvar los datos
    
    while (pata != nullptr)
    {
        Encolar(copia, PrimeroCola(pata)->dato); // Guardamos copia
        Desencolar(pata);
        elementos++;
    }
    
    // REGRESAR los datos a la cola original para no destruirla
    while (copia != nullptr) {
        Encolar(pata, PrimeroCola(copia)->dato);
        Desencolar(copia);
    }
    
    return elementos / 2;
}

// 2. CORRECCIÓN EN LA EXISTENCIA:
// Al igual que el divisor, si ibas desencolando para buscar, destruías la cola.
// Además, eliminamos la pila 'aux' que tenías ahí que no hacía nada y causaba fugas.
bool confirmar_existencia(Cola *&pata, int valor)
{
    Cola *aux = nullptr;
    bool encontrado = false; // <--- Bandera para avisar si apareció
    
    while (pata != nullptr)
    {
        if (PrimeroCola(pata)->dato == valor)
        {
            encontrado = true; // Lo encontramos, pero NO hacemos return todavía
        }
        Encolar(aux, PrimeroCola(pata)->dato); // Salvamos el dato
        Desencolar(pata);
    }
    
    // REGRESAR los datos a la cola original para dejarla intacta
    while (aux!= nullptr) {
        Encolar(pata, PrimeroCola(aux)->dato);
        Desencolar(aux);
    }
    
    return encontrado; // Ahora sí respondemos si existía o no
}

// 3. FUSIÓN REPARADA (Manteniendo tu estructura de Patatas)
void fusionar(Cola *&pata_derecha, Cola *&pata_izquierda, int inicio, int final)
{
    if (pata_derecha == nullptr || pata_izquierda == nullptr)
    {
        cout << "Tan vacias xd" << endl;
        return; // Añadido para que no continúe si están vacías
    }
    
    cout << "Patata 1" << endl;
    Cola *colaux = nullptr;
    Pila *aux = nullptr;
    Pila *ordenar = nullptr;
    
    // Ahora las validaciones funcionan porque confirmar_existencia ya no destruye la cola
    if (confirmar_existencia(pata_izquierda, inicio) == true && confirmar_existencia(pata_izquierda, final) == true)
    {
        // ARREGLO: 'divisor_de_colas' ahora deja la pata_derecha intacta, lista para el siguiente while
        int mitad_de_pata_derecha = divisor_de_colas(pata_derecha);
        
        cout << "Patata 2" << endl;
        while (pata_derecha != NULL)
        {
            Apilar(aux, PrimeroCola(pata_derecha)->dato);
            Desencolar(pata_derecha);
            cout << "Patata 3" << endl;
        }
        
        while (aux != NULL)
        {
            Apilar(ordenar, Tope(aux)->dato);
            Desapilar(aux);
            cout << "Patata 4" << endl;
        }
        
        while (mitad_de_pata_derecha != 0)
        {
            Encolar(colaux, Tope(ordenar)->dato);
            Desapilar(ordenar);
            mitad_de_pata_derecha--;
            cout << "Patata 5" << endl;
        }
        
        // ARREGLO: Corregido el '==' por '!=' en el nullptr para evitar que se rompa el programa.
        // Además cambiamos 'pata_izquierda->dato' por 'PrimeroCola(pata_izquierda)->dato'
        while (pata_izquierda != nullptr && PrimeroCola(pata_izquierda)->dato != inicio)
        {
            Desencolar(pata_izquierda); // Descartamos lo anterior al inicio
            cout << "Patata 6" << endl;
        }
        
        // ARREGLO: Se añade 'pata_izquierda != nullptr' por seguridad
        while (pata_izquierda != nullptr && PrimeroCola(pata_izquierda)->dato != final)
        {
            Encolar(colaux, PrimeroCola(pata_izquierda)->dato);
            Desencolar(pata_izquierda);
            cout << "Patata 7" << endl;
        }
        
        // Metemos el elemento 'final' que faltaba
        if (pata_izquierda != nullptr) {
            Encolar(colaux, PrimeroCola(pata_izquierda)->dato);
            Desencolar(pata_izquierda); // Desencolamos el final también
            cout << "Patata 8" << endl;
        }
        
        while (ordenar != nullptr)
        {
            Encolar(colaux, Tope(ordenar)->dato);
            Desapilar(ordenar);
            cout << "Patata 9" << endl;
        }
        
        cout << "Colas fucionadas, El resultado es el siguiente: " << endl;
        mostrarCola(colaux);
    }
    else {
        cout << "Los elementos a empezar no existen" << endl;
    }
}
main()
{
    Cola *pata_izquierda=nullptr;
    Cola *pata_derecha=nullptr;
    llenarCola(pata_izquierda);
    llenarCola(pata_derecha);
    fusionar(pata_derecha,pata_izquierda,5,9);
}