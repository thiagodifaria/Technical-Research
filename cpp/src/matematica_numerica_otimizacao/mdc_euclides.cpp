#include "matematica_numerica_otimizacao/mdc_euclides.hpp"

long long mdc_euclides(long long a, long long b) {
    // O MDC é geralmente definido para inteiros não-negativos,
    // então usamos o valor absoluto para lidar com entradas negativas.
    a = std::abs(a);
    b = std::abs(b);

    // Caso base da recursão: mdc(a, 0) = a
    if (b == 0) {
        return a;
    }
    
    // Passo recursivo: mdc(a, b) = mdc(b, a % b)
    return mdc_euclides(b, a % b);
}