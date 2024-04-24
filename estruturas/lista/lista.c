#include<stdio.h>
#include "operacoes.h"

struct node desalocar_node(int enessimo_elemento){
    int endereco_e_elemento = lista.l;
    int endereco_anterior_elemento;
    int endereco_retorno=NULL;
    if(quantidade_nodes(lista.l)>0){
        if(enessimo_elemento==1){//caso seja o primeiro
            free_node(lista.l);
            lista.l = node[lista.l].next;
            endereco_retorno = lista.l;
        }else if(enessimo_elemento<quantidade_nodes(lista.l)){//caso esteja entre outros
            for(int i=1;i<enessimo_elemento;i++){      
                if(i==enessimo_elemento-1){
                    endereco_anterior_elemento = enessimo_elemento;
                }
                endereco_e_elemento = node[endereco_e_elemento].next;
            }
            node[endereco_anterior_elemento].next = node[endereco_e_elemento].next;
            free_node(endereco_e_elemento);
            endereco_retorno = endereco_e_elemento;
        }else{//caso seja o ultimo
            for(int i=1;i<enessimo_elemento-1;i++){      
                endereco_e_elemento = node[endereco_e_elemento].next;
            }
            free_node(node[endereco_e_elemento].next);
            endereco_retorno = node[endereco_e_elemento].next;
            node[endereco_e_elemento].next = -1;
        }
    }
    return node[endereco_retorno];
}

void inserir_node_depois(int valor, int enessimo_elemento){
    if(enessimo_elemento<=quantidade_nodes(lista.l)){
        int endereco_node_livre = get_node(lista.l);
        int endereco_e_elemento = lista.l;
        for(int i=1;i<enessimo_elemento;i++){      
            endereco_e_elemento = node[endereco_e_elemento].next;
        }
        node[endereco_node_livre].next = node[endereco_e_elemento].next;
        node[endereco_node_livre].info = valor;
        node[endereco_e_elemento].next = endereco_node_livre;
    }
}
//sei que os metodos deveriam receber a lista e o que ele fosse usar,tipo a heap, e não ficar usando variavel global pre definida, mas é o que o tempo e o conhecimento permite fazer, então vai ter só o suficiente de codigo.
struct lista lista1;
struct lista lista2;
struct lista lista3;
void uniao_listas(){//lista3 = (lista1) U (lista2)
    int endereco_node_livre;
    int marcador;
    if(quantidade_nodes(lista.l)>0){
        endereco_node_livre = get_node();
        lista3.l = endereco_node_livre;
        node[endereco_node_livre].info = node[lista1.l].info;
        marcador = lista3.l;
    }
    for(int i=1;i<quantidade_nodes(lista.l);i++){
        endereco_node_livre = get_node();
        node[marcador].next = endereco_node_livre;
        marcador = endereco_node_livre;
        node[endereco_node_livre].info = node[retornar_endereco_node(lista1.l,i+1)].info;
    }//até aqui, ele copia todos os elementos da lista 1,
    //ai ele vai fazer uma simetria com a lista 2 e pegar os elementos que não se 
    //repetem e colocar na lista 3
    int comparador;
    int endereco_lista1 = lista1.l;
    int endereco_lista2 = lista2.l;
    for(int i=0;i<quantidade_nodes(lista2.l);i++){
        comparador=0;
        for(int p=0;p<quantidade_nodes(lista1.l);p++){
            if(node[endereco_lista2].info == node[endereco_lista1].info){
                comparador=1;
            }
            endereco_lista1 = node[endereco_lista1].next;
        }
        if(comparador==0){
            endereco_node_livre = get_node();
            node[marcador].next = endereco_node_livre;
            marcador = endereco_node_livre;
            node[endereco_node_livre].info = node[retornar_endereco_node(lista2.l,i+1)].info;
        }
    }
}
void interseccao_listas(){
    int endereco_lista1 = lista1.l;
    int endereco_lista2 = lista2.l;
    int comparador;
    int endereco_node_livre;
    int marcador;
    for(int i=0;i<quantidade_nodes(lista2.l);i++){
        comparador=0;
        for(int p=0;p<quantidade_nodes(lista1.l);p++){
            if(node[endereco_lista2].info == node[endereco_lista1].info){
                comparador=1;
            }
            endereco_lista1 = node[endereco_lista1].next;
        }
        if(comparador == 1 && lista3.l == -1){
            endereco_node_livre = get_node();
            lista3.l = endereco_node_livre;
            node[endereco_node_livre].info = node[lista1.l].info;
            marcador = lista3.l;
        }else if(comparador == 1){
            endereco_node_livre = get_node();
            node[marcador].next = endereco_node_livre;
            marcador = endereco_node_livre;
            node[endereco_node_livre].info = node[retornar_endereco_node(lista2.l,i+1)].info;
        }
    }
}
int main(){//está horrivel, eu sei, mas foi o que deu
    for(int i=0;i<NUMNODE-1;i++){
        node[i].next = i+1;
    }
    node[NUMNODE-1].next = -1;
    lista.l = -1;
    lista1.l = -1;
    lista2.l = -1;
    lista3.l = -1;
    return 0;
}