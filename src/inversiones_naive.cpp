#include <vector>
using namespace std;

// Esta funcion utiliza recursión para contar las inversiones en un arreglo usando fuerza bruta
void contar_inversiones_recursivo(const vector<int>& arr, int i, int j, long long& total) { // arr (vector), i (primer indice), j (segundo indice), total (contador de inversiones)
    int n = arr.size(); // tamaño del arreglo

    if (i >= n - 1) return; // este es el caso base: si i llega al final del arreglo, terminamos

    if (j >= n) { // si j llegó al final, pasamos al siguiente i
        contar_inversiones_recursivo(arr, i + 1, i + 2, total); // se avanza i y se reinicia j (arr es constante, i+1 es el siguiente indice, i+2 es el indice despues de j)
        return;
    }

    // Si hay una inversion el contador aumenta
    if (arr[i] > arr[j]) total++;

    // aca se utiliza la recursión para avanzar j
    contar_inversiones_recursivo(arr, i, j + 1, total);
}

// Esta funcion es la principal que se llama desde otros archivos y devuelve el total de inversiones
long long inversiones_fb(vector<int>& arr) {
    long long total = 0;
    contar_inversiones_recursivo(arr, 0, 1, total); // iniciamo la recursión con i=0 y j=1
    return total;
}
