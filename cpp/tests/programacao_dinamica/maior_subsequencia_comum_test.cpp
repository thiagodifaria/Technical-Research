#include <gtest/gtest.h>
#include "programacao_dinamica/maior_subsequencia_comum.hpp"

// Suíte de testes para a Maior Subsequência Comum (LCS)
TEST(LCSTest, TesteCasoSimples) {
    // LCS é "GTAB", comprimento 4
    EXPECT_EQ(lcs_length("AGGTAB", "GXTXAYB"), 4);
}

TEST(LCSTest, TesteStringsIdenticas) {
    std::string s = "ABCDEFGHI";
    EXPECT_EQ(lcs_length(s, s), s.length());
}

TEST(LCSTest, TesteStringsSemSubsequenciaComum) {
    EXPECT_EQ(lcs_length("ABC", "XYZ"), 0);
}

TEST(LCSTest, TesteUmaStringVazia) {
    EXPECT_EQ(lcs_length("ABCDE", ""), 0);
    EXPECT_EQ(lcs_length("", "XYZ"), 0);
}

TEST(LCSTest, TesteAmbasStringsVazias) {
    EXPECT_EQ(lcs_length("", ""), 0);
}

TEST(LCSTest, TesteCasoComplexo) {
    // LCS é "MJAU", comprimento 4
    EXPECT_EQ(lcs_length("XMJYAUZ", "MZJAWXU"), 4);
}

TEST(LCSTest, TesteSubsequenciaCompleta) {
    // A segunda string é uma subsequência da primeira
    EXPECT_EQ(lcs_length("abcdef", "ace"), 3);
    EXPECT_EQ(lcs_length("banana", "bna"), 3);
}