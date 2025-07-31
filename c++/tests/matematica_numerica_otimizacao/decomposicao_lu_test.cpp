#include <gtest/gtest.h>
#include "matematica_numerica_otimizacao/decomposicao_lu.hpp"
#include <cmath>

// --- Funções Auxiliares para os Testes ---

// Multiplica duas matrizes L e U
Matriz multiply_matrices(const Matriz& L, const Matriz& U) {
    int n = L.size();
    Matriz result(n, std::vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += L[i][k] * U[k][j];
            }
        }
    }
    return result;
}

// Compara duas matrizes com uma tolerância para erros de ponto flutuante
void assert_matrices_equal(const Matriz& A, const Matriz& B, double tol = 1e-9) {
    ASSERT_EQ(A.size(), B.size());
    for (size_t i = 0; i < A.size(); ++i) {
        ASSERT_EQ(A[i].size(), B[i].size());
        for (size_t j = 0; j < A[i].size(); ++j) {
            EXPECT_NEAR(A[i][j], B[i][j], tol);
        }
    }
}


// --- Suíte de Testes para a Decomposição LU ---
TEST(DecomposicaoLUTest, TesteMatrizSimples2x2) {
    Matriz A = {{4, 3}, {6, 3}};
    auto resultado = decomposicao_lu(A);
    Matriz produto_LU = multiply_matrices(resultado.L, resultado.U);
    assert_matrices_equal(A, produto_LU);
}

TEST(DecomposicaoLUTest, TesteMatriz3x3) {
    Matriz A = {{2, -1, -2}, 
                {-4, 6, 3}, 
                {-4, -2, 8}};

    Matriz L_esperada = {{1, 0, 0}, 
                         {-2, 1, 0}, 
                         {-2, -1, 1}};

    Matriz U_esperada = {{2, -1, -2}, 
                         {0, 4, -1}, 
                         {0, 0, 3}};
                         
    auto resultado = decomposicao_lu(A);
    
    assert_matrices_equal(L_esperada, resultado.L);
    assert_matrices_equal(U_esperada, resultado.U);

    Matriz produto_LU = multiply_matrices(resultado.L, resultado.U);
    assert_matrices_equal(A, produto_LU);
}

TEST(DecomposicaoLUTest, TesteMatrizNaoQuadrada) {
    Matriz A = {{1, 2, 3}, {4, 5, 6}};
    EXPECT_THROW(decomposicao_lu(A), std::invalid_argument);
}

TEST(DecomposicaoLUTest, TesteMatrizSingularSemPivoteamento) {
    // Esta matriz requer troca de linhas para ser decomposta,
    // então a nossa implementação simples deve falhar.
    Matriz A = {{0, 1}, {1, 1}};
    EXPECT_THROW(decomposicao_lu(A), std::runtime_error);
}

TEST(DecomposicaoLUTest, TesteMatrizIdentidade) {
    Matriz I = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    auto resultado = decomposicao_lu(I);
    
    // Para a identidade, L=I e U=I
    assert_matrices_equal(I, resultado.L);
    assert_matrices_equal(I, resultado.U);
}