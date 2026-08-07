# C Piscine Exam

Este directorio separa deliberadamente el material de referencia del trabajo
original:

- `reference/`: submódulo que apunta a `ayoub0x1/C-Piscine-exam` y conserva su
  procedencia e historial.
- `solutions/`: implementaciones propias, organizadas por nivel.

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

Las soluciones propias deben escribirse desde cero, validarse individualmente
y respetar las reglas académicas aplicables antes de publicarse.
