#include <iostream>

// função para calcular o fatorial
long long fatorial(long n) {
	long fat; // variável que armazena o valor acumulado
	fat = 1; // inicializando ela em 1

	// condição especial: se n = 0
	if (n == 0) {
		return 1;
	}

	// loop principal
	while (n >= 1) {
		fat = fat*n;
		n = n - 1;
	}

	return fat;

}



int main() {
	long numero;

	std::cout << "====Calculadora de Fatorial!====" << std::endl;
	std::cout << "Digite o numero que deseja calcular o fatorial: ";
	std::cin >> numero;

	std::cout << "Resultado de " << numero << " !: " << fatorial(numero);


}