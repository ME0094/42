# C08 — cabeceras, macros y estructuras

## Objetivo

Organizar declaraciones compartidas en cabeceras, usar macros simples y modelar
datos relacionados mediante estructuras.

| Ejercicio | Archivo principal | Enfoque |
|---|---|---|
| ex00 | `ft.h` | Prototipos comunes y protección contra inclusiones múltiples. |
| ex01 | `ft_boolean.h` | Tipo booleano y macros asociadas. |
| ex02 | `ft_abs.h` | Macro para el valor absoluto. |
| ex03 | `ft_point.h` | Definición de una estructura de punto. |
| ex04 | `ft_strs_to_tab.c` | Conversión de cadenas a un array de estructuras. |
| ex05 | `ft_show_tab.c` | Recorrido y presentación del array anterior. |

## Qué aprendí

- A proteger cabeceras con *include guards* y limitar su contenido a contratos compartidos.
- A diferenciar sustitución textual de macros y evaluación normal de funciones.
- A agrupar longitud, original y copia de una cadena en una estructura coherente.
- A terminar un array de estructuras con un elemento centinela.

## Dificultades

Una macro puede evaluar varias veces una expresión y necesita paréntesis para
preservar la precedencia. En el array de estructuras, el reto es liberar todas
las copias si una reserva falla y mantener intactos los punteros a las cadenas
originales.

## Estado del repositorio

| Aspecto | Situación |
|---|---|
| Cobertura | Implementaciones presentes para `ex00`–`ex05`. |
| Verificación | No hay pruebas automatizadas documentadas en esta carpeta. |
| Validación académica | No consta en el repositorio. |
