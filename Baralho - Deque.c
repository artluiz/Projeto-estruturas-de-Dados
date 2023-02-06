#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct sInfo{
	int valor;
	char naipe[10];
}INFO;

typedef struct sNo{
	INFO info;
	struct sNo *prox;
	struct sNo *ante;
}NO;

typedef struct sDeck{
	NO* base; //inicio
	NO* topo; //fim
}Deck;

void inicializar_Deck(Deck* deque){
	deque->base = NULL;
	deque->topo = NULL;
}

NO* aloca_no(){
	return (NO*) malloc(sizeof(NO));
}

int deque_vazio(Deck* deque){
	if(deque->base==NULL && deque->topo==NULL){
		return 1;
	}else{
		return 0;
	}
}


//adiciona as carats ao monte
void add_monte(Deck *deque, INFO inf){
	NO *novo;
	novo = aloca_no();

	if(novo!=NULL){
		novo->info.valor = inf.valor;
		strcpy(novo->info.naipe , inf.naipe);
		
		novo->prox = NULL;
		novo->ante = NULL;
		
		if(deque_vazio(deque)){
			deque->base= novo;
			deque->topo = novo;
		}else{
			(deque->base)->ante = novo;
			novo->prox = deque->base;
			deque->base = novo;
		}
	}else{
		printf("Erro na alocação do no \n");
	}
}

// funções de criar Monte
void cria_baralho(Deck* M){
	int i, cont = 1;
	INFO carta[53];
	
	for(i=0;i<52;i++){
		if(i>=0 && i<13){
			carta[i].valor=cont;
			strcpy(carta[i].naipe, "Espadas");
			cont ++;
		}else{
			if(i>=13 && i<26){
				if(i==13){
					cont = 1;
				}
				carta[i].valor=cont;
				strcpy(carta[i].naipe, "Copas  ");
				cont ++;
			}else{
				if(i>=26 && i<39){
					if(i==26){
						cont = 1;
					}
					carta[i].valor=cont;
					strcpy(carta[i].naipe, "Paus   ");
					cont ++;
				}else{
					if(i>=39 && i<52){
						if(i==39){
							cont = 1;
						}
						carta[i].valor=cont;
						strcpy(carta[i].naipe, "Ouro   ");
						cont ++;
					}
				}
			}
		}
	}
	
	//embaralhar
	srand(time(NULL));
	
	for (i = 0; i < 52; i++){
        int ale = rand() % 52;

        INFO temp = carta[i];
        carta[i] = carta[ale];
        carta[ale] = temp;
    }
    sleep(2);
    int aux;
    char aux2[10];
    
    for (i = 0; i < 52; i++){
    	
		add_monte(M, carta[i]);
	}
}

//funções de execução do usuário

//saca a carta e coloca a mão do usuário
NO* sacar(Deck *deque){
	NO *f;
	f = aloca_no();
	
	if(f!=NULL){
		if(!deque_vazio(deque)){
			if(deque->topo==deque->base){
				f=deque->topo;
				deque->topo = (deque->topo)->ante;
				deque->base = (deque->base)->prox;
				
				
			}else{
				f=deque->topo;
				deque->topo = (deque->topo)->ante;
				(deque->topo)->prox = f->prox;
				
			}
			
			return f;
		
		}
	}else{
		printf("Erro na alocação do no \n");
		
	}
}

//coloca a carta de volta no monte
void descarte(Deck *deque, NO *carta){
	
	if(deque_vazio(deque)){
			deque->base= carta;
			deque->topo = carta;
		}else{
			(deque->base)->ante = carta;
			carta->prox = deque->base;
			deque->base = carta;
			carta->ante = NULL;
		}
	
	printf("Carta descartada: | %d de %s | \n", deque->base->info.valor, deque->base->info.naipe);	
}

//deesaloca os nós ainda no monte principal
void desalocar_montep(Deck *deque){
	NO *aux, *f;
	
	if(!deque_vazio(deque)){
		
		aux = deque->base;
		
		aux = aux->prox;
		
		
		do{
			aux = aux->prox;
			
			f=deque->base;
			deque->base = (deque->base)->prox;
			(deque->base)->ante = f->ante;
			
			free(f);
			
		}while(deque->base != NULL);
		
		f=deque->base;
		deque->base = (deque->base)->prox;
		deque->topo = (deque->topo)->ante;
		
		free(f);
				
		printf("A fila agora esta vazia \n");
	}
}
















