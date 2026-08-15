#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "ListaEncadeadaFloat.h"

#define EPSILON 0.0001


int main(){
    setlocale(LC_ALL, "Portuguese");
    ListaFloat *Lista = cria_lista();
    int op, i;
    float passador;

    do{
        printf("TECLE [1] PARA ADICIONAR NO INÍCIO;..................|\n");
        printf("TECLE [2] PARA ADICIONAR NO FIM;.....................|\n");
        printf("TECLE [3] PARA IMPRIMIR A LISTA;.....................|\n");
        printf("TECLE [4] PARA REMOVER O INICIO DA LISTA;............|\n");
        printf("TECLE [5] PARA REMOVER O FINAL DA LISTA;.............|\n");
        printf("TECLE [6] PARA REMOVER AS OCORRÊNCIAS DE UM ELEMENTO;|\n");
        printf("TECLE [7] PARA INVERTER A LISTA;.....................|\n");
        printf("TECLE [8] PARA PARA ORDENAR A LISTA;.................|\n");
        printf("TECLE [9] PARA RECEBER O INDEX DE UM ELEMENTO;.......|\n");
        printf("TECLE [10] PARA RECEBER A MÉDIA DA LISTA;............|\n");
        printf("TECLE [0] PARA SAIR;.................................|\n-> ");
        scanf("%d", &op);
        if(op==1){
            puts("\nADICIONAR NO INÍCIO");
            printf("Digite um número: ");
            scanf("%f", &passador);
            inserir_inicio(Lista, passador);
            puts("ELEMENTO ADICIONADO!\n");
        }else if(op==2){
            puts("\nADICIONAR NO FIM");
            printf("Digite um número: ");
            scanf("%f", &passador);
            inserir_fim(Lista, passador);
            puts("ELEMENTO ADICIONADO!\n");
        }else if(op==3){
            puts("\nIMPRIMIR A LISTA: ");
            printf("Digite [1] para imprimir do inicio ou  [2] para imprimir do final: ");
            scanf("%d", &i);
            printf("\n");
            imprimir_lista(Lista, i);
            puts("FINALIZADO!\n");
        }else if(op==4){
            puts("\nREMOVER O INÍCIO...");
            remover_inicio(Lista);
            puts("FINALIZADO!\n");
        }else if(op==5){
            puts("\nREMOVER O FINAL...");
            remover_fim(Lista);
            puts("FINALIZADO!\n");
        }else if(op==6){
            puts("\nREMOVER TODAS AS OCORRÊNCIAS: ");
            printf("Digite um número: ");
            scanf("%f", &passador);
            remover_ocorrencias(Lista, passador);
            puts("FINALIZADO!\n");
        }else if(op==7){
            puts("\nINVERTER A LISTA...");
            inverter_lista(Lista);
            puts("FINALIZADO!\n");
        }else if(op==8){
            puts("\nORNDENAR A LISTA...");
            ordenar_lista_valores(Lista);
            puts("FINALIZADO!\n");
        }else if(op==9){
            puts("\nBUSCAR INDEX: ");
            printf("Digite um número: ");
            scanf("%f", &passador);
            i = busca_index(Lista, passador);
            if(i != -1){
                printf("\nO NÚMERO ESTÁ NA %d° POSIÇÃO LISTA.\n\n", i+1);
            }else{
                puts("\nO NÚMERO NÃO ESTÁ NA LISTA!\n");
            }
        }else if(op==10){
            puts("\nMÉDIA DA LISTA: ");
            float med;
            char letra = media_val(Lista, &med);
            if(letra == 's'){
                printf("A MÉDIA DOS ELEMENTOS É: %.1f.\n\n", med);
            }else{
                puts("A LISTA ESTÁ VAZIA!\n");
            }
        }else{
            if(op==0){
                puts("\nSAINDO DA LISTA...");
            }else{
                puts("\nOPÇÃO INVÁLIDA! TENTE NOVAMENTE.\n");
            }
        }
    }while(op != 0);

    destrutora(&Lista);
}
