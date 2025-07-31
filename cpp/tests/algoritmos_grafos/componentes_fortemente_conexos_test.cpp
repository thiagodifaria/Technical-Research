#include <gtest/gtest.h>
#include "algoritmos_grafos/componentes_fortemente_conexos.hpp"
#include <algorithm>

// Função auxiliar para normalizar a saída para testes estáveis.
// Ordena os vértices dentro de cada SCC e depois ordena os SCCs entre si.
void normalizar_sccs(std::vector<std::vector<int>>& sccs) {
    for (auto& scc : sccs) {
        std::sort(scc.begin(), scc.end());
    }
    std::sort(sccs.begin(), sccs.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a.front() < b.front();
    });
}

// Suíte de testes para o Algoritmo de Tarjan
TEST(TarjanSCCTest, TesteGrafoSimplesComMultiplosSCCs) {
    int V = 8;
    Grafo grafo(V);
    grafo[0].push_back(1);
    grafo[1].push_back(2);
    grafo[2].push_back(0); // SCC {0, 1, 2}
    grafo[3].push_back(1);
    grafo[3].push_back(4);
    grafo[4].push_back(5);
    grafo[5].push_back(3); // SCC {3, 4, 5}
    grafo[6].push_back(5);
    grafo[6].push_back(7); // SCC {6} e {7}
    
    auto resultado = encontrar_sccs_tarjan(grafo);
    normalizar_sccs(resultado);

    std::vector<std::vector<int>> esperado = {{0, 1, 2}, {3, 4, 5}, {6}, {7}};
    normalizar_sccs(esperado);

    EXPECT_EQ(resultado, esperado);
}

TEST(TarjanSCCTest, TesteGrafoFortementeConexo) {
    // Um ciclo simples onde todos os vértices formam um único SCC
    int V = 4;
    Grafo grafo(V);
    grafo[0].push_back(1);
    grafo[1].push_back(2);
    grafo[2].push_back(3);
    grafo[3].push_back(0);

    auto resultado = encontrar_sccs_tarjan(grafo);
    normalizar_sccs(resultado);

    std::vector<std::vector<int>> esperado = {{0, 1, 2, 3}};
    normalizar_sccs(esperado);

    EXPECT_EQ(resultado, esperado);
}

TEST(TarjanSCCTest, TesteGrafoAciclicoDirecionado) {
    // Em um DAG, cada vértice é seu próprio SCC
    int V = 4;
    Grafo grafo(V);
    grafo[0].push_back(1);
    grafo[1].push_back(2);
    grafo[2].push_back(3);

    auto resultado = encontrar_sccs_tarjan(grafo);
    normalizar_sccs(resultado);

    std::vector<std::vector<int>> esperado = {{0}, {1}, {2}, {3}};
    normalizar_sccs(esperado);

    EXPECT_EQ(resultado, esperado);
}

TEST(TarjanSCCTest, TesteGrafoDesconectado) {
    int V = 5;
    Grafo grafo(V);
    grafo[0].push_back(1);
    grafo[1].push_back(0); // SCC {0, 1}
    // Vértice 2 está isolado -> SCC {2}
    grafo[3].push_back(4); // SCC {3}, {4} pois é um DAG

    auto resultado = encontrar_sccs_tarjan(grafo);
    normalizar_sccs(resultado);

    std::vector<std::vector<int>> esperado = {{0, 1}, {2}, {3}, {4}};
    normalizar_sccs(esperado);

    EXPECT_EQ(resultado, esperado);
}

TEST(TarjanSCCTest, TesteGrafoVazioOuComUmVertice) {
    Grafo grafo_vazio(0);
    EXPECT_TRUE(encontrar_sccs_tarjan(grafo_vazio).empty());
    
    Grafo grafo_um_vertice(1);
    std::vector<std::vector<int>> esperado_um_vertice = {{0}};
    EXPECT_EQ(encontrar_sccs_tarjan(grafo_um_vertice), esperado_um_vertice);
}