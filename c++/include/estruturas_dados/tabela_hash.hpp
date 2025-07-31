#ifndef TABELA_HASH_HPP
#define TABELA_HASH_HPP

#include <vector>
#include <list>
#include <string>
#include <functional> // Para std::hash

/**
 * @file tabela_hash.hpp
 * @brief Contém a implementação de uma Tabela Hash genérica com tratamento de
 * colisão por encadeamento (chaining).
 *
 * @note Como esta é uma classe de template, toda a implementação (definição e
 * corpo dos métodos) está contida neste arquivo de cabeçalho. Isso é
 * necessário para que o compilador possa gerar o código para os tipos
 * específicos com os quais a TabelaHash é instanciada.
 */

template <typename Chave, typename Valor>
class TabelaHash {
private:
    /**
     * @struct Entrada
     * @brief Representa um par chave-valor armazenado na tabela.
     */
    struct Entrada {
        Chave chave;
        Valor valor;
    };

    std::vector<std::list<Entrada>> tabela; // O array de "buckets", cada um é uma lista ligada.
    size_t tamanho_atual;                  // Número de elementos na tabela.
    size_t capacidade;                     // Número de buckets na tabela.

    /**
     * @brief Função de hash interna.
     * Converte uma chave em um índice para o vetor 'tabela'.
     * @param chave A chave a ser hasheada.
     * @return O índice do bucket correspondente.
     */
    size_t hash_para_indice(const Chave& chave) const {
        // Usa o hash padrão do C++ para o tipo da Chave.
        return std::hash<Chave>{}(chave) % capacidade;
    }

public:
    /**
     * @brief Construtor da TabelaHash.
     * @param cap A capacidade inicial da tabela (número de buckets).
     */
    explicit TabelaHash(size_t cap = 16) : capacidade(cap), tamanho_atual(0) {
        tabela.resize(capacidade);
    }

    /**
     * @brief Insere um par chave-valor na tabela.
     * Se a chave já existir, o valor associado a ela é atualizado.
     * @param chave A chave para inserir.
     * @param valor O valor associado à chave.
     */
    void inserir(const Chave& chave, const Valor& valor) {
        size_t indice = hash_para_indice(chave);
        
        // Procura na lista (bucket) se a chave já existe.
        for (auto& entrada : tabela[indice]) {
            if (entrada.chave == chave) {
                // Chave encontrada, atualiza o valor.
                entrada.valor = valor;
                return;
            }
        }

        // Chave não encontrada, insere uma nova entrada no início da lista.
        tabela[indice].push_front({chave, valor});
        tamanho_atual++;
    }

    /**
     * @brief Busca um valor associado a uma chave.
     * @param chave A chave a ser buscada.
     * @param valor_encontrado Referência para armazenar o valor se a chave for encontrada.
     * @return true se a chave foi encontrada, false caso contrário.
     */
    bool buscar(const Chave& chave, Valor& valor_encontrado) const {
        size_t indice = hash_para_indice(chave);

        for (const auto& entrada : tabela[indice]) {
            if (entrada.chave == chave) {
                valor_encontrado = entrada.valor;
                return true;
            }
        }
        return false;
    }

    /**
     * @brief Remove um par chave-valor da tabela.
     * @param chave A chave do par a ser removido.
     * @return true se a chave foi encontrada e removida, false caso contrário.
     */
    bool remover(const Chave& chave) {
        size_t indice = hash_para_indice(chave);
        auto& lista = tabela[indice];

        for (auto it = lista.begin(); it != lista.end(); ++it) {
            if (it->chave == chave) {
                lista.erase(it);
                tamanho_atual--;
                return true;
            }
        }
        return false;
    }

    /**
     * @brief Retorna o número de elementos na tabela.
     * @return O tamanho atual da tabela.
     */
    size_t tamanho() const {
        return tamanho_atual;
    }
};

#endif // TABELA_HASH_HPP