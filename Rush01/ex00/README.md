# Rush01 / ex00 — Skyscrapers

## Objetivo

Resolver un tablero de rascacielos de 4 × 4 a partir de las pistas de visibilidad
de sus cuatro lados. Cada fila y columna debe contener las alturas del 1 al 4
sin repetirse y respetar todas las vistas proporcionadas.

## Componentes

| Archivo | Responsabilidad |
|---|---|
| `main.c` | Coordina validación, resolución y salida. |
| `input.c` | Interpreta las pistas recibidas por argumento. |
| `validation.c` | Rechaza formatos, valores y estados inválidos. |
| `solver.c` | Explora candidatos con backtracking. |
| `output.c` | Presenta el tablero o el error esperado. |
| `rush01.h` | Comparte tipos y prototipos. |

## Qué aprendí

- A traducir reglas de un problema a restricciones verificables en código.
- A usar backtracking: elegir, validar parcialmente, avanzar y deshacer.
- A podar candidatos mediante unicidad y pistas de visibilidad.
- A dividir un programa colaborativo en interfaces y responsabilidades claras.

## Dificultades

Esperar a completar el tablero para validar produciría demasiadas combinaciones.
La dificultad central es descartar pronto filas y columnas imposibles sin
rechazar una solución aún incompleta. Separar lectura, validación, búsqueda y
salida hace que cada regla pueda comprobarse de forma aislada.

## Estado del repositorio

| Aspecto | Situación |
|---|---|
| Cobertura | Implementación presente para `ex00`. |
| Verificación | No hay pruebas automatizadas documentadas en esta carpeta. |
| Validación académica | No consta en el repositorio. |
