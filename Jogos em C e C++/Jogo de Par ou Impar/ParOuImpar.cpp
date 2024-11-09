#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <conio.h>

int main(){

	setlocale(LC_ALL,"Portuguese");
	srand((unsigned)time(NULL));
	int numeroPC, numeroPlayer, parOuImpar, total;
	numeroPC = ((rand () % 10) + 1);

	printf("=======================================================================\n\n");
	printf("JOGO DO PAR OU ÍMPAR \n\n");
	printf("=======================================================================\n\n");
	printf("Modo de jogar: \n\n");
	printf("Escolha par ou ímpar\n");
	printf("Insira um número de 1 a 10 \n");
	printf("O PC também irá jogar um número de 1 a 10 \n");
	printf("Por fim será definido o vencedor \n\n");
	printf("=======================================================================\n\n");

	printf("Você quer par ou ímpar? \n");
	printf("Se você quiser par digite 1, se quiser ímpar digite 2: ");
	scanf("%d", &parOuImpar);
	printf("Jogue um número de 1 a 10: ");
	scanf("%d", &numeroPlayer);

	total = numeroPC + numeroPlayer;

	switch(parOuImpar){

		case 1:
			printf("Você jogou %d, o PC jogou %d, o total dos dois números é %d \n", numeroPlayer, numeroPC, total);
			if(total % 2 == 0){
				printf("%d é par, você ganhou ", total);
			}else{
				printf("%d é ímpar, você perdeu ", total);
			}
			break;

		case 2:
			printf("Você jogou %d, o PC jogou %d, o total dos dois números é %d \n", numeroPlayer, numeroPC, total);
			if(total % 2 == 0){
				printf("%d é par, você perdeu ", total);
			}else{
				printf("%d é ímpar, você ganhou ", total);
			}
			break;

		default:
			break;

	}

	getch();
	return 0;

}
