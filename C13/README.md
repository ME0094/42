# C13 — árboles binarios de búsqueda

## Objetivo

Crear y recorrer árboles binarios, insertar y buscar datos mediante un
comparador y procesar los nodos tanto por profundidad como por niveles.

| Ejercicio | Operación |
|---|---|
| ex00 | Creación e inicialización de un nodo. |
| ex01–ex03 | Recorridos prefijo, infijo y sufijo. |
| ex04 | Inserción conservando el orden del árbol. |
| ex05 | Búsqueda de un elemento mediante comparador. |
| ex06 | Cálculo de la altura o número de niveles. |
| ex07 | Recorrido en anchura con nivel y marca de primer elemento. |

## Qué aprendí

- A distinguir el momento de procesar un nodo en cada recorrido en profundidad.
- A mantener el invariante de orden mediante un comparador externo.
- A calcular propiedades recursivas combinando resultados de ambos subárboles.
- A recorrer por niveles conservando información de profundidad y posición.

## Dificultades

Un árbol vacío debe ser un caso base válido en todas las operaciones. La
inserción y búsqueda dependen de interpretar de forma uniforme el signo del
comparador. El recorrido por anchura es el más complejo porque necesita separar
niveles y comunicar cuándo se visita el primer nodo de cada uno.

## Estado del repositorio

| Aspecto | Situación |
|---|---|
| Cobertura | Implementaciones presentes para `ex00`–`ex07`. |
| Verificación | No hay pruebas automatizadas documentadas en esta carpeta. |
| Validación académica | No consta en el repositorio. |
