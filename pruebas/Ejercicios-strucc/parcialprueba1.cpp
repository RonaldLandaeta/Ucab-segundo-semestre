// ALGORITMOS Y ESTRUCTURAS DE DATOS (PERIODO 202613)
// PARCIAL I

// 1) Dada una lista dinámica simplemente enlazada con las estructuras vistas en clase: (6 ptos)

// Partiendo del inicio de la lista A hacia el fondo de la misma elimine, para cada número en lista, todos aquellos números que le siguen de manera inmediata y son sus múltiplos.

// Ejemplo, Lista A:
// (inicio) A -> 7 -> 3 -> 12 -> 15 -> 2 -> 9 -> 18 -> 6 -> 11 -> 27 -> NULL (fondo)

// Respuesta: A -> 7 -> 3 -> 2 -> 9 -> 6 -> 11 -> 27 -> NULL

// Nota: No se pueden usar estructuras auxiliares. Debe escribir cualquier rutina utilizada.

// 2) Dado un entero N positivo y una pila A, usando las primitivas de pilas vistas en clase y estructuras auxiliares: (6 ptos)

// Cree una rutina que elimine, partiendo del fondo de la pila hacia el tope, aquellos elementos que estén en posición par (el fondo es la posición 1) y sean múltiplos de N.

// Ejemplo:
// Sea N = 3. Pila A => Tope | 7 | 3 | 12 | 15 | 2 | 9 | 18 | 6 | 11 | 27 | Fondo

// Desde el fondo las posiciones par con múltiplos de 3 son los valores: 18 y 12.

// Respuesta: Pila A => Tope | 7 | 3 | 15 | 2 | 9 | 6 | 11 | 27 | Fondo

// 3) En esta pregunta el estudiante decide si resolver el problema como listas dinámicas simplemente enlazadas o como pila y aplicar las primitivas de pilas dadas en clase. En cualquier caso aplican las restricciones de la pregunta 1) o 2) respectivamente: (8 ptos)

// Cree una rutina que recibe dos estructuras lineales A y B se debe generar una tercera C con la diferencia simétrica entre A y B sin elementos repetidos.

// La diferencia simétrica está formada por todos los elementos de A que no se encuentren en B, unidos con todos los elementos de B que no se encuentren en A.

// Ejemplo:
// Sean A = { 1, 1, 3, 2, 4, 5, 6, 5, 2, 7 } y B = { 4, 77, 3, 44, 1, 77 }

// Respuesta: C = { 2, 5, 6, 7, 77, 44 }