#include <stdio.h>
#define TAMANHO_MAXIMO 10
#ifndef PILHA_H
#define PILHA_H

struct pilha{
  int topo;
  char memoria[TAMANHO_MAXIMO];
};
int tratarErroPop(struct pilha *mp){
  if(mp->topo>-1)return 1;
  printf("ERROR: impossivel usar pop\n");
  return 0;
}
int tratarErroPush(struct pilha *mp){
  if(mp->topo<TAMANHO_MAXIMO-2)return 1;
  printf("ERROR: impossivel usar push\n");
  return 0;
}
void pop(struct pilha *minhaPilha){
  if(tratarErroPop(minhaPilha)){
    char removido = minhaPilha->memoria[minhaPilha->topo];
    minhaPilha->topo -= 1;
    printf("%c\n",removido);
  }
}
void push(char dado, struct pilha *minhaPilha){
  if(tratarErroPush(minhaPilha)){
    minhaPilha->topo+=1;
    minhaPilha->memoria[minhaPilha->topo] = dado;
  }
}
void isEmpty(struct pilha *mp){
  if(mp->topo == -1) printf("está vazia");
  else printf("não está vazia");
}
#endif