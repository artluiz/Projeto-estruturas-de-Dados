#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Mão - Lista Estática.c"

typedef struct sNoJogador{
	char info[10];
	int vit;		//contador de mãos ganhas
	Deck M;		//monte do jogador
	Esp E[4];		//espaços de mesa do jogador
	Ex *extra;		//pilha extra para cartas de interesse
	struct sNoJogador *prox;
}NOJo;

typedef struct sJoooj{
	NOJo* inicio;
	NOJo* fim;
}Jog;

void inicializar_fila(Jog* fila){
	fila->inicio = NULL;
	fila->fim = NULL;
}

NOJo* aloca_no_1(){
	return (NOJo*) malloc(sizeof(NOJo));
}

int fila_vazia(Jog* fila){
	if(fila->inicio==NULL && fila->fim==NULL){
		return 1;
	}else{
		return 0;
	}
}

//cria um jogador, com seus montes
void criar_jogador(Jog* fila, char var[10]){
	NOJo *novo;
	novo = aloca_no_1();
	
	inicializar_Deck(&novo->M);
	
	inicia_pilha(&novo->extra);
	
	cria_baralho(&novo->M);
	
	inicializa_lista(&novo->E[0]);
	inicializa_lista(&novo->E[1]);
	inicializa_lista(&novo->E[2]);
	inicializa_lista(&novo->E[3]);
	
	&novo->vit;
	
	if(novo!=NULL){
		strcpy(novo->info,var);
		novo->prox = NULL;
		novo->vit = 0;
		if(fila_vazia(fila)){
			fila->inicio= novo;
			fila->fim = novo;
		}else{
			(fila->fim)->prox = novo;
			fila->fim = novo;
		}
	}else{
		printf("Erro na alocação do no \n");
	}
}

//troca os jogadores de posição na troca_turno
void troca_turno2(Jog* fila, NOJo *aux){

	(fila->fim)->prox = aux;
	fila->fim = aux;

}

//chamada na main para trocar o turno
void troca_turno(Jog* fila){
	NOJo *f;
	f = aloca_no_1();
	
	if(f!=NULL){
		
		f=fila->inicio;
		fila->inicio = (fila->inicio)->prox;
		
		f->prox = NULL;
		troca_turno2(fila, f);
		
	}else{
		printf("Erro na alocação do no \n");
	}
}

//verifica se o jogador pontuou
int checa_mao(Jog* jo){
	int i = 0;
	NO *aux;
	for(i=0; i<5; i++){
		if(jo->inicio->E[i].n == 2){
			
			jo->inicio->vit++;
			jo->inicio->E[i].n = -1;
		}
	}
}

//remove o jogador
void desenfileirar(Jog* fila){
	NOJo *f;
	f = aloca_no_1();
	
	if(f!=NULL){
		if(!fila_vazia(fila)){
			if(fila->fim==fila->inicio){
				f=fila->inicio;
				fila->inicio = (fila->inicio)->prox;
				inicializar_fila(fila);
				
				free(f);
			}else{
				f=fila->inicio;
				fila->inicio = (fila->inicio)->prox;
				
				free(f);
			}	
		}
	}else{
		printf("Erro na alocação do no \n");
	}
}




















