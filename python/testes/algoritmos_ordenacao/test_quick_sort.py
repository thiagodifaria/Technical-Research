import pytest
from python.algoritmos_ordenacao.quick_sort import quick_sort
import random
import sys


def test_empty_list():
    """Testa Quick Sort com uma lista vazia."""
    assert quick_sort([]) == []

def test_single_element_list():
    """Testa Quick Sort com uma lista contendo um único elemento."""
    assert quick_sort([5]) == [5]

def test_sorted_list():
    """Testa Quick Sort com uma lista já ordenada."""
    arr = [1, 2, 3, 4, 5]
    assert quick_sort(arr.copy()) == [1, 2, 3, 4, 5]

def test_reverse_sorted_list():
    """Testa Quick Sort com uma lista ordenada em ordem reversa."""
    arr = [5, 4, 3, 2, 1]
    assert quick_sort(arr.copy()) == [1, 2, 3, 4, 5]

def test_list_with_duplicates():
    """Testa Quick Sort com uma lista contendo elementos duplicados."""
    arr = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]
    assert quick_sort(arr.copy()) == [1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9]

def test_list_with_negative_numbers():
    """Testa Quick Sort com uma lista contendo números negativos."""
    arr = [-3, 1, -4, 0, 5, -9, 2]
    assert quick_sort(arr.copy()) == [-9, -4, -3, 0, 1, 2, 5]

def test_list_all_same_elements():
    """Testa Quick Sort com uma lista onde todos os elementos são iguais."""
    arr = [7, 7, 7, 7, 7]
    assert quick_sort(arr.copy()) == [7, 7, 7, 7, 7]

def test_random_list_small():
    """Testa Quick Sort com uma lista aleatória pequena."""
    arr = [random.randint(-100, 100) for _ in range(10)]
    sorted_arr = sorted(arr)
    assert quick_sort(arr.copy()) == sorted_arr

def test_random_list_moderate():
    """Testa Quick Sort com uma lista aleatória de tamanho moderado."""
    arr = [random.randint(-1000, 1000) for _ in range(100)]
    sorted_arr = sorted(arr)
    assert quick_sort(arr.copy()) == sorted_arr

def test_random_list_large():
    """Testa Quick Sort com uma lista aleatória maior."""
    original_recursion_limit = sys.getrecursionlimit()
    if original_recursion_limit < 2005 :
         sys.setrecursionlimit(2005)

    arr = [random.randint(-10000, 10000) for _ in range(1000)]
    sorted_arr = sorted(arr)
    quick_sort_result = quick_sort(arr.copy())
    assert quick_sort_result == sorted_arr

    sys.setrecursionlimit(original_recursion_limit)