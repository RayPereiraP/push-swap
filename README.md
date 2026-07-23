# Push_swap

*Este projeto foi criado como parte do currículo 42 por rayperei & wgolbert.*


## Descrição
Este projeto tem como objetivo ordenar uma pilha de números inteiros utilizando apenas duas pilhas (a e b) e um conjunto limitado de operações. [cite_start]O foco é a implementação de diferentes algoritmos de ordenação, compreendendo a complexidade de tempo e espaço (Notação Big-O)[cite: 586, 1409].

## Contribuições
Para garantir o equilíbrio técnico e o aprendizado mútuo, o projeto foi dividido em duas frentes de desenvolvimento principais, com sessões de pair programming para a integração final.

### **rayperei (Dev A)**
Foco na **validação de dados** e **performance algorítmica**:
*   **Parsing e Erros:** Implementação da validação rigorosa de argumentos, tratando duplicatas, valores não numéricos e limites de inteiros (`INT_MIN`/`INT_MAX`) [10, 25].
*   **Gerenciador de Flags:** Implementação das flags de estratégia (`--simple`, `--medium`, `--complex`, `--adaptive`) e da flag `--bench` [25, 26].
*   **Estratégias de Ordenação:** Desenvolvimento do algoritmo **Simples** ($\mathcal{O}(n^2)$) e do algoritmo **Complexo** ($\mathcal{O}(n \log n)$), utilizando a lógica de *Radix Sort* [10, 16, 27].

### **wgolbert (Dev B)**
Foco na **infraestrutura de dados** e **métrica matemática**:
*   **Operações Base:** Criação da estrutura de dados das pilhas A e B e implementação das 11 operações fundamentais (`sa`, `pa`, `ra`, `rra`, etc.), garantindo o gerenciamento de memória livre de *leaks* [12, 13, 27].
*   **Métrica de Desordem:** Implementação da função matemática para calcular o nível de desordem da pilha (entre 0 e 1) antes do início da ordenação [19, 28].
*   **Estratégia Média:** Desenvolvimento do algoritmo de complexidade média ($\mathcal{O}(n\sqrt{n})$) baseado em blocos (*chunks*) [15, 28].

### **Trabalho em Conjunto (Pair Programming)**
*   **Estratégia Adaptativa:** Lógica para seleção do algoritmo baseada nos limites de desordem (< 0.2, 0.2 a 0.5, e ≥ 0.5) [17, 29].
*   **Benchmark:** Formatação e exibição das estatísticas de desempenho no `stderr` [29, 30].
*   **Infraestrutura:** Configuração do `Makefile` e revisão constante da conformidade com a **Norma da 42** [2, 29].

## Instruções de Compilação
[cite_start]O projeto utiliza um `Makefile` padrão[cite: 568]:
- `make`: Compila o programa `push_swap`.
- `make clean`: Remove arquivos objetos.
- `make fclean`: Remove arquivos objetos e o executável.
- `make re`: Recompila tudo.

## Algoritmos Utilizados
- [cite_start]**Caso simples (Simples):** Classe $\mathcal{O}(n^2)$[cite: 1423].
- [cite_start]**Caso complexo:** Classe $\mathcal{O}(n \log n)$[cite: 1424].

## Operações Permitidas
- É importante listar as ferramentas que o seu programa utiliza para manipular as pilhas
- sa / sb / ss: Troca os dois primeiros elementos do topo da pilha A, B ou ambas
- pa / pb: Move o elemento do topo de uma pilha para a outra
- ra / rb / rr: Desloca todos os elementos para cima; o primeiro torna-se o último
- rra / rrb / rrr: Desloca todos os elementos para baixo; o último torna-se o primeiro


##  Detalhamento dos Algoritmos (Justificativa Técnica)
- A norma exige uma justificativa detalhada das escolhas algorítmicas
- Simples (O(n 2 )): Adaptação do Selection Sort. O programa localiza o menor valor em A, move-o para o topo pelo caminho mais curto (ra ou rra) e o envia para B
- Médio (O(n n)): Estratégia de particionamento em blocos (chunks). O intervalo de índices é dividido em pedaços calculados dinamicamente para otimizar a triagem
- Complexo (O(nlogn)): Utiliza Radix Sort (Base 2). O algoritmo analisa a representação binária dos índices normalizados, movendo elementos para B se o bit atual for 0 e mantendo em A se for 1
- Adaptativo: Escolhe o algoritmo baseado na métrica de desordem
Quando a pilha está quase ordenada (desordem < 0.2), algoritmos simples são mais eficientes por terem menor sobrecarga constante


## Modo Benchmark (--bench)
- Explique o que essa funcionalidade exibe no stderr para monitorar a performance
- Métrica de Desordem: Porcentagem calculada antes de qualquer movimento, onde 0% é uma pilha ordenada e 100% é a pior ordem possível
- Estatísticas: Exibe o total de operações e a contagem individual de cada um dos 11 movimentos realizados

## Metas de Performance
- Documentar os alvos de "excelência" ajuda a demonstrar a eficácia do seu código
- 100 números: Menos de 700 operações
- 500 números: Menos de 5500 operações

---