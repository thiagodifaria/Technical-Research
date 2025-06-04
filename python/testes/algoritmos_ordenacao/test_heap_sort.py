import pytest
from python.algoritmos_ordenacao.heap_sort import heap_sort
import random

def test_empty_list():
    """Testa Heap Sort com uma lista vazia."""
    assert heap_sort([]) == []

def test_single_element_list():
    """Testa Heap Sort com uma lista contendo um único elemento."""
    assert heap_sort([5]) == [5]

def test_sorted_list():
    """Testa Heap Sort com uma lista já ordenada."""
    assert heap_sort([1, 2, 3, 4, 5]) == [1, 2, 3, 4, 5]

def test_reverse_sorted_list():
    """Testa Heap Sort com uma lista ordenada em ordem reversa."""
    assert heap_sort([5, 4, 3, 2, 1]) == [1, 2, 3, 4, 5]

def test_list_with_duplicates():
    """Testa Heap Sort com uma lista contendo elementos duplicados."""
    assert heap_sort([3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]) == [1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9]

def test_list_with_negative_numbers():
    """Testa Heap Sort com uma lista contendo números negativos."""
    assert heap_sort([-3, 1, -4, 0, 5, -9, 2]) == [-9, -4, -3, 0, 1, 2, 5]

def test_list_all_same_elements():
    """Testa Heap Sort com uma lista onde todos os elementos são iguais."""
    assert heap_sort([7, 7, 7, 7, 7]) == [7, 7, 7, 7, 7]

def test_random_list_small():
    """Testa Heap Sort com uma lista aleatória pequena."""
    arr = [random.randint(-100, 100) for _ in range(10)]
    sorted_arr = sorted(arr)
    assert heap_sort(arr.copy()) == sorted_arr

def test_random_list_moderate():
    """Testa Heap Sort com uma lista aleatória de tamanho moderado."""
    arr = [random.randint(-1000, 1000) for _ in range(100)]
    sorted_arr = sorted(arr)
    assert heap_sort(arr.copy()) == sorted_arr