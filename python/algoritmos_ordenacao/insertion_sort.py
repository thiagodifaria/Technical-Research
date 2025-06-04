def insertion_sort(arr: list) -> list:
    """
    Ordena uma lista de elementos usando o algoritmo Insertion Sort.

    O Insertion Sort constrói a lista ordenada final um item por vez.
    Ele itera sobre a lista de entrada, e para cada elemento, o insere
    na posição correta dentro da sublista já ordenada à esquerda.

    Complexidade:
    - Tempo:
        - Pior Caso: O(n^2) - quando a lista está em ordem inversa.
        - Caso Médio: O(n^2)
        - Melhor Caso: O(n) - quando a lista já está ordenada.
    - Espaço: O(1) - ordenação in-place.

    Args:
        arr: A lista de elementos a ser ordenada. Os elementos devem ser comparáveis.

    Returns:
        A mesma lista `arr` ordenada.
    """
    n = len(arr)
    if n <= 1:
        return arr

    for i in range(1, n):
        key = arr[i]
        j = i - 1

        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

    return arr