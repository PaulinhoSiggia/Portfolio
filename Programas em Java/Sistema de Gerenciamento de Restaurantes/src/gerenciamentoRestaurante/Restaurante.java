package gerenciamentoRestaurante;
import java.util.Scanner;
import java.util.ArrayList;

public class Restaurante {
	
	Scanner scanner = new Scanner(System.in);
	ArrayList<Reserva> listaDeReservas = new ArrayList<>();
	int dia, qui = 0, sex = 0, sab = 0, dom = 0;
	
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
	
		System.out.println("\n=============================== ");
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
				somaReservas(dia, quantidadePessoas);
				Reserva reserva = new Reserva(nome, cpf, dia, quantidadePessoas);
				listaDeReservas.add(reserva);
				menu();
				/* A PARTIR DAQUI É TESTE
				System.out.println(" ");
				System.out.println(reserva); */
				break;
			case 2:
				listarReservas();
				menu();
				break;
			case 3:
				exibeSomas();
				menu();
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
	
	public void listarReservas() {
        if (listaDeReservas.isEmpty()) {
            System.out.println("Nenhuma reserva cadastrada\n");
        } else {
            System.out.println("Lista de Reservas:\n");
            for (Reserva reserva : listaDeReservas) {
                System.out.println(reserva);
            }
        }
    }
	
	public void somaReservas(int dia, int quantidadePessoas) {
		switch (dia) {
			case 1:
				qui += quantidadePessoas;
				break;
			case 2:
				sex += quantidadePessoas;
				break;
			case 3:
				sab += quantidadePessoas;
				break;
			case 4:
				dom += quantidadePessoas;
				break;		
		}
	}
	
	public void exibeSomas() {
		System.out.println("Total de reservas por dia:");
		System.out.println("Quinta - " + qui + " pessoas");
		System.out.println("Sexta - " + sex + " pessoas");
		System.out.println("Sábado - " + sab + " pessoas");
		System.out.println("Domingo - " + dom + " pessoas");
	}
	
}
