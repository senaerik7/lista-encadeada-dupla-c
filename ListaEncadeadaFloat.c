#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "ListaEncadeadaFloat.h"


typedef struct _blocofloat{
    float valor;
    struct _blocofloat *anterior;
    struct _blocofloat *proximo;
}BlocoFloat;

typedef struct _listafloat{
    BlocoFloat *inicio;
}ListaFloat;

ListaFloat *cria_lista(void){
    ListaFloat *L1 = (ListaFloat*)calloc(1, sizeof(ListaFloat));
    L1->inicio = NULL;
    return L1;
}

BlocoFloat *cria_bloco(float val){
    BlocoFloat *novo_bloco = (BlocoFloat*)calloc(1, sizeof(BlocoFloat));
    novo_bloco->anterior = NULL;
    novo_bloco->proximo = NULL;
    novo_bloco->valor = val;
    return novo_bloco;
}

void inserir_inicio(ListaFloat *L1, float val){
    BlocoFloat *novo_bloco = cria_bloco(val);
    if(L1->inicio == NULL){
        L1->inicio = novo_bloco;
    }else{
        novo_bloco->proximo = L1->inicio;
        L1->inicio->anterior = novo_bloco;
        L1->inicio = novo_bloco;
    }
}


