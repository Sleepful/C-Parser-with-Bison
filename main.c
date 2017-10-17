#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include "main.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
extern FILE* yyin;
extern int yyparse();
extern void clear_line_string();
extern int yydebug;

char* current_file[5];
int current_file_i = 0;


int main(int argc, char * * argv)
{
  errno = 0;
  verificarArgumentos(argc,argv);
  /* clear_line mallocs the current string buffer */
  clear_line_string();
  //yydebug = 1;
  current_file[0] = argv[1];
  yyparse();
  return 1;
}


/* verifica los argumentos pasados por linea de
 * comando al programa, devuelve:
 * 1=true
 * 0=false */
int verificarArgumentos(int argc, char * * argv)
  {
  if(argc==2)
    {
    char* nombre_archivo = argv[1];
    yyin = fopen(nombre_archivo, "r");
    if(yyin)
      return 1;
    else
      printf("\n  Archivo `%s` no encontrado.\n\n",argv[1]);
      exit(1);
    }
  print_help();
  exit(1);
  return 0;
  }

/* print a stdout si los argumentos son incorrectos */
void print_help()
  {
  printf(
  "\n  Porfavor llamar al programa con los argumentos correctos.\n\n  bison <nombre-del-archivo>\n\n   <nombre-del-archivo>     Archivo fuente C del cual desea verificar \n                            errores lexicos y sintácticos.\n\n");
  return;
  }
