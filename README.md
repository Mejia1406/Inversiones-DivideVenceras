# Inversiones-DivideVenceras
Autores: Isabella Bejarano Lopez - Samuel Moncada Mejía

Descripción
Este proyecto implementa y compara dos algoritmos para contar inversiones en un arreglo:
  ‭• Algoritmo Divide y Vencerás: Es una implementación basada en Merge Sort que se encarga de dividir el arreglo en dos partes, contar las inversiones y combinarlas. Complejidad O(n log n)
  ‭• Algoritmo Fuerza Bruta: Es una implementación que utiliza la recursividad. Complejidad O(n²)

Una inversión es un par de elementos (i, j) tal que i < j y A[i] > A[j].

Estructura Proyecto

Inversiones-DivideVenceras/
├── src/                          # Código fuente
│   ├── main.cpp                  # Programa principal y pruebas
│   ├── inversiones_dyv.cpp       # Algoritmo Divide y Vencerás
│   ├── inversiones_naive.cpp     # Algoritmo Fuerza Bruta
│   └── timing.hpp                # Medición de tiempo
├── data/                         # Archivos de entrada
│   └── input.txt                 # Casos de prueba
├── results/                      # Resultados de pruebas
├── report/                       # Documentación y reportes
│   └── Informe.pdf               # Documentación            
└── README.md                     # README

Compilación

Requisitos
‭  • Compilador C++ compatible con C++11 o superior(g++, clang++)
‭  ‭• Sistema operativo: Windows, Linux o macOS

Compilar Proyecto
# Ubicación del directorio del proyecto
cd Inversiones-DivideVenceras

# Compilación usando g++
g++ src/main.cpp src/inversiones_dyv.cpp src/inversiones_naive.cpp -o inversiones -o inversiones

Ejecución
./inversiones

Formato de entrada(data/input.txt)

numero de casos
tamaño_arreglo_1
elemento1 elemento2 ... elemento_n
tamaño_arreglo_2
elemento1 elemento2 ... elemento_n
...

Ejemplo:
4
5
2 3 8 6 1
5
1 2 3 4 5
5
5 4 3 2 1
200
200 199 198 ... 2 1

Salida

El programa crea:
‭  • Salida por consola: Se crea una tabla comparativa con los tiempos de ejecución
  • Archivo results/results.txt: Resultados para cada caso

Ejemplo salida por consola

Conteo de Inversiones 
n   Inversiones    t_dyv_ms       t_fb_ms        Son iguales o no?
------------------------------------------------------------
5   5              0.123          0.456          Si
5   0              0.089          0.234          Si
5   10             0.134          0.567          Si
200 19900          2.345          45.678         Si

Notas

• Se utiliza long long para el manejo de números grandes de inversiones
• La medición de tiempo se realiza en milisegundos
• Ambos algoritmos crean copias del arreglo original
• Se hace una verificación de que ambos produzcan el mismo resultado





