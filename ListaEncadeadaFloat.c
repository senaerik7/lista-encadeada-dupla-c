#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include "ListaEncadeadaFloat.h"

#define EPSILON 0.0001

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

void remover_inicio(ListaFloat *L1){
    if(L1->inicio == NULL){
        puts("\nA LISTA ESTÁ VAZIA!");
        return;
    }
    if(L1->inicio->proximo == NULL){
        free(L1->inicio);
        L1->inicio = NULL;
    }else{
        BlocoFloat *aux = L1->inicio;
        L1->inicio = L1->inicio->proximo;
        L1->inicio->anterior = NULL;
        free(aux);
    }
}

void remover_fim(ListaFloat *L1){
    if(L1->inicio == NULL){
        puts("\nA LISTA ESTÁ VAZIA!");
        return;
    }
    if(L1->inicio->proximo == NULL){
        free(L1->inicio);
        L1->inicio = NULL;
    }else{
        BlocoFloat *aux = L1->inicio;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->anterior->proximo = NULL;
        free(aux);
    }
}


void ordenar_lista_valores(ListaFloat *L1){
    if(L1->inicio == NULL || L1->inicio->proximo == NULL){
        puts("\nA LISTA JÁ ESTÁ ORDENADA!");
        return;
    }
    BlocoFloat *atual = L1->inicio;
    float aux = 0.0;
    int trocou  = 0;
    do{
        atual = L1->inicio;
        trocou = 0;
        while(atual->proximo != NULL){
            if(atual->valor>atual->proximo->valor){
                trocou = 1;
                aux = atual->proximo->valor;
                atual->proximo->valor = atual->valor;
                atual->valor = aux;
            }
            atual = atual->proximo;
        }
    }while(trocou != 0);
}

void remover_ocorrencias(ListaFloat *L1, float val){
    if(L1->inicio == NULL){
       puts("\nA LISTA ESTÁ VAZIA!");
       return;
    }
    BlocoFloat *atual = L1->inicio;
    BlocoFloat *aux = NULL;

    while(atual != NULL){
        if(fabs(atual->valor - val) < EPSILON){
            aux = atual;
            atual = atual->proximo;
            if(L1->inicio == aux){
                L1->inicio = aux->proximo;
                if(L1->inicio != NULL){
                    L1->inicio->anterior = NULL;
                }
            }else{
                aux->anterior->proximo = aux->proximo;
                if(aux->proximo != NULL){
                    aux->proximo->anterior = aux->anterior;
                }
            }
            free(aux);
        }else{
            atual = atual->proximo;
        }
    }
}

int inverter_lista(ListaFloat *L1){
    if(L1->inicio == NULL){
        return 0;
    }
    BlocoFloat *atual = L1->inicio;
    BlocoFloat *aux = NULL;
    while(atual != NULL){
        aux = atual->anterior;
        atual->anterior = atual->proximo;
        atual->proximo = aux;
        atual = atual->anterior;
    }
    if(aux != NULL){
        L1->inicio = aux->anterior;
    }
    return 1;
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

int busca_index(const ListaFloat *L1, float val){
    if(L1->inicio == NULL){
        return -1;
    }
    BlocoFloat *aux = L1->inicio;
    int contador = 0;
    while(aux != NULL){
        if(fabs(aux->valor - val) < EPSILON){
            return contador;
        }
        contador++;
        aux = aux->proximo;
    }
    return -1;
}

char media_val(const ListaFloat *L1, float *media){
    if(L1->inicio == NULL){
        return 'n';
    }
    BlocoFloat *aux = L1->inicio;
    float soma = 0.0;
    int contador = 0;
    while(aux != NULL){
        soma = soma + aux->valor;
        contador++;
        aux = aux->proximo;
    }
    *media = soma/contador;
    return 's';
}
