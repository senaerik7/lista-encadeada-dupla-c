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

void inserir_fim(ListaFloat *L1, float val){
    BlocoFloat *novo_bloco = cria_bloco(val);
    if(L1->inicio == NULL){
        L1->inicio = novo_bloco;
    }else{
        BlocoFloat *aux = L1->inicio;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = novo_bloco;
        novo_bloco->anterior = aux;
    }
}

void imprimir_lista(const ListaFloat *L1, int op){
    if(L1->inicio == NULL){
        puts("\nA LISTA ESTÁ VAZIA!");
        return;
    }
    BlocoFloat *aux = L1->inicio;
    BlocoFloat *fim = NULL;
    while(aux->proximo != NULL){
        aux = aux->proximo;
    }
    fim = aux;
    aux = L1->inicio;
    if(op == 1){
        printf("[Início] -> ");
        while(aux != NULL){
            if(aux == L1->inicio && aux->proximo == NULL){
                printf("[NULL|%.1f|NULL].", aux->valor);
            }else if(aux == L1->inicio){
                printf("[NULL|%.1f] -> ", aux->valor);
            }else if(aux->proximo == NULL){
                printf("[%.1f|NULL].", aux->valor);
            }else{
                printf("[|%.1f|] <-> ", aux->valor);
        }
            aux = aux->proximo;
        }
    }else if(op == 2){
        while(fim != NULL){
            if(fim->anterior == NULL){
                printf("[NULL|%.1f]", fim->valor);
            }else{
                printf("[|%.1f|] <-> ", fim->valor);
            }
            fim = fim->anterior;
        }
    }else{
        puts("\nOPÇÃO INVÁLIDA!");
        return;
    }
}
