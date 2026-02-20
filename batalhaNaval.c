#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Implementação final com Tabuleiro 10x10, Navios e Habilidades Especiais

#define LINHAS 10
#define COLUNAS 10

int main() {
    // Matriz principal do tabuleiro
    // Inicializada com 0 para evitar lixo de memória
    int tabuleiro[LINHAS][COLUNAS] = {0};

    // Matrizes de máscaras para habilidades (5x5)
    // 1 indica área afetada, 0 indica área livre

    int habilidadeCone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    int habilidadeCruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    int habilidadeOctaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    // Posicionamento dos Navios
    // Valor 3 representa posição ocupada por navio

    // Navio Vertical
    int navio1_coluna = 2;
    int navio1_linha_inicio = 2;
    for (int i = 0; i < 3; i++) {
        if (navio1_linha_inicio + i < LINHAS)
            tabuleiro[navio1_linha_inicio + i][navio1_coluna] = 3;
    }

    // Navio Horizontal
    int navio2_linha = 5;
    int navio2_coluna_inicio = 4;
    for (int i = 0; i < 3; i++) {
        if (navio2_coluna_inicio + i < COLUNAS)
            tabuleiro[navio2_linha][navio2_coluna_inicio + i] = 3;
    }

    // Navio Diagonal Principal
    int navio3_linha_inicio = 6;
    int navio3_coluna_inicio = 0;
    for (int i = 0; i < 3; i++) {
        if (navio3_linha_inicio + i < LINHAS && navio3_coluna_inicio + i < COLUNAS)
            tabuleiro[navio3_linha_inicio + i][navio3_coluna_inicio + i] = 3;
    }

    // Navio Diagonal Secundária
    int navio4_linha_inicio = 1;
    int navio4_coluna_inicio = 8;
    for (int i = 0; i < 3; i++) {
        if (navio4_linha_inicio + i < LINHAS && navio4_coluna_inicio - i >= 0)
            tabuleiro[navio4_linha_inicio + i][navio4_coluna_inicio - i] = 3;
    }

    // Aplicação das Habilidades
    // Sobrepõe as máscaras no tabuleiro principal
    // Valor 5 representa área atingida pela habilidade

    // Habilidade Cone (Origem: 0,0)
    int origemConeLinha = 0;
    int origemConeColuna = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (habilidadeCone[i][j] == 1) {
                if (origemConeLinha + i < LINHAS && origemConeColuna + j < COLUNAS) {
                    tabuleiro[origemConeLinha + i][origemConeColuna + j] = 5;
                }
            }
        }
    }

    // Habilidade Cruz (Origem: 4,4)
    int origemCruzLinha = 4;
    int origemCruzColuna = 4;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (habilidadeCruz[i][j] == 1) {
                if (origemCruzLinha + i < LINHAS && origemCruzColuna + j < COLUNAS) {
                    tabuleiro[origemCruzLinha + i][origemCruzColuna + j] = 5;
                }
            }
        }
    }

    // Habilidade Octaedro (Origem: 0,5)
    int origemOctaedroLinha = 0;
    int origemOctaedroColuna = 5;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (habilidadeOctaedro[i][j] == 1) {
                if (origemOctaedroLinha + i < LINHAS && origemOctaedroColuna + j < COLUNAS) {
                    tabuleiro[origemOctaedroLinha + i][origemOctaedroColuna + j] = 5;
                }
            }
        }
    }

    // Exibição do Tabuleiro
    printf("--- Tabuleiro Final ---\n");
    printf("Legenda: 0=Agua, 3=Navio, 5=Atingido\n\n");

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
