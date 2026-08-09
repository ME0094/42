# C09 — biblioteca estática y automatización de compilación

## Objetivo

Empaquetar funciones reutilizables en una biblioteca, automatizar su creación y
compilar proyectos de forma reproducible.

| Ejercicio | Entregable | Enfoque |
|---|---|---|
| ex00 | `libft_creator.sh` | Compila fuentes y crea `libft.a`. |
| ex01 | `Makefile` | Automatiza compilación, limpieza y reconstrucción. |
| ex02 | `ft_split` | Separa una cadena usando un conjunto de delimitadores. |

## Qué aprendí

- A distinguir compilación, archivos objeto, archivado y enlazado.
- A expresar dependencias y objetivos idempotentes en un `Makefile`.
- A evitar artefactos temporales innecesarios en el repositorio.
- A construir y liberar un array dinámico de cadenas terminado en `NULL`.

## Dificultades

La automatización debe funcionar al repetirse y reconstruir solo lo necesario.
En `ft_split`, delimitadores consecutivos y cadenas vacías obligan a separar con
claridad el conteo de palabras, la reserva y la copia de cada fragmento.

## Estado del repositorio

| Aspecto | Situación |
|---|---|
| Cobertura | Implementaciones presentes para `ex00`–`ex02`. |
| Verificación | No hay pruebas automatizadas documentadas en esta carpeta. |
| Validación académica | No consta en el repositorio. |
