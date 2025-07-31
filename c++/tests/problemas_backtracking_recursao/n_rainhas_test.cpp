#include <gtest/gtest.h>
#include "problemas_backtracking_recursao/n_rainhas.hpp"
#include <algorithm>

// Função auxiliar para normalizar a saída para testes estáveis,
// ordenando as soluções encontradas.
void normalizar_solucoes(std::vector<std::vector<std::string>>& solucoes) {
    std::sort(solucoes.begin(), solucoes.end());
}

// Suíte de testes para o problema das N-Rainhas
TEST(NQueensTest, TesteN1) {
    auto solucoes = resolver_n_rainhas(1);
    std::vector<std::vector<std::string>> esperado = {{"Q"}};
    EXPECT_EQ(solucoes, esperado);
    EXPECT_EQ(solucoes.size(), 1);
}

TEST(NQueensTest, TesteN2) {
    // Não há solução para N=2
    auto solucoes = resolver_n_rainhas(2);
    EXPECT_TRUE(solucoes.empty());
    EXPECT_EQ(solucoes.size(), 0);
}

TEST(NQueensTest, TesteN3) {
    // Não há solução para N=3
    auto solucoes = resolver_n_rainhas(3);
    EXPECT_TRUE(solucoes.empty());
    EXPECT_EQ(solucoes.size(), 0);
}

TEST(NQueensTest, TesteN4) {
    // Existem 2 soluções para N=4
    auto solucoes = resolver_n_rainhas(4);
    normalizar_solucoes(solucoes);

    std::vector<std::vector<std::string>> esperado = {
        {".Q..",
         "...Q",
         "Q...",
         "..Q."},
        {"..Q.",
         "Q...",
         "...Q",
         ".Q.."}
    };
    normalizar_solucoes(esperado);
    
    EXPECT_EQ(solucoes.size(), 2);
    EXPECT_EQ(solucoes, esperado);
}

TEST(NQueensTest, TesteN8) {
    // Para N=8 (tabuleiro de xadrez padrão), existem 92 soluções.
    // Verificar todas seria impraticável, então verificamos apenas a contagem.
    auto solucoes = resolver_n_rainhas(8);
    EXPECT_EQ(solucoes.size(), 92);
}

TEST(NQueensTest, TesteBordaN0) {
    auto solucoes = resolver_n_rainhas(0);
    EXPECT_TRUE(solucoes.empty());
}