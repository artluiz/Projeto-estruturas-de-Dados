#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"Baralho - Deque.c"

typedef struct sPilhaEspacoExtra{
	NO  *info;
	struct sPilhaEspacoExtra *ante;
}Ex;

void inicia_pilha(Ex **pilha){
	*pilha = NULL;	
}

Ex* aloca_no_pilha(){
	return (Ex*) malloc(sizeof(Ex));
}

int pilha_vazia(Ex *pilha){
	if(pilha==NULL){
		return 1;
	}else{
		return 0;
	}
}

//coloca a carta no monte extra
void adiciona_monte_extra(NO* carta, Ex** pilha){
	Ex *novo;
	novo = aloca_no_pilha();
	
	if(novo != NULL){
		novo->info = carta;
		if(pilha_vazia(*pilha)){
			novo->ante = NULL;
			*pilha = novo;
		}else{
			novo->ante = *pilha;
			*pilha = novo;
		}
		
	}else{
		printf("Erro na alocação do no \n");
	}
}

//retira a carta do topo do monte extra e retorna a mão do usuário
NO* saca_extra(Ex **pilha){
	NO *aux;
	
	if(pilha_vazia(*pilha)){
		return NULL;
	}else{
		aux = (*pilha)->info;
		*pilha = (*pilha)->ante;
		return aux;
	}
}

//desaloca os nós armazenados no deck extra
void desaloca_pilha(Ex **pilha){
	Ex *aux, *f;
	if(pilha_vazia(*pilha)){
		printf(", nao ha nada para exibir \n");
	}else{
		aux = *pilha;
		do{
			
			f=*pilha;
			*pilha = f->ante;
			
			free(f);
			
			aux = *pilha;
		}while(aux != NULL);
	}
}
