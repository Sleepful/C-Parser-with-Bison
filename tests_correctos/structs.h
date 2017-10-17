typedef struct arqui_s arqui;
arqui* initArqui();

void setPC (arqui*a,unsigned short num);
void setMAR(arqui*a,unsigned short num);

void setIR_fuente (arqui*a,unsigned short num);
void setIR_destino (arqui*a,unsigned short num);
void setIR_instruccion (arqui*a,unsigned short num);
void setIR_cuarto (arqui*a,unsigned short num);

unsigned short getIR_fuente      (arqui*a);
unsigned short getIR_destino     (arqui*a);
unsigned short getIR_instruccion (arqui*a);
unsigned short getIR_cuarto      (arqui*a);

void setMBR_fuente (arqui*a,unsigned short num);
void setMBR_destino (arqui*a,unsigned short num);
void setMBR_instruccion (arqui*a,unsigned short num);
void setMBR_cuarto (arqui*a,unsigned short num);

unsigned short getMBR_fuente      (arqui*a);
unsigned short getMBR_destino     (arqui*a);
unsigned short getMBR_instruccion (arqui*a);
unsigned short getMBR_cuarto      (arqui*a);

unsigned short getPC (arqui*a);
unsigned short getMAR(arqui*a);

unsigned short getBD_val         (arqui*a);
unsigned short getBD_fuente      (arqui*a);
unsigned short getBD_destino     (arqui*a);
unsigned short getBD_instruccion (arqui*a);
unsigned short getBD_cuarto      (arqui*a);
void setBD_val         (arqui*a,unsigned short num);
void setBD_fuente      (arqui*a,unsigned short num);
void setBD_destino     (arqui*a,unsigned short num);
void setBD_instruccion (arqui*a,unsigned short num);
void setBD_cuarto      (arqui*a,unsigned short num);

unsigned short getAX(arqui*a);
unsigned short getBX(arqui*a);
unsigned short getCX(arqui*a);
unsigned short getDX(arqui*a);
unsigned short getAL(arqui*a);
unsigned short getBL(arqui*a);
unsigned short getCL(arqui*a);
unsigned short getDL(arqui*a);
unsigned short getAH(arqui*a);
unsigned short getBH(arqui*a);
unsigned short getCH(arqui*a);
unsigned short getDH(arqui*a);

void setAX(arqui*a,unsigned short num);
void setBX(arqui*a,unsigned short num);
void setCX(arqui*a,unsigned short num);
void setDX(arqui*a,unsigned short num);
void setAL(arqui*a,unsigned short num);
void setBL(arqui*a,unsigned short num);
void setCL(arqui*a,unsigned short num);
void setDL(arqui*a,unsigned short num);
void setAH(arqui*a,unsigned short num);
void setBH(arqui*a,unsigned short num);
void setCH(arqui*a,unsigned short num);
void setDH(arqui*a,unsigned short num);

void setB1(arqui*a,unsigned short num);
void setB2(arqui*a,unsigned short num);
void setB3(arqui*a,unsigned short num);
void setB4(arqui*a,unsigned short num);

unsigned short getB1(arqui*a);
unsigned short getB2(arqui*a);
unsigned short getB3(arqui*a);
unsigned short getB4(arqui*a);

/* una celda de memoria puede
 * tener una instruccion o un
 * valor, asi que esto le dice
 * que tiene. Usa macros de
 * microinstrucciones.h para los
 * valores
 * */
unsigned short getcelda_tipo(arqui*a,unsigned short celda);
unsigned short getcelda_val(arqui*a,unsigned short celda);
unsigned short getcelda_fuente      (arqui*a,unsigned short celda);
unsigned short getcelda_destino     (arqui*a,unsigned short celda);
unsigned short getcelda_instruccion (arqui*a,unsigned short celda);
unsigned short getcelda_cuarto      (arqui*a,unsigned short celda);

void setcelda_tipo        (arqui*a,unsigned short celda,unsigned short val);
void setcelda_val         (arqui*a,unsigned short celda,unsigned short val);
void setcelda_fuente      (arqui*a,unsigned short celda,unsigned short val);
void setcelda_destino     (arqui*a,unsigned short celda,unsigned short val);
void setcelda_instruccion (arqui*a,unsigned short celda,unsigned short val);
void setcelda_cuarto      (arqui*a,unsigned short celda,unsigned short val);

unsigned short get_flag(arqui*a,int flag);
void set_flag_on(arqui*a,int flag);
void set_flag_off(arqui*a,int flag);

