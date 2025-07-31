#include "matematica_numerica_otimizacao/decomposicao_lu.hpp"

DecomposicaoLUResult decomposicao_lu(const Matriz& A) {
    if (A.empty() || A.size() != A[0].size()) {
        throw std::invalid_argument("A matriz de entrada deve ser quadrada.");
    }

    int n = A.size();
    Matriz L(n, std::vector<double>(n, 0.0));
    Matriz U(n, std::vector<double>(n, 0.0));

    for (int k = 0; k < n; ++k) {
        // 1. Calcula a k-ésima linha de U
        for (int j = k; j < n; ++j) {
            double soma = 0.0;
            for (int p = 0; p < k; ++p) {
                soma += L[k][p] * U[p][j];
            }
            U[k][j] = A[k][j] - soma;
        }

        // Define a diagonal de L como 1
        L[k][k] = 1.0;

        // Verifica se o pivô é zero. Se for, a decomposição sem pivoteamento falha.
        if (U[k][k] == 0.0) {
            throw std::runtime_error("Decomposicao LU falhou: pivô zero encontrado. Pivoteamento é necessário.");
        }

        // 2. Calcula a k-ésima coluna de L
        for (int i = k + 1; i < n; ++i) {
            double soma = 0.0;
            for (int p = 0; p < k; ++p) {
                soma += L[i][p] * U[p][k];
            }
            L[i][k] = (A[i][k] - soma) / U[k][k];
        }
    }

    return {L, U};
}