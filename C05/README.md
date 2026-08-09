# C05 — iteración, recursión y búsqueda

## Objetivo

Resolver problemas numéricos con versiones iterativas y recursivas, analizar
casos límite y terminar con una búsqueda por backtracking.

| Ejercicio | Implementación | Enfoque |
|---|---|---|
| ex00–ex01 | Factorial | Comparación entre iteración y recursión. |
| ex02–ex03 | Potencia | Exponente entero mediante ambos enfoques. |
| ex04 | Fibonacci | Definición recursiva de la sucesión. |
| ex05 | Raíz cuadrada | Búsqueda de una raíz entera exacta. |
| ex06 | Primalidad | Comprobación eficiente de divisores. |
| ex07 | Siguiente primo | Búsqueda incremental reutilizando la prueba de primalidad. |
| ex08 | Diez reinas | Backtracking y conteo de configuraciones válidas. |

## Qué aprendí

- A definir casos base correctos y comprobar que cada llamada recursiva progresa.
- A reconocer el coste de la recursión ingenua, especialmente en Fibonacci.
- A limitar la prueba de divisores mediante `d <= n / d`, sin multiplicaciones que desborden.
- A modelar restricciones por columnas y diagonales para podar el árbol de búsqueda.

## Dificultades

Los valores negativos, cero y uno cambian el significado de varias funciones y
deben resolverse antes del bucle o la recursión. En las diez reinas, el reto es
deshacer exactamente el estado de cada intento; mantener una posición por fila
y comprobar solo las reinas ya colocadas simplifica el backtracking.

## Estado del repositorio

| Aspecto | Situación |
|---|---|
| Cobertura | Implementaciones presentes para `ex00`–`ex08`. |
| Verificación | No hay pruebas automatizadas documentadas en esta carpeta. |
| Validación académica | No consta en el repositorio. |
