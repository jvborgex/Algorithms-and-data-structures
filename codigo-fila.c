#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "codigo-fila.h"

struct fila{
    int inicio, fim, total;
    int itens[TAM];
};

fila_t *create(){
    fila_t *f = (fila_t *)malloc(sizeof(fila_t));
    assert(f != NULL);
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
    return f;
}

int isEmpty(fila_t *f){
    assert(f != NULL);
    if (f->total == 0){
        return 1;
    }
    return 0;
}

int isFull(fila_t *f){
    assert(f != NULL);
    if (f->total == TAM){
        return 1;
    }
    return 0;
}

int insert(fila_t *f, elem x){
    assert(f != NULL);
    if (isFull(f) == 1){
        return 0;
    }
    f->itens[f->fim] = x;
    f->fim = (f->fim + 1) % TAM;
    f->total++;

    return 1;
}

int removeElem(fila_t *f, elem *x){
    assert(f != NULL);
    if (isEmpty(f) == 1){
        return 0;
    }
    *x = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % TAM;
    f->total--;
    return 1;
}

void destroy(fila_t *f){
    assert(f != NULL);
    free(f);
}

int main(){
    //criar uma fila
    fila_t *f = create();
    elem x;
    int i;

    //inserir elementos
    for (i = 0; i < TAM; i++){
        insert(f, i);
    }

    //imprimir a fila
    printf("Fila: ");
    while (isEmpty(f) == 0){
        removeElem(f, &x);
        printf("%d ", x);
    }
    printf("\n");
    
    destroy(f);
    return 0;
}
