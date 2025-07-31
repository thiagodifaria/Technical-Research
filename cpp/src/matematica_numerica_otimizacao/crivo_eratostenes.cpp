#include "matematica_numerica_otimizacao/crivo_eratostenes.hpp"

std::vector<int> crivo_eratostenes(int limite) {
    // Casos de borda: não há primos menores que 2.
    if (limite < 2) {
        return {}; // Retorna um vetor vazio
    }

    // Cria um vetor booleano 'is_prime' de tamanho 'limite + 1'.
    // Inicialmente, assume que todos os números são primos.
    std::vector<bool> is_prime(limite + 1, true);

    // 0 e 1 não são números primos.
    is_prime[0] = is_prime[1] = false;

    // Itera de 2 até a raiz quadrada do limite.
    for (int p = 2; p * p <= limite; ++p) {
        // Se is_prime[p] não foi marcado como falso, então p é primo.
        if (is_prime[p]) {
            // Marca todos os múltiplos de p como não-primos.
            // A otimização começa em p*p, pois múltiplos menores
            // (como 2*p, 3*p) já terão sido marcados por primos menores (2, 3, etc.).
            for (int i = p * p; i <= limite; i += p) {
                is_prime[i] = false;
            }
        }
    }

    // Coleta todos os números que permaneceram marcados como primos.
    std::vector<int> primos;
    for (int p = 2; p <= limite; ++p) {
        if (is_prime[p]) {
            primos.push_back(p);
        }
    }

    return primos;
}