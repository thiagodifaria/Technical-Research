import pytest
from matematica_numerica_otimizacao.fatoracao_pollard_rho import factorize

def test_numero_pequeno():
    """Testa a fatoração de um número pequeno com múltiplos fatores."""
    # 1002 = 2 * 3 * 167
    assert factorize(1002) == [2, 3, 167]

def test_numero_primo():
    """Testa a 'fatoração' de um número primo."""
    assert factorize(29) == [29]
    assert factorize(997) == [997] # Um primo maior

def test_semi_primo_grande():
    """Testa um número que é produto de dois primos grandes."""
    # 10403 = 101 * 103
    assert factorize(10403) == [101, 103]
    # Um caso maior que pode ser desafiador para a força bruta
    # 805111091 = 8971 * 89731
    assert factorize(805111091) == [8971, 89731]

def test_numero_com_fatores_repetidos():
    """Testa um número com potências de fatores primos."""
    # 120 = 2*2*2 * 3 * 5
    assert factorize(120) == [2, 2, 2, 3, 5]
    # 72 = 2^3 * 3^2
    assert factorize(72) == [2, 2, 2, 3, 3]

def test_casos_borda():
    """Testa casos de borda como 0, 1 e 2."""
    assert factorize(0) == []
    assert factorize(1) == []
    assert factorize(2) == [2]

def test_numero_grande():
    """Testa um número grande para verificar a performance."""
    # Este número é 2^61 - 1, um primo de Mersenne. O teste deve ser rápido.
    mersenne_prime = 2305843009213693951
    assert factorize(mersenne_prime) == [mersenne_prime]