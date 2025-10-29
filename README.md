# Inversiones-DivideVenceras

**Autores:** Isabella Bejarano Lopez - Samuel Moncada Mejía

## Descripción

Este proyecto implementa y compara dos algoritmos para contar inversiones en un arreglo:
- **Algoritmo Divide y Vencerás**: Es una implementación basada en Merge Sort con complejidad O(n log n)
- **Algoritmo Fuerza Bruta**: Es una implementación que utiliza recursividad con complejidad O(n²)

Una **inversión** en un arreglo es un par de índices (i,j) donde i < j pero A[i] > A[j].

## Estructura del Proyecto

```
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
└── README.md                     # ReadMe
```

## Compilación

### Requisitos
- Compilador C++ compatible con C++11 o superior (g++, clang++)
- Sistema operativo: Windows, Linux o macOS

### Compilar el proyecto

```bash
# Navegar al directorio del proyecto
cd Inversiones-DivideVenceras

# Compilar usando g++
g++ src/main.cpp src/inversiones_dyv.cpp src/inversiones_naive.cpp -o inversiones

```

## Ejecución

### Ejecutar el programa compilado

```bash
./inversiones
```

### Formato de entrada (data/input.txt)

```
n_casos
tamaño_arreglo_1
elemento_1 elemento_2 ... elemento_n
tamaño_arreglo_2
elemento_1 elemento_2 ... elemento_n
...
```

### Ejemplo de entrada

```
4
5
2 3 8 6 1
5
1 2 3 4 5
5
5 4 3 2 1
200
200 199 198 ... 2 1
```

## Salida

El programa genera:
1. **Salida por consola**: Tabla comparativa con tiempos de ejecución
2. **Archivo results/results.txt**: Resultados de cada caso

### Ejemplo de salida por consola

```
Conteo de Inversiones 
n   Inversiones    t_dyv_ms       t_fb_ms        Son iguales o no?
------------------------------------------------------------
5   5              0.123          0.456          Si
5   0              0.089          0.234          Si
5   10             0.134          0.567          Si
200 19900          2.345          45.678         Si
```

## Notas

- El programa utiliza `long long` para manejar números grandes de inversiones
- La medición de tiempo se realiza en milisegundos con alta precisión
- Ambos algoritmos se ejecutan con copias independientes del arreglo original
- Se verifica que ambos algoritmos produzcan el mismo resultado
