#ifndef FFT_HPP
#define FFT_HPP

#include <vector>
#include <complex>

/**
 * @file fft.hpp
 * @brief Contém a implementação da Transformada Rápida de Fourier (FFT) e
 * sua aplicação para multiplicação rápida de polinômios.
 */

// Define um apelido para std::complex<double> para facilitar a leitura.
using Complexo = std::complex<double>;

/**
 * @brief Calcula a Transformada Rápida de Fourier (FFT) ou sua inversa (IFFT) in-place.
 *
 * Esta função implementa o algoritmo iterativo de Cooley-Tukey para evitar recursão
 * profunda. Ela primeiro rearranja os coeficientes de entrada usando uma permutação
 * bit-reversal e depois constrói a DFT de baixo para cima.
 *
 * @param a Vetor de números complexos representando os coeficientes do polinômio.
 * O tamanho do vetor DEVE ser uma potência de 2. O vetor é modificado in-place.
 * @param invert Se `true`, calcula a Transformada Inversa de Fourier (IFFT).
 * Se `false` (padrão), calcula a FFT.
 *
 * @complexity
 * - Time: O(n log n), onde n é o tamanho do vetor 'a'.
 * - Space: O(1) de espaço auxiliar, pois a operação é in-place.
 */
void fft(std::vector<Complexo>& a, bool invert = false);

/**
 * @brief Multiplica dois polinômios usando FFT.
 *
 * Dados dois polinômios representados por seus vetores de coeficientes, esta função
 * calcula o polinômio resultante da multiplicação.
 *
 * @param a Coeficientes do primeiro polinômio.
 * @param b Coeficientes do segundo polinômio.
 * @return Um vetor `long long` com os coeficientes do polinômio resultante.
 *
 * @complexity
 * - Time: O(n log n), onde n é o tamanho do resultado (potência de 2 mais próxima).
 * - Space: O(n), para armazenar os vetores de coeficientes e seus análogos complexos.
 */
std::vector<long long> multiply_polynomials(const std::vector<long long>& a, const std::vector<long long>& b);

#endif // FFT_HPP