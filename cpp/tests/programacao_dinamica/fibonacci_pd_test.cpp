#include <gtest/gtest.h>
#include "programacao_dinamica/fibonacci_pd.hpp"

// Suíte de testes para as implementações de Fibonacci com PD
// --- Testes para a versão com Memoização ---
TEST(FibonacciPDTest, MemoizationCasosBase) { EXPECT_EQ(fibonacci_memo(0), 0); EXPECT_EQ(fibonacci_memo(1), 1); }
TEST(FibonacciPDTest, MemoizationNumerosPequenos) { EXPECT_EQ(fibonacci_memo(10), 55); }
TEST(FibonacciPDTest, MemoizationNumerosMaiores) { EXPECT_EQ(fibonacci_memo(40), 102334155); }
TEST(FibonacciPDTest, MemoizationLimiteDoLongLong) { EXPECT_EQ(fibonacci_memo(92), 7540113804746346429LL); }
TEST(FibonacciPDTest, MemoizationEntradaInvalida) { EXPECT_THROW(fibonacci_memo(-1), std::invalid_argument); }
TEST(FibonacciPDTest, MemoizationEstouroDeCapacidade) { EXPECT_THROW(fibonacci_memo(93), std::overflow_error); }

// --- Testes para a versão com Tabulação ---
TEST(FibonacciPDTest, TabulationCasosBase) { EXPECT_EQ(fibonacci_tab(0), 0); EXPECT_EQ(fibonacci_tab(1), 1); }
TEST(FibonacciPDTest, TabulationNumerosPequenos) { EXPECT_EQ(fibonacci_tab(10), 55); }
TEST(FibonacciPDTest, TabulationNumerosMaiores) { EXPECT_EQ(fibonacci_tab(40), 102334155); }
TEST(FibonacciPDTest, TabulationLimiteDoLongLong) { EXPECT_EQ(fibonacci_tab(92), 7540113804746346429LL); }
TEST(FibonacciPDTest, TabulationEntradaInvalida) { EXPECT_THROW(fibonacci_tab(-5), std::invalid_argument); }
TEST(FibonacciPDTest, TabulationEstouroDeCapacidade) { EXPECT_THROW(fibonacci_tab(93), std::overflow_error); }

// --- Novos Testes para a versão com Exponenciação de Matrizes ---
TEST(FibonacciPDTest, MatrixCasosBase) {
    EXPECT_EQ(fibonacci_matrix(0), 0);
    EXPECT_EQ(fibonacci_matrix(1), 1);
}

TEST(FibonacciPDTest, MatrixNumerosPequenos) {
    EXPECT_EQ(fibonacci_matrix(2), 1);
    EXPECT_EQ(fibonacci_matrix(5), 5);
    EXPECT_EQ(fibonacci_matrix(10), 55);
}

TEST(FibonacciPDTest, MatrixNumerosMaiores) {
    EXPECT_EQ(fibonacci_matrix(20), 6765);
    EXPECT_EQ(fibonacci_matrix(40), 102334155);
}

TEST(FibonacciPDTest, MatrixLimiteDoLongLong) {
    // O resultado deve ser idêntico às outras versões
    EXPECT_EQ(fibonacci_matrix(92), 7540113804746346429LL);
}

TEST(FibonacciPDTest, MatrixEntradaInvalida) {
    // Testa se lança a mesma exceção para n negativo
    EXPECT_THROW(fibonacci_matrix(-10), std::invalid_argument);
}

TEST(FibonacciPDTest, MatrixEstouroDeCapacidade) {
    // Testa se lança a mesma exceção para n > 92
    EXPECT_THROW(fibonacci_matrix(93), std::overflow_error);
}