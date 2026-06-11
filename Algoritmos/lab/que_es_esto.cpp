#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Función auxiliar: Counting Sort basado en un dígito específico (definido por 'exp')
void countingSortPorDigito(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> salida(n); // Arreglo de salida que guardará los elementos ordenados temporalmente
    int conteo[10] = {0};  // Inicializamos las posiciones/baldes para los dígitos del 0 al 9
    // 1. Almacenar el conteo de ocurrencias de cada dígito en la posición actual (exp)
    for (int i = 0; i < n; i++) {
        int digito = (arr[i] / exp) % 10;
        conteo[digito]++;
    }
    // 2. Modificar 'conteo' para que contenga las posiciones reales en el arreglo de salida
    for (int i = 1; i < 10; i++) {
        conteo[i] += conteo[i - 1];
    }
    // 3. Construir el arreglo de salida recorriendo desde el final para mantener la ESTABILIDAD
    for (int i = n - 1; i >= 0; i--) {
        int digito = (arr[i] / exp) % 10;
        salida[conteo[digito] - 1] = arr[i];
        conteo[digito]--; // Decrementar el conteo para el próximo elemento con el mismo dígito
    }
    // 4. Copiar los elementos ordenados de este dígito de vuelta al arreglo original
    for (int i = 0; i < n; i++) {
        arr[i] = salida[i];
    }
}

// Función principal de Radix Sort
void radixSort(vector<int>& arr) {
    if (arr.empty()) return;

    // 1. Encontrar el número máximo para saber cuántos dígitos tiene
    int maximo = *max_element(arr.begin(), arr.end());

    // 2. Hacer Counting Sort para cada dígito.
    // 'exp' representa el valor posicional: 1 (unidades), 10 (decenas), 100 (centenas)...
    for (int exp = 1; maximo / exp > 0; exp *= 10) {
        countingSortPorDigito(arr, exp);
    }
}

// Función para imprimir el arreglo
void imprimirArreglo(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> datos = {170, 45, 75, 90, 802, 24, 2, 66};
    cout << "Arreglo original: ";
    imprimirArreglo(datos);
    radixSort(datos);
    cout << "Arreglo ordenado con Radix Sort: ";
    imprimirArreglo(datos);
    return 0;
}