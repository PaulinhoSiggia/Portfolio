package gerenciamentoRestaurante;

public class Reserva {
	
	private String nome, cpf;
	private int dia, quantidadePessoas;
	
	public String getNome() {return nome;}
	public void setNome(String nome) {this.nome = nome;}
	
	public String getCpf() {return cpf;}
	public void setCpf(String cpf) {this.cpf = cpf;}
	
	public int getDia() {return dia;}
	public void setDia(int dia) {this.dia = dia;}
	
	public int getQuantidadePessoas() {return quantidadePessoas;}
	public void setQuantidadePessoas(int quantidadePessoas) {this.quantidadePessoas = quantidadePessoas;}
	
	public Reserva(String nome, String cpf, int dia, int quantidadePessoas) {
		this.nome = nome;
		this.cpf = cpf;
		this.dia = dia;
		this.quantidadePessoas = quantidadePessoas;
	}
	
	public String formataDia(int dia) {
		
		switch (dia) {
			case 1:
				return "1 - Quinta";				
			case 2:
				return "2 - Sexta";
			case 3:
				return "3 - Sábado";
			case 4:
				return "4 - Domingo";
		}
		
		return "0";
	}
	
	@Override
	public String toString() {
		return "Nome: " + nome + " \n"
				+ "CPF: " + cpf + " \n"
				+ "Dia: " + formataDia(dia) + " \n"
				+ "Número de Pessoas: " + quantidadePessoas + "\n"
				+ "=============================== \n";
	}

}
