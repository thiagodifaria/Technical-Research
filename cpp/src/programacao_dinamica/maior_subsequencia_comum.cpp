#include "programacao_dinamica/maior_subsequencia_comum.hpp"

int lcs_length(const std::string& str1, const std::string& str2) {
    int m = str1.length();
    int n = str2.length();

    if (m == 0 || n == 0) {
        return 0;
    }

    // Cria a tabela de DP com (m+1) linhas e (n+1) colunas, inicializada com 0.
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    // Preenche a tabela dp de forma bottom-up.
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            // Se os caracteres correspondem, o comprimento da LCS é 1 + LCS das strings menores.
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                // Se não correspondem, é o máximo da LCS obtida ignorando o caractere
                // de str1 ou ignorando o caractere de str2.
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // O valor no canto inferior direito da tabela é o comprimento da LCS para as strings completas.
    return dp[m][n];
}