#ifndef CRIVO_ERATOSTENES_HPP
#define CRIVO_ERATOSTENES_HPP

#include <vector>
#include <cmath>

/**
 * @file crivo_eratostenes.hpp
 * @brief Contém a implementação do Crivo de Eratóstenes para gerar números primos.
 */

/**
 * @brief Gera todos os números primos até um determinado limite usando o Crivo de Eratóstenes.
 *
 * O algoritmo funciona inicializando uma lista de todos os números de 2 até o limite como
 * potencialmente primos. Em seguida, ele itera a partir de 2 e, para cada número primo encontrado,
 * marca todos os seus múltiplos como não-primos. O processo continua até a raiz quadrada
 * do limite, pois qualquer número composto maior terá um fator primo menor ou igual a
 * esta raiz.
 *
 * @param limite O limite superior (inclusivo) para a geração de números primos.
 * @return Um std::vector<int> contendo todos os números primos de 2 até o limite em ordem crescente.
 *
 * @complexity
 * - Time: O(n log(log n)), onde n é o 'limite'. Esta é uma aproximação muito eficiente,
 * próxima de O(n).
 * - Space: O(n) para armazenar o array booleano que indica a primalidade de cada número.
 */
std::vector<int> crivo_eratostenes(int limite);

#endif // CRIVO_ERATOSTENES_HPP