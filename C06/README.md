# C06 — argumentos de línea de comandos

## Objetivo

Usar `argc` y `argv` para imprimir el nombre del programa y sus argumentos en
orden original, inverso y lexicográfico.

| Ejercicio | Programa | Enfoque |
|---|---|---|
| ex00 | `ft_print_program_name` | Imprime `argv[0]`. |
| ex01 | `ft_print_params` | Recorre los argumentos de izquierda a derecha. |
| ex02 | `ft_rev_params` | Recorre los argumentos en orden inverso. |
| ex03 | `ft_sort_params` | Ordena cadenas y muestra el resultado. |

## Qué aprendí

- A interpretar `argv` como un array de cadenas y a respetar sus límites.
- A separar el nombre del programa de los argumentos proporcionados por el usuario.
- A comparar cadenas lexicográficamente y permutar punteros en lugar de copiar contenido.
- A producir una salida exacta, con un argumento y un salto de línea por registro.

## Dificultades

Los errores típicos son empezar en `argv[0]` cuando no corresponde o acceder a
`argv[argc]`. En la ordenación, intercambiar los punteros completos reduce el
riesgo y evita necesitar memoria adicional para las cadenas.

## Estado del repositorio

| Aspecto | Situación |
|---|---|
| Cobertura | Implementaciones presentes para `ex00`–`ex03`. |
| Verificación | No hay pruebas automatizadas documentadas en esta carpeta. |
| Validación académica | No consta en el repositorio. |
