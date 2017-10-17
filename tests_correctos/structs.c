#include <stdlib.h>
#include "microinstrucciones.h"
#include "structs.h"
#define MEM_SIZE 256

typedef struct instructionRegister
  {
  unsigned short int instruccion;
  unsigned short int fuente;
  unsigned short int destino;
  unsigned short int cuarto;
  } iRegister;

typedef struct celda_memoria
  {
  unsigned short int tipo;
  unsigned short int val;
  iRegister instruccion;
  } celda_m;

typedef struct memoria_principal
  {
  celda_m celda[MEM_SIZE];
  } mem_p;

typedef struct registro_general
  {
  unsigned short int val;
  } reg_g;

typedef struct program_counter
  {
  unsigned short int val;
  } prog_c;

typedef struct bus_datos
  {
  unsigned short int val;
  unsigned short int instruccion;
  unsigned short int fuente;
  unsigned short int destino;
  unsigned short int cuarto;
  } bus_d;

typedef struct flags_alu
  {
  unsigned short int zero;
  unsigned short int sign;
  unsigned short int carry;
  unsigned short int auxiliary;
  unsigned short int parity;
  unsigned short int overflow;
  unsigned short int interrupt;
  unsigned short int direction;
  unsigned short int trap;
  } flags_a;

typedef struct arqui_s
  {
  iRegister IR;
  iRegister MBR;
  reg_g AX;
  reg_g BX;
  reg_g CX;
  reg_g DX;
  bus_d BD;
  reg_g B1;
  reg_g B2;
  reg_g B3;
  reg_g B4;
  reg_g MAR;
  prog_c PC;
  mem_p MEM;
  flags_a FLAGS;
  }
  arqui;

arqui* initArqui()
  {
  arqui *a = malloc(sizeof(arqui));

  iRegister ir;
  ir.instruccion = 0;
  ir.fuente      = 0;
  ir.destino     = 0;
  ir.cuarto      = 0;
  a->IR =ir;

  iRegister mbr;
  mbr.instruccion = 0;
  mbr.fuente      = 0;
  mbr.destino     = 0;
  mbr.cuarto      = 0;
  a->MBR =mbr;

  a->AX.val = 0;
  a->BX.val = 0;
  a->CX.val = 0;
  a->DX.val = 0;

  a->BD.val = 0;
  a->BD.instruccion = 0;
  a->BD.fuente      = 0;
  a->BD.destino     = 0;
  a->BD.cuarto      = 0;

  a->PC.val = 0;
  a->B1.val = 0;
  a->B2.val = 0;
  a->B3.val = 0;
  a->B4.val = 0;
  a->MAR.val = 0;
  a->PC.val = 0;

  mem_p mp;
  int i;
  for(i=0; i<MEM_SIZE; i++)
  {
    mp.celda[i].tipo=VALOR;
    mp.celda[i].val=0;
    mp.celda[i].instruccion.instruccion=0;
    mp.celda[i].instruccion.fuente=0;
    mp.celda[i].instruccion.destino=0;
    mp.celda[i].instruccion.cuarto=0;
  }
  a->MEM = mp;

  flags_a f;
  f.zero=0;
  f.sign=0;
  f.carry=0;
  f.auxiliary=0;
  f.parity=0;
  f.overflow=0;
  f.interrupt=0;
  f.direction=0;
  f.trap=0;
  a->FLAGS = f;
  return a;
  }


void setPC(arqui*a,unsigned short num)
  {
  a->PC.val = num;
  return;
  }
void setMAR(arqui*a,unsigned short num)
  {
  a->MAR.val = num;
  return;
  }

void setIR_fuente (arqui*a,unsigned short num)
  {
  a->IR.fuente = num;
  return;
  }
void setIR_destino (arqui*a,unsigned short num)
  {
  a->IR.destino = num;
  return;
  }
void setIR_instruccion (arqui*a,unsigned short num)
  {
  a->IR.instruccion = num;
  return;
  }
void setIR_cuarto (arqui*a,unsigned short num)
  {
  a->IR.cuarto = num;
  return;
  }


unsigned short getIR_fuente (arqui*a)
  {
  return a->IR.fuente;
  }
unsigned short getIR_destino (arqui*a)
  {
  return a->IR.destino;
  }
unsigned short getIR_instruccion (arqui*a)
  {
  return a->IR.instruccion;
  }
unsigned short getIR_cuarto (arqui*a)
  {
  return a->IR.cuarto;
  }


void setMBR_fuente (arqui*a,unsigned short num)
  {
  a->MBR.fuente = num;
  return;
  }
void setMBR_destino (arqui*a,unsigned short num)
  {
  a->MBR.destino = num;
  return;
  }
void setMBR_instruccion (arqui*a,unsigned short num)
  {
  a->MBR.instruccion = num;
  return;
  }
void setMBR_cuarto (arqui*a,unsigned short num)
  {
  a->MBR.cuarto = num;
  return;
  }


unsigned short getMBR_fuente (arqui*a)
  {
  return a->MBR.fuente;
  }
unsigned short getMBR_destino (arqui*a)
  {
  return a->MBR.destino;
  }
unsigned short getMBR_instruccion (arqui*a)
  {
  return a->MBR.instruccion;
  }
unsigned short getMBR_cuarto (arqui*a)
  {
  return a->MBR.cuarto;
  }

unsigned short getPC(arqui*a)
  {
  return a->PC.val;
  }
unsigned short getMAR(arqui*a)
  {
  return a->MAR.val;
  }


unsigned short getBD_val         (arqui*a)
  {
  return a->BD.val;
  }
unsigned short getBD_fuente      (arqui*a)
  {
  return a->BD.fuente;
  }
unsigned short getBD_destino     (arqui*a)
  {
  return a->BD.destino;
  }
unsigned short getBD_instruccion (arqui*a)
  {
  return a->BD.instruccion;
  }
unsigned short getBD_cuarto      (arqui*a)
  {
  return a->BD.cuarto;
  }
void setBD_val         (arqui*a,unsigned short num)
  {
  a->BD.val = num;
  return;
  }
void setBD_fuente      (arqui*a,unsigned short num)
  {
  a->BD.fuente = num;
  return;
  }
void setBD_destino     (arqui*a,unsigned short num)
  {
  a->BD.destino = num;
  return;
  }
void setBD_instruccion (arqui*a,unsigned short num)
  {
  a->BD.instruccion = num;
  return;
  }
void setBD_cuarto      (arqui*a,unsigned short num)
  {
  a->BD.cuarto = num;
  return;
  }

unsigned short getAX(arqui*a)
  {
  return a->AX.val;
  }

unsigned short getBX(arqui*a)
  {
  return a->BX.val;
  }

unsigned short getCX(arqui*a)
  {
  return a->CX.val;
  }

unsigned short getDX(arqui*a)
  {
  return a->DX.val;
  }


unsigned short getAL(arqui*a)
  {
  unsigned short L = a->AX.val & 0xFF;
  return L;
  }

unsigned short getBL(arqui*a)
  {
  unsigned short L = a->BX.val & 0xFF;
  return L;
  }

unsigned short getCL(arqui*a)
  {
  unsigned short L = a->CX.val & 0xFF;
  return L;
  }

unsigned short getDL(arqui*a)
  {
  unsigned short L = a->DX.val & 0xFF;
  return L;
  }


unsigned short getAH(arqui*a)
  {
  unsigned short L = a->AX.val & 0xFF00;
  return L;
  }

unsigned short getBH(arqui*a)
  {
  unsigned short L = a->BX.val & 0xFF00;
  return L;
  }

unsigned short getCH(arqui*a)
  {
  unsigned short L = a->CX.val & 0xFF00;
  return L;
  }

unsigned short getDH(arqui*a)
  {
  unsigned short L = a->DX.val & 0xFF00;
  return L;
  }


void setAX(arqui*a,unsigned short num)
  {
  a->AX.val=num;
  return;
  }

void setBX(arqui*a,unsigned short num)
  {
  a->BX.val=num;
  return;
  }

void setCX(arqui*a,unsigned short num)
  {
  a->CX.val=num;
  return;
  }

void setDX(arqui*a,unsigned short num)
  {
  a->DX.val=num;
  return;
  }

void setAL(arqui*a,unsigned short num)
  {
  num = num & 0XFF;
  a->AX.val= a->AX.val & 0xFF00;
  a->AX.val=num | a->AX.val;
  return;
  }

void setBL(arqui*a,unsigned short num)
  {
  num = num & 0XFF;
  a->BX.val= a->BX.val & 0xFF00;
  a->BX.val=num | a->BX.val;
  return;
  }

void setCL(arqui*a,unsigned short num)
  {
  num = num & 0XFF;
  a->CX.val= a->CX.val & 0xFF00;
  a->CX.val=num | a->CX.val;
  return;
  }

void setDL(arqui*a,unsigned short num)
  {
  num = num & 0XFF;
  a->DX.val= a->DX.val & 0xFF00;
  a->DX.val=num | a->DX.val;
  return;
  }

void setAH(arqui*a,unsigned short num)
  {
  num = num & 0XFF00;
  a->AX.val= a->AX.val & 0xFF;
  a->AX.val=num | a->AX.val;
  return;
  }

void setBH(arqui*a,unsigned short num)
  {
  num = num & 0XFF00;
  a->BX.val= a->BX.val & 0xFF;
  a->BX.val=num | a->BX.val;
  return;
  }

void setCH(arqui*a,unsigned short num)
  {
  num = num & 0XFF00;
  a->CX.val= a->CX.val & 0xFF;
  a->CX.val=num | a->CX.val;
  return;
  }

void setDH(arqui*a,unsigned short num)
  {
  num = num & 0XFF00;
  a->DX.val= a->DX.val & 0xFF;
  a->DX.val=num | a->DX.val;
  return;
  }

void setB1(arqui*a,unsigned short num)
  {
  a->B1.val=num;
  return;
  }
void setB2(arqui*a,unsigned short num)
  {
  a->B2.val=num;
  return;
  }
void setB3(arqui*a,unsigned short num)
  {
  a->B3.val=num;
  return;
  }
void setB4(arqui*a,unsigned short num)
  {
  a->B4.val=num;
  return;
  }

unsigned short getB1(arqui*a)
  {
  return a->B1.val;
  }
unsigned short getB2(arqui*a)
  {
  return a->B2.val;
  }
unsigned short getB3(arqui*a)
  {
  return a->B3.val;
  }
unsigned short getB4(arqui*a)
  {
  return a->B4.val;
  }


unsigned short getcelda_tipo(arqui*a,unsigned short celda)
  {
  return a->MEM.celda[celda].tipo;
  }
unsigned short getcelda_val(arqui*a,unsigned short celda)
  {
  return a->MEM.celda[celda].val;
  }
unsigned short getcelda_fuente      (arqui*a,unsigned short celda)
  {
  return a->MEM.celda[celda].instruccion.fuente;
  }
unsigned short getcelda_destino     (arqui*a,unsigned short celda)
  {
  return a->MEM.celda[celda].instruccion.destino;
  }
unsigned short getcelda_instruccion (arqui*a,unsigned short celda)
  {
  return a->MEM.celda[celda].instruccion.instruccion;
  }
unsigned short getcelda_cuarto      (arqui*a,unsigned short celda)
  {
  return a->MEM.celda[celda].instruccion.cuarto;
  }

void setcelda_tipo        (arqui*a,unsigned short celda,unsigned short val)
  {
  a->MEM.celda[celda].tipo=val;
  return;
  }
void setcelda_val         (arqui*a,unsigned short celda,unsigned short val)
  {
  a->MEM.celda[celda].val=val;
  return;
  }
void setcelda_fuente      (arqui*a,unsigned short celda,unsigned short val)
  {
  a->MEM.celda[celda].instruccion.fuente =val;
  return;
  }
void setcelda_destino     (arqui*a,unsigned short celda,unsigned short val)
  {
  a->MEM.celda[celda].instruccion.destino =val;
  return;
  }
void setcelda_instruccion (arqui*a,unsigned short celda,unsigned short val)
  {
  a->MEM.celda[celda].instruccion.instruccion =val;
  return;
  }
void setcelda_cuarto      (arqui*a,unsigned short celda,unsigned short val)
  {
  a->MEM.celda[celda].instruccion.cuarto =val;
  return;
  }


unsigned short get_flag(arqui*a,int flag)
  {
  switch(flag)
    {
    case ZERO     :
      return a->FLAGS.zero;
    case SIGN     :
      return a->FLAGS.sign;
    case CARRY    :
      return a->FLAGS.carry;
    case AUXILIARY:
      return a->FLAGS.auxiliary;
    case PARITY   :
      return a->FLAGS.parity;
    case OVERFLOW :
      return a->FLAGS.overflow;
    case INTERRUPT:
      return a->FLAGS.interrupt;
    case DIRECTION:
      return a->FLAGS.direction;
    case TRAP     :
      return a->FLAGS.trap;
    }
    exit(0);
    return 99;
  }
void set_flag_on(arqui*a,int flag)
  {
  switch(flag)
    {
    case ZERO     :
      a->FLAGS.zero=1;
      return;
    case SIGN     :
      a->FLAGS.sign=1;
      return;
    case CARRY    :
      a->FLAGS.carry=1;
      return;
    case AUXILIARY:
      a->FLAGS.auxiliary=1;
      return;
    case PARITY   :
      a->FLAGS.parity=1;
      return;
    case OVERFLOW :
      a->FLAGS.overflow=1;
      return;
    case INTERRUPT:
      a->FLAGS.interrupt=1;
      return;
    case DIRECTION:
      a->FLAGS.direction=1;
      return;
    case TRAP     :
      a->FLAGS.trap=1;
      return;
    }
    exit(0);
    return;
  }
void set_flag_off(arqui*a,int flag)
  {
  switch(flag)
    {
    case ZERO     :
      a->FLAGS.zero=0;
      return;
    case SIGN     :
      a->FLAGS.sign=0;
      return;
    case CARRY    :
      a->FLAGS.carry=0;
      return;
    case AUXILIARY:
      a->FLAGS.auxiliary=0;
      return;
    case PARITY   :
      a->FLAGS.parity=0;
      return;
    case OVERFLOW :
      a->FLAGS.overflow=0;
      return;
    case INTERRUPT:
      a->FLAGS.interrupt=0;
      return;
    case DIRECTION:
      a->FLAGS.direction=0;
      return;
    case TRAP     :
      a->FLAGS.trap=0;
      return;
    }
    exit(0);
    return;
  }
