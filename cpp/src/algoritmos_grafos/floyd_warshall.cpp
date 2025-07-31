#include "algoritmos_grafos/floyd_warshall.hpp"

MatrizAdjacencia floyd_warshall(const MatrizAdjacencia& grafo) {
    if (grafo.empty()) {
        return {};
    }

    int V = grafo.size();
    // Cria uma cópia da matriz de adjacência para trabalhar.
    MatrizAdjacencia dist = grafo;

    // O algoritmo principal com três laços aninhados.
    // k -> vértice intermediário
    // i -> vértice de origem
    // j -> vértice de destino
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                // Se o caminho i->k e k->j existem (não são infinitos)
                // e se o caminho através de k é mais curto que o caminho direto i->j
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    // Opcional: Detecção de ciclo negativo.
    // Se a distância de um nó para ele mesmo se torna negativa,
    // significa que ele faz parte de um ciclo de peso negativo.
    for (int i = 0; i < V; ++i) {
        if (dist[i][i] < 0) {
            // Poderia lançar uma exceção ou apenas retornar a matriz
            // com os valores negativos na diagonal como um indicador.
            // Para este projeto, retornamos a matriz como está.
        }
    }

    return dist;
}