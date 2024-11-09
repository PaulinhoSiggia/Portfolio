#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string>
#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;
#define letra_branca "\033[97m"
#define letra_amarela "\033[33m"
#define letra_vermelha "\033[31m"
#define letra_verde "\033[32m"

void desenhaTracos(){
	printf("=======================================================================\n");
}

void pulaLinha(){
	printf("\n");
}

void cabecalho(){
	desenhaTracos();
	pulaLinha();
	printf(letra_amarela);
	printf("JOGO DA FORCA");
	pulaLinha();
	printf(letra_branca);
	pulaLinha();
	desenhaTracos();
	pulaLinha();
}

string retornaPalavraAleatoria(){

	srand((unsigned)time(NULL));
	int dica = rand() % 5;
	int palavraAleatoria;
	string palavraDaForca;

	string frutas[30] = {"ABACATE", "ABACAXI", "A�AI", "ACEROLA", "AMORA", "BANANA", "CAJA", "CARAMBOLA", "CEREJA", "COCO", "FIGO", "FRAMBOESA", "GOIABA", "JABUTICABA", "JACA", "KIWI", "LARANJA", "LIMAO", "MA�A", "MAMAO", "MANGA", "MARACUJA", "MELANCIA", "MELAO", "MORANGO", "PERA", "PESSEGO", "PITAYA", "TANGERINA", "UVA"};
	string objetos[29] = {"CELULAR", "SAPATO", "CHINELO", "TENIS", "COPO", "PRATO", "GARFO", "COLHER", "GARRAFA", "CANETA", "LAPIS", "BORRACHA", "APONTADOR", "LIVRO", "ALICATE", "ANEL", "BALDE", "BOLA", "AGULHA", "CHAVE", "CADERNO", "CANECA", "DADO", "ESTOJO", "FRIGIDEIRA", "LAMPADA", "LANTERNA", "TELEFONE", "VELA"};
	string legumes[20] = {"ABOBORA", "ABOBRINHA", "AIPIM", "BATATA", "BERINJELA", "BETERRABA", "CEBOLA", "CHUCHU", "ERVILHA", "INHAME", "JILO", "MANDIOCA", "MANDIOQUINHA", "MILHO", "NABO", "PALMITO", "PEPINO", "QUIABO", "RABANETE", "VAGEM"};
	string paises[58] = {"ANGOLA", "CAMAROES", "EGITO", "GANA", "MARROCOS", "NIGERIA", "SENEGAL", "TUNISIA", "CANADA", "CUBA", "HONDURAS", "JAMAICA", "MEXICO", "EUA", "NICARAGUA", "PANAMA", "ARGENTINA", "BOLIVIA", "BRASIL", "CHILE", "COLOMBIA", "EQUADOR", "PARAGUAI", "PERU", "URUGUAI", "VENEZUELA", "CHINA", "INDIA", "ISRAEL", "JAPAO", "COREIA", "VIETNAM", "AUSTRIA", "BELGICA", "BULGARIA", "CROACIA", "DINAMARCA", "FRAN�A", "ALEMANHA", "FINLANDIA", "GRECIA", "HUNGRIA", "ITALIA", "HOLANDA", "NORUEGA", "POLONIA", "PORTUGAL", "RUSSIA", "ESPANHA", "SUECIA", "SUI�A", "TURQUIA", "UCRANIA", "INGLATERRA", "ESCOCIA", "IRLANDA", "GALES", "AUSTRALIA"};
	string animais[38] = {"ABELHA", "ARANHA", "BALEIA", "BOI", "BORBOLETA", "CACHORRO", "CANGURU", "CAVALO", "COBRA", "COELHO", "CORUJA", "DINOSSAURO", "ELEFANTE", "GAIVOTA", "GALINHA", "GALO", "GIRAFA", "LEAO", "LAGARTO", "LOBO", "LULA", "MACACO", "MICO", "MORCEGO", "CAPIVARA", "OVELHA", "PANDA", "POLVO", "PORCO", "RAPOSA", "RATO", "SAPO", "TAMANDUA", "TIGRE", "TUBARAO", "URSO", "URUBU", "VACA"};

	if(dica == 0){ 
		srand((unsigned)time(NULL));
		palavraAleatoria = rand() % 30;
		palavraDaForca = frutas[palavraAleatoria];
		printf("Dica: Fruta \n");
	}else if(dica == 1){
		srand((unsigned)time(NULL));
		palavraAleatoria = rand() % 29;
		palavraDaForca = objetos[palavraAleatoria];
		printf("Dica: Objeto \n");
	}else if(dica == 2){
		srand((unsigned)time(NULL));
		palavraAleatoria = rand() % 20;
		palavraDaForca = legumes[palavraAleatoria];
		printf("Dica: Legume \n");
	}else if(dica == 3){
		srand((unsigned)time(NULL));
		palavraAleatoria = rand() % 58;
		palavraDaForca = paises[palavraAleatoria];
		printf("Dica: Pa�s \n");
	}else if(dica == 4){
		srand((unsigned)time(NULL));
		palavraAleatoria = rand() % 38;
		palavraDaForca = animais[palavraAleatoria];
		printf("Dica: Animal \n");
	}

	return palavraDaForca;

}

string retornaPalavraComMascara(string palavraDaForca, int tamanhoDaPalavra){
	int cont = 0;
	string palavraComMascara;

	while(cont < tamanhoDaPalavra){
		palavraComMascara += "_";
		cont++;
	}

	return palavraComMascara;
}

void menuInicial();

void jogar(){

	string palavraJogar = retornaPalavraAleatoria();
	int tamanhoDaPalavra = palavraJogar.size();
	cout << "Tamanho da palavra: " << tamanhoDaPalavra << " letras \n";
	cout << "Voc� tem 10 tentativas \n";
	pulaLinha();
	cout << "Para jogar basta apertar uma letra e teclar Enter \n";
	cout << "Se quiser chutar a palavra inteira aperte 1 e tecle Enter \n";
	pulaLinha();
	string palavraComMascara = retornaPalavraComMascara(palavraJogar, tamanhoDaPalavra);

	int tentativas = 0, maximoDeTentativas = 10;
	int cont = 0;
	char letra;
	string letrasArriscadas;
	
	while((maximoDeTentativas - tentativas > 0) && (palavraComMascara != palavraJogar) && (letra != '1')){

		cout << palavraComMascara << "\n";
		pulaLinha();
		cout << "Digite uma letra ou o n�mero 1 e aperte Enter: ";
		cin >> letra;
		
		if(letra == 'q'){
			letra = 'Q';
		}else if(letra == 'w'){
			letra = 'W';
		}else if(letra == 'e'){
			letra = 'E';
		}else if(letra == 'r'){
			letra = 'R';
		}else if(letra == 't'){
			letra = 'T';
		}else if(letra == 'y'){
			letra = 'Y';
		}else if(letra == 'u'){
			letra = 'U';
		}else if(letra == 'i'){
			letra = 'I';
		}else if(letra == 'o'){
			letra = 'O';
		}else if(letra == 'p'){
			letra = 'P';
		}else if(letra == 'a'){
			letra = 'A';
		}else if(letra == 's'){
			letra = 'S';
		}else if(letra == 'd'){
			letra = 'D';
		}else if(letra == 'f'){
			letra = 'F';
		}else if(letra == 'g'){
			letra = 'G';
		}else if(letra == 'h'){
			letra = 'H';
		}else if(letra == 'j'){
			letra = 'J';
		}else if(letra == 'k'){
			letra = 'K';
		}else if(letra == 'l'){
			letra = 'L';
		}else if(letra == '�'){
			letra = '�';
		}else if(letra == 'z'){
			letra = 'Z';
		}else if(letra == 'x'){
			letra = 'X';
		}else if(letra == 'c'){
			letra = 'C';
		}else if(letra == 'v'){
			letra = 'V';
		}else if(letra == 'b'){
			letra = 'B';
		}else if(letra == 'n'){
			letra = 'N';
		}else if(letra == 'm'){
			letra = 'M';
		}else if(letra == '�'){
			letra = 'A';
		}else if(letra == '�'){
			letra = 'A';
		}else if(letra == '�'){
			letra = 'A';
		}else if(letra == '�'){
			letra = 'A';
		}else if(letra == '�'){
			letra = 'A';
		}else if(letra == '�'){
			letra = 'A';
		}else if(letra == '�'){
			letra = 'A';
		}else if(letra == '�'){
			letra = 'A';
		}else if(letra == '�'){
			letra = 'E';
		}else if(letra == '�'){
			letra = 'E';
		}else if(letra == '�'){
			letra = 'E';
		}else if(letra == '�'){
			letra = 'E';
		}else if(letra == '�'){
			letra = 'E';
		}else if(letra == '�'){
			letra = 'E';
		}else if(letra == '�'){
			letra = 'I';
		}else if(letra == '�'){
			letra = 'I';
		}else if(letra == '�'){
			letra = 'I';
		}else if(letra == '�'){
			letra = 'I';
		}else if(letra == '�'){
			letra = 'I';
		}else if(letra == '�'){
			letra = 'I';
		}else if(letra == '�'){
			letra = 'O';
		}else if(letra == '�'){
			letra = 'O';
		}else if(letra == '�'){
			letra = 'O';
		}else if(letra == '�'){
			letra = 'O';
		}else if(letra == '�'){
			letra = 'O';
		}else if(letra == '�'){
			letra = 'O';
		}else if(letra == '�'){
			letra = 'O';
		}else if(letra == '�'){
			letra = 'O';
		}else if(letra == '�'){
			letra = 'U';
		}else if(letra == '�'){
			letra = 'U';
		}else if(letra == '�'){
			letra = 'U';
		}else if(letra == '�'){
			letra = 'U';
		}else if(letra == '�'){
			letra = 'U';
		}else if(letra == '�'){
			letra = 'U';
		}else if(letra == '�'){
			letra = 'U';
		}else if(letra == '�'){
			letra = 'U';
		}

		while((letra != 'Q') && (letra != 'W') && (letra != 'E') && (letra != 'R') && (letra != 'T') && (letra != 'Y') && (letra != 'U') && (letra != 'I') && (letra != 'O') && (letra != 'P') && (letra != 'A') && (letra != 'S') && (letra != 'D') && (letra != 'F') && (letra != 'G') && (letra != 'H') && (letra != 'J') && (letra != 'K') && (letra != 'L') && (letra != '�') && (letra != 'Z') && (letra != 'X') && (letra != 'C') && (letra != 'V') && (letra != 'B') && (letra != 'N') && (letra != 'M') && (letra != '1')){
			cout << "Caractere inv�lido, digite uma letra ou o n�mero 1 aperte Enter: ";
			cin >> letra;
		} 
		
			
		if(letra != '1'){

			for(cont = 0; cont < tamanhoDaPalavra; cont++){
				if(palavraJogar[cont] == letra){
					palavraComMascara[cont] = palavraJogar[cont];
				}
			}

			letrasArriscadas += letra;
		
			tentativas ++;
			pulaLinha();
			cout << "Tentativas Restantes: " << maximoDeTentativas - tentativas << "\n";
			cout << "Letras arriscadas: " << letrasArriscadas;
			pulaLinha();
			pulaLinha();

		}

	}

	string palavraInteira;
	int j, tamanhoDaPalavraInteira;

	if(letra == '1'){

		cout << "Chute uma palavra inteira: ";
		cin >> palavraInteira;

		tamanhoDaPalavraInteira = palavraInteira.size();
		
		for(j = 0; j < tamanhoDaPalavraInteira; j++){
		
			if(palavraInteira[j] == 'q'){
				palavraInteira[j] = 'Q';
			}else if(palavraInteira[j] == 'w'){
				palavraInteira[j] = 'W';
			}else if(palavraInteira[j] == 'e'){
				palavraInteira[j] = 'E';
			}else if(palavraInteira[j] == 'r'){
				palavraInteira[j] = 'R';
			}else if(palavraInteira[j] == 't'){
				palavraInteira[j] = 'T';
			}else if(palavraInteira[j] == 'y'){
				palavraInteira[j] = 'Y';
			}else if(palavraInteira[j] == 'u'){
				palavraInteira[j] = 'U';
			}else if(palavraInteira[j] == 'i'){
				palavraInteira[j] = 'I';
			}else if(palavraInteira[j] == 'o'){
				palavraInteira[j] = 'O';
			}else if(palavraInteira[j] == 'p'){
				palavraInteira[j] = 'P';
			}else if(palavraInteira[j] == 'a'){
				palavraInteira[j] = 'A';
			}else if(palavraInteira[j] == 's'){
				palavraInteira[j] = 'S';
			}else if(palavraInteira[j] == 'd'){
				palavraInteira[j] = 'D';
			}else if(palavraInteira[j] == 'f'){
				palavraInteira[j] = 'F';
			}else if(palavraInteira[j] == 'g'){
				palavraInteira[j] = 'G';
			}else if(palavraInteira[j] == 'h'){
				palavraInteira[j] = 'H';
			}else if(palavraInteira[j] == 'j'){
				palavraInteira[j] = 'J';
			}else if(palavraInteira[j] == 'k'){
				palavraInteira[j] = 'K';
			}else if(palavraInteira[j] == 'l'){
				palavraInteira[j] = 'L';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = '�';
			}else if(palavraInteira[j] == 'z'){
				palavraInteira[j] = 'Z';
			}else if(palavraInteira[j] == 'x'){
				palavraInteira[j] = 'X';
			}else if(palavraInteira[j] == 'c'){
				palavraInteira[j] = 'C';
			}else if(palavraInteira[j] == 'v'){
				palavraInteira[j] = 'V';
			}else if(palavraInteira[j] == 'b'){
				palavraInteira[j] = 'B';
			}else if(palavraInteira[j] == 'n'){
				palavraInteira[j] = 'N';
			}else if(palavraInteira[j] == 'm'){
				palavraInteira[j] = 'M';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'A';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'A';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'A';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'A';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'A';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'A';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'A';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'A';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'E';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'E';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'E';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'E';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'E';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'E';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'I';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'I';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'I';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'I';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'I';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'I';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'O';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'O';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'O';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'O';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'O';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'O';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'O';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'O';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'U';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j]= 'U';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'U';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'U';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'U';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'U';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'U';
			}else if(palavraInteira[j] == '�'){
				palavraInteira[j] = 'U';
			}
		
		}

	}

	if(letra != '1'){
		if(palavraComMascara == palavraJogar){
			printf(letra_verde);
			cout << "Parab�ns, voc� acertou, a palavra era " << palavraJogar << "\n";
		}else{
			printf(letra_vermelha);
			cout << "Voc� perdeu, a palavra era " << palavraJogar << "\n";
		}
		printf(letra_branca);
		pulaLinha();
	}else{
		if(palavraInteira == palavraJogar){
			printf(letra_verde);
			pulaLinha();
			cout << "Parab�ns, voc� acertou, a palavra era " << palavraJogar << "\n";
		}else{
			printf(letra_vermelha);
			pulaLinha();
			cout << "Voc� perdeu, a palavra era " << palavraJogar << "\n";
		}
		printf(letra_branca);
		pulaLinha();
	}

	int retornaProMenu = 0;

	printf(letra_amarela);
	cout << "Voc� deseja jogar novamente? \n\n";
	printf(letra_branca);
	cout << "1 - Sim, jogar novamente \n";
	cout << "2 - N�o, voltar para o menu inicial \n\n";
	cout << "Aperte 1 ou 2 e tecle Enter: ";
	cin >> retornaProMenu;
	pulaLinha();

	while((retornaProMenu != 1) && (retornaProMenu != 2)){
		cout << "N�mero inv�lido, aperte 1 ou 2 tecle Enter: ";
		cin >> retornaProMenu;	
		pulaLinha();
	}

	if(retornaProMenu == 1){
		system("CLS");
		cabecalho();
		jogar();
	}else{
		system("CLS");
		cabecalho();
		menuInicial();
	}

}

void informacoes();

void menuInicial(){
	int opcaoDoMenu = 0;
	while((opcaoDoMenu != 1) && (opcaoDoMenu != 2) && (opcaoDoMenu != 3)){
		printf("1 - Jogar \n");
		printf("2 - Sobre \n");
		printf("3 - Sair \n");
		printf("Digite 1, 2 ou 3 e aperte Enter: ");
		cin >> opcaoDoMenu;
		if((opcaoDoMenu != 1) && (opcaoDoMenu != 2) && (opcaoDoMenu != 3)){
			pulaLinha();
			printf("N�mero inv�lido \n");
			pulaLinha();
		}	

		switch(opcaoDoMenu){
			case 1:
				system("CLS");
				cabecalho();
				jogar();
				break;
			case 2:
				system("CLS");
				cabecalho();
				informacoes();
				break;
			case 3:
				system("CLS");
				cabecalho();
				printf("Muito obrigado por jogar esse jogo \n");
				printf("Tecle Enter para sair \n");
				break;
		}
	}
}

void informacoes(){
	int menu = 0;
	printf("Jogo criado por Paulinho Siggia em 2022 \n");
	printf("Todos os direitos reservados \n\n");
	printf("Aperte 1 e tecle Enter para retornar ao menu ");
	cin >> menu;
	while(menu != 1){
		printf("N�mero inv�lido, aperte 1 e tecle Enter para retornar ao menu ");
		cin >> menu;
	}
	system("CLS");
	cabecalho();
	menuInicial();
}

int main(){

	setlocale(LC_ALL,"Portuguese");
	srand((unsigned)time(NULL));
	system("color 0F");

	cabecalho();
	menuInicial();



	getch();
	return 0;

}
