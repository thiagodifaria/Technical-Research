#ifndef MAIOR_SUBSEQUENCIA_COMUM_HPP
#define MAIOR_SUBSEQUENCIA_COMUM_HPP

#include <string>
#include <vector>
#include <algorithm> // Para std::max

/**
 * @file maior_subsequencia_comum.hpp
 * @brief Contém a implementação para encontrar o comprimento da Maior Subsequência Comum (LCS).
 */

/**
 * @brief Calcula o comprimento da Maior Subsequência Comum (LCS) entre duas strings.
 *
 * Uma subsequência é uma sequência que pode ser derivada de outra sequência deletando zero ou
 * mais elementos sem mudar a ordem dos elementos restantes. A Maior Subsequência Comum de
 * duas sequências é a subsequência mais longa que é comum a ambas.
 *
 * Esta função usa programação dinâmica (abordagem de tabulação) para construir uma tabela
 * `dp[i][j]` que armazena o comprimento da LCS das substrings `str1[0...i-1]` e `str2[0...j-1]`.
 *
 * @param str1 A primeira string.
 * @param str2 A segunda string.
 * @return O comprimento (int) da maior subsequência comum.
 *
 * @complexity
 * - Time: O(M * N), onde M e N são os comprimentos de str1 e str2, respectivamente.
 * - Space: O(M * N), para armazenar a tabela de programação dinâmica.
 */
int lcs_length(const std::string& str1, const std::string& str2);

#endif // MAIOR_SUBSEQUENCIA_COMUM_HPP