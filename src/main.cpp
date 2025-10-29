#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include "timing.hpp"

using namespace std;

// Declaramos las funciones para contar inversiones
long long inversiones_dyv(vector<int>& arr);
long long inversiones_fb(vector<int>& arr);

// Esta funcion es la que hace las pruebas y mide tiempos
void experimentar(const string& nombre_input, const string& nombre_output) {
    ifstream entrada(nombre_input); // abre el archivo de entrada
    ofstream salida(nombre_output); // abre el archivo de salida

    // si hay un error al abrir los archivos se muestra un mensaje y se sale
    if (!entrada.is_open()) {
        cerr << "Error al abrir el archivo de entrada: " << nombre_input << endl;
        return;
    }

    // declaramos la variable para el número de casos de prueba y la leemos
    int casos;
    entrada >> casos;

    cout << "\n Conteo de Inversiones \n";
    cout << left // esto es para alinear a la izquierda en el archivo de salida
         << setw(4)  << "n" // se le asigna un ancho de 4 caracteres a "n"
         << setw(15) << "Inversiones" // ancho de 15 a "Inversiones"
         << setw(15) << "t_dyv_ms" // ancho de 15 a "t_dyv_ms"
         << setw(15) << "t_fb_ms" // ancho de 15 a "t_fb_ms"
         << "Son iguales o no?\n"; // esto es para saber si los resultados de la fuerza bruta y DyV coinciden o no
    cout << string(60, '-') << "\n"; // esto es para hacer una linea de 60 guiones para separar todo

    for (int i = 0; i < casos; i++) {  // recorremos cada caso de prueba
        int n; // declaramos la variable para el tamaño del arreglo
        entrada >> n; // se lee el tamaño
        vector<int> arr(n); // creamos un arreglo de tamaño n
        for (int i = 0; i < n; i++) entrada >> arr[i]; // leemos los elementos del arreglo

        vector<int> arr_dyv = arr; // esta es una copia para Divide y Vencerás
        vector<int> arr_fb = arr; // esta es una copia para la fuerza bruta

        double tiempo_dyv = 0.0, tiempo_fb = 0.0; // inicializamos las variables para los tiempos
        long long inv_dyv = 0, inv_fb = 0; // inicializamos las variables para las inversiones

        // aca medimos el tiempo de cada algoritmo y guardamos el resultado
        tiempo_dyv = medir_tiempo_ms([&]() {
            inv_dyv = inversiones_dyv(arr_dyv);
        });

        tiempo_fb = medir_tiempo_ms([&]() {
            inv_fb = inversiones_fb(arr_fb);
        });

        bool coinciden = (inv_dyv == inv_fb); // verificamos si los resultados son iguales o no

        cout << left
             << setw(4)  << n
             << setw(15) << inv_dyv
             << setw(15) << fixed << setprecision(3) << tiempo_dyv
             << setw(15) << tiempo_fb
             << (coinciden ? "Si" : "No") << "\n";

        salida << "n=" << n
               << "  inv=" << inv_dyv
               << "  t_dyv_ms=" << fixed << setprecision(3) << tiempo_dyv // el fixed y setprecision(3) es para mostrar 3 decimales
               << "  t_fb_ms=" << tiempo_fb << "\n";
    }

    cout << "\nResultados guardados en: " << nombre_output << endl;

    entrada.close();
    salida.close();
}

// Este main llama a experimentar y pasa los nombres de los archivos de entrada y salida
int main() {
    experimentar("data/input.txt", "results/results.txt");
    return 0;
}
