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
	printf("JOGO DO PAR OU �MPAR \n\n");
	printf("=======================================================================\n\n");
	printf("Modo de jogar: \n\n");
	printf("Escolha par ou �mpar\n");
	printf("Insira um n�mero de 1 a 10 \n");
	printf("O PC tamb�m ir� jogar um n�mero de 1 a 10 \n");
	printf("Por fim ser� definido o vencedor \n\n");
	printf("=======================================================================\n\n");

	printf("Voc� quer par ou �mpar? \n");
	printf("Se voc� quiser par digite 1, se quiser �mpar digite 2: ");
	scanf("%d", &parOuImpar);
	printf("Jogue um n�mero de 1 a 10: ");
	scanf("%d", &numeroPlayer);

	total = numeroPC + numeroPlayer;

	switch(parOuImpar){

		case 1:
			printf("Voc� jogou %d, o PC jogou %d, o total dos dois n�meros � %d \n", numeroPlayer, numeroPC, total);
			if(total % 2 == 0){
				printf("%d � par, voc� ganhou ", total);
			}else{
				printf("%d � �mpar, voc� perdeu ", total);
			}
			break;

		case 2:
			printf("Voc� jogou %d, o PC jogou %d, o total dos dois n�meros � %d \n", numeroPlayer, numeroPC, total);
			if(total % 2 == 0){
				printf("%d � par, voc� perdeu ", total);
			}else{
				printf("%d � �mpar, voc� ganhou ", total);
			}
			break;

		default:
			break;

	}

	getch();
	return 0;

}
