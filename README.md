# Push_swap

*Este projeto foi criado como parte do currículo 42 por rayperei & wgolbert.*


## Descrição
Este projeto tem como objetivo ordenar uma pilha de números inteiros utilizando apenas duas pilhas (a e b) e um conjunto limitado de operações. [cite_start]O foco é a implementação de diferentes algoritmos de ordenação, compreendendo a complexidade de tempo e espaço (Notação Big-O)[cite: 586, 1409].

## Contribuições
*Conforme exigido pelas normas do projeto, abaixo detalhamos o trabalho de cada membro:*

- **rayperei:**
  - Implementação da gestão e tratamento de argumentos (`argc`/`argv`), suportando múltiplos argumentos ou strings únicas com espaços.
  - Desenvolvimento do sistema de parsing e validação rigorosa de erros (checagem de limites de inteiros `INT_MIN`/`INT_MAX` e detecção de números duplicados).
  - Criação da estrutura de dados base para as pilhas A e B e alocação dinâmica de memória.

- **wgolbert:**
  - Implementação do motor de operações oficiais do projeto (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`).
  - Desenvolvimento do pré-processador/normalizador de dados para indexação dos números de `0` a `N-1`.
  - Colaboração na lógica dos algoritmos de ordenação (`sort_three`, `sort_five` e o algoritmo principal) e configuração do `Makefile`.

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