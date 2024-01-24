// JOGO DA ADIVINHAÇÃO

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <conio.h>

void tracos(){
	printf("=======================================================================\n");
}

void pulalinha(){
	printf("\n");
}

int main(){

	setlocale(LC_ALL,"");
	int aleatorio, palpite, execucao;

execucao = 0;
while(execucao != 2){

	srand((unsigned)time(NULL));
	aleatorio = rand () % 1001;

	tracos();
	printf("JOGO DA ADIVINHAÇÃO\n");
	tracos();
	pulalinha();
	printf("Um número aleatório entre 0 e 1000 foi gerado pelo computador \n");
	printf("O seu objetivo é acertar esse número \n");
	printf("Você pode dar quantos palpites forem necessários até acertar o valor \n");
	printf("\nPara jogar basta digitar um número entre 0 e 1000 e apertar enter \n");
	pulalinha();
	tracos();
	pulalinha();
	printf("Qual você acha que é o número aleatório? ");
	scanf("%d", &palpite);
	while((palpite <= -1) || (palpite >= 1001)){
		printf("Número inválido, o jogo é entre 0 e 1000, dê um novo palpite \n");
		printf("Qual você acha que é o número aleatório? ");
		scanf("%d", &palpite);
	}

	while(palpite != aleatorio){
		if(aleatorio > palpite){
			printf("Você errou, o número aleatório é maior que esse \n");
		if(palpite <= -1){
			printf("E além de estar errado esse número é inválido, o jogo é entre 0 e 1001 \n");
		}
		}if(aleatorio < palpite){
			printf("Você errou, o número aleatório é menor que esse \n");
		}
		if(palpite >= 1001){
			printf("E além de estar errado esse número é inválido, o jogo é entre 0 e 1001 \n");
		}
		printf("Dê um novo palpite: ");
		scanf("%d", &palpite);
	}

	printf("\nParabéns, você acertou \n");
	printf("O número aleatório era %d e você disse %d \n", aleatorio, palpite);
	pulalinha();

	execucao = 0;

	while((execucao != 1) && (execucao != 2)){
		printf("Você deseja jogar novamente? \n");
		printf("1 - Sim \n");
		printf("2 - Não \n");
		printf("Digite 1 ou 2: ");
		scanf("%d", &execucao);
		if((execucao != 1) && (execucao != 2)){
			printf("\nNúmero inválido \n\n");
		}if(execucao == 1){
			system("CLS");
		}
	}

	if(execucao == 2){
		printf("\nTecle Enter para sair \n");
	}

}

	getch();
	return 0;

}
