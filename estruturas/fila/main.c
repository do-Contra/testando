#include<stdio.h>
#include"fila.h"
int main(){
    struct fila minhaFila;
    minhaFila.rear = -1;
    minhaFila.front = 0;
    minhaFila.virado = 0;

    int valor;
    int c=0;
    while(1){
        c++;
        printf("1 - inserir\n2 - remover\n");
        scanf("%d",&valor);
        if(valor == 1){
            insert(c,&minhaFila);
        }else{
            remover(&minhaFila);
        }
        mostrar(&minhaFila);
    }
    
    return 0;
}