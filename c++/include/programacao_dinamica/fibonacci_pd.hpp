#ifndef FIBONACCI_PD_HPP
#define FIBONACCI_PD_HPP

#include <vector>
#include <stdexcept>

/**
 * @file fibonacci_pd.hpp
 * @brief Contém implementações da sequência de Fibonacci usando Programação Dinâmica e otimizações.
 */

/**
 * @brief Calcula o n-ésimo número de Fibonacci usando Memoização (Top-Down).
 * @complexity Time: O(n), Space: O(n)
 */
long long fibonacci_memo(int n);

/**
 * @brief Calcula o n-ésimo número de Fibonacci usando Tabulação (Bottom-Up).
 * @complexity Time: O(n), Space: O(n)
 */
long long fibonacci_tab(int n);

/**
 * @brief Calcula o n-ésimo número de Fibonacci usando Exponenciação de Matrizes.
 *
 * Esta abordagem se baseia na propriedade de que a matriz [[1, 1], [1, 0]] elevada à n-ésima
 * potência está diretamente relacionada ao (n+1)-ésimo número de Fibonacci. Usando a técnica de
 * "exponenciação por quadratura" (binary exponentiation), a potência da matriz é calculada
 * em tempo logarítmico.
 *
 * @param n A posição na sequência de Fibonacci a ser calculada (base 0).
 * @return O n-ésimo número de Fibonacci como um `long long`.
 * @throws std::invalid_argument se n for negativo.
 * @throws std::overflow_error se n > 92.
 *
 * @complexity
 * - Time: O(log n) - Devido à exponenciação por quadratura.
 * - Space: O(log n) - Devido à pilha de recursão da função de potência.
 */
long long fibonacci_matrix(int n);

#endif // FIBONACCI_PD_HPP