// Ana Clara Guarizi de Souza - UVV 2024/2 CC4N - Matrícula 202309136

#include <stdio.h>
#include <stdlib.h>

// estrutura do nó da árvore
typedef struct NodoBST {
    int chave;
    struct NodoBST* subArvoreEsq;
    struct NodoBST* subArvoreDir;
} NodoBST;

// Método responsável por criar um novo nó
NodoBST* criarNodoBSTdoBST(int chave) {
    NodoBST* no = (NodoBST*)malloc(sizeof(NodoBST));
    no->chave = chave;
    no->subArvoreEsq = no->subArvoreDir = NULL;
    return no;
}

// Método responsável por inserir na árvore BST
NodoBST* adicionarNaBST(NodoBST* raiz, int chave) {
    if (raiz == NULL) {
        return criarNodoBSTdoBST(chave);
    }
    if (chave < raiz->chave) {
        raiz->subArvoreEsq = adicionarNaBST(raiz->subArvoreEsq, chave);
    } else if (chave > raiz->chave) {
        raiz->subArvoreDir = adicionarNaBST(raiz->subArvoreDir, chave);
    }
    // se o chave já existe, não adiciona
    return raiz;
}

// Método responsável por imprimir a árvore (em ordem)
void mostrarEmOrdemBST(NodoBST* raiz) {
    if (raiz != NULL) {
        mostrarEmOrdemBST(raiz->subArvoreEsq);
        printf("%d ", raiz->chave);
        mostrarEmOrdemBST(raiz->subArvoreDir);
    }
}

// função principal
int main() {
    NodoBST* raiz = NULL;
    int i, arr[50];
    
    // gerando um array aleatório de 50 elementos
    printf("Array aleatório de 50 elementos:\n");
    for (i = 0; i < 50; i++) {
        arr[i] = rand() % 100;  // número aleatório entre 0 e 99
        printf("%d ", arr[i]);
        raiz = adicionarNaBST(raiz, arr[i]);
    }

    printf("\n\nEstrutura BST em ordem:\n");
    mostrarEmOrdemBST(raiz);
    printf("\n");

    return 0;
}
