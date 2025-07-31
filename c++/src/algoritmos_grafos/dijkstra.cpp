#include "algoritmos_grafos/dijkstra.hpp"

std::vector<long long> dijkstra(const GrafoPonderado& grafo, int origem) {
    int V = grafo.size();
    if (V == 0) return {};

    const long long INF = std::numeric_limits<long long>::max();
    std::vector<long long> dist(V, INF);

    // Fila de prioridade (min-heap) para armazenar pares {distância, vértice}
    // std::greater torna a fila uma min-heap.
    using ParDistVertice = std::pair<long long, int>;
    std::priority_queue<ParDistVertice, std::vector<ParDistVertice>, std::greater<ParDistVertice>> pq;

    // Inicializa a distância da origem como 0 e a insere na fila.
    dist[origem] = 0;
    pq.push({0, origem});

    while (!pq.empty()) {
        // Extrai o vértice com a menor distância da fila.
        long long d_u = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Otimização: se já encontramos um caminho mais curto para 'u', ignoramos.
        if (d_u > dist[u]) {
            continue;
        }

        // Itera sobre todos os vizinhos 'v' de 'u'.
        for (const auto& aresta : grafo[u]) {
            int v = aresta.first;
            int peso = aresta.second;

            // Relaxamento da aresta: se um caminho mais curto para 'v' for encontrado...
            if (dist[u] + peso < dist[v]) {
                // ...atualiza a distância e insere na fila.
                dist[v] = dist[u] + peso;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}