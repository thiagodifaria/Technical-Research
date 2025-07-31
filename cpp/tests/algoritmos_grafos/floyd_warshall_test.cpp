#include <gtest/gtest.h>
#include "algoritmos_grafos/floyd_warshall.hpp"

// Suíte de testes para o Algoritmo de Floyd-Warshall
TEST(FloydWarshallTest, TesteGrafoSimples) {
    int V = 4;
    MatrizAdjacencia grafo = {
        {0,   5,   INF, 10},
        {INF, 0,   3,   INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    MatrizAdjacencia esperada = {
        {0, 5, 8, 9},
        {INF, 0, 3, 4},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    MatrizAdjacencia resultado = floyd_warshall(grafo);
    EXPECT_EQ(resultado, esperada);
}

TEST(FloydWarshallTest, TesteGrafoComPesosNegativos) {
    int V = 4;
    MatrizAdjacencia grafo = {
        {0,   -1,  4,   INF},
        {INF, 0,   3,   2},
        {INF, INF, 0,   INF},
        {INF, -2,  INF, 0}
    };

    MatrizAdjacencia esperada = {
        {0, -1, 2, 1},
        {INF, 0, 3, 2},
        {INF, INF, 0, INF},
        {INF, -2, 1, 0}
    };
    
    MatrizAdjacencia resultado = floyd_warshall(grafo);
    EXPECT_EQ(resultado, esperada);
}

TEST(FloydWarshallTest, TesteGrafoDesconectado) {
    int V = 4;
    MatrizAdjacencia grafo = {
        {0, 1, INF, INF},
        {1, 0, INF, INF},
        {INF, INF, 0, 2},
        {INF, INF, 2, 0}
    };

    // O resultado deve manter as distâncias INF entre os componentes
    MatrizAdjacencia esperada = {
        {0, 1, INF, INF},
        {1, 0, INF, INF},
        {INF, INF, 0, 2},
        {INF, INF, 2, 0}
    };
    
    MatrizAdjacencia resultado = floyd_warshall(grafo);
    EXPECT_EQ(resultado, esperada);
}

TEST(FloydWarshallTest, TesteGrafoComCicloNegativo) {
    int V = 3;
    MatrizAdjacencia grafo = {
        {0,   1,   INF},
        {INF, 0,   -1},
        {INF, -1,  0}
    };

    MatrizAdjacencia resultado = floyd_warshall(grafo);
    // Vértices 1 e 2 estão em um ciclo negativo (1 -> 2 -> 1, peso total -2)
    // As distâncias de/para eles podem ser infinitamente pequenas.
    // O algoritmo detecta isso fazendo com que dist[i][i] < 0.
    EXPECT_LT(resultado[1][1], 0);
    EXPECT_LT(resultado[2][2], 0);
    EXPECT_EQ(resultado[0][0], 0); // 0 não está no ciclo
}

TEST(FloydWarshallTest, TesteGrafoVazio) {
    MatrizAdjacencia grafo(0);
    EXPECT_TRUE(floyd_warshall(grafo).empty());
}