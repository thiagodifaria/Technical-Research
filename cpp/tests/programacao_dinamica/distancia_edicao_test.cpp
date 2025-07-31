#include <gtest/gtest.h>
#include "programacao_dinamica/distancia_edicao.hpp"

// Suíte de testes para a Distância de Edição (Levenshtein)
TEST(DistanciaEdicaoTest, TesteCasoClassico) {
    // kitten -> sitten (substituição 'k' por 's')
    // sitten -> sittin (substituição 'e' por 'i')
    // sittin -> sitting (inserção de 'g')
    // Custo total: 3
    EXPECT_EQ(distancia_edicao("kitten", "sitting"), 3);
}

TEST(DistanciaEdicaoTest, TesteStringsIdenticas) {
    EXPECT_EQ(distancia_edicao("hello", "hello"), 0);
}

TEST(DistanciaEdicaoTest, TesteUmaStringVazia) {
    // 5 exclusões para transformar "apple" em ""
    EXPECT_EQ(distancia_edicao("apple", ""), 5);
}

TEST(DistanciaEdicaoTest, TesteOutraStringVazia) {
    // 6 inserções para transformar "" em "banana"
    EXPECT_EQ(distancia_edicao("", "banana"), 6);
}

TEST(DistanciaEdicaoTest, TesteAmbasVazias) {
    EXPECT_EQ(distancia_edicao("", ""), 0);
}

TEST(DistanciaEdicaoTest, TesteApenasSubstituicao) {
    EXPECT_EQ(distancia_edicao("book", "back"), 2); // o->a, o->c
}

TEST(DistanciaEdicaoTest, TesteApenasInsercao) {
    EXPECT_EQ(distancia_edicao("cat", "cats"), 1);
    EXPECT_EQ(distancia_edicao("flaw", "flaws"), 1);
}

TEST(DistanciaEdicaoTest, TesteApenasDelecao) {
    EXPECT_EQ(distancia_edicao("cart", "cat"), 1);
    EXPECT_EQ(distancia_edicao("apple", "aple"), 1);
}

TEST(DistanciaEdicaoTest, TesteCasoComum) {
    EXPECT_EQ(distancia_edicao("sunday", "saturday"), 3);
}