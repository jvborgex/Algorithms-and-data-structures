#include <stdio.h>
#include <stdlib.h>
#include "codigo-pilha.h"

struct pilha{
    int indTopo;
    elem itens[TamPilha];
};

pilha_t *create(){
    pilha_t *p = (pilha_t *)malloc(sizeof(pilha_t));
    assert(p != NULL);

    p->indTopo = -1;

    return p;
}

void destroy(pilha_t *p){
    if (p != NULL){
        free(p);
    }

    p = NULL;
}

int verifyFull(pilha_t *p){
    assert(p != NULL);

    if(p->indTopo == TamPilha - 1){
        return 1;
    }else{
        return 0;
    }
}

int verifyEmpty(pilha_t *p){
    assert(p != NULL);
    
    if(p->indTopo == -1){
        return 1;
    }else{
        return 0;
    }
}

int push(pilha_t *p, elem x){
    assert(p != NULL);

    if(verifyFull(p) == 1){
        return -1;
    }

    p->indTopo = p->indTopo + 1;
    p->itens[p->indTopo] = x;

    return 1;
}

int pop(pilha_t *p, elem *x){
    assert(p != NULL);

    if(verifyEmpty(p) == 1){
        return -1;
    }

    *x = p->itens[p->indTopo];
    p->indTopo -= 1;
    return 1;
}

int top(pilha_t *p, elem *x){
    assert(p != NULL);

    if(verifyEmpty(p) == 1){
        return -1;
    }

    *x = p->itens[p->indTopo];
    return 1;
}
