#define NULL_M       0
  /* es igual a un nop
   * osea no hacer nada*/


/* micro instrucciones */

#define MOV_M        1
#define ALU_M        2
#define MEM_M        3
#define TEST_M       4
#define IN_M         5
#define OUT_M        6

/* ASM instrucciones */

#define MOV_A        7
#define OUT_A        8
#define IN_A         9
#define JMP_A        10
#define JZ_A         11
#define CMP_A        12
#define CLI_A        13
#define STI_A        14
#define VAL_A        15
  /* VAL es una instruccion extra
   * indica que la instruccion no
   * se supone que sea una instruccion
   * y es solamente un valor*/

/* flags */

#define ZERO         16
#define SIGN         17
#define CARRY        18
#define INTERRUPT    19
/* las flags siguientes no se usan */
#define PARITY       20
#define OVERFLOW     21
#define AUXILIARY    22
#define DIRECTION    23
#define TRAP         24

/* operaciones alu */

#define ADD          25
#define SUB          26
#define MUL          27
#define DIV          28
#define AND          29
#define OR           30
#define XOR          31
#define NOT          32
#define SHL          33
#define SHR          34

/* operaciones mem */

#define READ         35
#define WRITE        36

/* celdas memoria */

#define INSTR        37
#define VALOR        38

/* registros */


#define R_AX          39
#define R_BX          40
#define R_CX          41
#define R_DX          42

#define R_AL          43
#define R_BL          44
#define R_CL          45
#define R_DL          46

#define R_AH          47
#define R_BH          48
#define R_CH          49
#define R_DH          50

/* modo de direccionamiento */
/* se utiliza en el cuarto dato de
 * una instruccion para saber el
 * modo de direccionamiento*/

#define D_INMEDIATO   51
#define D_REGISTRO    52
#define D_DIRECTO     53
#define D_INDEXADO    54

/* last macro, used for interesting purposes */
#define LAST          55
