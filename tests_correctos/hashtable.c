/* HASHTABLE y funciones para utilizarla
 * (al final del archivo)
 *
 * hashtable sacado de internet
 * cortesia de:
 *  https://stackoverflow.com/a/4384446/2446144
 * source de:
 *  C Programming Language, 2nd Edition
 *  */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "microinstrucciones.h"

struct nlist { /* table entry: */
    struct nlist *next; /* next entry in chain */
    char *name; /* defined name */
    char *defn; /* replacement text */
};

#define HASHSIZE 201
static struct nlist *hashtab[HASHSIZE]; /* pointer table */

/* hash: form hash value for string s */
unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
      hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
          return np; /* found */
    return NULL; /* not found */
}

char *strdup_ht(char *);
/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL) { /* not found */
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup_ht(name)) == NULL)
          return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else /* already there */
        free((void *) np->defn); /*free previous defn */
    if ((np->defn = strdup_ht(defn)) == NULL)
       return NULL;
    return np;
}

char *strdup_ht(char *s) /* make a duplicate of s */
{
    char *p;
    p = (char *) malloc(strlen(s)+1); /* +1 for ’\0’ */
    if (p != NULL)
       strcpy(p, s);
    return p;
}

/*
 * Esta seccion es parte del codigo
 * de la progra, agrega y busca el
 * correspondiente valor int de una
 * instruccion con su valor de string
 *
 * */

void init_default_instructions(void)
  {
  add_instruction(MOV_A     ,"mov"  );
  add_instruction(OUT_A     ,"out"  );
  add_instruction(IN_A      ,"in"   );
  add_instruction(JMP_A     ,"jmp"  );
  add_instruction(JZ_A      ,"jz"   );
  add_instruction(CMP_A     ,"cmp"  );
  add_instruction(CLI_A     ,"cli"  );
  add_instruction(STI_A     ,"sti"  );
  add_instruction(VAL_A     ,"val"  );
  return;
  }

void add_instruction(int id, char* def)
  {
    /* adds (int,char) */
    char *name;
    name = (char*)&id;
    install (name,def);
    /* adds (char,int) */
    install (def,name);
    return;
  }

char* find_instr_char(int id)
  {
  char* a;
  a = lookup((char*)&id)->defn;
  return a;
  }

int find_instr_id(char* name)
  {
  int a;
  a = lookup(name)->defn[0];
  return a;
  }

