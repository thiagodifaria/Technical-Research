#include <gtest/gtest.h>
#include "matematica_numerica_otimizacao/mdc_euclides.hpp"

// Suíte de testes para o Algoritmo de Euclides (MDC)
TEST(MDCEuclidesTest, TesteComNumerosPrimosEntreSi) {
    // Dois números primos entre si devem ter MDC = 1
    EXPECT_EQ(mdc_euclides(17, 13), 1);
    EXPECT_EQ(mdc_euclides(35, 88), 1); // 35 = 5*7, 88 = 8*11
}

TEST(MDCEuclidesTest, TesteComMultiplo) {
    // Se um número é múltiplo do outro, o MDC é o menor número
    EXPECT_EQ(mdc_euclides(60, 12), 12);
    EXPECT_EQ(mdc_euclides(12, 60), 12); // Testa a ordem inversa
}

TEST(MDCEuclidesTest, TesteComCasoComum) {
    // Um caso de teste padrão
    EXPECT_EQ(mdc_euclides(54, 24), 6);
    EXPECT_EQ(mdc_euclides(1071, 462), 21);
}

TEST(MDCEuclidesTest, TesteComZero) {
    // O MDC de um número 'n' e 0 é |n|
    EXPECT_EQ(mdc_euclides(42, 0), 42);
    EXPECT_EQ(mdc_euclides(0, 42), 42);
    EXPECT_EQ(mdc_euclides(0, 0), 0); // Caso especial
}

TEST(MDCEuclidesTest, TesteComNumerosNegativos) {
    // O MDC deve ser o mesmo para os valores absolutos
    EXPECT_EQ(mdc_euclides(-54, 24), 6);
    EXPECT_EQ(mdc_euclides(54, -24), 6);
    EXPECT_EQ(mdc_euclides(-54, -24), 6);
}

TEST(MDCEuclidesTest, TesteComNumerosGrandes) {
    // Verifica o tratamento de 'long long'
    long long p = 123456789LL;
    long long a = 15 * p; // ...1851851835
    long long b = 25 * p; // ...3086419725
    
    // MDC(15*p, 25*p) deve ser 5*p
    EXPECT_EQ(mdc_euclides(a, b), 5 * p);
    
    // Outro caso grande
    EXPECT_EQ(mdc_euclides(3921920LL, 1654560LL), 61280LL);
}