#include "matematica_numerica_otimizacao/fft.hpp"
#include <cmath>
#include <numbers> // Para std::numbers::pi
#include <algorithm>

void fft(std::vector<Complexo>& a, bool invert) {
    int n = a.size();
    if (n <= 1) return;

    // 1. Permutação bit-reversal
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            std::swap(a[i], a[j]);
    }

    // 2. Loop principal (bottom-up)
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * std::numbers::pi / len * (invert ? -1 : 1);
        Complexo wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            Complexo w(1);
            for (int j = 0; j < len / 2; j++) {
                Complexo u = a[i + j];
                Complexo v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    // 3. Se for IFFT, divide cada elemento por n
    if (invert) {
        for (Complexo& x : a)
            x /= n;
    }
}

std::vector<long long> multiply_polynomials(const std::vector<long long>& a, const std::vector<long long>& b) {
    std::vector<Complexo> fa(a.begin(), a.end());
    std::vector<Complexo> fb(b.begin(), b.end());

    // 1. Achar a menor potência de 2 que seja grande o suficiente
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    
    fa.resize(n);
    fb.resize(n);

    // 2. Calcular FFT de ambos os polinômios
    fft(fa, false);
    fft(fb, false);

    // 3. Multiplicação no domínio da frequência
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];

    // 4. Calcular a IFFT para voltar ao domínio dos coeficientes
    fft(fa, true);

    // 5. Arredondar e converter para o resultado final
    std::vector<long long> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    
    // Remove zeros à direita desnecessários
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }

    return result;
}