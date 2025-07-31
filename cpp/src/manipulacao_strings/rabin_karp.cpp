#include "manipulacao_strings/rabin_karp.hpp"

std::vector<int> rabin_karp(const std::string& texto, const std::string& padrao) {
    int T = texto.length();
    int P = padrao.length();
    std::vector<int> ocorrencias;

    if (P == 0 || T == 0 || P > T) {
        return ocorrencias; // Retorna vetor vazio para casos de borda
    }

    // Constantes para o cálculo do hash
    const int d = 256; // Número de caracteres no alfabeto de entrada
    const int q = 101; // Um número primo para o módulo

    long long hash_p = 0; // hash para o padrão
    long long hash_t = 0; // hash para a janela atual do texto
    long long h = 1;

    // O valor de h será pow(d, P-1) % q
    for (int i = 0; i < P - 1; i++) {
        h = (h * d) % q;
    }

    // Calcula o valor de hash do padrão e da primeira janela do texto
    for (int i = 0; i < P; i++) {
        hash_p = (d * hash_p + padrao[i]) % q;
        hash_t = (d * hash_t + texto[i]) % q;
    }

    // Desliza a janela do padrão sobre o texto
    for (int i = 0; i <= T - P; i++) {
        // Compara os hashes da janela atual do texto e do padrão.
        if (hash_p == hash_t) {
            // Se os hashes correspondem, verifica caractere por caractere
            // para garantir que não é uma colisão (falso positivo).
            bool match = true;
            for (int j = 0; j < P; j++) {
                if (texto[i + j] != padrao[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                ocorrencias.push_back(i);
            }
        }

        // Calcula o hash para a próxima janela do texto (rolling hash)
        if (i < T - P) {
            // Remove o dígito/caractere da esquerda e adiciona o da direita
            hash_t = (d * (hash_t - texto[i] * h) + texto[i + P]) % q;
            
            // Podemos obter um valor de hash negativo, então o ajustamos
            if (hash_t < 0) {
                hash_t = (hash_t + q);
            }
        }
    }
    return ocorrencias;
}