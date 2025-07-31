import pytest
import numpy as np
from matematica_numerica_otimizacao.algoritmo_simplex_basico import simplex

def test_problema_padrao_2_variaveis():
    """
    Testa um problema de programação linear clássico.
    Maximizar: Z = 3*x1 + 5*x2
    Sujeito a:
    1*x1 + 0*x2 <= 4
    0*x1 + 2*x2 <= 12
    3*x1 + 2*x2 <= 18
    x1, x2 >= 0
    
    Solução ótima conhecida: Z = 36 em x1 = 2, x2 = 6.
    """
    c = [3, 5]
    A = [[1, 0], 
         [0, 2], 
         [3, 2]]
    b = [4, 12, 18]

    solucao, valor_otimo = simplex(c, A, b)

    assert valor_otimo == pytest.approx(36)
    assert solucao['x1'] == pytest.approx(2)
    assert solucao['x2'] == pytest.approx(6)

def test_problema_3_variaveis():
    """
    Testa um problema com 3 variáveis.
    Maximizar: Z = 5*x1 + 4*x2 + 3*x3
    Sujeito a:
    2*x1 + 3*x2 + 1*x3 <= 5
    4*x1 + 1*x2 + 2*x3 <= 11
    3*x1 + 4*x2 + 2*x3 <= 8
    x1, x2, x3 >= 0
    
    Solução ótima conhecida: Z = 13 em x1 = 2, x2 = 0, x3 = 1.
    """
    c = [5, 4, 3]
    A = [[2, 3, 1],
         [4, 1, 2],
         [3, 4, 2]]
    b = [5, 11, 8]

    solucao, valor_otimo = simplex(c, A, b)

    assert valor_otimo == pytest.approx(13)
    assert solucao['x1'] == pytest.approx(2)
    assert solucao['x2'] == pytest.approx(0)
    assert solucao.get('x3', 0) == pytest.approx(1) # Usa .get para o caso de x3 ser não-básica

def test_problema_ilimitado():
    """
    Testa um problema onde a solução é ilimitada.
    Maximizar: Z = 2*x1 + 1*x2
    Sujeito a:
    1*x1 - 1*x2 <= 10
    2*x1       <= 40
    x1, x2 >= 0
    
    x2 pode aumentar indefinidamente.
    """
    c = [2, 1]
    A = [[1, -1],
         [2, 0]]
    b = [10, 40]

    solucao, valor_otimo = simplex(c, A, b)
    
    assert solucao is None
    assert valor_otimo is None