# C03 — comparación y concatenación de cadenas

## Objetivo

Reimplementar operaciones clásicas de `<string.h>` usando únicamente recorridos
con índices y el terminador nulo de C.

| Ejercicio | Implementación | Enfoque |
|---|---|---|
| ex00 | `ft_strcmp` | Comparación lexicográfica completa. |
| ex01 | `ft_strncmp` | Comparación limitada a `n` caracteres. |
| ex02 | `ft_strcat` | Concatenación al final del destino. |
| ex03 | `ft_strncat` | Concatenación limitada. |
| ex04 | `ft_strstr` | Búsqueda de una subcadena. |
| ex05 | `ft_strlcat` | Concatenación acotada con cálculo del tamaño total. |

## Qué aprendí

- A recorrer cadenas sin salir del límite marcado por `\0`.
- A interpretar los caracteres como valores sin signo al compararlos.
- A distinguir entre el número máximo de caracteres leídos y el tamaño total del búfer.
- A conservar el terminador nulo al concatenar siempre que el destino tenga espacio.

## Dificultades

Los casos más delicados son las cadenas vacías, `n == 0`, una subcadena vacía y
un búfer menor que la cadena que ya contiene. La solución consiste en separar
primero la búsqueda del final o del punto de coincidencia y aplicar después los
límites, evitando accesos fuera del array.

## Estado del repositorio

| Aspecto | Situación |
|---|---|
| Cobertura | Implementaciones presentes para `ex00`–`ex05`. |
| Verificación | No hay pruebas automatizadas documentadas en esta carpeta. |
| Validación académica | No consta en el repositorio. |
