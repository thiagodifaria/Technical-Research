#include <gtest/gtest.h>
#include <string>
#include "estruturas_dados/tabela_hash.hpp"

// Suíte de testes para a TabelaHash
TEST(TabelaHashTest, TesteInsercaoEBusca) {
    TabelaHash<std::string, int> mapa;
    mapa.inserir("um", 1);
    mapa.inserir("dois", 2);

    int valor;
    EXPECT_TRUE(mapa.buscar("um", valor));
    EXPECT_EQ(valor, 1);

    EXPECT_TRUE(mapa.buscar("dois", valor));
    EXPECT_EQ(valor, 2);

    EXPECT_EQ(mapa.tamanho(), 2);
}

TEST(TabelaHashTest, TesteBuscaChaveInexistente) {
    TabelaHash<std::string, int> mapa;
    mapa.inserir("existe", 100);
    
    int valor;
    EXPECT_FALSE(mapa.buscar("nao_existe", valor));
}

TEST(TabelaHashTest, TesteAtualizacaoDeValor) {
    TabelaHash<std::string, int> mapa;
    mapa.inserir("chave", 10);
    
    int valor;
    mapa.buscar("chave", valor);
    EXPECT_EQ(valor, 10);
    EXPECT_EQ(mapa.tamanho(), 1);

    // Atualiza o valor para a mesma chave
    mapa.inserir("chave", 20);
    mapa.buscar("chave", valor);
    EXPECT_EQ(valor, 20);

    // O tamanho não deve aumentar
    EXPECT_EQ(mapa.tamanho(), 1);
}

TEST(TabelaHashTest, TesteDeRemocao) {
    TabelaHash<std::string, int> mapa;
    mapa.inserir("a", 1);
    mapa.inserir("b", 2);

    EXPECT_EQ(mapa.tamanho(), 2);
    
    EXPECT_TRUE(mapa.remover("a"));
    EXPECT_EQ(mapa.tamanho(), 1);

    int valor;
    EXPECT_FALSE(mapa.buscar("a", valor)); // Não deve mais encontrar 'a'
    EXPECT_TRUE(mapa.buscar("b", valor));  // 'b' ainda deve estar lá
    EXPECT_EQ(valor, 2);

    EXPECT_FALSE(mapa.remover("c")); // Tenta remover chave inexistente
    EXPECT_EQ(mapa.tamanho(), 1);
}

TEST(TabelaHashTest, TesteDeColisao) {
    // Usa uma capacidade pequena para forçar colisões
    // Chaves 5, 9, 13, etc., colidirão no mesmo bucket (índice 1) se capacidade=4
    TabelaHash<int, std::string> mapa(4);

    mapa.inserir(1, "um");
    mapa.inserir(5, "cinco"); // Colide com 1 (1 % 4 == 5 % 4)
    mapa.inserir(9, "nove");  // Colide com 1
    mapa.inserir(3, "tres");

    EXPECT_EQ(mapa.tamanho(), 4);

    std::string valor;
    EXPECT_TRUE(mapa.buscar(1, valor));
    EXPECT_EQ(valor, "um");

    EXPECT_TRUE(mapa.buscar(5, valor));
    EXPECT_EQ(valor, "cinco");
    
    EXPECT_TRUE(mapa.buscar(9, valor));
    EXPECT_EQ(valor, "nove");
    
    EXPECT_TRUE(mapa.buscar(3, valor));
    EXPECT_EQ(valor, "tres");
}

TEST(TabelaHashTest, TesteRemocaoComColisao) {
    TabelaHash<int, std::string> mapa(4);
    mapa.inserir(1, "um");
    mapa.inserir(5, "cinco");
    mapa.inserir(9, "nove");

    // Remove o item do meio da lista encadeada (bucket)
    EXPECT_TRUE(mapa.remover(5));
    EXPECT_EQ(mapa.tamanho(), 2);

    std::string valor;
    EXPECT_FALSE(mapa.buscar(5, valor)); // 'cinco' foi removido
    EXPECT_TRUE(mapa.buscar(1, valor));  // 'um' permanece
    EXPECT_EQ(valor, "um");
    EXPECT_TRUE(mapa.buscar(9, valor));  // 'nove' permanece
    EXPECT_EQ(valor, "nove");
}