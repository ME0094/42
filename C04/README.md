# C04 — cadenas y conversiones numéricas

## Objetivo

Consolidar la entrada y salida básica y convertir entre texto y números, tanto
en decimal como en bases definidas por una cadena de símbolos.

| Ejercicio | Implementación | Enfoque |
|---|---|---|
| ex00 | `ft_strlen` | Longitud de una cadena. |
| ex01 | `ft_putstr` | Escritura secuencial con `write`. |
| ex02 | `ft_putnbr` | Impresión recursiva de enteros. |
| ex03 | `ft_atoi` | Lectura de espacios, signos y dígitos decimales. |
| ex04 | `ft_putnbr_base` | Conversión de un entero a una base válida. |
| ex05 | `ft_atoi_base` | Conversión de una cadena desde una base válida. |

## Qué aprendí

- A separar el análisis del signo, la acumulación del valor y la salida de dígitos.
- A validar una base: al menos dos símbolos, sin repetidos, espacios ni signos.
- A usar recursión para imprimir desde el dígito más significativo.
- A tratar el mínimo entero sin intentar convertirlo primero a su positivo representable.

## Dificultades

El punto crítico es combinar signos consecutivos y detener la conversión en el
primer carácter ajeno a la base. En la salida, el mínimo de `int` requiere
evitar un desbordamiento; trabajar con un tipo más amplio o descomponer el valor
antes de negarlo mantiene el cálculo definido.

## Estado del repositorio

| Aspecto | Situación |
|---|---|
| Cobertura | Implementaciones presentes para `ex00`–`ex05`. |
| Verificación | No hay pruebas automatizadas documentadas en esta carpeta. |
| Validación académica | No consta en el repositorio. |
