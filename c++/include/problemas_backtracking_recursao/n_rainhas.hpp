#ifndef N_RAINHAS_HPP
#define N_RAINHAS_HPP

#include <vector>
#include <string>

/**
 * @file n_rainhas.hpp
 * @brief Contém a implementação para resolver o problema das N-Rainhas.
 */

/**
 * @brief Encontra todas as soluções distintas para o problema das N-Rainhas.
 *
 * O problema consiste em posicionar N rainhas de xadrez em um tabuleiro N×N de tal
 * forma que nenhuma rainha ameace a outra. A solução utiliza um algoritmo de
 * backtracking recursivo para explorar todas as possíveis posições seguras para as rainhas,
 * coluna por coluna.
 *
 * @param n O tamanho do tabuleiro e o número de rainhas a serem posicionadas.
 * @return Um `std::vector<std::vector<std::string>>` contendo todas as soluções.
 * Cada solução é um `std::vector<std::string>` que representa o tabuleiro,
 * com 'Q' indicando uma rainha e '.' um espaço vazio.
 *
 * @complexity
 * - Time: A complexidade é superior a polinomial, aproximadamente O(N!). O backtracking
 * poda significativamente a árvore de busca, mas o crescimento ainda é exponencial.
 * - Space: O(N^2), para armazenar o tabuleiro e as soluções encontradas.
 */
std::vector<std::vector<std::string>> resolver_n_rainhas(int n);

#endif // N_RAINHAS_HPP