#ifndef ARVORE_AVL_HPP
#define ARVORE_AVL_HPP

#include <algorithm> // Para std::max
#include <stdexcept> // Para std::runtime_error
#include <vector>

/**
 * @file arvore_avl.hpp
 * @brief Contém a implementação de uma Árvore AVL (Árvore de Busca Binária Autobalanceada).
 *
 * @note Como esta é uma classe de template, toda a implementação está neste arquivo de cabeçalho.
 */

template <typename Chave>
class ArvoreAVL {
private:
    struct Node {
        Chave chave;
        Node* esquerda;
        Node* direita;
        int altura;

        Node(Chave c) : chave(c), esquerda(nullptr), direita(nullptr), altura(1) {}
    };

    Node* raiz;

    // --- Funções Auxiliares ---

    int altura(Node* n) {
        return (n == nullptr) ? 0 : n->altura;
    }

    int obter_balanco(Node* n) {
        if (n == nullptr) return 0;
        return altura(n->esquerda) - altura(n->direita);
    }

    Node* rotacao_direita(Node* y) {
        Node* x = y->esquerda;
        Node* T2 = x->direita;
        x->direita = y;
        y->esquerda = T2;
        y->altura = std::max(altura(y->esquerda), altura(y->direita)) + 1;
        x->altura = std::max(altura(x->esquerda), altura(x->direita)) + 1;
        return x;
    }

    Node* rotacao_esquerda(Node* x) {
        Node* y = x->direita;
        Node* T2 = y->esquerda;
        y->esquerda = x;
        x->direita = T2;
        x->altura = std::max(altura(x->esquerda), altura(x->direita)) + 1;
        y->altura = std::max(altura(y->esquerda), altura(y->direita)) + 1;
        return y;
    }

    Node* inserir_helper(Node* no, Chave chave) {
        // 1. Inserção padrão de BST
        if (no == nullptr) return new Node(chave);
        if (chave < no->chave)
            no->esquerda = inserir_helper(no->esquerda, chave);
        else if (chave > no->chave)
            no->direita = inserir_helper(no->direita, chave);
        else
            return no; // Chaves duplicadas não são permitidas

        // 2. Atualizar altura do nó ancestral
        no->altura = 1 + std::max(altura(no->esquerda), altura(no->direita));

        // 3. Obter o fator de balanço e aplicar rotações se necessário
        int balanco = obter_balanco(no);

        // Caso Esquerda-Esquerda (LL)
        if (balanco > 1 && chave < no->esquerda->chave)
            return rotacao_direita(no);

        // Caso Direita-Direita (RR)
        if (balanco < -1 && chave > no->direita->chave)
            return rotacao_esquerda(no);

        // Caso Esquerda-Direita (LR)
        if (balanco > 1 && chave > no->esquerda->chave) {
            no->esquerda = rotacao_esquerda(no->esquerda);
            return rotacao_direita(no);
        }

        // Caso Direita-Esquerda (RL)
        if (balanco < -1 && chave < no->direita->chave) {
            no->direita = rotacao_direita(no->direita);
            return rotacao_esquerda(no);
        }

        return no;
    }

    Node* no_valor_minimo(Node* no) {
        Node* atual = no;
        while (atual->esquerda != nullptr)
            atual = atual->esquerda;
        return atual;
    }

    Node* remover_helper(Node* no_raiz, Chave chave) {
        // 1. Remoção padrão de BST
        if (no_raiz == nullptr) return no_raiz;
        if (chave < no_raiz->chave)
            no_raiz->esquerda = remover_helper(no_raiz->esquerda, chave);
        else if (chave > no_raiz->chave)
            no_raiz->direita = remover_helper(no_raiz->direita, chave);
        else {
            if ((no_raiz->esquerda == nullptr) || (no_raiz->direita == nullptr)) {
                Node* temp = no_raiz->esquerda ? no_raiz->esquerda : no_raiz->direita;
                if (temp == nullptr) { // Sem filhos
                    temp = no_raiz;
                    no_raiz = nullptr;
                } else { // Um filho
                    *no_raiz = *temp;
                }
                delete temp;
            } else {
                Node* temp = no_valor_minimo(no_raiz->direita);
                no_raiz->chave = temp->chave;
                no_raiz->direita = remover_helper(no_raiz->direita, temp->chave);
            }
        }

        if (no_raiz == nullptr) return no_raiz;

        // 2. Atualizar altura e rebalancear (similar à inserção)
        no_raiz->altura = 1 + std::max(altura(no_raiz->esquerda), altura(no_raiz->direita));
        int balanco = obter_balanco(no_raiz);

        // LL e LR
        if (balanco > 1) {
            if (obter_balanco(no_raiz->esquerda) >= 0) // LL
                return rotacao_direita(no_raiz);
            else { // LR
                no_raiz->esquerda = rotacao_esquerda(no_raiz->esquerda);
                return rotacao_direita(no_raiz);
            }
        }
        // RR e RL
        if (balanco < -1) {
            if (obter_balanco(no_raiz->direita) <= 0) // RR
                return rotacao_esquerda(no_raiz);
            else { // RL
                no_raiz->direita = rotacao_direita(no_raiz->direita);
                return rotacao_esquerda(no_raiz);
            }
        }

        return no_raiz;
    }
    
    void in_order_helper(Node* no, std::vector<Chave>& resultado) const {
        if (no != nullptr) {
            in_order_helper(no->esquerda, resultado);
            resultado.push_back(no->chave);
            in_order_helper(no->direita, resultado);
        }
    }

    void destruir_arvore(Node* no) {
        if (no != nullptr) {
            destruir_arvore(no->esquerda);
            destruir_arvore(no->direita);
            delete no;
        }
    }

public:
    ArvoreAVL() : raiz(nullptr) {}
    ~ArvoreAVL() { destruir_arvore(raiz); }

    void inserir(Chave chave) {
        raiz = inserir_helper(raiz, chave);
    }

    void remover(Chave chave) {
        raiz = remover_helper(raiz, chave);
    }
    
    bool buscar(Chave chave) const {
        Node* atual = raiz;
        while (atual != nullptr) {
            if (chave < atual->chave)
                atual = atual->esquerda;
            else if (chave > atual->chave)
                atual = atual->direita;
            else
                return true;
        }
        return false;
    }
    
    std::vector<Chave> in_order_traversal() const {
        std::vector<Chave> resultado;
        in_order_helper(raiz, resultado);
        return resultado;
    }
};

#endif // ARVORE_AVL_HPP