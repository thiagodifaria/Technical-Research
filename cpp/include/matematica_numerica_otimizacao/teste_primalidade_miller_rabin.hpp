#ifndef TESTE_PRIMALIDADE_MILLER_RABIN_HPP
#define TESTE_PRIMALIDADE_MILLER_RABIN_HPP

#include <cstdint> // Para uint64_t

/**
 * @file teste_primalidade_miller_rabin.hpp
 * @brief Contém a implementação do Teste de Primalidade de Miller-Rabin.
 */

/**
 * @brief Realiza o Teste de Primalidade de Miller-Rabin em um número 'n'.
 *
 * @param n O número a ser testado.
 * @param k O número de rodadas (testemunhas) a serem executadas.
 * @return `true` se 'n' for provavelmente primo, `false` se for garantidamente composto.
 */
bool is_prime_miller_rabin(uint64_t n, int k = 10);

#endif // TESTE_PRIMALIDADE_MILLER_RABIN_HPP