
﻿# Lista de Exercício sobre Ranges e Funções Templates

Essa lista de exercícios tem por objetivo o desenvolvimento de uma biblioteca de funções **template** que operam sobre **ranges**, i.e. um par de ponteiros que definem um intervalo aberto-fechado sobre uma coleção. A programação com template ou _gabarito_ em C++ permite que você programe uma função sem especificar o tipo de dados sobre o qual a função vai trabalhar. Dessa forma é possível, por exemplo, criar uma _única_ função de ordenação que ordenda qualquer coleção de informações, como inteiros, strings, frutas e monstros.

# Compilando o Projeto

## Usando `cmake`

Nesta lista, todos os exercícios serão implementados na forma de uma função template.
Existem um arquivo `tests/main.cpp` onde os **testes unitários** para cada função foram implementados. Você pode olhar esse arquivo para entender como os testes foram projetados, mas você não deve alterá-lo.

A compilação e execução das questões pode ser feita usando `cmake`. A partir da pasta raiz do projeto faça:

```
cmake -S . -B build
```

para gerar os arquivos `Makefiles` do projeto na pasta `build` que será criada. Em seguinda compile com:

```
cmake --build build --target run_tests
```

Esse comando ativa a compilação e, em seguida, executa os testes.

Alternativamente, se você desejar apenas compilar e não rodar os testes, utilize:

```
cmake --build build
```

A compilação gera um executável com o nome `all_tests` dentro da pasta `build/tests`.

Logo após a compilação, para executar o programa com os testes use os comandos:

```
./build/tests/all_tests
```

Caso você deseje repetir o processo de compilação, digamos, após uma alteração, basta executar o comando `make` dentro da pasta `build`.

## Usando Compilação Manual com `g++`

É possível compilar o programa "na mão" (i.e. sem o `cmake`) usando o `g++`. Para isso use o comando abaixo a partir do diretório raiz do projeto.

```
mkdir -p build
```

para criar a pasta `build` onde o executável será gerado, e

```
g++ -Wall -std=c++17 -pedantic tests/include/tm/test_manager.cpp tests/main.cpp -I include -I tests/include/tm -o build/all_tests
```

para compilar e gerar o executável em `build`.

O executável será gerado na pasta `build`, bastando executá-lo depois, como explicado acima.

&copy; DIMAp/UFRN 2020-2024.
