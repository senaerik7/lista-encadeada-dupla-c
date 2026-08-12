#ifndef LISTAENCADEADAFLOAT_H_INCLUDED
#define LISTAENCADEADAFLOAT_H_INCLUDED

typedef struct _listafloat ListaFloat;
typedef struct _blocofloat BlocoFloat;

ListaFloat *cria_lista(void);
BlocoFloat *cria_bloco(float val);

void inserir_inicio(ListaFloat *L1, float val);

#endif
