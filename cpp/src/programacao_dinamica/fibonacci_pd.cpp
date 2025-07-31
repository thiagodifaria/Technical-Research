#include "programacao_dinamica/fibonacci_pd.hpp"

// --- Implementação da Memoização (Top-Down) ---
long long fib_memo_helper(int n, std::vector<long long>& memo) {
    if (memo[n] != -1) return memo[n];
    memo[n] = fib_memo_helper(n - 1, memo) + fib_memo_helper(n - 2, memo);
    return memo[n];
}

long long fibonacci_memo(int n) {
    if (n < 0) throw std::invalid_argument("Fibonacci não é definido para números negativos.");
    if (n > 92) throw std::overflow_error("O resultado para n > 92 excede a capacidade de um long long.");
    if (n <= 1) return n;
    std::vector<long long> memo(n + 1, -1);
    memo[0] = 0;
    memo[1] = 1;
    return fib_memo_helper(n, memo);
}

// --- Implementação da Tabulação (Bottom-Up) ---
long long fibonacci_tab(int n) {
    if (n < 0) throw std::invalid_argument("Fibonacci não é definido para números negativos.");
    if (n > 92) throw std::overflow_error("O resultado para n > 92 excede a capacidade de um long long.");
    if (n <= 1) return n;
    std::vector<long long> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// --- Nova Implementação com Exponenciação de Matrizes ---

// Função auxiliar para multiplicar duas matrizes 2x2: F e M.
// O resultado é armazenado em F.
void multiply(long long F[2][2], long long M[2][2]) {
    long long x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    long long y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    long long z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    long long w = F[1][0] * M[0][1] + F[1][1] * M[1][1];
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

// Função auxiliar para calcular F^n em tempo O(log n)
void power(long long F[2][2], int n) {
    if (n == 0 || n == 1) return;
    long long M[2][2] = {{1, 1}, {1, 0}};

    power(F, n / 2);
    multiply(F, F);

    if (n % 2 != 0) {
        multiply(F, M);
    }
}

long long fibonacci_matrix(int n) {
    if (n < 0) throw std::invalid_argument("Fibonacci não é definido para números negativos.");
    if (n > 92) throw std::overflow_error("O resultado para n > 92 excede a capacidade de um long long.");
    if (n == 0) return 0;

    long long F[2][2] = {{1, 1}, {1, 0}};
    power(F, n - 1);

    return F[0][0];
}