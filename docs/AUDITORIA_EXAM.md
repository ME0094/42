# Auditoría de calidad de C Piscine Exam

## Alcance

La puerta de calidad revisa individualmente los 73 ejercicios de `Exam` contra
su correspondiente `subject.en.txt`. Para cada ejercicio comprueba:

- presencia de los archivos esperados;
- compilación con `-Wall -Wextra -Werror`;
- cumplimiento de Norminette;
- símbolos externos compatibles con las funciones permitidas.

La prueba de memoria ejecuta con Valgrind todas las funciones que reservan o
liberan memoria, todos los programas compilables sin argumentos y casos
funcionales representativos con entrada.

## Reproducción

En WSL, con Norminette y Valgrind instalados:

```sh
sh Exam/tests/quality.sh
```

El resultado solo es válido cuando finaliza con `Quality gate: PASS`, muestra
73 ejercicios aprobados y no informa de errores de Norminette, compilación,
funciones permitidas o memoria.

## Interpretación

Esta auditoría es una defensa técnica reproducible, no una garantía de
aceptación por un evaluador ni una sustitución de las reglas vigentes de 42.
Los casos límite deben ampliarse cuando se detecte una regresión o una
interpretación más precisa de un enunciado.
