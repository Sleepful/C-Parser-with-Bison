D      [0-9]
L      [a-zA-Z_]
H      [a-fA-F0-9]
E      [Ee][+-]?{D}+
FS     (f|F|l|L)
IS     (u|U|l|L)*

%{
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <libgen.h>
#include "grammar.tab.h"
#include "main.h"

#define RESET       "\033[0m"
#define KNRM        "\x1B[0m"
#define KRED        "\x1B[31m"
#define KGRN        "\x1B[32m"
#define KYEL        "\x1B[33m"
#define KBLU        "\x1B[34m"
#define KMAG        "\x1B[35m"
#define KCYN        "\x1B[36m"
#define KWHT        "\x1B[37m"
#define BOLDBLACK   "\033[1m\033[30m"
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
void count();
void comment();
int check_type();
void lexical_error();
void count_error();
char* concat();
extern char* current_file[MAX_INCL];
extern int current_file_i;


char* header_file;
char* tmp_file;
char* dir;
%}
%option yylineno
%x incl
%%


"/*"((("*"[^/])?)|[^*])*"*/" { count(); /* ignore multi line comments */}
"//".*                  { count();  /* ignore comments */      }



^#include               { BEGIN(incl);                         }
<incl>[ \t]*[<\"]       {}
      /* normal includes */
<incl>[a-zA-Z_\.0-9]+\" {
                        if ( current_file_i+1 >= MAX_INCL )
                          {
                          printf("\n Includes nested too deeply.\n");
                          exit( 1 );
                          }
                        tmp_file = malloc(strlen(current_file[current_file_i]));
                        strcpy(tmp_file,current_file[current_file_i]);
                        dirname(tmp_file);
                        header_file = malloc(
                                            strlen(tmp_file)+
                                            1+
                                            strlen(yytext)+
                                            1
                                            );
                        header_file[0] = '\0';
                        //printf("header %s \n",header_file);
                        //printf("yytext %s \n",yytext);
                        strcat(header_file, tmp_file);
                        //printf("header %s \n",header_file);
                        strcat(header_file, "/");
                        //printf("header d %s \n",tmp_file);
                        strcat(header_file, yytext);
                        header_file[strlen(header_file)-1] = 0;
                        //printf(BOLDGREEN"\nOpening file :"RESET"%s \n",header_file);

                        yyin = fopen(header_file, "r");

                        if(!yyin)
                          {
                          printf("\nERROR opening file\n");
                          yyterminate();
                          }
                        else
                          {
                          current_file_i++;
                          current_file[current_file_i]=header_file;
                          //printf(BOLDGREEN "\nReading file :" RESET " %s\n",header_file);
                          yypush_buffer_state(yy_create_buffer( yyin, YY_BUF_SIZE));
                          }
                        BEGIN(INITIAL);
                        }
      /* system includes */
<incl>[a-zA-Z_\.0-9]+>  {
                        }


^"#"define.*                    { count();    }
"auto"                  { count();    return(AUTO);            }
"break"                 { count();    return(BREAK);           }
"case"                  { count();    return(CASE);            }
"char"                  { count();    return(CHAR);            }
"const"                 { count();    return(CONST);           }
"continue"              { count();    return(CONTINUE);        }
"default"               { count();    return(DEFAULT);         }
"do"                    { count();    return(DO);              }
"double"                { count();    return(DOUBLE);          }
"else"                  { count();    return(ELSE);            }
"enum"                  { count();    return(ENUM);            }
"extern"                { count();    return(EXTERN);          }
"float"                 { count();    return(FLOAT);           }
"for"                   { count();    return(FOR);             }
"goto"                  { count();    return(GOTO);            }
"if"                    { count();    return(IF);              }
"int"                   { count();    return(INT);             }
"long"                  { count();    return(LONG);            }
"register"              { count();    return(REGISTER);        }
"return"                { count();    return(RETURN);          }
"short"                 { count();    return(SHORT);           }
"signed"                { count();    return(SIGNED);          }
"sizeof"                { count();    return(SIZEOF);          }
"static"                { count();    return(STATIC);          }
"struct"                { count();    return(STRUCT);          }
"switch"                { count();    return(SWITCH);          }
"typedef"               { count();    return(TYPEDEF);         }
"union"                 { count();    return(UNION);           }
"unsigned"              { count();    return(UNSIGNED);        }
"void"                  { count();    return(VOID);            }
"volatile"              { count();    return(VOLATILE);        }
"while"                 { count();    return(WHILE);           }
{L}({L}|{D})*           { count();    return(check_type());    }
0[xX]{H}+{IS}?          { count();    return(CONSTANT);        }
0{D}+{IS}?              { count();    return(CONSTANT);        }
{D}+{IS}?               { count();    return(CONSTANT);        }
L?'(\\.|[^\\'])+'       { count();    return(CONSTANT);        }
{D}+{E}{FS}?            { count();    return(CONSTANT);        }
{D}*"."{D}+({E})?{FS}?  { count();    return(CONSTANT);        }
{D}+"."{D}*({E})?{FS}?  { count();    return(CONSTANT);        }
L?\"(\\.|[^\\"])*\"     { count();    return(STRING_LITERAL);  }
"..."                   { count();    return(ELLIPSIS);        }
">>="                   { count();    return(RIGHT_ASSIGN);    }
"<<="                   { count();    return(LEFT_ASSIGN);     }
"+="                    { count();    return(ADD_ASSIGN);      }
"-="                    { count();    return(SUB_ASSIGN);      }
"*="                    { count();    return(MUL_ASSIGN);      }
"/="                    { count();    return(DIV_ASSIGN);      }
"%="                    { count();    return(MOD_ASSIGN);      }
"&="                    { count();    return(AND_ASSIGN);      }
"^="                    { count();    return(XOR_ASSIGN);      }
"|="                    { count();    return(OR_ASSIGN);       }
">>"                    { count();    return(RIGHT_OP);        }
"<<"                    { count();    return(LEFT_OP);         }
"++"                    { count();    return(INC_OP);          }
"--"                    { count();    return(DEC_OP);          }
"->"                    { count();    return(PTR_OP);          }
"&&"                    { count();    return(AND_OP);          }
"||"                    { count();    return(OR_OP);           }
"<="                    { count();    return(LE_OP);           }
">="                    { count();    return(GE_OP);           }
"=="                    { count();    return(EQ_OP);           }
"!="                    { count();    return(NE_OP);           }
";"                     { count();    return(';');             }
("{"|"<%")              { count();    return('{');             }
("}"|"%>")              { count();    return('}');             }
","                     { count();    return(',');             }
":"                     { count();    return(':');             }
"="                     { count();    return('=');             }
"("                     { count();    return('(');             }
")"                     { count();    return(')');             }
("["|"<:")              { count();    return('[');             }
("]"|":>")              { count();    return(']');             }
"."                     { count();    return('.');             }
"&"                     { count();    return('&');             }
"!"                     { count();    return('!');             }
"~"                     { count();    return('~');             }
"-"                     { count();    return('-');             }
"+"                     { count();    return('+');             }
"*"                     { count();    return('*');             }
"/"                     { count();    return('/');             }
"%"                     { count();    return('%');             }
"<"                     { count();    return('<');             }
">"                     { count();    return('>');             }
"^"                     { count();    return('^');             }
"|"                     { count();    return('|');             }
"?"                     { count();    return('?');             }
[\t\n\f ]               { count();                             }
.                       { count();                             }
%%

int yywrap(void)
{
  yypop_buffer_state();
  if ( !YY_CURRENT_BUFFER )
    return 1;
  current_file_i--;
  //printf(BOLDRED "\nExiting file : %s\n" RESET,header_file);
  return 0;
}

extern void yyerror(const char *s);

int column = 0;
int l_error_flag=0;

void count_error()
  {
  count();
  if(l_error_flag)
    yyerror("Lexical error");
  l_error_flag =1;
  return;
  }

/* manejo de line_string:
 *  el string de la linea actual que se esta leyendo
 *  hasta el current token
 * */
char* line_string;

void clear_line_string()
  {
  //printf("clear line string\n");
  free(line_string);
  line_string = malloc(1);
  strcpy(line_string,"");
  return;
  }

void append_line_string()
  {
  //printf("append line string\n");
  char* temp;
  temp = concat(line_string,yytext);
  free(line_string);
  line_string = temp;
  return;
  }

void fill_line()
  {
  char c;
  int puts =0;
  int strlen_int = strlen (line_string);
  char *ptr = malloc(2*sizeof(char));


  /* color */

  /* no more color */
  puts = 0;
  while ((c = input()) != '\n')
    {
    ptr[0] = c;
    ptr[1] = '\0';
    line_string = concat(line_string,ptr);
    puts++;
    }
  free(ptr);
  for(puts;puts>0;puts--)
    {
    c = line_string[strlen_int+puts];
    unput(c);
    }
  return;
  }

char* concat(char *s1,char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);
    /* +1 for the null terminator */
    /* check for malloc error */
    if (!result)
      {
      printf("failed to realloc in function concat(), lexicon.l");
      exit(9); //failed to realloc
      }
    //printf("string %s\n", line_string);
    strcpy(result, s1);
    strcat(result, s2);
    //printf("string %s\n", result);
    //printf("string %s\n", result);
    return result;
}

/* prints a lexical error to stdout */
/* not gonna use this probably */
void llerror()
  {
  return;
  }

void count()
{
  //ECHO;
  int i;

  for (i = 0; yytext[i] != '\0'; i++)
    {
    if (yytext[i] == '\n')
      {
      clear_line_string();
      column = 0;
      return;
      }
    else if (yytext[i] == '\t')
      {
      column += 8 - (column % 8);
      }
    else
      {
      column++;
      }
    }
    append_line_string();
    l_error_flag = 0;
    return;

  //ECHO;
}


int check_type()
{
/*
* pseudo code --- this is what it should check
*
*  if (yytext == type_name)
*    return(TYPE_NAME);
*
*  return(IDENTIFIER);
*/

/*
*  it actually will only return IDENTIFIER
*/

  //ECHO;
  return(IDENTIFIER);
}

/*
void comment()
{
  char c, c1;

loop:
  while ((c = input()) != '*' && c != 0)
    ;//putchar(c);

  if ((c1 = input()) != '/' && c != 0)
  {
    ;//unput(c1);
    goto loop;
  }

  if (c != 0)
    ;//putchar(c1);
}
*/
