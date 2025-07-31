#ifndef COMPONENTES_FORTEMENTE_CONEXOS_HPP
#define COMPONENTES_FORTEMENTE_CONEXOS_HPP

#include <vector>

/**
 * @file componentes_fortemente_conexos.hpp
 * @brief Contém a implementação do Algoritmo de Tarjan para encontrar Componentes Fortemente Conexos (SCCs).
 */

// Apelido para o grafo não ponderado (lista de adjacência)
using Grafo = std::vector<std::vector<int>>;

/**
 * @brief Encontra todos os Componentes Fortemente Conexos (SCCs) em um grafo direcionado
 * usando o Algoritmo de Tarjan.
 *
 * O algoritmo realiza uma única busca em profundidade (DFS) no grafo. Ele mantém dois valores
 * por vértice: um tempo de descoberta e um "low-link" (o menor tempo de descoberta
 * alcançável a partir do vértice). Um vértice é a raiz de um SCC se seu valor de low-link
 * for igual ao seu tempo de descoberta. Os SCCs são então extraídos de uma pilha auxiliar.
 *
 * @param grafo O grafo direcionado, representado como uma lista de adjacência.
 * @return Um `std::vector<std::vector<int>>`, onde cada vetor interno é um SCC.
 * A ordem dos SCCs e a ordem dos vértices dentro de cada SCC não são garantidas.
 *
 * @complexity
 * - Time: O(V + E), onde V é o número de vértices e E o número de arestas.
 * - Space: O(V), para armazenar os vetores auxiliares e a pilha da DFS.
 */
std::vector<std::vector<int>> encontrar_sccs_tarjan(const Grafo& grafo);

#endif // COMPONENTES_FORTEMENTE_CONEXOS_HPP