#include <chrono>
#include <functional>
using namespace std::chrono; // este std es solo para evitar escribir std::chrono:: cada vez
// se colocaria using namespace std; pero no es recomendable en archivos .hpp entonces mejor no

// inline se usa para definir la funcion en archivos .hpp sin errores de multiples definiciones 
inline double medir_tiempo_ms(std::function<void()> func) { // la funcion recibe otra funcion como parametro
    auto inicio = high_resolution_clock::now(); // se toma el tiempo actual antes de ejecutar la función
    func(); // se ejecuta la función pasada como parámetro
    auto fin = high_resolution_clock::now(); // se toma el tiempo actual después de ejecutar la función
    duration<double, std::milli> duracion = fin - inicio; // se calcula la duración en milisegundos
    return duracion.count(); // se retorna la duración como un valor double o sea decimal
}
