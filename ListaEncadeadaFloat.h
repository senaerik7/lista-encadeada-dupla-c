#ifndef LISTAENCADEADAFLOAT_H_INCLUDED
#define LISTAENCADEADAFLOAT_H_INCLUDED

typedef struct _listafloat ListaFloat;
typedef struct _blocofloat BlocoFloat;

ListaFloat *cria_lista(void);
BlocoFloat *cria_bloco(float val);

void inserir_inicio(ListaFloat *L1, float val);
void inserir_fim(ListaFloat *L1, float val);
void imprimir_lista(const ListaFloat *L1, int op);

#endif
