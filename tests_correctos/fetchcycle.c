#include "microinstrucciones.h"
#include "fetchcycle.h"
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>

/* HACE FALTA:
 *   Parsing ASM: parsear programa ASM
 *   y colocarlo dentro de la memoria
 *   principal como numeritos short unsigned
 *   para ser faciles de leer. Esto se debe
 *   de hacer para poder correr un programa.
 *
 *   Y algunos modos de direccionamiento no
 *   estan implmenetados.
 *
 *   Paso de ejecucion.
 * */

void set_registro(arqui*a);
int ciclo_array[5];
int paso_fetch=0;

void siguiente_paso_ciclofetch(arqui* a)
  {
  int paso;
  paso = paso_fetch;
  switch(paso)
    {
    case 0:
      busqueda(a);
      break;
    case 1:
      decodificar(a);
      break;
    case 2:
      indirecto(a);
      break;
    case 3:
      ejecucion(a);
      break;
    case 4:
      interrupciones(a);
      printf("ciclo fetch terminado\n");
      break;
    deafult:
      printf("este paso no existe\n ver fetchcycle.c: void siguiente_paso_...");
      exit(0);
    }
    return;
  }
void hacer_ciclofetch(arqui* a)
  {
  if(paso_fetch==0)
    {
    busqueda(a);
    }
  if(paso_fetch==1)
    {
    decodificar(a);
    }
  if(paso_fetch==2)
    {
    indirecto(a);
    }
  if(paso_fetch==3)
    {
    ejecucion(a);
    }
  if(paso_fetch==4)
    {
    interrupciones(a);
    }
    printf("ciclo fetch terminado\n");
    return;
  }


/*
 * BD <-- PC
 * MAR <-- BD
 * read
 * BD <-- MBR
 * IR <-- BD
 * Inc PC
 */

void busqueda (arqui* a)
  {
  unsigned short temp;
  /* BD <-- PC */
  temp = getPC(a);
  setBD_val(a,temp);
  /* MAR <-- BD */
  temp = getBD_val(a);
  setMAR(a,temp);
  /* read */
  /* lee memoria y lo pasa a MBR*/
  setMBR_fuente
    (a,getcelda_fuente (a,getMAR(a)));
  setMBR_destino
    (a,getcelda_destino (a,getMAR(a)));
  setMBR_instruccion
    (a,getcelda_instruccion (a,getMAR(a)));
  setMBR_cuarto
    (a,getcelda_cuarto (a,getMAR(a)));
  /* en caso de que la memoria tenga un
   * valor en vez de una instruccion habria
   * que hacer algo diferente(?)
   * A: not really */


  /* BD <-- MBR */
  setBD_fuente      (a,getMBR_fuente      (a));
  setBD_destino     (a,getMBR_destino     (a));
  setBD_instruccion (a,getMBR_instruccion (a));
  setBD_cuarto      (a,getMBR_cuarto      (a));
  /* IR <-- BD*/
  setIR_fuente      (a,getBD_fuente      (a));
  setIR_destino     (a,getBD_destino     (a));
  setIR_instruccion (a,getBD_instruccion (a));
  setIR_cuarto      (a,getBD_cuarto      (a));
  /* inc pc */
  unsigned short pc = getPC(a);
  setPC(a,++pc);
  /* next paso */
  paso_fetch++;
  return;
  }

/* almacena instruccion en IR */
void decodificar (arqui* a)
  {
  /* next paso */
  paso_fetch++;
  return;
  }

/* se posicionan los datos en los
 * registros.
 * IR_cuarto indica modo direccionamiento
 * IR_instruccion indica tipo instruccion
 * creo que el proposito de esto es
 * buscar los valores si no estan inmediatos
 * y agregarlos como inmediatos al
 * setIR_fuente
 * de tal manera que en el IR_fuente solo
 * queden valores inmediatos o "literales"
 */
void indirecto (arqui* a)
  {
  /* si no es una instruccion de mov
   * no hace nada  */
  if(getIR_instruccion(a)!=MOV_A)
    {
    paso_fetch++;
    return;
    }
  /* inmediato */
  if(getIR_cuarto(a)==D_INMEDIATO)
    {
    /* nada */
    }
  /* registro */
  if(getIR_cuarto(a)==D_REGISTRO)
    {
    short unsigned reg;
    reg = getIR_fuente(a);
    switch(reg)
      {
      case R_AX:
        setIR_fuente(a,getAX(a));
        break;
      case R_BX:
        setIR_fuente(a,getBX(a));
        break;
      case R_CX:
        setIR_fuente(a,getCX(a));
        break;
      case R_DX:
        setIR_fuente(a,getDX(a));
        break;
      case R_AL:
        setIR_fuente(a,getAL(a));
        break;
      case R_BL:
        setIR_fuente(a,getBL(a));
        break;
      case R_CL:
        setIR_fuente(a,getCL(a));
        break;
      case R_DL:
        setIR_fuente(a,getDL(a));
        break;
      case R_AH:
        setIR_fuente(a,getAH(a));
        break;
      case R_BH:
        setIR_fuente(a,getBH(a));
        break;
      case R_CH:
        setIR_fuente(a,getCH(a));
        break;
      case R_DH:
        setIR_fuente(a,getDH(a));
        break;
      }
    }
  /* directo */
  if(getIR_cuarto(a)==D_DIRECTO)
    {
    /* sin implementar */
    }
  /* indexado */
  if(getIR_cuarto(a)==D_INDEXADO)
    {
    /* sin implementar */
    }
  /* next paso */
  paso_fetch++;
  return;
  }

/* se ejecuta el microprograma */
void ejecucion (arqui* a)
  {
  /* no es una instruccion y no hace nada */
  if
    (getIR_instruccion(a)==VAL_A
    || getIR_instruccion(a)==NULL_M)
      {
      paso_fetch++;
      return;
      }

  /* Ejecucion
   * ---------
   *
   * PASOS NECESARIOS:
   *   1.  leer codigo instruccion asm del IR
   *       y decidir que ejecutar.
   *   2.  buscar el microprograma del asm en
   *       un archivo con el mismo nombre?
   *   3.  parsear el archivo de microprograma
   *       y convertirlo a microinstrucciones
   *   3.1 guardar estas microinstrucciones en
   *       alguna parte del programa para poder
   *       ejecutarlas una a una.
   *       ó
   *       ejecutar cada microinstruccion confo-
   *       rme se van parseando hasta llegar a
   *       all end of file.
   *   4.  fin, guardar resultados en sus
   *       registros apropiados. (implementar
   *       modos de direccionamiento aqui)
   *
   * */
  /* 1. leer codigo de asm (IR)*/
    short unsigned codigo_instr;
    codigo_instr = getIR_instruccion(a);
  /* 2. buscar microprograma */
    /* excepto si es un mov, porque no hay microprograma */
    if(codigo_instr == MOV_A)
      {
      set_registro(a);
      }
    else
      {
      /* sin implementar */
      }
  /* 3. while loop de parsear y ejecutar */
  /* 4. the end */
    /* cerrar archivo? */
  /* next paso */
  paso_fetch++;
  return;
  }

/* no hay interrupciones lol */
void interrupciones (arqui* a)
  {
  set_flag_off(a,INTERRUPT);
  /* next paso */
  paso_fetch=0;
  return;
  }

void set_registro(arqui*a)
  {
  int registro = getIR_destino(a);
  short unsigned valor = getIR_fuente(a);
  setBD_val(a,valor);
  switch(registro)
    {
    case R_AX:
      setAX(a,valor);
      break;
    case R_BX:
      setBX(a,valor);
      break;
    case R_CX:
      setCX(a,valor);
      break;
    case R_DX:
      setDX(a,valor);
      break;
    case R_AL:
      setAL(a,valor);
      break;
    case R_BL:
      setBL(a,valor);
      break;
    case R_CL:
      setCL(a,valor);
      break;
    case R_DL:
      setDL(a,valor);
      break;
    case R_AH:
      setAH(a,valor);
      break;
    case R_BH:
      setBH(a,valor);
      break;
    case R_CH:
      setCH(a,valor);
      break;
    case R_DH:
      setDH(a,valor);
      break;
    }
  return;
  }
