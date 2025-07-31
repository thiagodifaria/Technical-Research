#include <gtest/gtest.h>
#include "matematica_numerica_otimizacao/fft.hpp"

// Suíte de testes para a Transformada Rápida de Fourier (via multiplicação de polinômios)
TEST(FFTTest, TesteSimples) {
    // (1 + 2x) * (3 + 4x) = 3 + 10x + 8x^2
    std::vector<long long> a = {1, 2};
    std::vector<long long> b = {3, 4};
    std::vector<long long> esperado = {3, 10, 8};
    EXPECT_EQ(multiply_polynomials(a, b), esperado);
}

TEST(FFTTest, TestePolinomioZero) {
    std::vector<long long> a = {5, 0, 10, 6};
    std::vector<long long> b = {0};
    std::vector<long long> esperado = {0};
    EXPECT_EQ(multiply_polynomials(a, b), esperado);
}

TEST(FFTTest, TestePolinomioIdentidade) {
    std::vector<long long> a = {10, 20, 30};
    std::vector<long long> b = {1};
    std::vector<long long> esperado = {10, 20, 30};
    EXPECT_EQ(multiply_polynomials(a, b), esperado);
}

TEST(FFTTest, TesteGrausDiferentes) {
    // (1 + x + x^2) * (2 + x) = 2 + 3x + 3x^2 + x^3
    std::vector<long long> a = {1, 1, 1};
    std::vector<long long> b = {2, 1};
    std::vector<long long> esperado = {2, 3, 3, 1};
    EXPECT_EQ(multiply_polynomials(a, b), esperado);
}

TEST(FFTTest, TesteCoeficientesGrandesEZero) {
    // (50 + 10x^3) * (20 + 2x^2) = 1000 + 100x^2 + 200x^3 + 20x^5
    std::vector<long long> a = {50, 0, 0, 10};
    std::vector<long long> b = {20, 0, 2};
    std::vector<long long> esperado = {1000, 0, 100, 200, 0, 20};
    EXPECT_EQ(multiply_polynomials(a, b), esperado);
}