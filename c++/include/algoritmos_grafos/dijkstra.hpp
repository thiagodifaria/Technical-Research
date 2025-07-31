#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <vector>
#include <queue>
#include <limits> // Para std::numeric_limits

/**
 * @file dijkstra.hpp
 * @brief Contém a implementação do Algoritmo de Dijkstra para o problema do caminho mais curto.
 */

// Apelido para representar um par {vértice_destino, peso_aresta}
using ArestaPonderada = std::pair<int, int>;
// Apelido para o grafo (lista de adjacência)
using GrafoPonderado = std::vector<std::vector<ArestaPonderada>>;

/**
 * @brief Encontra os caminhos mais curtos de um único vértice de origem para todos os outros
 * vértices em um grafo ponderado, utilizando o Algoritmo de Dijkstra.
 *
 * O algoritmo funciona mantendo um conjunto de vértices cujas distâncias mínimas da origem
 * já foram finalizadas. A cada passo, ele seleciona o vértice `u` que ainda não foi
 * finalizado e que tem a menor distância conhecida da origem. Para cada vizinho `v` de `u`,
 * ele "relaxa" a aresta, ou seja, verifica se o caminho para `v` através de `u` é mais
 * curto do que o caminho conhecido anteriormente para `v`.
 *
 * Esta implementação utiliza uma fila de prioridade (min-heap) para obter uma performance eficiente.
 *
 * @warning O algoritmo de Dijkstra só funciona corretamente para grafos com **pesos de aresta não-negativos**.
 *
 * @param grafo O grafo, representado como uma lista de adjacência. `grafo[u]` contém um
 * vetor de pares `{v, w}`, indicando uma aresta de `u` para `v` com peso `w`.
 * @param origem O índice do vértice de partida (0-indexado).
 * @return Um `std::vector<long long>` onde o elemento no índice `i` representa a menor
 * distância da `origem` até o vértice `i`. Se um vértice for inacessível, a distância
 * será o valor máximo de `long long`.
 *
 * @complexity
 * - Time: O(E log V), onde E é o número de arestas e V é o número de vértices.
 * - Space: O(V + E), para armazenar o grafo, o vetor de distâncias e a fila de prioridade.
 */
std::vector<long long> dijkstra(const GrafoPonderado& grafo, int origem);

#endif // DIJKSTRA_HPP