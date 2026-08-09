# C10 — lectura de archivos y utilidades de consola

## Objetivo

Recrear utilidades sencillas de Unix para aprender descriptores de archivo,
lectura por bloques, tratamiento de errores y proyectos divididos en módulos.

| Ejercicio | Programa | Enfoque |
|---|---|---|
| ex00 | `ft_display_file` | Muestra un archivo validando los argumentos. |
| ex01 | `ft_cat` | Concatena archivos y admite la entrada estándar. |
| ex02 | `ft_tail` | Presenta el tramo final solicitado y gestiona varios archivos. |
| ex03 | `ft_hexdump` | Formatea bytes, desplazamientos y representación imprimible. |

## Qué aprendí

- A abrir, leer y cerrar descriptores, comprobando cada valor de retorno.
- A procesar flujos por bloques en lugar de asumir que una lectura entrega todo.
- A enviar mensajes de error al descriptor adecuado y continuar cuando procede.
- A coordinar cabeceras, varios archivos fuente y reglas de compilación.

## Dificultades

Una lectura corta no equivale necesariamente a fin de archivo y cada descriptor
abierto debe cerrarse incluso tras un error. `tail` añade el cálculo del tramo
final y `hexdump` exige conservar el desplazamiento y alinear exactamente grupos
parciales, duplicados y caracteres no imprimibles.

## Estado del repositorio

| Aspecto | Situación |
|---|---|
| Cobertura | Implementaciones presentes para `ex00`–`ex03`. |
| Verificación | Hay reglas de compilación, pero no una suite de pruebas documentada en esta carpeta. |
| Validación académica | Realizado fuera del periodo de Piscine; sin validación de Moulinette. |
