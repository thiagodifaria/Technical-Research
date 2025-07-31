#include "programacao_dinamica/mochila_01.hpp"

int mochila_01(int capacidade, const std::vector<Item>& itens) {
    int n = itens.size();

    if (n == 0 || capacidade <= 0) {
        return 0;
    }

    // Tabela de DP: dp[i][c] armazena o valor máximo para os primeiros 'i' itens
    // com uma capacidade 'c'.
    // As dimensões são (n+1) x (capacidade+1) para facilitar a indexação.
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacidade + 1, 0));

    // Itera sobre cada item
    for (int i = 1; i <= n; ++i) {
        // O item atual corresponde a itens[i-1] (indexação 0)
        int peso_atual = itens[i - 1].peso;
        int valor_atual = itens[i - 1].valor;

        // Itera sobre cada possível capacidade da mochila
        for (int c = 1; c <= capacidade; ++c) {
            // Caso 1: O item atual é muito pesado para a capacidade 'c'.
            // Nesse caso, não podemos incluí-lo. O valor máximo é o mesmo que
            // o valor máximo sem este item.
            if (peso_atual > c) {
                dp[i][c] = dp[i - 1][c];
            } else {
                // Caso 2: O item atual cabe na mochila.
                // Temos duas escolhas:
                // a) Não incluir o item: o valor é dp[i-1][c].
                // b) Incluir o item: o valor é valor_atual + o valor máximo que
                //    podemos obter com os itens restantes e a capacidade restante
                //    (c - peso_atual).
                dp[i][c] = std::max(dp[i - 1][c], valor_atual + dp[i - 1][c - peso_atual]);
            }
        }
    }

    // O resultado final está na célula que considera todos os 'n' itens e a capacidade total.
    return dp[n][capacidade];
}