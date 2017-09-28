# Objetivo

  Imprimir errores sintacticos a consola como los mensajes de error del compilador

# Por hacer

  * validacion de argumentos:
      si no se pasan argumentos o los argumentos no son correctos, desplegar un --help
        notas: no se si se puede hacer con el redirecconamiento de unix: > (asi estaba en el proyecto pasado)

  * el preprocesador con #include y #define.
    puntos extra:
      macros con parametros
      
      notas: no se si el #include puede ser entre varios archivos o si hay que verificar que no hayan #include circulares. Usar mismo comportamiento que gcc como los "<",">", etc.

  * como hacer todos los errores sintacticos de C posibles con Bison

  * generar buenos mensajes de error
      indicar exactamente donde se da el error:
      desplegar linea del fuente
      indicador a la posicion mas proxima donde se da el error

  * mismo componente lexico del proyecto pasado

  * puntos extra:
      opcion -B
      generar una presentacion beamer como en el proyecto pasado
      lo mismo que los errores a consola solo que con beamer y con
      un par de slides introductorios

  * 8 pruebas de programas grandes
    extra:
      si son programas del ioccc.org

