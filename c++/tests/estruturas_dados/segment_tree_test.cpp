#include <gtest/gtest.h>
#include "estruturas_dados/segment_tree.hpp"
#include <limits>

// Suíte de testes para a Segment Tree
TEST(SegmentTreeTest, TesteSomaDeIntervalo) {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree<int> st(arr, std::plus<int>(), 0);

    // Soma de todo o array
    EXPECT_EQ(st.query(0, 5), 36);
    // Soma de um sub-intervalo
    EXPECT_EQ(st.query(1, 3), 15); // 3 + 5 + 7
    // Soma de um único elemento
    EXPECT_EQ(st.query(4, 4), 9);
}

TEST(SegmentTreeTest, TesteAtualizacaoSoma) {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree<int> st(arr, std::plus<int>(), 0);

    // Atualiza o elemento no índice 2 de 5 para 6
    st.update(2, 6);

    // Verifica se as somas foram atualizadas
    EXPECT_EQ(st.query(0, 5), 37); // Soma total mudou
    EXPECT_EQ(st.query(1, 3), 16); // 3 + 6 + 7
}

TEST(SegmentTreeTest, TesteMinimoDeIntervalo) {
    std::vector<int> arr = {2, 5, 1, 8, 3, 9};
    auto min_fn = [](int a, int b) { return std::min(a, b); };
    SegmentTree<int> st(arr, min_fn, std::numeric_limits<int>::max());

    // Mínimo de todo o array
    EXPECT_EQ(st.query(0, 5), 1);
    // Mínimo de um sub-intervalo
    EXPECT_EQ(st.query(1, 4), 1); // min(5, 1, 8, 3)
    EXPECT_EQ(st.query(3, 5), 3); // min(8, 3, 9)
}

TEST(SegmentTreeTest, TesteAtualizacaoMinimo) {
    std::vector<int> arr = {2, 5, 1, 8, 3, 9};
    auto min_fn = [](int a, int b) { return std::min(a, b); };
    SegmentTree<int> st(arr, min_fn, std::numeric_limits<int>::max());
    
    // Atualiza o 1 para 10
    st.update(2, 10);
    // O novo mínimo do array deve ser 2
    EXPECT_EQ(st.query(0, 5), 2);

    // Atualiza o 8 para 0
    st.update(3, 0);
    // Agora o novo mínimo deve ser 0
    EXPECT_EQ(st.query(0, 5), 0);
}


TEST(SegmentTreeTest, TesteMaximoDeIntervalo) {
    std::vector<int> arr = {2, 5, 1, 8, 3, 9};
    auto max_fn = [](int a, int b) { return std::max(a, b); };
    SegmentTree<int> st(arr, max_fn, std::numeric_limits<int>::min());

    EXPECT_EQ(st.query(0, 5), 9);
    EXPECT_EQ(st.query(0, 3), 8); // max(2, 5, 1, 8)
}

TEST(SegmentTreeTest, TesteCasosDeBorda) {
    std::vector<int> arr = {10};
    SegmentTree<int> st(arr, std::plus<int>(), 0);

    EXPECT_EQ(st.query(0, 0), 10);
    st.update(0, 20);
    EXPECT_EQ(st.query(0, 0), 20);

    // Testa exceções para intervalos inválidos
    EXPECT_THROW(st.query(0, 1), std::out_of_range);
    EXPECT_THROW(st.query(-1, 0), std::out_of_range);
    EXPECT_THROW(st.query(1, 0), std::out_of_range);
    EXPECT_THROW(st.update(1, 5), std::out_of_range);
}