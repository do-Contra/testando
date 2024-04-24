#include<stdio.h>
#include<stdlib.h>
#define TAMANHO_MAXIMO 3
struct fila{
    int virado;
    int front;
    int rear;
    int data[TAMANHO_MAXIMO];
};
void insert(int valor,struct fila *f){
    if(f->virado==0 && f->rear<TAMANHO_MAXIMO-1){
        f->rear++;
        f->data[f->rear]= valor;
    }else if(f->rear==TAMANHO_MAXIMO-1 && (f->front>0|| f->virado)){
        f->rear = 0;
        f->data[f->rear]= valor;
        f->virado=!f->virado;
    }else if(f->virado==1 && f->rear<TAMANHO_MAXIMO-1 && f->rear<f->front-1){
        f->rear++;
        f->data[f->rear]= valor;
    }else{
        printf("fila esta cheia!\n");
    }
}
void remover(struct fila *f){
    if(f->front<TAMANHO_MAXIMO && ((f->front!=0 && f->front <= f->rear) || f->virado==0)){
        f->data[f->front] = -1;
        f->front++;
        if(f->front==TAMANHO_MAXIMO){
            f->front=0;
            f->virado=!f->virado;
        }
    }else{
        printf("a fila esta vazia!\n");
    }
}
void mostrar(struct fila *f){
    for(int x=0;x<TAMANHO_MAXIMO;x++){
        printf("%d\t",f->data[x]);
    }
    printf("\n");
} 