%{
#include "scanner.h"
%}
%option nounput yylineno

%%

    /* comments in c! */
      /* multi line */
"/*"((("*"[^/])?)|[^*])*"*/" return COMMENT;
      /* single line */
"//".*          return COMMENT;
    /* skip preprocessor lines */
^"#".*          return PREPROCESSOR;
    /*  reserved keywords */
auto          return KEYWORD;
double          return KEYWORD;
int          return KEYWORD;
struct          return KEYWORD;
break          return KEYWORD;
else          return KEYWORD;
long          return KEYWORD;
switch          return KEYWORD;
case          return KEYWORD;
enum          return KEYWORD;
register          return KEYWORD;
typedef          return KEYWORD;
char          return KEYWORD;
extern          return KEYWORD;
return          return KEYWORD;
union          return KEYWORD;
const          return KEYWORD;
float          return KEYWORD;
short          return KEYWORD;
unsigned          return KEYWORD;
continue          return KEYWORD;
for          return KEYWORD;
signed          return KEYWORD;
void          return KEYWORD;
default          return KEYWORD;
goto          return KEYWORD;
sizeof          return KEYWORD;
volatile          return KEYWORD;
do          return KEYWORD;
if          return KEYWORD;
static          return KEYWORD;
while          return KEYWORD;
    /* constants */
      /* decimal */
[-+]?[0-9]+        return CONSTANTLITERAL;
      /* octal */
O[0-9]+          return CONSTANTLITERAL;
      /* hexadecimal */
OX[0-9abcdef]+      return CONSTANTLITERAL;
      /* real(fractional) */
[-+]?[0-9]+(\.[0-9]+)?  return CONSTANTLITERAL;
      /* single character */
'([^\r^\n^']|\\0)'        return CONSTANTCHAR;
      /* strings */
\"[^\"]*\" return CONSTANTSTRING;


    /* Identifier (variable names) */
[a-zA-Z_][_a-zA-Z0-9]*  return IDENTIFIER;

    /* operators */
      /* arithmetic */
\+            return OPERATOR;
-             return OPERATOR;
\*             return OPERATOR;
\/             return OPERATOR;
\%            return OPERATOR;
\+\+            return OPERATOR;
"--"            return OPERATOR;

      /* relational */
==            return OPERATOR;
!=            return OPERATOR;
\>             return OPERATOR;
\<             return OPERATOR;
\>=            return OPERATOR;
\<=            return OPERATOR;
      /* logical */
&&            return OPERATOR;
\|\|            return OPERATOR;
!            return OPERATOR;
      /* bitwise */
&             return OPERATOR;
\|             return OPERATOR;
\^             return OPERATOR;
~             return OPERATOR;
\<\<            return OPERATOR;
\>\>            return OPERATOR;
      /* misc */
"?"            return OPERATOR;

      /* punctuators */
\(            return PUNCTUATOR;
\)            return PUNCTUATOR;
\{            return PUNCTUATOR;
\}            return PUNCTUATOR;
\[            return PUNCTUATOR;
\]            return PUNCTUATOR;
,            return PUNCTUATOR;
:            return PUNCTUATOR;
;            return PUNCTUATOR;
=            return PUNCTUATOR;


    /* skip new lines and blank spaces */
[ \t\n]          return BLANK;
    /* everything not defined before is caught here, considered an error */
.            return ERROR;

%%

int yywrap(void)
{
  return 1;
}


