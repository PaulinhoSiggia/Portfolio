// JOGO DA ADIVINHA��O

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
	printf("JOGO DA ADIVINHA��O\n");
	tracos();
	pulalinha();
	printf("Um n�mero aleat�rio entre 0 e 1000 foi gerado pelo computador \n");
	printf("O seu objetivo � acertar esse n�mero \n");
	printf("Voc� pode dar quantos palpites forem necess�rios at� acertar o valor \n");
	printf("\nPara jogar basta digitar um n�mero entre 0 e 1000 e apertar enter \n");
	pulalinha();
	tracos();
	pulalinha();
	printf("Qual voc� acha que � o n�mero aleat�rio? ");
	scanf("%d", &palpite);
	while((palpite <= -1) || (palpite >= 1001)){
		printf("N�mero inv�lido, o jogo � entre 0 e 1000, d� um novo palpite \n");
		printf("Qual voc� acha que � o n�mero aleat�rio? ");
		scanf("%d", &palpite);
	}

	while(palpite != aleatorio){
		if(aleatorio > palpite){
			printf("Voc� errou, o n�mero aleat�rio � maior que esse \n");
		if(palpite <= -1){
			printf("E al�m de estar errado esse n�mero � inv�lido, o jogo � entre 0 e 1001 \n");
		}
		}if(aleatorio < palpite){
			printf("Voc� errou, o n�mero aleat�rio � menor que esse \n");
		}
		if(palpite >= 1001){
			printf("E al�m de estar errado esse n�mero � inv�lido, o jogo � entre 0 e 1001 \n");
		}
		printf("D� um novo palpite: ");
		scanf("%d", &palpite);
	}

	printf("\nParab�ns, voc� acertou \n");
	printf("O n�mero aleat�rio era %d e voc� disse %d \n", aleatorio, palpite);
	pulalinha();

	execucao = 0;

	while((execucao != 1) && (execucao != 2)){
		printf("Voc� deseja jogar novamente? \n");
		printf("1 - Sim \n");
		printf("2 - N�o \n");
		printf("Digite 1 ou 2: ");
		scanf("%d", &execucao);
		if((execucao != 1) && (execucao != 2)){
			printf("\nN�mero inv�lido \n\n");
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
