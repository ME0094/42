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
