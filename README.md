# Calculadora de Fatorial em C++

Programa de linha de comando que calcula o fatorial de um número inteiro, com **validação robusta da entrada do usuário**: rejeita letras, números decimais (como `5.7`), valores negativos e números grandes demais para o tipo de resultado.

## Funcionalidades

- Cálculo iterativo do fatorial (`n!`) usando `unsigned long long`
- Leitura segura da entrada com `std::getline` + `std::stoi`
- Rejeita entradas inválidas, como `abc`, `5.7` e `12abc`
- Rejeita números negativos (o fatorial não é definido para eles)
- Limita a entrada a no máximo 20, pois `21!` ultrapassa o limite do `unsigned long long`
- Pede a entrada novamente até o usuário digitar um valor válido

## Requisitos

- Compilador C++ com suporte a C++11 ou superior (GCC, Clang ou MSVC)

## Como compilar e executar

```bash
# Compilar
g++ -std=c++11 -Wall -o fatorial fatorial.cpp

# Executar (Linux/macOS)
./fatorial

# Executar (Windows)
fatorial.exe
```

## Exemplo de uso

```
====Calculadora de Fatorial!====
Digite o numero que deseja calcular o fatorial: abc
Entrada invalida! Digite apenas um numero inteiro.
Digite o numero que deseja calcular o fatorial: 5.7
Entrada invalida! Digite apenas um numero inteiro.
Digite o numero que deseja calcular o fatorial: -3
Fatorial nao existe para numeros negativos.
Digite o numero que deseja calcular o fatorial: 25
Maximo suportado: 20 (acima disso estoura o unsigned long long).
Digite o numero que deseja calcular o fatorial: 5
Resultado de 5!: 120
```

## Como funciona

### `fatorial(int n)`

Calcula o fatorial com um laço `while`, multiplicando o acumulador por `n` e decrementando até chegar a 1. Para `n = 0` e `n = 1`, o laço não executa e o resultado é `1`, o que dispensa um caso especial para o zero.

### `lerInteiro(const std::string& mensagem)`

Lê a linha inteira como texto e só devolve o valor se ele for um inteiro válido:

1. `std::getline` captura a linha completa, sem deixar lixo no buffer.
2. `std::stoi` converte o texto para `int`. Ele lança `invalid_argument` se não houver número (ex.: `abc`) e `out_of_range` se o valor não couber em um `int`.
3. O parâmetro `pos` informa quantos caracteres foram convertidos. Se for diferente do tamanho da string, sobrou conteúdo (ex.: o `.7` de `5.7`) e a entrada é rejeitada.

### `main()`

Chama `lerInteiro` em um laço, validando o intervalo (`0` a `20`), e exibe o resultado.

## Limitações

| Limite | Motivo |
|--------|--------|
| Máximo de `20!` = 2.432.902.008.176.640.000 | `21!` excede o maior valor de `unsigned long long` (2⁶⁴ − 1) |
| Somente inteiros não negativos | O fatorial clássico não é definido para negativos nem decimais |

Para calcular fatoriais maiores, seria necessário usar uma biblioteca de inteiros de precisão arbitrária, como a [GMP](https://gmplib.org/) ou a [Boost.Multiprecision](https://www.boost.org/doc/libs/release/libs/multiprecision/).

## Estrutura do projeto

```
.
├── fatorial.cpp
└── README.md
```
