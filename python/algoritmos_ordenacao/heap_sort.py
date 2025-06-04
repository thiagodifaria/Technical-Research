def _heapify(arr: list, n: int, i: int):
    """
    Função auxiliar para transformar uma subárvore com raiz no índice i
    em um max-heap. n é o tamanho do heap.
    """
    largest = i
    left_child = 2 * i + 1
    right_child = 2 * i + 2

    if left_child < n and arr[left_child] > arr[largest]:
        largest = left_child

    if right_child < n and arr[right_child] > arr[largest]:
        largest = right_child

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        _heapify(arr, n, largest)

def heap_sort(arr: list) -> list:
    """
    Ordena uma lista de elementos usando o algoritmo Heap Sort.

    O Heap Sort é um algoritmo de ordenação por comparação baseado na estrutura
    de dados Binary Heap. Ele primeiro transforma a lista em um max-heap
    (onde cada pai é maior ou igual a seus filhos). Em seguida, remove
    repetidamente o maior elemento do heap (a raiz) e o coloca no final
    da lista ordenada, reconstruindo o heap com os elementos restantes.

    Complexidade:
    - Tempo: O(n log n) para todos os casos (pior, médio, melhor).
        - Construção do heap: O(n)
        - n extrações do heap: n * O(log n)
    - Espaço: O(1) - ordenação in-place.

    Args:
        arr: A lista de elementos a ser ordenada. Os elementos devem ser comparáveis.

    Returns:
        A mesma lista `arr` ordenada.
    """
    n = len(arr)
    if n <= 1:
        return arr

    for i in range(n // 2 - 1, -1, -1):
        _heapify(arr, n, i)

    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        _heapify(arr, i, 0)

    return arr