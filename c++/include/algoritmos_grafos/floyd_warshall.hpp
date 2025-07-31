#ifndef FLOYD_WARSHALL_HPP
#define FLOYD_WARSHALL_HPP

#include <vector>
#include <limits> // Para std::numeric_limits

/**
 * @file floyd_warshall.hpp
 * @brief Contém a implementação do Algoritmo de Floyd-Warshall para o problema do caminho mais curto entre todos os pares.
 */

// Apelido para a matriz de adjacência/distâncias.
using MatrizAdjacencia = std::vector<std::vector<long long>>;

// Constante para representar a ausência de uma aresta (infinito).
const long long INF = std::numeric_limits<long long>::max();

/**
 * @brief Encontra os caminhos mais curtos entre todos os pares de vértices em um grafo
 * ponderado, utilizando o Algoritmo de Floyd-Warshall.
 *
 * O algoritmo é um exemplo de programação dinâmica que, para cada par de vértices (i, j),
 * considera se o caminho de i para j pode ser encurtado ao passar por um vértice intermediário k.
 * Ele itera sobre todos os possíveis vértices intermediários para todos os pares de vértices.
 *
 * A função opera sobre uma matriz de adjacência, onde `grafo[i][j]` contém o peso da
 * aresta de i para j, ou `INF` se não houver uma aresta direta.
 *
 * A implementação também permite a detecção de ciclos negativos. Se, após a execução,
 * qualquer elemento da diagonal `dist[i][i]` for negativo, um ciclo negativo existe.
 *
 * @param grafo O grafo, representado como uma matriz de adjacência de V x V.
 * @return Uma matriz de V x V onde o elemento `[i][j]` contém a menor
 * distância do vértice `i` até o vértice `j`.
 *
 * @complexity
 * - Time: O(V^3), onde V é o número de vértices.
 * - Space: O(V^2), para armazenar a matriz de distâncias.
 */
MatrizAdjacencia floyd_warshall(const MatrizAdjacencia& grafo);

#endif // FLOYD_WARSHALL_HPP