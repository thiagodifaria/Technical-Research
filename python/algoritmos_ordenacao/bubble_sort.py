def bubble_sort(arr: list) -> list:
    """
    Ordena uma lista de elementos usando o algoritmo Bubble Sort.

    O Bubble Sort compara repetidamente pares adjacentes de elementos e os troca
    se estiverem na ordem errada. Este processo é repetido até que nenhuma troca
    seja necessária, indicando que a lista está ordenada.

    Complexidade:
    - Tempo:
        - Pior Caso: O(n^2) - quando a lista está em ordem inversa.
        - Caso Médio: O(n^2)
        - Melhor Caso: O(n) - quando a lista já está ordenada (com otimização).
    - Espaço: O(1) - ordenação in-place.

    Args:
        arr: A lista de elementos a ser ordenada. Os elementos devem ser comparáveis.

    Returns:
        A mesma lista `arr` ordenada.
    """
    n = len(arr)
    if n <= 1:
        return arr

    for i in range(n):
        swapped = False
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break
    return arr