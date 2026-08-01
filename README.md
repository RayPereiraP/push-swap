*Esta atividade foi criada como parte do currículo 42 por rayperei, wgolbert.*

# Push_swap

## Descrição

O objetivo deste projeto é ordenar uma pilha de números inteiros (`a`)
utilizando apenas duas pilhas (`a` e `b`) e um conjunto restrito de 11
operações, com o menor número possível de operações. O programa recebe os
números via linha de comando, valida a entrada e imprime, em `stdout`, a
sequência de operações que, executada na ordem, deixa `a` ordenada e `b`
vazia.

Além da ordenação em si, o projeto explora e compara diferentes estratégias
algorítmicas — da mais simples (O(n²)) à mais eficiente (O(n log n)) —,
avaliando o impacto real da complexidade de tempo em pilhas de tamanhos
diferentes.

## Instruções

### Compilação

```bash
make        # compila o programa e gera o executável push_swap
make clean  # remove os arquivos objeto (.o)
make fclean # remove os arquivos objeto e o executável
make re     # fclean + all, recompila tudo do zero
```

### Uso

```bash
./push_swap [--flag] N1 N2 N3 ...
```

**Importante:** as flags precisam ser passadas **antes** dos números —
`./push_swap --bench 5 3 8 1` funciona, `./push_swap 5 3 8 1 --bench` não
(o parser interpreta `--bench` como um argumento numérico inválido e
retorna erro).

**Flags disponíveis:**
| Flag | Efeito |
|---|---|
| *(nenhuma)* | Usa a estratégia adaptativa (padrão) |
| `--simple` | Força o algoritmo O(n²) |
| `--medium` | Força o algoritmo O(n√n) |
| `--complex` | Força o algoritmo O(n log n) |
| `--adaptive` | Força a seleção automática por desordem |
| `--bench` | Imprime estatísticas de desempenho em `stderr` |

**Exemplos:**
```bash
./push_swap 5 3 8 1 9 2 7 4 6
./push_swap --complex 5 3 8 1 9 2 7 4 6
./push_swap --bench --medium 5 3 8 1 9 2 7 4 6
```

### Testando com o checker

```bash
ARG="2 1 0"
./push_swap $ARG | ./checker_linux $ARG
```

## Recursos

Referências consultadas durante o desenvolvimento, e em que parte do
projeto cada uma foi aplicada:

- **Enunciado oficial do projeto push_swap (42 Network)** — definição das
  11 operações permitidas, formato de entrada/saída e regras de validação.
  Base para todo o `parser.c`, `flags.c` e as `operations_*.c`.
- **Documentação sobre Selection Sort** — usada como referência conceitual
  para o algoritmo `--simple` (`algo_simple.c`): a cada iteração, encontra
  o menor elemento restante e o move para a posição correta.
- **Documentação sobre Radix Sort (LSD, base 2)** — usada como base teórica
  para o algoritmo `--complex` (`algo_complex.c`): ordenação bit a bit,
  do bit menos significativo para o mais significativo, usando o índice
  normalizado de cada valor.
- **Material sobre ordenação por blocos (bucket/chunk-based sorting)** —
  inspiração para o algoritmo `--medium` (`algo_medium.c`): divisão do
  intervalo de valores em `√n` blocos, processados individualmente.
- **Norma 42 (Norminette)** — guia de estilo de código seguido em todos
  os arquivos do projeto (padrão de nomenclatura, limite de linhas por
  função, proibição de certas estruturas de controle, etc.).

## Contribuições

O projeto foi dividido em duas frentes principais de desenvolvimento,
com sessões de pair programming para integração e revisão conjunta.

### rayperei (Dev A) — Validação de dados e performance algorítmica
- **Parsing e tratamento de erros:** validação rigorosa dos argumentos
  (`parser.c`), detectando valores não numéricos, duplicados e fora dos
  limites de `int` (`INT_MIN`/`INT_MAX`).
- **Gerenciador de flags:** implementação das flags de estratégia
  (`--simple`, `--medium`, `--complex`, `--adaptive`) e da flag `--bench`
  (`flags.c`).
- **Algoritmo Simples (O(n²)):** implementação do `algo_simple.c`.
- **Algoritmo Complexo (O(n log n)):** implementação do radix sort em
  `algo_complex.c`.
   **Benchmark:** formatação e exibição das estatísticas de desempenho em
  `stderr` (`benchmark.c`).

### wgolbert (Dev B) — Infraestrutura de dados e métrica matemática
- **Operações base:** estrutura de dados das pilhas `a` e `b`
  (`t_stack`/`t_list`) e as 11 operações fundamentais (`sa`, `pa`, `ra`,
  `rra`, etc.), com gerenciamento de memória livre de vazamentos
  (`operations_*.c`, `free_memory.c`).
- **Métrica de desordem:** função que calcula o nível de desordem da
  pilha (entre 0 e 1) antes do início da ordenação (`disorder.c`).
- **Algoritmo Médio (O(n√n)):** implementação do algoritmo por blocos em
  `algo_medium.c`.

### Trabalho em conjunto
- **Estratégia adaptativa:** lógica de seleção automática de algoritmo
  com base nos limiares de desordem (`algo_adaptive.c`).
- **Infraestrutura:** configuração do `Makefile` e revisão constante de
  conformidade com a Norma 42.

## Operações Permitidas

| Operação | Efeito |
|---|---|
| `sa` / `sb` / `ss` | Troca os 2 primeiros elementos do topo de `a`/`b`/de ambas |
| `pa` / `pb` | Move o elemento do topo de uma pilha para o topo da outra |
| `ra` / `rb` / `rr` | Desloca todos os elementos para cima; o primeiro vira o último |
| `rra` / `rrb` / `rrr` | Desloca todos os elementos para baixo; o último vira o primeiro |

## Detalhamento dos Algoritmos (Justificativa Técnica)

### Simples — O(n²)
Adaptação do *Selection Sort*. Repetidamente localiza o menor valor
restante em `a`, o rotaciona até o topo pelo caminho mais curto (`ra` se
estiver na metade de cima da pilha, `rra` se estiver na metade de baixo)
e o envia para `b` (`pb`). Ao final, devolve tudo de `b` para `a` com
`pa` — como os elementos foram empilhados em ordem crescente, a devolução
já resulta na pilha ordenada. Por repetir uma busca linear O(n) para cada
um dos n elementos, a complexidade total é O(n²).

### Médio — O(n√n)
Estratégia de particionamento em blocos (*chunks*). O intervalo de
índices normalizados (0 a `size - 1`) é dividido em aproximadamente `√n`
blocos de largura `n / √n`. Para cada bloco, o algoritmo localiza um
elemento cujo índice pertence à faixa do bloco atual, o move para `b`
pelo caminho mais curto, e mantém uma ordenação parcial dentro de `b`. Ao
final de todos os blocos, os elementos são devolvidos de `b` para `a` em
ordem decrescente de índice, reconstituindo a pilha ordenada.

### Complexo — O(n log n)
Utiliza *Radix Sort* (base 2, LSD — do bit menos significativo ao mais
significativo). Cada valor é previamente normalizado para um índice entre
0 e `size - 1` (via *merge sort* + busca binária em `index_array.c`).
Para cada bit, do menos ao mais significativo: se o bit do índice for 1,
o elemento é rotacionado para o fim da fila (`ra`); se for 0, é enviado
para `b` (`pb`). Ao final de cada rodada, `b` é devolvida integralmente
para `a`. Após processar `⌈log₂(size)⌉` bits, a pilha está ordenada.
Usar o índice normalizado (em vez do valor original) garante um número de
bits proporcional apenas ao tamanho da lista, independente da magnitude
dos valores de entrada.

### Adaptativo
Calcula o nível de desordem da pilha antes de decidir qual estratégia
executar:
- **Desordem < 0.2:** usa o algoritmo **Simples** (baixo overhead,
  compensa em pilhas quase ordenadas).
- **Desordem entre 0.2 e 0.5:** usa o algoritmo **Médio**.
- **Desordem ≥ 0.5:** usa o algoritmo **Complexo** (mais eficiente em
  pilhas muito desordenadas).

## Modo Benchmark (`--bench`)

Ativado com a flag `--bench`, imprime em `stderr` (para não se misturar
com a lista de operações em `stdout`):

- **Métrica de desordem inicial:** percentual calculado antes de qualquer
  movimento, onde 0% representa uma pilha já ordenada e 100% representa a
  pior ordem possível (todos os pares fora de ordem).
- **Estratégia utilizada** e sua classe de complexidade.
- **Contagem total de operações** realizadas.
- **Contagem individual** de cada uma das 11 operações (`sa`, `sb`, `ss`,
  `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`).
- **Razão operações/tamanho** e uma avaliação de performance frente às
  metas de excelência do projeto.

## Metas de Performance

| Tamanho da entrada | Passa | Bom | Excelente |
|---|---|---|---|
| 100 números | < 2000 ops | < 1500 ops | < 700 ops |
| 500 números | < 12000 ops | < 8000 ops | < 5500 ops |