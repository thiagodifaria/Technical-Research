#include <gtest/gtest.h>
#include "programacao_dinamica/mochila_01.hpp"

// Suíte de testes para o Problema da Mochila 0/1
TEST(Mochila01Test, TesteCasoSimples) {
    std::vector<Item> itens = {{1, 1}, {3, 4}, {4, 5}, {5, 7}};
    int capacidade = 7;
    // Solução ótima: itens {3, 4} e {4, 5} -> peso 7, valor 9
    EXPECT_EQ(mochila_01(capacidade, itens), 9);
}

TEST(Mochila01Test, TesteMochilaSemCapacidade) {
    std::vector<Item> itens = {{10, 60}, {20, 100}, {30, 120}};
    int capacidade = 0;
    EXPECT_EQ(mochila_01(capacidade, itens), 0);
}

TEST(Mochila01Test, TesteSemItens) {
    std::vector<Item> itens = {};
    int capacidade = 50;
    EXPECT_EQ(mochila_01(capacidade, itens), 0);
}

TEST(Mochila01Test, TesteTodosItensCabem) {
    std::vector<Item> itens = {{10, 60}, {20, 100}, {30, 120}};
    int capacidade = 100; // Suficiente para todos os itens (peso total 60)
    // O valor deve ser a soma de todos os valores
    EXPECT_EQ(mochila_01(capacidade, itens), 60 + 100 + 120);
}

TEST(Mochila01Test, TesteNenhumItemCabe) {
    std::vector<Item> itens = {{60, 100}, {70, 150}, {80, 200}};
    int capacidade = 50;
    EXPECT_EQ(mochila_01(capacidade, itens), 0);
}

TEST(Mochila01Test, TesteSolucaoNaoGulosa) {
    // Este é um caso clássico onde uma abordagem gulosa (ex: melhor razão valor/peso) falha.
    // Razões V/P: item1=6, item2=5, item3=4.
    // A abordagem gulosa pegaria o item 1 (10, 60) e o item 2 (20, 100) -> peso 30, valor 160.
    // A solução ótima é pegar o item 2 (20, 100) e o item 3 (30, 120) -> peso 50, valor 220.
    std::vector<Item> itens = {{10, 60}, {20, 100}, {30, 120}};
    int capacidade = 50;
    EXPECT_EQ(mochila_01(capacidade, itens), 220);
}