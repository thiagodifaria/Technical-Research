#include <gtest/gtest.h>
#include "matematica_numerica_otimizacao/teste_primalidade_miller_rabin.hpp"

// Suíte de testes para o Teste de Primalidade de Miller-Rabin
TEST(MillerRabinTest, TesteNumerosPequenosPrimos) {
    EXPECT_TRUE(is_prime_miller_rabin(2));
    EXPECT_TRUE(is_prime_miller_rabin(3));
    EXPECT_TRUE(is_prime_miller_rabin(5));
    EXPECT_TRUE(is_prime_miller_rabin(7));
    EXPECT_TRUE(is_prime_miller_rabin(11));
    EXPECT_TRUE(is_prime_miller_rabin(97));
}

TEST(MillerRabinTest, TesteNumerosPequenosCompostos) {
    EXPECT_FALSE(is_prime_miller_rabin(4));
    EXPECT_FALSE(is_prime_miller_rabin(6));
    EXPECT_FALSE(is_prime_miller_rabin(9));
    EXPECT_FALSE(is_prime_miller_rabin(15));
    EXPECT_FALSE(is_prime_miller_rabin(100));
}

TEST(MillerRabinTest, TesteCasosDeBorda) {
    EXPECT_FALSE(is_prime_miller_rabin(0));
    EXPECT_FALSE(is_prime_miller_rabin(1));
}

TEST(MillerRabinTest, TesteNumerosDeCarmichael) {
    // Números de Carmichael são compostos que enganam o teste de Fermat,
    // mas devem ser detectados como compostos pelo Miller-Rabin.
    EXPECT_FALSE(is_prime_miller_rabin(561));   // 3 * 11 * 17
    EXPECT_FALSE(is_prime_miller_rabin(1105));  // 5 * 13 * 17
    EXPECT_FALSE(is_prime_miller_rabin(1729));  // 7 * 13 * 19
}

TEST(MillerRabinTest, TestePrimosGrandes) {
    // Um primo de Mersenne
    EXPECT_TRUE(is_prime_miller_rabin(2147483647)); // 2^31 - 1
    // Outros primos grandes
    EXPECT_TRUE(is_prime_miller_rabin(1000000007));
    EXPECT_TRUE(is_prime_miller_rabin(999999999989LL)); // Um primo grande de 12 dígitos
}

TEST(MillerRabinTest, TesteCompostosGrandes) {
    EXPECT_FALSE(is_prime_miller_rabin(1000000007LL * 1000000009LL));
    EXPECT_FALSE(is_prime_miller_rabin(999999999989LL * 2));
    // Um pseudo-primo forte de base 2, mas composto
    EXPECT_FALSE(is_prime_miller_rabin(2047)); // 23 * 89
}