#ifndef RESOLVEDOR_SUDOKU_HPP
#define RESOLVEDOR_SUDOKU_HPP

#include <vector>

/**
 * @file resolvedor_sudoku.hpp
 * @brief Contém a implementação de um resolvedor de Sudoku usando backtracking.
 */

// Apelido para a representação do tabuleiro de Sudoku
using TabuleiroSudoku = std::vector<std::vector<int>>;

/**
 * @brief Resolve um tabuleiro de Sudoku 9x9 usando um algoritmo de backtracking.
 *
 * A função tenta preencher as células vazias (indicadas por 0) de acordo com as
 * regras do Sudoku. Ela procura a próxima célula vazia, tenta preenchê-la com
 * os números de 1 a 9 e, para cada tentativa válida, chama a si mesma recursivamente.
 * Se uma chamada recursiva não leva a uma solução, ela desfaz a jogada (backtrack)
 * e tenta o próximo número.
 *
 * @param tabuleiro O tabuleiro de Sudoku a ser resolvido. Será modificado in-place
 * se uma solução for encontrada.
 * @return `true` se uma solução for encontrada, `false` caso contrário.
 *
 * @complexity
 * - Time: Exponencial, em torno de O(9^m), onde m é o número de células vazias.
 * A complexidade é alta, mas a poda da árvore de busca pelas regras do Sudoku
 * torna a execução prática para a maioria dos tabuleiros.
 * - Space: O(1), pois o tamanho do tabuleiro é fixo (9x9). A pilha de recursão
 * ocupa O(m) de espaço.
 */
bool resolver_sudoku(TabuleiroSudoku& tabuleiro);

#endif // RESOLVEDOR_SUDOKU_HPP