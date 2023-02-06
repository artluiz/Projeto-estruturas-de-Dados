#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Jogador - Fila.c"


int main(){
	int op, ret = 1, monte, i;
	char elem;
	Jog Jo;
	inicializar_fila(&Jo);
	NO *carta, *aux;
	
	printf("Aguarde... Seus montes estao sendo embaralhados \n");
	
	criar_jogador(&Jo,"Jogador 1");
	
	printf("Quase la... \n");
	
	criar_jogador(&Jo,"Jogador 2");
	
	do{
		
		printf("Vez de %s \n", Jo.inicio->info);
		printf("Voce tem %d pontos \n", Jo.inicio->vit);
		
		printf("\n----------------------------------------------------\n");
		
		for(i=0; i<4; i++){
			printf("Espaco: %d ", i+1);
			imprime_Mao(&Jo.inicio->E[i]);
		}
		
		printf("----------------------------------------------------\n");
		
		if(&Jo.inicio->extra == NULL){
			carta = sacar(&Jo.inicio->M);
		}else{
			printf("Deseja sacar de qual monte: \n 1) Principal \n 2) Extra \n");
			scanf("%d", &monte);
			fflush(stdin);
			if(monte == 1){
				carta = sacar(&Jo.inicio->M);
				
			}else{
				carta = saca_extra(&Jo.inicio->extra);
			}
		}
		printf("\n----------------------------------------------------\n");
		if(carta != NULL){
			
			if(carta->info.valor == 1){
				printf("Carta Sacada: | A de %s | \n", carta->info.naipe);
			}else{
				if(carta->info.valor == 11){
					printf("Carta Sacada: | J de %s | \n", carta->info.naipe);
				}else{
					if(carta->info.valor == 12){
						printf("Carta Sacada: | Q de %s | \n", carta->info.naipe);
					}else{
						if(carta->info.valor == 13){
							printf("Carta Sacada: | K de %s | \n", carta->info.naipe);
						}else{
							printf("Carta Sacada: | %d de %s |  \n", carta->info.valor, carta->info.naipe);
						}
					}
				}
			}
		
		
		
			do{
				if(!ret){
					printf("Erro com sua escolha, selecione outra opcao \n");
				}
				printf("\n----------------------------------------------------\n");
				printf("Digite o que deseja fazer com a carta sacada: \n");
				printf("\n 1) Inserir na mao 1");
				printf("\n 2) Inserir na mao 2");
				printf("\n 3) Inserir na mao 3");
				printf("\n 4) Inserir na mao 4");
				printf("\n 5) Inserir no monte extra");
				printf("\n 6) Descartar \n");
				printf("\n----------------------------------------------------\n");
				scanf("%d", &op);
				fflush(stdin);
				
				switch(op){
					case 1:
						ret = insere_mao(carta, &Jo.inicio->E[0]);
						if(ret){
							free(carta);
						}
						
						break;
					case 2:
						ret = insere_mao(carta, &Jo.inicio->E[1]);
						if(ret){
							free(carta);
						}
						
						break;
					case 3:
						ret = insere_mao(carta, &Jo.inicio->E[2]);
						if(ret){
							free(carta);
						}
						
						break;
					case 4:
						ret = insere_mao(carta, &Jo.inicio->E[3]);
						if(ret){
							free(carta);
						}
						
						break;
					case 5:
						ret = 1;
						adiciona_monte_extra(carta, &Jo.inicio->extra);
						
						break;
					case 6:
						ret = 1;
						descarte(&Jo.inicio->M,carta);
						
						break;
						
				}
				
			}while(!ret);		//caso ocorra algum erro com a escolha do usuário acerca da carta
		
		}else{
			printf("Monte extra vazio, nao ha o que sacar \n");
		}
		
		checa_mao(&Jo);
		
		troca_turno(&Jo);
		
	}while((Jo.inicio)->vit != 5);
	
	printf("\n***************************************************\n");
	printf("***************************************************\n");
	printf("***************************************************\n ");
	printf("        Parabens %s ganhou!!!!!!!!!!!! \n", Jo.inicio->info);
	printf("***************************************************\n");
	printf("***************************************************\n");
	printf("***************************************************\n");
	
	printf("Aguarde... Seus montes estao sendo desalocados \n");
	
	desalocar_montep(&Jo.inicio->M);
	desaloca_pilha(&Jo.inicio->extra);
	
	desalocar_montep(&Jo.fim->M);
	desaloca_pilha(&Jo.fim->extra);
	
	desenfileirar(&Jo);
	desenfileirar(&Jo);
	
	printf("Obrigado por jogar :D \n");
	
	return 0;
}

