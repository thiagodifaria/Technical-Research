#include <gtest/gtest.h>
#include "manipulacao_strings/rabin_karp.hpp"

// Suíte de testes para o algoritmo Rabin-Karp
TEST(RabinKarpTest, TestePadraoNoInicio) {
    std::string texto = "ABCDEF";
    std::string padrao = "ABC";
    std::vector<int> esperados = {0};
    EXPECT_EQ(rabin_karp(texto, padrao), esperados);
}

TEST(RabinKarpTest, TestePadraoNoFinal) {
    std::string texto = "ABCDEF";
    std::string padrao = "DEF";
    std::vector<int> esperados = {3};
    EXPECT_EQ(rabin_karp(texto, padrao), esperados);
}

TEST(RabinKarpTest, TesteMultiplasOcorrencias) {
    std::string texto = "abracadabra";
    std::string padrao = "abra";
    std::vector<int> esperados = {0, 7};
    EXPECT_EQ(rabin_karp(texto, padrao), esperados);
}

TEST(RabinKarpTest, TesteOcorrenciasSobrepostas) {
    std::string texto = "aaaaa";
    std::string padrao = "aa";
    std::vector<int> esperados = {0, 1, 2, 3};
    EXPECT_EQ(rabin_karp(texto, padrao), esperados);
}

TEST(RabinKarpTest, TestePadraoInexistente) {
    std::string texto = "ABCDEF";
    std::string padrao = "XYZ";
    EXPECT_TRUE(rabin_karp(texto, padrao).empty());
}

TEST(RabinKarpTest, TestePadraoMaiorQueTexto) {
    std::string texto = "curto";
    std::string padrao = "textomaior";
    EXPECT_TRUE(rabin_karp(texto, padrao).empty());
}

TEST(RabinKarpTest, TesteDeBordaTextoOuPadraoVazio) {
    EXPECT_TRUE(rabin_karp("texto", "").empty());
    EXPECT_TRUE(rabin_karp("", "padrao").empty());
    EXPECT_TRUE(rabin_karp("", "").empty());
}

TEST(RabinKarpTest, TesteCasoComplexo) {
    // Um texto mais longo para verificar robustez
    std::string texto = "AABRAACADABRAACAADABRA";
    std::string padrao = "ACAAD";
    std::vector<int> esperados = {13};
    EXPECT_EQ(rabin_karp(texto, padrao), esperados);
}