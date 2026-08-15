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

void ordenar_lista(ListaFloat *L1){
    if(L1->inicio == NULL || L1->inicio->proximo == NULL){
        puts("\nA LISTA JÁ ESTÁ ORNDENADA");
        return;
    }
    BlocoFloat *atual = L1->inicio;
    BlocoFloat *aux1 = NULL;
    BlocoFloat *aux2 = NULL;
    BlocoFloat *aux3 = NULL;
    int trocou = 0;
    do{
        atual = L1->inicio;
        trocou = 0;
        while(atual->proximo != NULL){
            if(atual->valor>atual->proximo->valor){
                trocou = 1;
                aux1 = atual->proximo;
                aux2 = aux1->proximo;
                aux1->anterior = atual->anterior;
                aux1->proximo = atual;
                aux3 = atual->anterior;
                atual->anterior = aux1;
                atual->proximo = aux2;
                if(aux3 != NULL){
                    aux3->proximo = aux1;
                }else{
                    L1->inicio = aux1;
                }
                if(aux2 != NULL){
                    aux2->anterior = atual;
                }
            }
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
            if(L1->inicio == atual){
                L1->inicio = atual->proximo;
                if(L1->inicio != NULL){
                    L1->inicio->anterior = NULL;
                }
            }else{
                atual->anterior->proximo = atual->proximo;
                if(atual->proximo != NULL){
                    atual->proximo->anterior = atual->anterior;
                }
            }
            atual = atual->proximo;
            free(aux);
            aux = NULL;
        }else{
            atual = atual->proximo;
        }
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
