#include "programacao_dinamica/distancia_edicao.hpp"

int distancia_edicao(const std::string& str1, const std::string& str2) {
    int m = str1.length();
    int n = str2.length();

    // Cria a tabela de DP
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));

    // Casos base: inicializa a tabela
    // Custo para transformar uma string vazia em str2 (n inserções)
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j;
    }
    // Custo para transformar str1 em uma string vazia (m exclusões)
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i;
    }

    // Preenche o resto da tabela
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            // Custo de substituição: 0 se os caracteres forem iguais, 1 caso contrário.
            int custo_substituicao = (str1[i - 1] == str2[j - 1]) ? 0 : 1;

            // O valor de dp[i][j] é o mínimo entre as três operações possíveis:
            int delecao = dp[i - 1][j] + 1;
            int insercao = dp[i][j - 1] + 1;
            int substituicao = dp[i - 1][j - 1] + custo_substituicao;
            
            dp[i][j] = std::min({delecao, insercao, substituicao});
        }
    }

    // O resultado final está no canto inferior direito da tabela
    return dp[m][n];
}