#ifndef RABIN_KARP_HPP
#define RABIN_KARP_HPP

#include <string>
#include <vector>

/**
 * @file rabin_karp.hpp
 * @brief Contém a implementação do algoritmo Rabin-Karp para busca de padrões em texto.
 */

/**
 * @brief Encontra todas as ocorrências de um padrão em um texto usando o algoritmo Rabin-Karp.
 *
 * O algoritmo Rabin-Karp funciona deslizando uma janela do tamanho do padrão sobre o texto.
 * Para cada janela, ele calcula um valor de hash e o compara com o hash do padrão.
 * Se os hashes correspondem (um "hit"), o algoritmo realiza uma verificação caractere a caractere
 * para confirmar a correspondência e descartar colisões de hash (falsos positivos).
 * A eficiência do algoritmo vem do uso de uma técnica de "rolling hash", que permite
 * calcular o hash da próxima janela em tempo constante, O(1), a partir da janela anterior.
 *
 * @param texto A string na qual a busca será realizada.
 * @param padrao A string padrão a ser procurada.
 * @return Um `std::vector<int>` contendo os índices (base 0) de início de todas as
 * ocorrências do padrão no texto. Retorna um vetor vazio se nenhuma ocorrência for encontrada.
 *
 * @complexity
 * - Time:
 * - Average/Best Case: O(T + P), onde T é o comprimento do texto e P é o comprimento do padrão.
 * - Worst Case: O(T * P), ocorre em caso de múltiplas colisões de hash (spurious hits).
 * - Space: O(k), onde k é o número de ocorrências encontradas para armazenar o resultado.
 * O espaço auxiliar do algoritmo em si é O(1).
 */
std::vector<int> rabin_karp(const std::string& texto, const std::string& padrao);

#endif // RABIN_KARP_HPP