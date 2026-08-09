# C Piscine Exam

Este directorio separa deliberadamente el material de referencia del trabajo
original:

- `reference/`: submódulo que apunta a `ayoub0x1/C-Piscine-exam` y conserva su
  procedencia e historial.
- `Level00/` a `Level05/`: implementaciones propias, organizadas por nivel.

## Clonado

Para obtener también la referencia externa:

```sh
git clone --recurse-submodules git@github.com:ME0094/42.git
```

En una copia ya existente:

```sh
git submodule update --init --recursive
```

## Actualización de la referencia

```sh
git submodule update --remote Exam/reference
```

Las soluciones propias se escriben desde cero, se validan individualmente con
`tests/run.sh` y respetan las reglas académicas aplicables.

## Puertas de calidad

Desde WSL se pueden reproducir las tres comprobaciones principales:

```sh
sh Exam/tests/run.sh
sh Exam/tests/memory.sh
sh Exam/tests/audit.sh
sh Exam/tests/quality.sh
```

La auditoría comprueba los 73 ejercicios contra sus enunciados: archivos
esperados, compilación estricta, Norminette y símbolos externos permitidos.
La prueba de memoria ejecuta Valgrind sobre todas las funciones que reservan o
liberan memoria, todos los programas y casos representativos con entrada.

Los criterios completos están documentados en la
[auditoría de calidad](../docs/AUDITORIA_EXAM.md).

## Uso pedagógico

Antes de consultar una solución, realiza un intento propio, define casos límite
y conserva una explicación del bloqueo. Después de comparar enfoques, cierra la
referencia y reescribe la solución desde cero. Consulta el
[plan pedagógico](../docs/PLAN_PEDAGOGICO.md) para seguir el itinerario completo.

## Qué aprendí

- **Level00:** salida exacta con `write`, control de argumentos y recorridos mínimos.
- **Level01:** manipulación básica de cadenas, punteros y transformaciones de caracteres.
- **Level02:** conversión de texto, operaciones con bits, conjuntos de caracteres y subsecuencias.
- **Level03:** rangos dinámicos, bases, aritmética, primalidad, formato de palabras y listas.
- **Level04:** gestión de memoria, listas, ordenación, partición de cadenas, parsers y búsqueda espacial.
- **Level05:** pilas, expresiones RPN, estructuras anidadas, máscaras de opciones, memoria y ciclos.

Cada nivel dispone de su propio README con objetivos, método de práctica y casos
de comprobación. Las implementaciones originales abarcan 11 ejercicios en
Level00, 13 en Level01, 15 en Level02, 15 en Level03, 13 en Level04 y 6 en
Level05: 73 ejercicios en total.

## Dificultades

La progresión combina restricciones de funciones permitidas con formatos de
salida estrictos. En los primeros niveles, los fallos más fáciles de pasar por
alto son cadenas vacías, argumentos ausentes y límites de recorrido. En los
niveles intermedios aparecen propiedad de memoria, bases, bits y reenlace de
listas. Los últimos ejercicios requieren modelar estados explícitos para no
mezclar análisis, validación y ejecución.

La estrategia común del repositorio es compilar con advertencias estrictas,
probar casos límite, ejecutar los arneses funcionales y revisar con Valgrind las
rutas que reservan memoria. La matriz de `tests/MATRIZ_FUNCIONAL.tsv` mantiene
trazabilidad entre cada implementación y sus comprobaciones.

## Estado del repositorio

| Aspecto | Situación |
|---|---|
| Cobertura | 73 implementaciones presentes entre Level00 y Level05. |
| Verificación | Pruebas funcionales, auditoría, calidad y memoria reproducibles desde `tests/`. |
| Validación académica | Las pruebas locales no equivalen a una validación oficial de 42. |
