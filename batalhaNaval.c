#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Novato - Posicionamento dos Navios

// Definição das constantes para o tamanho do tabuleiro
#define LINHAS 5
#define COLUNAS 5

int main() {
    // Declaração da matriz bidimensional para o tabuleiro
    // Inicializamos com 0 para garantir que não haja lixo de memória
    int tabuleiro[LINHAS][COLUNAS] = {0};

    // Coordenadas iniciais dos navios
    // Navio 1: Vertical (coluna fixa, linha varia)
    // Ocupa: (1,1), (2,1), (3,1)
    int navio1_coluna = 1;
    int navio1_linha_inicio = 1;

    // Navio 2: Horizontal (linha fixa, coluna varia)
    // Ocupa: (0,1), (0,2), (0,3)
    int navio2_linha = 0;
    int navio2_coluna_inicio = 1;

    // Posicionamento do Navio 1 (Vertical)
    for (int i = 0; i < 3; i++) {
        tabuleiro[navio1_linha_inicio + i][navio1_coluna] = 3;
    }

    // Posicionamento do Navio 2 (Horizontal)
    for (int i = 0; i < 3; i++) {
        tabuleiro[navio2_linha][navio2_coluna_inicio + i] = 3;
    }

    // Exibição das Coordenadas dos Navios
    printf("--- Coordenadas dos Navios ---\n");

    // Exibindo coordenadas do Navio 1 (Vertical)
    printf("Navio 1 (Vertical):\n");
    for (int i = 0; i < 3; i++) {
        printf("Parte %d: (%d, %d)\n", i + 1, navio1_linha_inicio + i, navio1_coluna);
    }

    printf("\n");

    // Exibindo coordenadas do Navio 2 (Horizontal)
    printf("Navio 2 (Horizontal):\n");
    for (int i = 0; i < 3; i++) {
        printf("Parte %d: (%d, %d)\n", i + 1, navio2_linha, navio2_coluna_inicio + i);
    }

    return 0;
}
