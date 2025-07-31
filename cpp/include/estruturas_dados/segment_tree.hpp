#ifndef SEGMENT_TREE_HPP
#define SEGMENT_TREE_HPP

#include <vector>
#include <functional> // Para std::plus, std::function
#include <stdexcept>

/**
 * @file segment_tree.hpp
 * @brief Contém a implementação de uma Segment Tree (Árvore de Segmentos) genérica.
 *
 * @note Como esta é uma classe de template, toda a implementação está neste arquivo de cabeçalho.
 */

template <typename T>
class SegmentTree {
private:
    std::vector<T> tree;
    const std::vector<T>& original_array;
    int n;
    std::function<T(T, T)> combiner; // Função para combinar nós (ex: soma, min, max)
    T identity_value;                // Valor identidade para a operação (ex: 0 para soma)

    // Constrói a árvore recursivamente
    void build_helper(int node, int start, int end) {
        if (start == end) {
            tree[node] = original_array[start];
        } else {
            int mid = start + (end - start) / 2;
            build_helper(2 * node, start, mid);
            build_helper(2 * node + 1, mid + 1, end);
            tree[node] = combiner(tree[2 * node], tree[2 * node + 1]);
        }
    }

    // Atualiza a árvore recursivamente
    void update_helper(int node, int start, int end, int index, T value) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = start + (end - start) / 2;
            if (start <= index && index <= mid) {
                update_helper(2 * node, start, mid, index, value);
            } else {
                update_helper(2 * node + 1, mid + 1, end, index, value);
            }
            tree[node] = combiner(tree[2 * node], tree[2 * node + 1]);
        }
    }

    // Realiza a consulta no intervalo recursivamente
    T query_helper(int node, int start, int end, int q_start, int q_end) {
        if (q_start > end || q_end < start) {
            return identity_value; // Intervalo fora da consulta
        }
        if (q_start <= start && end <= q_end) {
            return tree[node]; // Intervalo totalmente contido na consulta
        }
        int mid = start + (end - start) / 2;
        T p1 = query_helper(2 * node, start, mid, q_start, q_end);
        T p2 = query_helper(2 * node + 1, mid + 1, end, q_start, q_end);
        return combiner(p1, p2);
    }

public:
    /**
     * @brief Construtor da Segment Tree.
     * @param arr O vetor de dados original.
     * @param comb A função de combinação (ex: `std::plus<T>()` para soma).
     * @param identity O valor identidade da operação de combinação (ex: 0 para soma).
     */
    SegmentTree(const std::vector<T>& arr, std::function<T(T, T)> comb, T identity)
        : original_array(arr), n(arr.size()), combiner(comb), identity_value(identity) {
        if (n == 0) return;
        tree.resize(4 * n); // Tamanho seguro para a árvore
        build_helper(1, 0, n - 1); // Nó raiz é o 1
    }

    /**
     * @brief Realiza uma consulta de agregação em um intervalo [start, end].
     * @param start O índice inicial do intervalo (inclusivo).
     * @param end O índice final do intervalo (inclusivo).
     * @return O resultado da agregação no intervalo.
     */
    T query(int start, int end) {
        if (start < 0 || end >= n || start > end) {
            throw std::out_of_range("Intervalo de consulta inválido.");
        }
        return query_helper(1, 0, n - 1, start, end);
    }

    /**
     * @brief Atualiza o valor de um elemento no índice especificado.
     * @param index O índice do elemento a ser atualizado.
     * @param value O novo valor para o elemento.
     */
    void update(int index, T value) {
        if (index < 0 || index >= n) {
            throw std::out_of_range("Índice de atualização inválido.");
        }
        update_helper(1, 0, n - 1, index, value);
    }
};

#endif // SEGMENT_TREE_HPP