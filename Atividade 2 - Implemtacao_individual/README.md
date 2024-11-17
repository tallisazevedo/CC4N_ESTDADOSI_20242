# Implementação de Algoritmos de Ordenação em C

Este repositório contém a implementação de cinco algoritmos de ordenação na linguagem C:

- Shellsort
- Quicksort
- Heapsort
- RadixSort
- Mergesort


## Análise de Complexidade

| Algoritmo   | Melhor Caso         | Caso Médio          | Pior Caso          | Complexidade de Espaço |
|-------------|---------------------|---------------------|--------------------|-------------------------|
| **Shellsort** | \( O(n \log n) \)   | \( O(n^{3/2}) \)    | \( O(n^2) \)       | \( O(1) \)             |
| **Quicksort** | \( O(n \log n) \)   | \( O(n \log n) \)   | \( O(n^2) \)       | \( O(\log n) \)        |
| **Heapsort**  | \( O(n \log n) \)   | \( O(n \log n) \)   | \( O(n \log n) \)  | \( O(1) \)             |
| **RadixSort** | \( O(nk) \)         | \( O(nk) \)         | \( O(nk) \)        | \( O(n + k) \)         |
| **Mergesort** | \( O(n \log n) \)   | \( O(n \log n) \)   | \( O(n \log n) \)  | \( O(n) \)             |

**Nota**:
- \( n \) é o número de elementos no array de entrada.
- \( k \) é o número de dígitos do maior número (para o RadixSort).

## Como Compilar e Executar

Cada algoritmo foi implementado em um arquivo C separado. Siga os passos abaixo para compilar e executar:

1. Navegue até o diretório do algoritmo que deseja testar.
2. Compile o arquivo usando GCC:
   ```bash
   gcc -o saida algoritmo.c
   ```
   Substitua `algoritmo.c` pelo nome do arquivo correspondente (ex.: `quicksort.c`).
3. Execute o programa compilado:
   ```bash
   ./saida
   ```

## Casos de Teste

Cada algoritmo foi testado com os seguintes casos de entrada:
1. Arrays aleatórios.
2. Arrays já ordenados.
3. Arrays em ordem reversa.
4. Arrays com muitos elementos repetidos.

### Exemplo de Saída para Quicksort:
**Entrada:**
```
10, 7, 8, 9, 1, 5
```

**Saída:**
```
Array original:
10 7 8 9 1 5
Array ordenado:
1 5 7 8 9 10
```