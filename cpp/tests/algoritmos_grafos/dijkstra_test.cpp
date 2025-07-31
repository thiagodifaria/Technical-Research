#include <gtest/gtest.h>
#include "algoritmos_grafos/dijkstra.hpp"

// Suíte de testes para o Algoritmo de Dijkstra
TEST(DijkstraTest, TesteGrafoSimples) {
    int V = 5;
    GrafoPonderado grafo(V);
    grafo[0].push_back({1, 10});
    grafo[0].push_back({2, 3});
    grafo[1].push_back({3, 2});
    grafo[2].push_back({1, 4});
    grafo[2].push_back({3, 8});
    grafo[2].push_back({4, 2});
    grafo[3].push_back({4, 5});

    int origem = 0;
    std::vector<long long> distancias = dijkstra(grafo, origem);
    
    std::vector<long long> esperadas = {0, 7, 3, 9, 5};
    EXPECT_EQ(distancias, esperadas);
}

TEST(DijkstraTest, TesteVerticeInacessivel) {
    int V = 4;
    GrafoPonderado grafo(V);
    grafo[0].push_back({1, 1});
    grafo[1].push_back({0, 2}); // Grafo com 0 e 1 conectados
    // Vértices 2 e 3 estão isolados

    int origem = 0;
    const long long INF = std::numeric_limits<long long>::max();
    std::vector<long long> distancias = dijkstra(grafo, origem);

    std::vector<long long> esperadas = {0, 1, INF, INF};
    EXPECT_EQ(distancias, esperadas);
}

TEST(DijkstraTest, TesteCaminhoNaoDireto) {
    int V = 3;
    GrafoPonderado grafo(V);
    grafo[0].push_back({1, 10}); // Caminho direto A->B com peso 10
    grafo[0].push_back({2, 2});  // Caminho A->C com peso 2
    grafo[2].push_back({1, 3});  // Caminho C->B com peso 3

    int origem = 0;
    // O caminho mais curto de 0 para 1 é 0->2->1 com custo 2+3=5
    std::vector<long long> distancias = dijkstra(grafo, origem);
    
    std::vector<long long> esperadas = {0, 5, 2};
    EXPECT_EQ(distancias, esperadas);
}

TEST(DijkstraTest, TesteGrafoCiclico) {
    int V = 4;
    GrafoPonderado grafo(V);
    grafo[0].push_back({1, 1});
    grafo[1].push_back({2, 2});
    grafo[2].push_back({3, 3});
    grafo[2].push_back({1, 1}); // Aresta de volta, criando um ciclo 1-2

    int origem = 0;
    std::vector<long long> distancias = dijkstra(grafo, origem);
    
    std::vector<long long> esperadas = {0, 1, 3, 6};
    EXPECT_EQ(distancias, esperadas);
}

TEST(DijkstraTest, TesteOrigemSemSaida) {
    int V = 3;
    GrafoPonderado grafo(V);
    // Vértice 0 (origem) não tem arestas de saída
    grafo[1].push_back({2, 5});
    
    int origem = 0;
    const long long INF = std::numeric_limits<long long>::max();
    std::vector<long long> distancias = dijkstra(grafo, origem);

    std::vector<long long> esperadas = {0, INF, INF};
    EXPECT_EQ(distancias, esperadas);
}

TEST(DijkstraTest, TesteGrafoVazio) {
    GrafoPonderado grafo(0);
    EXPECT_TRUE(dijkstra(grafo, 0).empty());
}