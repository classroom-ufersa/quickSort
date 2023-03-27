# QuickSort

### Quick Sort é um método de ordenação que têm o objetivo principal posicionar os elementos de uma estrutura de dados em uma determinada ordem para assim acessar os dados de forma mais eficiente. Esse algorito de ordenação funciona por divisão e conquista, ou seja, a lógica será repartir um vetor em um conjunto de dados, como subgrupos, que são ordenados de forma independente. O particionamento é feito através de um número qualquer, que chamaremos neste código de pivô. A intenção é fazer com que todos os números colocados à esquerda deste particionamento sejam menores ou iguais ao pivô (número qualquer que está presente na lista).
  

  # Vantagens e Desvantagens
## Vantagens: 
### - É extremamente eficiente para ordenar arquivos de dados.
### - Necessita de apenas uma pequena pilha como memória auxiliar. 
### - Requer O(n log n) comparações em média (caso médio) para ordenar n itens. 
 

 ## Desvantagens:
### -Tem um pior caso O(n2) comparações.
### - Sua implementação é delicada e difícil:
### - Um pequeno engano pode levar a efeitos inesperados para
### algumas entradas de dados.
### - O método não é estável. 