# Push_swap

*Este projeto foi criado como parte do currículo 42 por rayperei & wgolbert.*


## Descrição
Este projeto tem como objetivo ordenar uma pilha de números inteiros utilizando apenas duas pilhas (a e b) e um conjunto limitado de operações. [cite_start]O foco é a implementação de diferentes algoritmos de ordenação, compreendendo a complexidade de tempo e espaço (Notação Big-O)[cite: 586, 1409].

## Contribuições
*Conforme exigido pelas normas do projeto, abaixo detalhamos o trabalho de cada membro:*

- **rayperei:**
  - Implementação da estrutura de dados das pilhas (listas encadeadas) e gerenciamento de memória (alocação e liberação segura com `free`).
  - Módulo de *parsing* e validação de argumentos (tratamento de entradas inválidas, overflow de inteiros de `INT_MIN` a `INT_MAX` e detecção de números duplicados).
  - Pré-processamento e normalização (indexação dos números de $0$ a $N-1$ para simplificar a manipulação lógica).

- **wgolbert:**
  - Implementação das operações básicas das pilhas (`sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`).
  - Desenvolvimento dos algoritmos de ordenação para pilhas pequenas (casos de 2, 3 e até 5 elementos).
  - Desenvolvimento do algoritmo de ordenação complexa (Radix Sort / manipulação de bits) e escolha da estratégia adaptativa de ordenação.

## Instruções de Compilação
[cite_start]O projeto utiliza um `Makefile` padrão[cite: 568]:
- `make`: Compila o programa `push_swap`.
- `make clean`: Remove arquivos objetos.
- `make fclean`: Remove arquivos objetos e o executável.
- `make re`: Recompila tudo.

## Algoritmos Utilizados
- [cite_start]**Caso simples (Simples):** Classe $\mathcal{O}(n^2)$[cite: 1423].
- [cite_start]**Caso complexo:** Classe $\mathcal{O}(n \log n)$[cite: 1424].

---