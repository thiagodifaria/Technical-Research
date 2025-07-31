#include "problemas_backtracking_recursao/resolvedor_sudoku.hpp"

// Verifica se é seguro colocar 'num' na célula (linha, coluna)
bool is_safe(const TabuleiroSudoku& tabuleiro, int linha, int coluna, int num) {
    // Verifica a linha
    for (int c = 0; c < 9; ++c) {
        if (tabuleiro[linha][c] == num) {
            return false;
        }
    }

    // Verifica a coluna
    for (int l = 0; l < 9; ++l) {
        if (tabuleiro[l][coluna] == num) {
            return false;
        }
    }

    // Verifica o subquadrado 3x3
    int inicio_linha_quadrado = linha - linha % 3;
    int inicio_coluna_quadrado = coluna - coluna % 3;
    for (int l = 0; l < 3; ++l) {
        for (int c = 0; c < 3; ++c) {
            if (tabuleiro[l + inicio_linha_quadrado][c + inicio_coluna_quadrado] == num) {
                return false;
            }
        }
    }

    return true;
}

bool resolver_sudoku(TabuleiroSudoku& tabuleiro) {
    int linha, coluna;
    bool encontrou_vazio = false;

    // Encontra a próxima célula vazia
    for (linha = 0; linha < 9; ++linha) {
        for (coluna = 0; coluna < 9; ++coluna) {
            if (tabuleiro[linha][coluna] == 0) {
                encontrou_vazio = true;
                break;
            }
        }
        if (encontrou_vazio) {
            break;
        }
    }

    // Caso base: se não há mais células vazias, o Sudoku está resolvido
    if (!encontrou_vazio) {
        return true;
    }

    // Tenta colocar os números de 1 a 9 na célula vazia
    for (int num = 1; num <= 9; ++num) {
        if (is_safe(tabuleiro, linha, coluna, num)) {
            // Faz a jogada
            tabuleiro[linha][coluna] = num;

            // Recorre para o resto do tabuleiro
            if (resolver_sudoku(tabuleiro)) {
                return true;
            }

            // Se a recursão não levou a uma solução, desfaz a jogada (backtrack)
            tabuleiro[linha][coluna] = 0;
        }
    }

    // Se nenhum número de 1 a 9 funcionou nesta célula, retorna false
    return false;
}