// Ana Clara Guarizi de Souza - UVV 2024/2 CC4N - Matrícula 202309136

#include <stdio.h>
#include <stdlib.h>

// estrutura do nó da árvore AVL
typedef struct NodoAVL {
    int valor;
    struct NodoAVL* filhoEsq;
    struct NodoAVL* filhoDir;
    int nivel;  // nivel do nó
} NodoAVL;

// Método responsável por criar um novo nó
NodoAVL* novoNodoAVLAVL(int valor) {
    NodoAVL* no = (NodoAVL*)malloc(sizeof(NodoAVL));
    no->valor = valor;
    no->filhoEsq = no->filhoDir = NULL;
    no->nivel = 1;
    return no;
}

// Método responsável por obter a nivel de um nó
int nivel(NodoAVL* no) {
    return (no == NULL) ? 0 : no->nivel;
}

// Método responsável por calcular o fator de balanceamento
int calcularBalanceamento(NodoAVL* no) {
    return (no == NULL) ? 0 : nivel(no->filhoEsq) - nivel(no->filhoDir);
}

// Método responsável por rotação à filhoEsq
NodoAVL* rotacionarParaEsquerda(NodoAVL* x) {
    NodoAVL* y = x->filhoDir;
    NodoAVL* T2 = y->filhoEsq;
    
    // realizando a rotação
    y->filhoEsq = x;
    x->filhoDir = T2;
    
    // atualizando as nivels
    x->nivel = 1 + (nivel(x->filhoEsq) > nivel(x->filhoDir) ? nivel(x->filhoEsq) : nivel(x->filhoDir));
    y->nivel = 1 + (nivel(y->filhoEsq) > nivel(y->filhoDir) ? nivel(y->filhoEsq) : nivel(y->filhoDir));
    
    return y;
}

// Método responsável por rotação à filhoDir
NodoAVL* rotacionarParaDireita(NodoAVL* y) {
    NodoAVL* x = y->filhoEsq;
    NodoAVL* T2 = x->filhoDir;
    
    // realizando a rotação
    x->filhoDir = y;
    y->filhoEsq = T2;
    
    // atualizando as nivels
    y->nivel = 1 + (nivel(y->filhoEsq) > nivel(y->filhoDir) ? nivel(y->filhoEsq) : nivel(y->filhoDir));
    x->nivel = 1 + (nivel(x->filhoEsq) > nivel(x->filhoDir) ? nivel(x->filhoEsq) : nivel(x->filhoDir));
    
    return x;
}

// Método responsável por inserir na árvore AVL
NodoAVL* adicionarNaAVL(NodoAVL* no, int valor) {
    // 1. realizar a inserção na árvore binária de busca normal
    if (no == NULL) {
        return novoNodoAVLAVL(valor);
    }

    if (valor < no->valor) {
        no->filhoEsq = adicionarNaAVL(no->filhoEsq, valor);
    } else if (valor > no->valor) {
        no->filhoDir = adicionarNaAVL(no->filhoDir, valor);
    } else {
        return no;  // se o valor já existe, não adiciona
    }

    // 2. atualizar a nivel do nó atual
    no->nivel = 1 + (nivel(no->filhoEsq) > nivel(no->filhoDir) ? nivel(no->filhoEsq) : nivel(no->filhoDir));

    // 3. verificar o fator de balanceamento e realizar rotações se necessário
    int balance = calcularBalanceamento(no);

    // se o nó estiver desbalanceado, existem 4 casos

    // caso 1: desbalanceamento à filhoEsq
    if (balance > 1 && valor < no->filhoEsq->valor) {
        return rotacionarParaDireita(no);
    }

    // caso 2: desbalanceamento à filhoDir
    if (balance < -1 && valor > no->filhoDir->valor) {
        return rotacionarParaEsquerda(no);
    }

    // caso 3: desbalanceamento à filhoEsq-filhoDir
    if (balance > 1 && valor > no->filhoEsq->valor) {
        no->filhoEsq = rotacionarParaEsquerda(no->filhoEsq);
        return rotacionarParaDireita(no);
    }

    // caso 4: desbalanceamento à filhoDir-filhoEsq
    if (balance < -1 && valor < no->filhoDir->valor) {
        no->filhoDir = rotacionarParaDireita(no->filhoDir);
        return rotacionarParaEsquerda(no);
    }

    return no;
}

// Método responsável por imprimir a árvore
void mostrarEmOrdemAVL(NodoAVL* raiz) {
    if (raiz != NULL) {
        mostrarEmOrdemAVL(raiz->filhoEsq);
        printf("%d ", raiz->valor);
        mostrarEmOrdemAVL(raiz->filhoDir);
    }
}

// função principal
int main() {
    NodoAVL* raiz = NULL;
    int i, arr[50];
    
    // gerando um array aleatório de 50 elementos
    printf("Array aleatório de 50 elementos:\n");
    for (i = 0; i < 50; i++) {
        arr[i] = rand() % 100;  // número aleatório entre 0 e 99
        printf("%d ", arr[i]);
        raiz = adicionarNaAVL(raiz, arr[i]);
    }

    printf("\n\nEstrutura AVL em ordem:\n");
    mostrarEmOrdemAVL(raiz);
    printf("\n");

    return 0;
}
