#ifndef LISTAENCADEADAFLOAT_H_INCLUDED
#define LISTAENCADEADAFLOAT_H_INCLUDED
#include <math.h>
#define EPSILON 0.0001

typedef struct _listafloat ListaFloat;
typedef struct _blocofloat BlocoFloat;

ListaFloat *cria_lista(void);
BlocoFloat *cria_bloco(float val);

void inserir_inicio(ListaFloat *L1, float val);
void inserir_fim(ListaFloat *L1, float val);
void imprimir_lista(const ListaFloat *L1, int op);
void remover_inicio(ListaFloat *L1);
void remover_fim(ListaFloat *L1);
void remover_ocorrencias(ListaFloat *L1, float val);
int busca_index(const ListaFloat *L1, float val);
char media_val(const ListaFloat *L1, float *media);

#endif
