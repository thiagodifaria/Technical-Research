#ifndef DISTANCIA_EDICAO_HPP
#define DISTANCIA_EDICAO_HPP

#include <string>
#include <vector>
#include <algorithm> // Para std::min e std::max

/**
 * @file distancia_edicao.hpp
 * @brief Contém a implementação para calcular a Distância de Edição (Levenshtein).
 */

/**
 * @brief Calcula a Distância de Edição (Levenshtein) entre duas strings.
 *
 * A distância de Levenshtein representa o número mínimo de edições de um único caractere
 * (inserção, exclusão ou substituição) necessárias para transformar uma string na outra.
 *
 * A solução utiliza programação dinâmica para construir uma tabela `dp[i][j]`, que armazena
 * a distância de edição entre os primeiros `i` caracteres de `str1` e os primeiros `j`
 * caracteres de `str2`.
 *
 * @param str1 A primeira string.
 * @param str2 A segunda string.
 * @return A distância de edição (int) entre as duas strings.
 *
 * @complexity
 * - Time: O(M * N), onde M e N são os comprimentos de str1 e str2, respectivamente.
 * - Space: O(M * N), para armazenar a tabela de programação dinâmica.
 */
int distancia_edicao(const std::string& str1, const std::string& str2);

#endif // DISTANCIA_EDICAO_HPP