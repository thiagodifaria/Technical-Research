#include "algoritmos_grafos/componentes_fortemente_conexos.hpp"
#include <stack>
#include <algorithm> // Para std::min

class TarjanSCCFinder {
private:
    const Grafo& grafo;
    int V;
    int tempo;
    std::vector<int> tempos_descoberta;
    std::vector<int> low_link;
    std::vector<bool> na_pilha;
    std::stack<int> pilha;
    std::vector<std::vector<int>> sccs;

    void dfs(int u) {
        tempos_descoberta[u] = low_link[u] = tempo++;
        pilha.push(u);
        na_pilha[u] = true;

        for (int v : grafo[u]) {
            if (tempos_descoberta[v] == -1) { // Vértice v ainda não visitado
                dfs(v);
                low_link[u] = std::min(low_link[u], low_link[v]);
            } else if (na_pilha[v]) { // Vértice v está na pilha (back-edge)
                low_link[u] = std::min(low_link[u], tempos_descoberta[v]);
            }
        }

        // Se u é a raiz de um SCC
        if (low_link[u] == tempos_descoberta[u]) {
            std::vector<int> scc_atual;
            while (true) {
                int vertice = pilha.top();
                pilha.pop();
                na_pilha[vertice] = false;
                scc_atual.push_back(vertice);
                if (u == vertice) break;
            }
            sccs.push_back(scc_atual);
        }
    }

public:
    explicit TarjanSCCFinder(const Grafo& g) : grafo(g) {
        V = grafo.size();
        tempo = 0;
        tempos_descoberta.assign(V, -1);
        low_link.assign(V, -1);
        na_pilha.assign(V, false);
    }

    std::vector<std::vector<int>> encontrar_sccs() {
        for (int i = 0; i < V; ++i) {
            if (tempos_descoberta[i] == -1) {
                dfs(i);
            }
        }
        return sccs;
    }
};

std::vector<std::vector<int>> encontrar_sccs_tarjan(const Grafo& grafo) {
    if (grafo.empty()) return {};
    TarjanSCCFinder finder(grafo);
    return finder.encontrar_sccs();
}