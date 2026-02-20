#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal

// Definição das constantes para o tamanho do tabuleiro
// Expandido para 10x10 conforme requisito do Nível Aventureiro
#define LINHAS 10
#define COLUNAS 10

int main() {
    // Declaração da matriz bidimensional para o tabuleiro
    // Inicializamos com 0 para garantir que não haja lixo de memória
    int tabuleiro[LINHAS][COLUNAS] = {0};

    // --- Posicionamento dos Navios ---

    // Navio 1: Vertical (coluna fixa, linha varia)
    // Ocupa: (2,2), (3,2), (4,2)
    int navio1_coluna = 2;
    int navio1_linha_inicio = 2;
    for (int i = 0; i < 3; i++) {
        tabuleiro[navio1_linha_inicio + i][navio1_coluna] = 3;
    }

    // Navio 2: Horizontal (linha fixa, coluna varia)
    // Ocupa: (5,4), (5,5), (5,6)
    int navio2_linha = 5;
    int navio2_coluna_inicio = 4;
    for (int i = 0; i < 3; i++) {
        tabuleiro[navio2_linha][navio2_coluna_inicio + i] = 3;
    }

    // Navio 3: Diagonal Principal (linha e coluna variam igualmente)
    // Ocupa: (0,0), (1,1), (2,2) - Note que (2,2) colide com Navio 1. Vamos ajustar.
    // Ajuste: (6,0), (7,1), (8,2)
    int navio3_linha_inicio = 6;
    int navio3_coluna_inicio = 0;
    for (int i = 0; i < 3; i++) {
        tabuleiro[navio3_linha_inicio + i][navio3_coluna_inicio + i] = 3;
    }

    // Navio 4: Diagonal Secundária (linha aumenta, coluna diminui)
    // Ocupa: (1,8), (2,7), (3,6)
    int navio4_linha_inicio = 1;
    int navio4_coluna_inicio = 8;
    for (int i = 0; i < 3; i++) {
        tabuleiro[navio4_linha_inicio + i][navio4_coluna_inicio - i] = 3;
    }

    // --- Exibição do Tabuleiro Completo ---
    printf("--- Tabuleiro de Batalha Naval ---\n");
    printf("0 = Agua, 3 = Navio\n\n");

    // Loop aninhado para percorrer e exibir a matriz
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); // Quebra de linha ao final de cada linha do tabuleiro
    }

    return 0;
}
