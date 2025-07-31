#include "problemas_backtracking_recursao/n_rainhas.hpp"
#include <cmath> // Para std::abs

class NQueensSolver {
private:
    int n;
    std::vector<std::vector<std::string>> solucoes;
    std::vector<int> tabuleiro; // tabuleiro[coluna] = linha

    // Verifica se é seguro colocar uma rainha na posição (linha, coluna)
    bool is_safe(int linha, int coluna) {
        // Verifica as colunas anteriores
        for (int c_anterior = 0; c_anterior < coluna; ++c_anterior) {
            int l_anterior = tabuleiro[c_anterior];
            
            // Verifica a mesma linha
            if (l_anterior == linha) {
                return false;
            }
            // Verifica as diagonais
            if (std::abs(l_anterior - linha) == std::abs(c_anterior - coluna)) {
                return false;
            }
        }
        return true;
    }

    // A função de backtracking recursiva
    void resolver_helper(int coluna) {
        // Caso base: todas as rainhas foram posicionadas com sucesso
        if (coluna == n) {
            // Constrói a representação do tabuleiro e adiciona às soluções
            std::vector<std::string> solucao_formatada;
            for (int i = 0; i < n; ++i) {
                std::string linha_str(n, '.');
                linha_str[tabuleiro[i]] = 'Q';
                solucao_formatada.push_back(linha_str);
            }
            // A representação do tabuleiro aqui é com a rainha na coluna `tabuleiro[i]`
            // Vamos corrigir para a representação correta (linha `i`, coluna `tabuleiro[i]`)
            // Erro comum de lógica. O correto é `board[col] = row`.
            // Nossa representação `tabuleiro[coluna] = linha` está correta.
            // A formatação da solução precisa ser ajustada.
            std::vector<std::string> solucao_final(n, std::string(n, '.'));
             for(int c = 0; c < n; ++c){
                solucao_final[tabuleiro[c]][c] = 'Q';
             }
            solucoes.push_back(solucao_final);
            return;
        }

        // Tenta colocar uma rainha em cada linha da coluna atual
        for (int linha = 0; linha < n; ++linha) {
            if (is_safe(linha, coluna)) {
                tabuleiro[coluna] = linha;   // Coloca a rainha
                resolver_helper(coluna + 1); // Recorre para a próxima coluna
                // Backtrack não é explicitamente necessário aqui, pois
                // tabuleiro[coluna] será sobrescrito na próxima iteração do loop.
            }
        }
    }


public:
    explicit NQueensSolver(int board_size) : n(board_size) {
        tabuleiro.resize(n);
    }

    std::vector<std::vector<std::string>> solve() {
        if (n <= 0) return {};
        resolver_helper(0);
        return solucoes;
    }
};


std::vector<std::vector<std::string>> resolver_n_rainhas(int n) {
    NQueensSolver solver(n);
    return solver.solve();
}