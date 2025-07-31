#include <gtest/gtest.h>
#include "estruturas_dados/arvore_avl.hpp"
#include <vector>

// Suíte de testes para a Árvore AVL
TEST(ArvoreAVLTest, TesteInsercaoSimplesEBusca) {
    ArvoreAVL<int> arvore;
    arvore.inserir(10);
    arvore.inserir(20);
    arvore.inserir(5);

    EXPECT_TRUE(arvore.buscar(10));
    EXPECT_TRUE(arvore.buscar(20));
    EXPECT_TRUE(arvore.buscar(5));
    EXPECT_FALSE(arvore.buscar(15));
    
    std::vector<int> esperado = {5, 10, 20};
    EXPECT_EQ(arvore.in_order_traversal(), esperado);
}

TEST(ArvoreAVLTest, TesteRotacaoSimplesDireita_LL) {
    ArvoreAVL<int> arvore;
    arvore.inserir(30);
    arvore.inserir(20);
    arvore.inserir(10); // Desbalanceamento LL, requer rotação à direita na raiz (30)

    std::vector<int> esperado = {10, 20, 30};
    EXPECT_EQ(arvore.in_order_traversal(), esperado);
}

TEST(ArvoreAVLTest, TesteRotacaoSimplesEsquerda_RR) {
    ArvoreAVL<int> arvore;
    arvore.inserir(10);
    arvore.inserir(20);
    arvore.inserir(30); // Desbalanceamento RR, requer rotação à esquerda na raiz (10)

    std::vector<int> esperado = {10, 20, 30};
    EXPECT_EQ(arvore.in_order_traversal(), esperado);
}

TEST(ArvoreAVLTest, TesteRotacaoDuplaEsquerdaDireita_LR) {
    ArvoreAVL<int> arvore;
    arvore.inserir(30);
    arvore.inserir(10);
    arvore.inserir(20); // Desbalanceamento LR

    std::vector<int> esperado = {10, 20, 30};
    EXPECT_EQ(arvore.in_order_traversal(), esperado);
}

TEST(ArvoreAVLTest, TesteRotacaoDuplaDireitaEsquerda_RL) {
    ArvoreAVL<int> arvore;
    arvore.inserir(10);
    arvore.inserir(30);
    arvore.inserir(20); // Desbalanceamento RL

    std::vector<int> esperado = {10, 20, 30};
    EXPECT_EQ(arvore.in_order_traversal(), esperado);
}

TEST(ArvoreAVLTest, TesteInsercaoComplexa) {
    ArvoreAVL<int> arvore;
    std::vector<int> valores = {9, 5, 10, 0, 6, 11, -1, 1, 2};
    for(int val : valores) {
        arvore.inserir(val);
    }

    std::sort(valores.begin(), valores.end());
    EXPECT_EQ(arvore.in_order_traversal(), valores);
}

TEST(ArvoreAVLTest, TesteRemocaoSimples) {
    ArvoreAVL<int> arvore;
    arvore.inserir(10);
    arvore.inserir(5);
    arvore.inserir(15);
    arvore.inserir(12);

    arvore.remover(12); // Remove um nó folha
    EXPECT_FALSE(arvore.buscar(12));
    
    std::vector<int> esperado1 = {5, 10, 15};
    EXPECT_EQ(arvore.in_order_traversal(), esperado1);
    
    arvore.remover(5); // Remove um nó com um filho (neste caso, nenhum)
    EXPECT_FALSE(arvore.buscar(5));
    
    std::vector<int> esperado2 = {10, 15};
    EXPECT_EQ(arvore.in_order_traversal(), esperado2);
}

TEST(ArvoreAVLTest, TesteRemocaoComRotacao) {
    ArvoreAVL<int> arvore;
    arvore.inserir(10);
    arvore.inserir(5);
    arvore.inserir(15);
    arvore.inserir(12);
    arvore.inserir(20);
    arvore.inserir(25);
    
    // Árvore inicial é balanceada.
    // In-order: 5, 10, 12, 15, 20, 25
    arvore.remover(5); // Remover o 5 causa desbalanceamento em 15 (fator 2)
                       // e deve acionar uma rotação RR (à esquerda) em 15.
    
    std::vector<int> esperado = {10, 12, 15, 20, 25};
    EXPECT_EQ(arvore.in_order_traversal(), esperado);
    EXPECT_FALSE(arvore.buscar(5));
}