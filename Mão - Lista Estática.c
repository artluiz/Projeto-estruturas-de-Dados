#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Monte Extra - Pilha.c"

typedef struct sListaEst{
	NO Es[4];
	int n;
}Esp;

void inicializa_lista(Esp *L){
	L->n = -1;
}

int lista_vazia(Esp *L){
	if(L->n==-1){
		return 1;
	}else{
		return 0;
	}
}

int lista_cheia(Esp *L){
	if(L->n+1 == 3){
		return 1;
	}else{
		return 0;
	}
}

//printa a as mãos do jogador 
void imprime_Mao(Esp *E){
	int i = 0;;
	
	if(!lista_vazia(E)){
		for(i=0; i<E->n+1;i++){
			switch (E->Es[i].info.valor){
				case 1:
					printf("| A de %s |", E->Es[i].info.naipe);
					
					break;
				
				case 11:
					printf("| J de %s |", E->Es[i].info.naipe);
					
					break;
				
				case 12:
					printf("| Q de %s |", E->Es[i].info.naipe);
					
					break;
					
				case 13:
					printf("| K de %s |", E->Es[i].info.naipe);
					
					break;
					
				default:
					printf("| %d de %s |", E->Es[i].info.valor, E->Es[i].info.naipe);
					
					break;
			}
				
		}
		printf("\n");
	}else{
		printf("Mao vazia \n");
	}
}

//insere a carta sacada na mão desejada	
int insere_mao(NO *carta, Esp *E){
	int i, v = 0;
	if(!lista_cheia(E)){
		if(lista_vazia(E)){
			E->Es[0]=*carta;
			E->n++;
			return 1;
		}else{
			
			if(E->n == 0){
				if((carta->info.valor == E->Es[0].info.valor+1) || (carta->info.valor == E->Es[0].info.valor-1) || (carta->info.valor == E->Es[0].info.valor)){
					v = 1;
				}else{
					if((E->Es[0].info.valor == 1) && (carta->info.valor == 13)){
						v=1;
					}else{
						if((E->Es[0].info.valor == 13) && (carta->info.valor == 1)){
							v=1;
						}
					}
				}
			}else{
				if(E->Es[0].info.valor == E->Es[1].info.valor){
					if(carta->info.valor == E->Es[0].info.valor){
						v=1;
					}
				}else{
					if((carta->info.valor == E->Es[0].info.valor-1)){
						v=1;
					}else{
						if((carta->info.valor == E->Es[1].info.valor+1)){
							v=1;
						}else{
							if((E->Es[0].info.valor == 1) && (carta->info.valor == 13)){
								v=1;
							}else{
								if((E->Es[1].info.valor == 1) && (carta->info.valor == 13)){
								v=1;
								}else{
									if((E->Es[0].info.valor == 13) && (carta->info.valor == 1)){
										v=1;
									}else{
										if((E->Es[1].info.valor == 13) && (carta->info.valor == 1)){
											v=1;
										}
									}
								}
							}
						}
					}
				}
			}	
		}
	
		if(v==1){
				
			if(carta->info.valor < E->Es[0].info.valor){ 		//veridica se a carta é menor que a da primeira posição
				E->Es[2] = E->Es[1];
				E->Es[1] = E->Es[0];
				E->Es[0] = *carta;
				E->n++;
				
				return 1;
			}else{
				if(carta->info.valor == E->Es[0].info.valor){		//veridica se a carta é igual que a da primeira posição
					E->Es[2] = E->Es[1];
					E->Es[1] = *carta;
					E->n++;
					return 1;
				}else{
					if(carta->info.valor > E->Es[0].info.valor){		//veridica se a carta é maior que a da primeira posição
						if(carta->info.valor < E->Es[1].info.valor){		//veridica se a carta é menor que a da segunda posição
							E->Es[2] = E->Es[1];
							E->Es[1] = *carta;
							E->n++;
							return 1;
						}else{
							E->Es[2] = *carta;
							E->n++;
							return 1;
						}
					}
				}
			}
			
		}else{
			return 0;
		}
			
			
	}else{
		printf("Mao cheia, nao eh possivel adicionar \n");
		return 0;
	}
		
}
