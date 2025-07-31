#ifndef MDC_EUCLIDES_HPP
#define MDC_EUCLIDES_HPP

#include <cmath> // Para std::abs

/**
 * @file mdc_euclides.hpp
 * @brief Contém a implementação do Algoritmo de Euclides para calcular o Máximo Divisor Comum (MDC).
 */

/**
 * @brief Calcula o Máximo Divisor Comum (MDC) de dois números inteiros usando o Algoritmo de Euclides.
 * * O Algoritmo de Euclides é um método eficiente para encontrar o MDC de dois inteiros.
 * A implementação é recursiva e baseia-se no princípio de que o MDC de dois números
 * não muda se o número maior for substituído pela sua diferença com o número menor.
 * Esta versão usa o operador módulo para maior eficiência.
 * A função lida com números negativos, calculando o MDC de seus valores absolutos.
 * * @param a O primeiro número inteiro.
 * @param b O segundo número inteiro.
 * @return O Máximo Divisor Comum de 'a' e 'b'. Se ambos forem 0, o comportamento é indefinido (esta implementação retorna 0).
 * * @complexity
 * - Time: O(log(min(|a|, |b|))) - A complexidade de tempo é logarítmica em relação ao menor dos dois números.
 * - Space: O(log(min(|a|, |b|))) - Devido à pilha de recursão.
 */
long long mdc_euclides(long long a, long long b);

#endif // MDC_EUCLIDES_HPP