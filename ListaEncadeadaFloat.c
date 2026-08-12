#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


typedef struct _blocofloat{
    float valor;
    struct _blocofloat *anterior;
    struct _blocofloat *proximo;
}BlocoFloat;

typedef struct _listafloat{
    BlocoFloat *inicio;
    BlocoFloat *fim;
}ListaFloat;

ListaFloat *cria_lista(void){
    ListaFloat *L1 = (ListaFloat*)calloc(1,sizeof(ListaFloat));
    L1->inicio = NULL;
    L1->fim = NULL;
    return L1;
}
