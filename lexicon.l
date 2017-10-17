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
#include "grammar.tab.h"

void count();
void comment();
int check_type();
void lexical_error();
void count_error();
char* concat();
%}
%option yylineno

%%


"/*"((("*"[^/])?)|[^*])*"*/" { count(); /* ignore multi line comments */}
"//".*                  { count();  /* ignore comments */      }
^"#".*                  { count();  /* ignore comments */      }
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

int yywrap()
{
  return(1);
}


extern void yyerror(const char *s);
extern int recovering();

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
