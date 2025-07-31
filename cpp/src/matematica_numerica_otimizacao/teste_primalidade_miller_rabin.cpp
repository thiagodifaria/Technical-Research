#include "matematica_numerica_otimizacao/teste_primalidade_miller_rabin.hpp"
#include <random>
#include <chrono>

// Função auxiliar para multiplicação modular que evita overflow
// Calcula (a * b) % mod de forma segura.
uint64_t mulmod(uint64_t a, uint64_t b, uint64_t mod) {
    uint64_t res = 0;
    a %= mod;
    while (b > 0) {
        if (b % 2 == 1) res = (res + a) % mod;
        a = (a * 2) % mod;
        b /= 2;
    }
    return res;
}

// Função auxiliar para exponenciação modular: (base^exp) % mod
// Usa a multiplicação modular segura para evitar overflow.
uint64_t power(uint64_t base, uint64_t exp, uint64_t mod) {
    uint64_t res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = mulmod(res, base, mod);
        base = mulmod(base, base, mod);
        exp /= 2;
    }
    return res;
}

// Função principal que implementa o teste de primalidade de Miller-Rabin.
// O nome agora corresponde exatamente ao do arquivo .hpp
bool is_prime_miller_rabin(uint64_t n, int k) {
    // Casos base
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    // Escreve n-1 como d * 2^s
    uint64_t d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
    }

    // Gerador de números aleatórios para as testemunhas
    std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    
    // Executa k rodadas do teste
    for (int i = 0; i < k; i++) {
        std::uniform_int_distribution<uint64_t> dist(2, n - 2);
        uint64_t a = dist(rng);

        // Calcula x = a^d % n
        uint64_t x = power(a, d, n);

        if (x == 1 || x == n - 1) {
            continue;
        }

        uint64_t temp_d = d;
        bool is_composite = true;
        while (temp_d != n - 1) {
            x = mulmod(x, x, n);
            temp_d *= 2;
            if (x == n - 1) {
                is_composite = false;
                break;
            }
        }

        if (is_composite) {
            return false; // Garantidamente composto
        }
    }

    // Passou em todos os k testes, provavelmente primo
    return true;
}