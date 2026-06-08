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
float divisor_de_colas(Cola *&pata)
{
    int elementos = 0;
    Pila *aux=nullptr;
    Pila *ordenar=nullptr;
    while (pata!=nullptr)
    {
        Apilar(aux,PrimeroCola(pata)->dato);
        Desencolar(pata);
        elementos++;
    }
    while (aux!=nullptr)
    {
        Apilar(ordenar,Tope(aux)->dato);
        Desapilar(aux);
    }
    while (ordenar!=nullptr)
    {
        Encolar(pata,Tope(ordenar)->dato);
        Desapilar(ordenar);
    }
    return elementos/2;
}
bool confirmar_existencia(Cola *&pata,int valor)
{
    Pila *aux=nullptr;
    Pila *ordenar=nullptr;
    bool encontrado;
    if (pata == nullptr || PrimeroCola(pata) == nullptr) return false;
    while ( PrimeroCola(pata)!=nullptr)
    {
        if (PrimeroCola(pata)->dato == valor)
        {
            encontrado = true;
        }
        Apilar(aux, PrimeroCola(pata)->dato);
        Desencolar(pata);
    }
    while (aux!=nullptr)
    {
        Apilar(ordenar,Tope(aux)->dato);
        Desapilar(aux);
    }
    while (ordenar!=nullptr)
    {
        Encolar(pata,Tope(ordenar)->dato);
        Desapilar(ordenar);
    }
    return encontrado;
}
void fusionar(Cola *&pata_derecha,Cola *&pata_izquierda,int inicio, int final)
{
    if (pata_derecha==nullptr || pata_izquierda==nullptr)
    {
        cout<<"Tan vacias xd"<<endl;
    }
    cout<<"Patata 1"<<endl;
    Cola *colaux=nullptr;
    Pila *aux=nullptr;
    Pila *ordenar=nullptr;
    if (confirmar_existencia(pata_izquierda,inicio)==true && confirmar_existencia(pata_izquierda,final)==true)
    {
        int mitad_de_pata_derecha= divisor_de_colas(pata_derecha);
            cout<<"Patata 2"<<endl;
        while (PrimeroCola(pata_derecha)!=NULL)
        {
            Apilar(aux,PrimeroCola(pata_derecha)->dato);
            Desencolar(pata_derecha);
            cout<<"Patata 3"<<endl;
        }
        while (aux!=NULL)
        {
            Apilar(ordenar,Tope(aux)->dato);
            Desapilar(aux);
                cout<<"Patata 4"<<endl;
        }
        while (mitad_de_pata_derecha!=0)
        {
            Encolar(colaux,Tope(ordenar)->dato);
            Desapilar(ordenar);
            mitad_de_pata_derecha--;
                cout<<"Patata 5"<<endl;
        }
        while( PrimeroCola(pata_izquierda)!=nullptr && PrimeroCola(pata_izquierda)->dato!=inicio)
        {
            Desencolar(pata_izquierda);
                cout<<"Patata 6"<<endl;
        }
        while (pata_izquierda!=nullptr && PrimeroCola(pata_izquierda)->dato!=final)
        {
            Encolar(colaux,PrimeroCola(pata_izquierda)->dato);
            Desencolar(pata_izquierda);
                cout<<"Patata 7"<<endl;
        }
        if (pata_izquierda != nullptr) 
        {
            Encolar(colaux, PrimeroCola(pata_izquierda)->dato);
            Desencolar(pata_izquierda); // Desencolamos el final también
            cout << "Patata 8" << endl;
        }
        while (ordenar!=nullptr)
        {
            Encolar(colaux,Tope(ordenar)->dato);
            Desapilar(ordenar);
                cout<<"Patata 9"<<endl;
        }
        cout<<"Colas fucionadas, El resultado es el siguiente: "<<endl;
        mostrarCola(colaux);
    }
    else{cout<<"Los elementos a empezar no existen"<<endl;}
}
// 4) Dada una cola determinar el valor mínimo de la cola sin perder la cola original. 
void menor(Cola *&pata) 
{
    int menor_actual=PrimeroCola(pata)->dato;
    Pila *aux=nullptr;
    Pila *ordenar=nullptr;
    while (!ColaVacia(pata))
    {
        if(menor_actual<PrimeroCola(pata)->dato)
        {
            Apilar(aux,PrimeroCola(pata)->dato);
            Desencolar(pata);
        }
        else
        {
            menor_actual=PrimeroCola(pata)->dato;
            Apilar(aux,PrimeroCola(pata)->dato);
            Desencolar(pata);
        }
    }
    while (!PilaVacia(aux))
    {
        Apilar(ordenar,Tope(aux)->dato);
        Desapilar(aux);
    }
    while (!PilaVacia(ordenar))
    {
        Encolar(pata,Tope(ordenar)->dato);
        Desapilar(ordenar);
    }
    cout<<"El menor numero es: "<<menor_actual<<endl;
}
// 5) Implementar una función o procedimiento que combine dos colas ordenadas en una sola cola 
// ordenada (no  hay  que  aplicar  ningún algoritmo de ordenamiento, sólo a través del recorrido).   
// Ejemplo: sean C1= {1,2,3,4,4,7} y C2={1,2,5,6,8,8,9} el resultado es:  
// C3= {1,2,3,4,5,6,7,8,9} 
void combinarColas(Cola *&c1, Cola *&c2, Cola *&c3)
{
    // Colas auxiliares para respaldar C1 y C2 y no destruirlas
    Cola *auxC1 = nullptr;
    Cola *auxC2 = nullptr;
    // Variable para rastrear el último valor insertado en C3 (para evitar duplicados)
    // Lo inicializamos con un valor bandera o controlaremos la primera inserción
    int ultimoInsertado;
    bool esPrimero = true;
    // Ciclo principal: Comparamos frentes mientras AMBAS colas tengan elementos
    while (!ColaVacia(c1) && !ColaVacia(c2))
    {
        int val1 = PrimeroCola(c1)->dato;
        int val2 = PrimeroCola(c2)->dato;
        int seleccionado;
        if (val1 < val2)
        {
            seleccionado = val1;
            Encolar(auxC1, val1); // Respaldamos en auxC1
            Desencolar(c1);       // Avanzamos en c1
        }
        else if (val2 < val1)
        {
            seleccionado = val2;
            Encolar(auxC2, val2); // Respaldamos en auxC2
            Desencolar(c2);       // Avanzamos en c2
        }
        else // Si son iguales (val1 == val2)
        {
            seleccionado = val1;  // Tomamos cualquiera
            Encolar(auxC1, val1); // Respaldamos en ambos
            Encolar(auxC2, val2);
            Desencolar(c1);       // Avanzamos en ambos para saltar el duplicado
            Desencolar(c2);
        }
        // Insertar en C3 controlando que no se repita con el último insertado
        if (esPrimero || seleccionado != ultimoInsertado)
        {
            Encolar(c3, seleccionado);
            ultimoInsertado = seleccionado;
            esPrimero = false;
        }
    }
    // Si C1 aún tiene elementos (porque C2 se vació primero)
    while (!ColaVacia(c1))
    {
        int val = PrimeroCola(c1)->dato;
        if (esPrimero || val != ultimoInsertado)
        {
            Encolar(c3, val);
            ultimoInsertado = val;
            esPrimero = false;
        }
        Encolar(auxC1, val);
        Desencolar(c1);
    }
    // Si C2 aún tiene elementos (porque C1 se vació primero)
    while (!ColaVacia(c2))
    {
        int val = PrimeroCola(c2)->dato;
        if (esPrimero || val != ultimoInsertado)
        {
            Encolar(c3, val);
            ultimoInsertado = val;
            esPrimero = false;
        }
        Encolar(auxC2, val);
        Desencolar(c2);
    }
    // --- RESTAURACIÓN DE LAS COLAS ORIGINALES ---
    // Devolvemos los datos de auxC1 a c1
    while (!ColaVacia(auxC1))
    {
        Encolar(c1, PrimeroCola(auxC1)->dato);
        Desencolar(auxC1);
    }
    // Devolvemos los datos de auxC2 a c2
    while (!ColaVacia(auxC2))
    {
        Encolar(c2, PrimeroCola(auxC2)->dato);
        Desencolar(auxC2);
    }
}
// 6) Desarrolla una función que verifique si dos colas son iguales (contienen los mismos elementos en 
// el mismo orden). 
void confirmar_igualdad(Cola *&pierna,Cola *&brazos)
{
    if (ColaVacia(pierna) || ColaVacia(brazos))return;
    Cola *cola1=nullptr;
    Cola *cola2=nullptr;
    while (!ColaVacia(pierna) && !ColaVacia(brazos))
    {
        if (PrimeroCola(pierna)->dato==PrimeroCola(brazos)->dato)
        {
            Encolar(cola1,PrimeroCola(pierna)->dato);
            Encolar(cola2,PrimeroCola(brazos)->dato);
            Desencolar(pierna);
            Desencolar(brazos);
        } 
        else 
        {
            cout<<"Las colas no son iguales"<<endl;
            return;
        }
    }
    if (ColaVacia(pierna) && ColaVacia(brazos))
    {
        cout<<"Las colas son iguales con el mismo orden"<<endl;
    }
    else
    {
        cout<<"Las colas no tiene el mismo largo, tejo xd"<<endl;
    }
}
// 7)  Un centro de servicio técnico tiene dos colas para que los clientes registren sus computadoras 
// para reparación. Los clientes deben elegir en cuál formarse según múltiples criterios que optimizan 
// su tiempo de espera y la eficiencia del centro de servicio. 
// Cada cliente tiene la siguiente información: - Identificación del cliente - Nombre del Cliente -Tiempo estimado de reparación: Cuánto tiempo tomará reparar su computadora. - Prioridad de atención: Nivel de urgencia del cliente, por ejemplo: 1 para urgencia baja, 2 para 
// alta. - Categoría del cliente: Puede ser “Cliente Nuevo” o “Cliente Frecuente”. Los clientes frecuentes 
// tienen prioridad sobre los nuevos si el resto de los criterios son iguales. 
// Criterios para elegir la cola 
// Cuando un cliente llega al centro de servicio, debe elegir en cuál de las dos colas formarse, siguiendo 
// estos criterios de prioridad: 
// 1. Menor tiempo total de espera acumulado en la cola: El cliente elige la cola donde el tiempo total 
// estimado de espera para todos los clientes actuales es menor. 
// 2. Prioridad de atención: Si ambas colas tienen el mismo tiempo de espera total, el cliente debe 
// elegir la cola donde los clientes de mayor prioridad (urgencia alta) están siendo atendidos más 
// rápidamente. 
// 3. Categoría del cliente: Si ambos tiempos de espera y la prioridad son iguales, los clientes 
// frecuentes (los que han realizado visitas previas) se forman en la cola con mayor cantidad de otros 
// clientes frecuentes, para recibir beneficios como descuentos o recompensas de fidelidad. 
// 4. Cantidad de clientes en espera: Si todos los criterios anteriores son iguales, el cliente elige la 
// cola con menos clientes para reducir la congestión en una sola cola. 
// 5. Orden aleatorio en caso de igualdad total: Si ambas colas tienen exactamente el mismo tiempo 
// de espera, prioridad, categoría de cliente y cantidad de clientes, el cliente elige una cola de manera 
// aleatoria. 
// Consideraciones adicionales  - Puedes permitir que los clientes cambien de cola si una opción más rápida se hace disponible, o 
// mantenerlos en la cola original. - Implementa una función para simular el progreso de tiempo y mover clientes en cada cola de 
// acuerdo con el tiempo estimado de reparación de cada cliente. 
// Este ejercicio te permitirá implementar una cola dinámica que reaccione a las decisiones de los 
// // clientes según diferentes criterios, utilizando el TDA COLAS
//Laboratorio:
// 1) Desarrolla un procedimiento que permita invertir los N primeros 
// elementos de una cola. Ejemplo: C={1,2,3,4,5,6,7,8,9} y N = 5 
// CInverN= {5,4,3,2,1,6,7,8,9} 
// 2) A partir de una cola de números enteros, generar una nueva cola con los 
// números pares ubicados al principio de la cola y los impares al final de la 
// cola. Ejemplo:  C= {33,2,5,4,12,5,7,8,10,20} 
// Cnueva= {2,4,12,8,10,20,33,5,5,7} 