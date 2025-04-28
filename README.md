# HASH TABLES: Tabelas de Espalhamentos

## Proposta
Implementar, testar e estudar a eficiência de tabelas de espalhamentos. Este diretório possui um arquivo de
makefile para ajudar na compilação e execução dos testes. Digite o comando `make all`.

## O que é uma tabela de espalhamento?
Uma tabela de espalhamento é uma estrutura de dados que permite realizar consultas em tempo constante.
Ela armazena seus dados em um array e utiliza uma função de mapeamento para identificar a posição do dado
buscado. A função de mapeamento converte uma chave em um valor inteiro, a posição do array aonde os dados
referentes a chave se encontram.
Duas chaves diferentes podem indicar uma mesma posição em um array, através da função de mapeamento. E este
evento é chamado de _colisão_. Uma boa função de mapeamento deve evitar essas colisões, mas na prática, sempre
acontecem.
Para se tratar as colisões, uma estratégia utilizada é implementar a tabela de espalhamento com listas ligadas,
onde cada posição do array é uma lista, dividindo os dados em seções. Ao buscar um dado na tabela, identificamos
qual a lista o dado se encontra através da função de mapeamento e depois realizamos uma busca sequencial na lista
ligada.

## Literatura
Este projeto tem por referência o livro _Dominando algoritmos com C, primeira edição_, de Kyle Loudon.

