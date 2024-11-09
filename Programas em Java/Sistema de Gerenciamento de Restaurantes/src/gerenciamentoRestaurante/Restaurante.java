package gerenciamentoRestaurante;
import java.util.Scanner;

public class Restaurante {
	
	Scanner scanner = new Scanner(System.in);
	int dia;
	
	public int validaDia(int dia) {
		
		switch(dia) {
			case 1:
				return 1;
			case 2:
				return 2;
			case 3:
				return 3;
			case 4:
				return 4;
			default:
				System.out.printf("Dia Inválido - Insira 1, 2, 3 ou 4 \n");
				dia = scanner.nextInt();
				scanner.nextLine();
				validaDia(dia);
				break;
		}
		
		return validaDia(dia);
				
	}

	public void menu() {
	
		System.out.println("=============================== ");
		System.out.println("GERENCIAMENTO DO RESTAURANTE ");
		System.out.println("=============================== \n");
		System.out.println("1 - Fazer Reserva ");
		System.out.println("2 - Listar Reserva ");
		System.out.println("3 - Total de Pessoas Por Dia ");
		System.out.println("4 - Sair ");
		int opcao = scanner.nextInt();
		scanner.nextLine();
		
		switch (opcao) {
		
			case 1:
				System.out.printf("Insira o nome: ");
				String nome = scanner.nextLine();
				System.out.printf("Insira o CPF: ");
				String cpf = scanner.nextLine();
				System.out.println("Insira o dia da reserva: ");
				System.out.println("1 - Quinta ");
				System.out.println("2 - Sexta ");
				System.out.println("3 - Sábado ");
				System.out.println("4 - Domingo ");
				dia = scanner.nextInt();
				scanner.nextLine();
				dia = validaDia(dia);
				System.out.printf("Insira a quantidade de pessoas: ");
				int quantidadePessoas = scanner.nextInt();
				scanner.nextLine();
				Reserva reserva = new Reserva(nome, cpf, dia, quantidadePessoas);
				// A PARTIR DAQUI É TESTE
				System.out.println(" ");
				System.out.println(reserva);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				System.exit(0);
				break;
			default:
				System.out.println("Número Inválido - Insira 1, 2, 3 ou 4 \n");
				menu();
				break;				
		}
		
		scanner.close();
		
	}
	
}
