# Plan pedagógico de C y preparación para la Piscina 42

## Propósito

Este repositorio público sirve como itinerario de práctica autónoma de C. No es
material oficial de 42 ni sustituye sus normas, evaluaciones o acompañamiento
entre pares. Las soluciones se utilizan para revisar un intento propio, no para
evitar el proceso de aprendizaje.

Al terminar el itinerario, la persona estudiante deberá poder:

- traducir un problema pequeño a un algoritmo verificable;
- escribir C legible con control explícito de memoria y errores;
- compilar con advertencias estrictas y diagnosticar fallos;
- explicar cada decisión sin depender del código del repositorio;
- resolver ejercicios contrarreloj conservando precisión y simplicidad.

## Principios de aprendizaje

1. **Intento antes que consulta.** Dedicar al menos 30 minutos a comprender,
   diseñar y probar una solución antes de abrir la implementación disponible.
2. **Recuperación activa.** Rehacer ejercicios sin mirar código después de 1,
   3, 7 y 14 días.
3. **Explicación oral.** Poder describir entradas, invariantes, complejidad,
   casos límite y errores posibles.
4. **Pruebas antes de confianza.** Una compilación correcta no demuestra un
   comportamiento correcto.
5. **Progreso por dominio.** Avanzar al alcanzar los criterios de salida, no
   únicamente por haber transcurrido una semana.

## Ciclo de trabajo por ejercicio

1. Leer el enunciado y anotar entradas, salida exacta, restricciones y funciones
   permitidas.
2. Escribir ejemplos propios, incluidos cadena vacía, cero, límites, argumentos
   incorrectos y errores de asignación cuando correspondan.
3. Diseñar el algoritmo en lenguaje natural y estimar tiempo y memoria.
4. Implementar sin consultar la solución del repositorio.
5. Compilar con `cc -Wall -Wextra -Werror` y ejecutar las pruebas propias.
6. Comparar con la implementación publicada solo después de tener un intento
   funcional o de documentar el bloqueo.
7. Registrar una reflexión breve: error principal, corrección y regla aprendida.
8. Rehacer el ejercicio desde cero durante las sesiones de repaso espaciado.

## Itinerario de 12 semanas

La carga recomendada es de 8 a 12 horas semanales, repartidas en cuatro o cinco
sesiones. Cada semana incluye práctica, revisión entre pares y una sesión corta
sin consultar apuntes.

### Fase 1 — Fundamentos y disciplina de trabajo (semanas 1 y 2)

- Terminal, compilación, tipos, operadores, condiciones, bucles y funciones.
- Salida con `write`, tratamiento de argumentos y coincidencia exacta de salida.
- Ejercicios: `Exam/Level00`, `Exam/Level01` y selección inicial de `C03`–`C04`.
- Criterio de salida: resolver de nuevo cinco ejercicios aleatorios sin mirar y
  explicar todos los avisos del compilador.

### Fase 2 — Cadenas, memoria y representación (semanas 3 y 4)

- Punteros, arrays, cadenas, conversiones, bases, bits y asignación dinámica.
- Ejercicios: `Exam/Level02`, `C05`, `C06` y `C07`.
- Criterio de salida: implementar y probar funciones de cadena sin biblioteca,
  justificar cada acceso y liberar toda memoria reservada.

### Fase 3 — Descomposición y estructuras (semanas 5 y 6)

- Recursividad, rangos, listas enlazadas, punteros a función y modularidad.
- Ejercicios: `Exam/Level03`, `C08`, `C09` y `C11`.
- Criterio de salida: dibujar el estado de memoria de una lista, construir un
  arnés de prueba y defender la complejidad de la solución.

### Fase 4 — Sistemas y casos complejos (semanas 7 y 8)

- Descriptores, lectura de archivos, errores, algoritmos de recorrido e
  intérpretes pequeños.
- Ejercicios: `Exam/Level04`, `C10` y `C12`.
- Criterio de salida: resolver dos ejercicios medianos consecutivos sin fugas,
  accesos inválidos ni funciones no autorizadas.

### Fase 5 — Integración y robustez (semanas 9 y 10)

- Pilas, análisis de expresiones, ciclos, representación de memoria y validación
  exhaustiva de entrada.
- Ejercicios: `Exam/Level05`, `C13` y revisión de `Rush01`.
- Criterio de salida: pasar una simulación de 3 horas y explicar después las
  decisiones, fallos descartados y pruebas utilizadas.

### Fase 6 — Consolidación y portfolio (semanas 11 y 12)

- Rehacer ejercicios fallados, reducir complejidad accidental y mejorar nombres.
- Preparar una demostración pública basada en razonamiento, pruebas y evolución,
  no en el número bruto de soluciones.
- Realizar dos simulaciones completas con ejercicios elegidos al azar.
- Criterio final: obtener al menos 80 % en la rúbrica, sin ningún fallo crítico de
  memoria, compilación, autoría o explicación.

## Rutina semanal recomendada

- **Sesión A — Concepto:** explicación breve y dos ejercicios guiados.
- **Sesión B — Práctica deliberada:** tres ejercicios sin consultar soluciones.
- **Sesión C — Depuración:** pruebas límite, compilador, memoria y simplificación.
- **Sesión D — Repaso:** recuperación espaciada de ejercicios anteriores.
- **Sesión E — Simulación o revisión entre pares:** tiempo limitado y defensa oral.

## Evaluación formativa

Cada ejercicio se valora sobre 10 puntos:

- 2 puntos: comprensión de requisitos y restricciones;
- 2 puntos: corrección funcional y salida exacta;
- 2 puntos: casos límite y pruebas reproducibles;
- 2 puntos: claridad, descomposición y funciones permitidas;
- 1 punto: memoria, errores y ausencia de comportamiento indefinido;
- 1 punto: explicación oral y capacidad de rehacerlo.

Un ejercicio se considera dominado con 8/10 y una repetición correcta sin apoyo
al menos siete días después. Un fallo de compilación estricta, una función no
permitida, código no comprendido o una fuga grave impiden marcarlo como dominado.

## Uso de las soluciones públicas

- Consultar primero la ruta y el enunciado de referencia, nunca comenzar copiando.
- Comparar algoritmos y pruebas, no líneas aisladas.
- Cerrar la solución y reescribir el ejercicio desde una carpeta vacía.
- Citar el repositorio si se reutilizan ideas o fragmentos donde una licencia y
  las reglas académicas lo permitan.
- No presentar estas implementaciones como soluciones oficiales ni como trabajo
  propio de otra persona.

## Verificación técnica

Desde WSL, la colección de exámenes puede comprobarse con:

```sh
sh Exam/tests/run.sh
```

La revisión mínima de cada entrega debe confirmar compilación estricta, salida
exacta, funciones permitidas, casos límite y limpieza del árbol Git. Norminette
se añadirá a la comprobación cuando esté disponible en el entorno.

## Registro de progreso

Para cada sesión se recomienda conservar únicamente información pedagógica:

- fecha y ejercicios intentados;
- tiempo hasta una primera solución válida;
- error conceptual principal;
- prueba que reveló el error;
- fecha del próximo repaso;
- estado: iniciado, funcional, verificado o dominado.

No deben registrarse credenciales, datos personales, enunciados restringidos,
calificaciones oficiales ni material cuya publicación no esté autorizada.
