#include <iostream>
using namespace std;

// Estructura base: El "Vagón"
struct Nodo {
    int dato;
    Nodo *prox;
};

// --- PRIMITIVAS DE LIA MENDOZA ---

Nodo *crearNodo(int valor) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->prox = NULL;
    return nuevo;
}

bool listaVacia(Nodo *inicio) {
    return inicio == NULL;
}

void insertarUltimo(Nodo *&inicio, int valor) {
    Nodo *nuevo = crearNodo(valor);
    if (listaVacia(inicio)) {
        inicio = nuevo;
    } else {
        Nodo *auxiliar = inicio;
        while (auxiliar->prox != NULL) {
            auxiliar = auxiliar->prox;
        }
        auxiliar->prox = nuevo;
    }
}

// --- SOLUCIÓN AL EJERCICIO DE LA IMAGEN ---

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

// --- FUNCIÓN PARA MOSTRAR LA LISTA NORMAL (Para comparar) ---
void mostrarLista(Nodo *inicio) {
    if (listaVacia(inicio)) {
        cout << "Lista vacía" << endl;
        return;
    }
    Nodo *mover = inicio;
    while (mover != NULL) {
        cout << mover->dato << " -> ";
        mover = mover->prox;
    }
    cout << "NULL" << endl;
}

// --- PROGRAMA PRINCIPAL PARA PROBAR ---
int main() {
    Nodo *L1 = NULL;

    // Creamos la lista del ejemplo: {3, 44, 55, 3, 8}
    insertarUltimo(L1, 3);
    insertarUltimo(L1, 44);
    insertarUltimo(L1, 55);
    insertarUltimo(L1, 3);
    insertarUltimo(L1, 8);

    cout << "Lista Original: ";
    mostrarLista(L1);

    cout << "Lista Invertida: ";
    imprimirInvertido(L1); 
    cout << endl;

    return 0;
}