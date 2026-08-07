# Level04 — memoria, listas y parsers

## Objetivos

- Reservar y liberar estructuras dinámicas con seguridad.
- Ordenar y filtrar listas conservando enlaces válidos.
- Implementar parsers y transformaciones con estados explícitos.

## Método

Define invariantes antes del bucle: qué memoria existe, quién la libera y qué
parte de la entrada ya está procesada. Divide algoritmos grandes en ayudantes
pequeños compatibles con las funciones permitidas.

## Comprobación personal

Incluye listas vacías, eliminación en cabeza y cola, asignaciones fallidas cuando
puedan simularse, bases extremas y entradas con solo separadores.
