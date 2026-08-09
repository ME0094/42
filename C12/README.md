# C12 — listas simplemente enlazadas

## Objetivo

Construir una biblioteca progresiva de listas enlazadas: creación, inserción,
recorrido, búsqueda, eliminación, inversión, ordenación y fusión.

| Ejercicio | Operación |
|---|---|
| ex00–ex04 | Crear un nodo, insertar delante o detrás, contar y obtener el último. |
| ex05–ex08 | Crear desde argumentos, limpiar, acceder por índice e invertir enlaces. |
| ex09–ex12 | Recorrer con callbacks, filtrar, buscar y eliminar por comparación. |
| ex13–ex15 | Fusionar, ordenar e invertir mediante intercambio de datos. |
| ex16–ex17 | Insertar y fusionar conservando una lista ordenada. |

## Qué aprendí

- A representar una secuencia dinámica con nodos y enlaces `next`.
- A modificar la cabeza mediante `t_list **` cuando la operación puede reemplazarla.
- A conservar el siguiente nodo antes de eliminar o reenlazar el actual.
- A parametrizar recorridos, comparaciones y destrucción con punteros a función.

## Dificultades

Los casos difíciles ocurren en la cabeza, la lista vacía y varios nodos
consecutivos que deben eliminarse. Dibujar los enlaces antes y después de cada
operación ayuda a no perder sublistas. En las fusiones ordenadas, cada nodo debe
quedar enlazado una sola vez y el resultado debe mantener el criterio recibido.

## Estado del repositorio

| Aspecto | Situación |
|---|---|
| Cobertura | Implementaciones presentes para `ex00`–`ex17`. |
| Verificación | No hay pruebas automatizadas documentadas en esta carpeta. |
| Validación académica | No consta en el repositorio. |
