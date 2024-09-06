# Get Next Line

## Objetivos
Este proyecto tiene como objetivo implementar una función útil y práctica, `get_next_line`, que te permitirá leer líneas de un archivo de manera eficiente. Además, te ayudará a entender y trabajar con variables estáticas en C, un concepto poderoso que te permitirá almacenar datos entre llamadas a funciones.

## Instrucciones Generales
- El proyecto debe estar escrito en lenguaje C.
- Debes seguir la Norma de estilo de C para la codificación.
- Asegúrate de que no haya errores inesperados en la ejecución (segfaults, errores de memoria, etc.). En caso contrario, el proyecto será considerado no funcional.
- Toda la memoria asignada debe ser liberada adecuadamente para evitar fugas de memoria.
- El proyecto debe incluir un **Makefile** que compile el código con las flags `-Wall`, `-Werror` y `-Wextra`. Este debe tener las reglas estándar: `all`, `clean`, `fclean`, `re` y, si hay bonus, la regla `bonus`.
- Si utilizas la librería **libft**, esta debe ser incluida en el proyecto con su propio Makefile.
- Se recomienda crear programas de prueba para verificar el correcto funcionamiento.

## Parte Obligatoria
- Función principal: `get_next_line(int fd)`
- El objetivo es leer un archivo línea por línea usando un descriptor de archivo (`fd`).
- La función devolverá cada línea leída hasta llegar al final del archivo o en caso de error.
- Debe funcionar con cualquier valor de `BUFFER_SIZE` que se le pase en la compilación, manejando correctamente archivos grandes o pequeños.
- **Funciones autorizadas**: `read`, `malloc`, `free`.

## Parte Bonus
- Implementar la función `get_next_line` con la capacidad de gestionar múltiples descriptores de archivo al mismo tiempo.
- Desarrollar la función utilizando una sola variable estática.

## Archivos a Entregar
- `get_next_line.c`
- `get_next_line_utils.c`
- `get_next_line.h`
- (Para bonus) `get_next_line_bonus.c`, `get_next_line_bonus.h`, `get_next_line_utils_bonus.c`

## Consideraciones Adicionales
Este proyecto es una excelente oportunidad para optimizar el manejo de la lectura de archivos, utilizando conceptos importantes como variables estáticas y gestión de memoria.
