#ifndef MOCHILA_01_HPP
#define MOCHILA_01_HPP

#include <vector>
#include <algorithm> // Para std::max

/**
 * @file mochila_01.hpp
 * @brief Contém a solução para o Problema da Mochila 0/1 usando programação dinâmica.
 */

/**
 * @struct Item
 * @brief Representa um item com um peso e um valor definidos.
 */
struct Item {
    int peso;
    int valor;
};

/**
 * @brief Resolve o Problema da Mochila 0/1.
 *
 * Dado um conjunto de itens, cada um com um peso e um valor, determina o número de cada item
 * a incluir em uma coleção para que o peso total seja menor ou igual a uma dada capacidade
 * e o valor total seja o maior possível. No caso "0/1", para cada item, há duas opções:
 * ou o item é incluído na mochila, ou não é. Não é possível incluir uma fração de um item.
 *
 * A solução utiliza uma abordagem de programação dinâmica bottom-up, construindo uma tabela
 * `dp[i][c]` que armazena o valor máximo que pode ser obtido usando os primeiros `i` itens
 * com uma capacidade de mochila de `c`.
 *
 * @param capacidade A capacidade máxima de peso da mochila.
 * @param itens Um `std::vector` de `Item`, contendo os itens disponíveis.
 * @return O valor máximo que pode ser colocado na mochila.
 *
 * @complexity
 * - Time: O(N * C), onde N é o número de itens e C é a capacidade da mochila.
 * - Space: O(N * C) para a tabela de programação dinâmica. (Pode ser otimizado para O(C)).
 */
int mochila_01(int capacidade, const std::vector<Item>& itens);

#endif // MOCHILA_01_HPP