#include <gtest/gtest.h>
#include "matematica_numerica_otimizacao/crivo_eratostenes.hpp"

// Suíte de testes para o Crivo de Eratóstenes
TEST(CrivoEratostenesTest, TesteComLimitePequeno) {
    std::vector<int> esperados = {2, 3, 5, 7};
    EXPECT_EQ(crivo_eratostenes(10), esperados);
}

TEST(CrivoEratostenesTest, TesteComLimitePrimo) {
    // O próprio limite (13) é um número primo e deve ser incluído.
    std::vector<int> esperados = {2, 3, 5, 7, 11, 13};
    EXPECT_EQ(crivo_eratostenes(13), esperados);
}

TEST(CrivoEratostenesTest, TesteDeBordaLimiteInferior) {
    // Limites abaixo de 2 não devem retornar nenhum primo.
    EXPECT_TRUE(crivo_eratostenes(0).empty());
    EXPECT_TRUE(crivo_eratostenes(1).empty());

    // Limite 2 deve retornar apenas o primo 2.
    std::vector<int> esperados = {2};
    EXPECT_EQ(crivo_eratostenes(2), esperados);
}

TEST(CrivoEratostenesTest, TesteComLimiteModerado) {
    // É conhecido que existem 25 números primos até 100.
    // O primeiro é 2 e o último é 97.
    auto primos = crivo_eratostenes(100);
    
    EXPECT_EQ(primos.size(), 25);
    EXPECT_EQ(primos.front(), 2);
    EXPECT_EQ(primos.back(), 97);
}

TEST(CrivoEratostenesTest, TesteComLimiteNaoPrimo) {
    // Testa um limite que não é primo para garantir que ele não seja incluído.
    // Primos até 20: 2, 3, 5, 7, 11, 13, 17, 19
    std::vector<int> esperados = {2, 3, 5, 7, 11, 13, 17, 19};
    EXPECT_EQ(crivo_eratostenes(20), esperados);
}