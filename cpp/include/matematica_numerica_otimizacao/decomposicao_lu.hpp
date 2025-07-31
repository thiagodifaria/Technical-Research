#ifndef DECOMPOSICAO_LU_HPP
#define DECOMPOSICAO_LU_HPP

#include <vector>
#include <stdexcept>

/**
 * @file decomposicao_lu.hpp
 * @brief Contém a implementação da Decomposição LU para matrizes.
 */

using Matriz = std::vector<std::vector<double>>;

/**
 * @struct DecomposicaoLUResult
 * @brief Estrutura para armazenar os resultados (matrizes L e U) da Decomposição LU.
 */
struct DecomposicaoLUResult {
    Matriz L;
    Matriz U;
};

/**
 * @brief Realiza a Decomposição LU de uma matriz quadrada A, resultando em A = LU.
 *
 * Esta função implementa o algoritmo de Doolittle, onde a matriz L (Lower triangular)
 * possui uma diagonal principal de 1s, e a matriz U (Upper triangular) contém os
 * pivôs na diagonal.
 *
 * @warning Esta é uma implementação simplificada que **NÃO UTILIZA PIVOTEAMENTO**.
 * Como resultado, ela falhará (lançará uma exceção) se um zero aparecer na
 * diagonal durante o processo de fatoração. Para aplicações robustas, uma
 * implementação com pivoteamento (resultando em PA = LU) é necessária.
 *
 * @param A A matriz quadrada a ser decomposta.
 * @return Um objeto `DecomposicaoLUResult` contendo as matrizes L e U.
 * @throws std::invalid_argument se a matriz de entrada não for quadrada.
 * @throws std::runtime_error se a decomposição falhar devido a um pivô zero.
 *
 * @complexity
 * - Time: O(n^3), onde n é a dimensão da matriz.
 * - Space: O(n^2), para armazenar as matrizes L e U.
 */
DecomposicaoLUResult decomposicao_lu(const Matriz& A);

#endif // DECOMPOSICAO_LU_HPP