# C11 — punteros a función y comportamiento parametrizable

## Objetivo

Usar funciones como argumentos para recorrer, transformar, comprobar y ordenar
datos sin acoplar el algoritmo a una operación concreta.

| Ejercicio | Implementación | Enfoque |
|---|---|---|
| ex00 | `ft_foreach` | Aplica una acción a cada entero. |
| ex01 | `ft_map` | Crea un array con los valores transformados. |
| ex02 | `ft_any` | Comprueba si algún elemento satisface un predicado. |
| ex03 | `ft_count_if` | Cuenta coincidencias de un predicado. |
| ex04 | `ft_is_sort` | Verifica el orden mediante un comparador. |
| ex05 | `do-op` | Despacha operaciones aritméticas. |
| ex06 | `ft_sort_string_tab` | Orden lexicográfico de cadenas. |
| ex07 | `ft_advanced_sort_string_tab` | Orden definido por el comparador recibido. |

## Qué aprendí

- A declarar y llamar punteros a función con firmas compatibles.
- A expresar acciones, transformaciones, predicados y comparadores como contratos.
- A reutilizar el mismo recorrido con comportamientos distintos.
- A manejar operadores inválidos y divisiones o módulos por cero.

## Dificultades

La firma del *callback* debe coincidir exactamente y su valor de retorno tiene
un significado distinto según el ejercicio. Para `ft_is_sort` hay que aceptar
orden ascendente o descendente, mientras que en la ordenación avanzada el signo
del comparador decide cada intercambio.

## Estado del repositorio

| Aspecto | Situación |
|---|---|
| Cobertura | Implementaciones presentes para `ex00`–`ex07`. |
| Verificación | No hay pruebas automatizadas documentadas en esta carpeta. |
| Validación académica | No consta en el repositorio. |
