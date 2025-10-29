#include <vector>
using namespace std;

// Esta función se encarga de fusionar dos mitades del array contar las inversiones
long long merge_and_count(vector<int>& arr, int left, int mid, int right) { // los parametros son arr (vector), left (inicio), mid (medio), right (final)
    vector<int> leftPart(arr.begin() + left, arr.begin() + mid + 1); // se crea subarrays para la parte izquierda para la fusión
    vector<int> rightPart(arr.begin() + mid + 1, arr.begin() + right + 1); // se crea subarrays para la parte derecha para la fusión

    int i = 0, j = 0, k = left; // se inicializa los indices para i (izquierda), j (derecha) y k (array original)
    long long count = 0; // long long porque el número de inversiones puede ser grande

    while (i < leftPart.size() && j < rightPart.size()) { // mientras no se hayan recorrido ambos subarrays
        if (leftPart[i] <= rightPart[j]) { // si el elemento de la parte izquierda es menor o igual al de la derecha
            arr[k++] = leftPart[i++]; // se añade el elemento de la izquierda al array original
        } else { // si el elemento de la parte derecha es menor
            arr[k++] = rightPart[j++]; // se añade el elemento de la derecha al array original
            count += (leftPart.size() - i); // se cuenta las inversiones
        }
    }

    while (i < leftPart.size()) arr[k++] = leftPart[i++]; // se añaden los elementos restantes de la parte izquierda
    while (j < rightPart.size()) arr[k++] = rightPart[j++]; // se añaden los elementos restantes de la parte derecha

    return count; // se retorna el conteo de inversiones 
}

// Esta función implementa el algoritmo de Merge Sort y cuenta las inversiones
long long merge_sort_count(vector<int>& arr, int left, int right) { 
    long long count = 0; // se crea un contador otra vez
    if (left < right) { // si el indice izquierdo es menor que el derecho
        int mid = (left + right) / 2; // se encuentra el punto medio
        count += merge_sort_count(arr, left, mid); // se cuenta las inversiones en la parte izquierda
        count += merge_sort_count(arr, mid + 1, right); // se cuenta las inversiones en la parte derecha
        count += merge_and_count(arr, left, mid, right); // se cuentan las inversiones entre ambas partes
    }
    return count; // se retorna el total de inversiones
}

// Esta funcion es para ser llamada en otros archivos
long long inversiones_dyv(vector<int>& arr) {
    return merge_sort_count(arr, 0, arr.size() - 1); // se llama a la función merge_sort_count con los indices iniciales 0 y tamaño-1(-1 porque es un array que empieza en 0)
}
