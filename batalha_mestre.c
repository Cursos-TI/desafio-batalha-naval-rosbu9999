#include <stdio.h>

int main() {
    // Inicializar o mapa
    char *mapa[10][10] = {
        {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"},
        {"1", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
        {"2", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
        {"3", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
        {"4", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
        {"5", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
        {"6", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
        {"7", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
        {"8", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
        {"9", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
    };

    // Definição dos barcos
    int barco1_linhas[3] = {4, 4, 4};
    int barco1_colunas[3] = {4, 5, 6};

    int barco2_linhas[3] = {3, 4, 5};
    int barco2_colunas[3] = {8, 8, 8};

    int barco3_linhas[3] = {5, 6, 7};
    int barco3_colunas[3] = {1, 2, 3};

    int barco4_linhas[3] = {7, 8, 9};
    int barco4_colunas[3] = {9, 8, 7};

    // Posicionar os barcos
    for (int i = 0; i < 3; i++) {
        mapa[barco1_linhas[i]][barco1_colunas[i]] = "3";
    }

    for (int i = 0; i < 3; i++) {
        mapa[barco2_linhas[i]][barco2_colunas[i]] = "3";
    }

    for (int i = 0; i < 3; i++) {
        mapa[barco3_linhas[i]][barco3_colunas[i]] = "3";
    }

    for (int i = 0; i < 3; i++) {
        mapa[barco4_linhas[i]][barco4_colunas[i]] = "3";
    }

    // MATRIZES DE HABILIDADE
    int cone[4][3];
    int cruz[5][3];
    int octaedro[3][3];

    // Inicializar cone
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            cone[i][j] = 0;
        }
    }
    cone[0][1] = 1;
    cone[1][0] = 1; cone[1][1] = 1; cone[1][2] = 1;
    cone[2][0] = 1; cone[2][1] = 1; cone[2][2] = 1;
    cone[3][0] = 1; cone[3][1] = 1; cone[3][2] = 1;

    // Inicializar cruz
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            cruz[i][j] = 0;
        }
    }
    cruz[0][1] = 1;
    cruz[1][1] = 1;
    cruz[2][0] = 1; cruz[2][1] = 1; cruz[2][2] = 1;
    cruz[3][1] = 1;
    cruz[4][1] = 1;

    // Inicializar octaedro
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            octaedro[i][j] = 0;
        }
    }
    octaedro[0][1] = 1;
    octaedro[1][0] = 1; octaedro[1][1] = 1; octaedro[1][2] = 1;
    octaedro[2][1] = 1;

    // Aplicar cone
    int origem_linha = 2;
    int origem_coluna = 7;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            int linha_tab = origem_linha + i - 2;
            int coluna_tab = origem_coluna + j - 1;
            if (linha_tab >= 0 && linha_tab < 10 && coluna_tab >= 0 && coluna_tab < 10) {
                if (cone[i][j] == 1 && mapa[linha_tab][coluna_tab][0] == '0') {
                    mapa[linha_tab][coluna_tab] = "5";
                }
            }
        }
    }

    // Aplicar cruz
    origem_linha = 5;
    origem_coluna = 5;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            int linha_tab = origem_linha + i - 2;
            int coluna_tab = origem_coluna + j - 1;
            if (linha_tab >= 0 && linha_tab < 10 && coluna_tab >= 0 && coluna_tab < 10) {
                if (cruz[i][j] == 1 && mapa[linha_tab][coluna_tab][0] == '0') {
                    mapa[linha_tab][coluna_tab] = "5";
                }
            }
        }
    }

    // Aplicar octaedro
    origem_linha = 7;
    origem_coluna = 7;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int linha_tab = origem_linha + i - 1;
            int coluna_tab = origem_coluna + j - 1;
            if (linha_tab >= 0 && linha_tab < 10 && coluna_tab >= 0 && coluna_tab < 10) {
                if (octaedro[i][j] == 1 && mapa[linha_tab][coluna_tab][0] == '0') {
                    mapa[linha_tab][coluna_tab] = "5";
                }
            }
        }
    }

    // Imprimir o mapa
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%s\t", mapa[i][j]);
        }
        printf("\n");
    }

    return 0;
}
