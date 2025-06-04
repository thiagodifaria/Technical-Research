import pytest
from python.algoritmos_ordenacao.bubble_sort import bubble_sort
import random

def test_empty_list():
    """Testa Bubble Sort com uma lista vazia."""
    assert bubble_sort([]) == []

def test_single_element_list():
    """Testa Bubble Sort com uma lista contendo um único elemento."""
    assert bubble_sort([5]) == [5]

def test_sorted_list():
    """Testa Bubble Sort com uma lista já ordenada."""
    assert bubble_sort([1, 2, 3, 4, 5]) == [1, 2, 3, 4, 5]

def test_reverse_sorted_list():
    """Testa Bubble Sort com uma lista ordenada em ordem reversa."""
    assert bubble_sort([5, 4, 3, 2, 1]) == [1, 2, 3, 4, 5]

def test_list_with_duplicates():
    """Testa Bubble Sort com uma lista contendo elementos duplicados."""
    assert bubble_sort([3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]) == [1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9]

def test_list_with_negative_numbers():
    """Testa Bubble Sort com uma lista contendo números negativos."""
    assert bubble_sort([-3, 1, -4, 0, 5, -9, 2]) == [-9, -4, -3, 0, 1, 2, 5]

def test_list_all_same_elements():
    """Testa Bubble Sort com uma lista onde todos os elementos são iguais."""
    assert bubble_sort([7, 7, 7, 7, 7]) == [7, 7, 7, 7, 7]

def test_random_list_small():
    """Testa Bubble Sort com uma lista aleatória pequena."""
    arr = [random.randint(-100, 100) for _ in range(10)]
    sorted_arr = sorted(arr)
    assert bubble_sort(arr.copy()) == sorted_arr

def test_random_list_moderate():
    """Testa Bubble Sort com uma lista aleatória de tamanho moderado."""
    arr = [random.randint(-1000, 1000) for _ in range(50)]
    sorted_arr = sorted(arr)
    assert bubble_sort(arr.copy()) == sorted_arr