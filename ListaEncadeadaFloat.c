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
