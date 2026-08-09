# C07 — reserva dinámica y transformación de cadenas

## Objetivo

Crear arrays y cadenas cuyo tamaño se conoce en tiempo de ejecución, gestionar
su propiedad y construir conversiones y separaciones más complejas.

| Ejercicio | Implementación | Enfoque |
|---|---|---|
| ex00 | `ft_strdup` | Duplicación de una cadena reservando memoria. |
| ex01 | `ft_range` | Array de enteros en un intervalo semiabierto. |
| ex02 | `ft_ultimate_range` | Devolución del array mediante un doble puntero. |
| ex03 | `ft_strjoin` | Unión de varias cadenas con separador. |
| ex04 | `ft_convert_base` | Conversión entre dos bases arbitrarias válidas. |
| ex05 | `ft_split` | División en palabras según un conjunto de separadores. |

## Qué aprendí

- A calcular el tamaño antes de reservar y añadir espacio para `\0` o el puntero final.
- A devolver memoria mediante punteros dobles y señalar correctamente un rango vacío.
- A separar validación, análisis numérico y generación de la representación final.
- A liberar reservas parciales si falla una operación posterior.

## Dificultades

La parte más sensible es mantener coherentes conteo, reserva y escritura. Un
desfase produce desbordamientos o cadenas sin terminar. En `ft_split`, contar
primero las palabras y medir cada una permite construir un array terminado en
`NULL` y definir claramente quién debe liberar cada bloque.

## Estado del repositorio

| Aspecto | Situación |
|---|---|
| Cobertura | Implementaciones presentes para `ex00`–`ex05`. |
| Verificación | No hay pruebas automatizadas documentadas en esta carpeta. |
| Validación académica | No consta en el repositorio. |
