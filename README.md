# Inversiones-DivideVenceras

**Autores:** Isabella Bejarano Lopez - Samuel Moncada Mejía

## Descripción

Este proyecto implementa y compara dos algoritmos para contar inversiones en un arreglo:
- **Algoritmo Divide y Vencerás**: Implementación eficiente basada en Merge Sort con complejidad O(n log n)
- **Algoritmo Fuerza Bruta**: Implementación recursiva con complejidad O(n²)

Una **inversión** en un arreglo es un par de índices (i,j) donde i < j pero arr[i] > arr[j].

## Estructura del Proyecto

```
Inversiones-DivideVenceras/
├── src/                          # Código fuente
│   ├── main.cpp                  # Programa principal y experimentación
│   ├── inversiones_dyv.cpp       # Algoritmo Divide y Vencerás
│   ├── inversiones_naive.cpp     # Algoritmo Fuerza Bruta
│   └── timing.hpp                # Utilidades para medición de tiempo
├── data/                         # Archivos de entrada
│   └── input.txt                 # Casos de prueba
├── results/                      # Resultados de experimentos
├── report/                       # Documentación y reportes
│   └── Informe.pdf               # Documentación del proyecto
└── README.md                     # Este archivo
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
g++ -std=c++11 -O2 src/main.cpp src/inversiones_dyv.cpp src/inversiones_naive.cpp -o inversiones

# En Windows (genera .exe automáticamente)
g++ -std=c++11 -O2 src/main.cpp src/inversiones_dyv.cpp src/inversiones_naive.cpp -o inversiones.exe
```

### Opciones de compilación recomendadas
- `-std=c++11`: Usa el estándar C++11
- `-O2`: Optimización de rendimiento
- `-Wall`: Mostrar advertencias del compilador
- `-Wextra`: Advertencias adicionales

## Ejecución

### Ejecutar el programa compilado

```bash
# En Linux/macOS
./inversiones

# En Windows
inversiones.exe
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
2. **Archivo results/results.txt**: Resultados detallados de cada caso

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

## Algoritmos Implementados

### 1. Divide y Vencerás (O(n log n))
- Basado en el algoritmo Merge Sort
- Cuenta inversiones durante la fase de fusión
- Eficiente para arreglos grandes

### 2. Fuerza Bruta Recursiva (O(n²))
- Compara todos los pares posibles
- Implementación recursiva
- Útil para verificación y comparación

## Análisis de Complejidad

| Algoritmo | Complejidad Temporal | Complejidad Espacial |
|-----------|---------------------|---------------------|
| Divide y Vencerás | O(n log n) | O(n) |
| Fuerza Bruta | O(n²) | O(n) |

## Casos de Prueba Incluidos

1. **Caso mixto**: `[2, 3, 8, 6, 1]` - 5 inversiones
2. **Caso ordenado**: `[1, 2, 3, 4, 5]` - 0 inversiones
3. **Caso inverso**: `[5, 4, 3, 2, 1]` - 10 inversiones
4. **Caso grande**: Arreglo de 200 elementos en orden descendente

## Notas de Implementación

- El programa utiliza `long long` para manejar números grandes de inversiones
- La medición de tiempo se realiza en milisegundos con alta precisión
- Ambos algoritmos se ejecutan con copias independientes del arreglo original
- Se verifica que ambos algoritmos produzcan el mismo resultado

## Contribuciones

Este proyecto fue desarrollado como parte de un curso de análisis de algoritmos, implementando y comparando diferentes enfoques para resolver el problema de conteo de inversiones.