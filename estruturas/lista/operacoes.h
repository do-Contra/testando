#include<stdio.h>
#ifndef OPERACOES_H
#define OPERACOES_H
#define NUMNODE 50

struct lista{
    int l;
};
struct lista lista;

struct node{
    int next;
    int info;
};
struct node node[NUMNODE];
int avail = 0;
int get_node(){
    int node_livre=NULL;
    if(avail!=-1){
        node_livre = avail;
        avail = node[avail].next;
    }
    return node_livre;
}
void free_node(int node_usado){
    node[node_usado].next = avail;
    avail = node_usado;
}
int quantidade_nodes(int endereco_node){
    int total=0;
    int marcador = endereco_node;
    if(endereco_node != -1){
        total++;
        while(node[marcador].next != -1){
            total++;
            marcador = node[marcador].next;
        }
    }
    return total;
}
/*
//não usei essa função, e de todo jeito, consegue ser pior do que o resto
// do codigo, ela deveria receber o endereço da lista, mas é isso ai,
// deu não pra fazer, muita coisa
void inserir_node(int valor){
    int endereco_node = get_node();
    node[endereco_node].next = lista.l;
    node[endereco_node].info = valor;
    lista.l = endereco_node;
}
*/
int retornar_endereco_node(int endereco_node, int posicao){
    int retorno_endereco = endereco_node; 
    for(int i=1;i<posicao;i++){
        retorno_endereco = node[retorno_endereco].next;
    }
    return retorno_endereco;
}
#endif