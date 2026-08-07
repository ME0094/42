# Auditoría de calidad de C Piscine Exam

## Alcance

La puerta de calidad revisa individualmente los 73 ejercicios de `Exam` contra
su correspondiente `subject.en.txt`. Para cada ejercicio comprueba:

- presencia de los archivos esperados;
- compilación con `-Wall -Wextra -Werror`;
- cumplimiento de Norminette;
- símbolos externos compatibles con las funciones permitidas.

La matriz `Exam/tests/MATRIZ_FUNCIONAL.tsv` documenta una entrada y su oráculo
de salida para cada uno de los 73 ejercicios. `functional.sh` ejecuta esa
matriz con comparación byte a byte, incluidas las diferencias de espacios y
saltos de línea, y rechaza cualquier ejercicio ausente o duplicado.

La prueba de memoria ejecuta con Valgrind todas las funciones que reservan o
liberan memoria, todos los programas compilables sin argumentos y casos
funcionales representativos con entrada.

## Reproducción

En WSL, con Norminette y Valgrind instalados:

```sh
sh Exam/tests/quality.sh
```

El resultado solo es válido cuando finaliza con `Quality gate: PASS`, muestra
`Functional coverage: total=73 unique=73 expected=73 passed=73 failed=0`,
73 ejercicios auditados y ningún error de Norminette, compilación, funciones
permitidas o memoria.

## Interpretación

Esta auditoría es una defensa técnica reproducible, no una garantía de
aceptación por un evaluador ni una sustitución de las reglas vigentes de 42.
Los casos límite deben ampliarse cuando se detecte una regresión o una
interpretación más precisa de un enunciado.
