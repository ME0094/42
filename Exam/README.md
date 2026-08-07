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

## Uso pedagógico

Antes de consultar una solución, realiza un intento propio, define casos límite
y conserva una explicación del bloqueo. Después de comparar enfoques, cierra la
referencia y reescribe la solución desde cero. Consulta el
[plan pedagógico](../docs/PLAN_PEDAGOGICO.md) para seguir el itinerario completo.
