typedef struct arqui_s arqui;
arqui *arquitectura;

void hacer_ciclofetch(arqui* a);

void busqueda (arqui* a);
void decodificar (arqui* a);
void indirecto (arqui* a);
void ejecucion (arqui* a);
void interrupciones (arqui* a);
void siguiente_paso_ciclofetch(arqui* a);

