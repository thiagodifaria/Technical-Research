def merge_sort(arr: list) -> list:
    """
    Ordena uma lista de elementos usando o algoritmo Merge Sort.

    O Merge Sort é um algoritmo de ordenação eficiente do tipo "dividir para conquistar".
    Ele funciona da seguinte maneira:
    1. Dividir: Se a lista tiver mais de um elemento, divida-a recursivamente em duas sub-listas
       (aproximadamente do mesmo tamanho) até que cada sub-lista contenha um único elemento
       (que é trivialmente ordenado).
    2. Conquistar: Mescle (merge) repetidamente as sub-listas ordenadas para produzir novas
       sub-listas ordenadas, até que reste apenas uma sub-lista, que é a lista ordenada final.

    Complexidade:
    - Tempo: O(n log n) para todos os casos (pior, médio, melhor).
        - A divisão leva log n níveis.
        - Em cada nível, a mesclagem leva O(n) tempo.
    - Espaço: O(n) - devido à necessidade de arrays auxiliares para a mesclagem.
      (Existem implementações in-place, mas são complexas e geralmente não são a forma padrão).

    Args:
        arr: A lista de elementos a ser ordenada. Os elementos devem ser comparáveis.

    Returns:
        Uma nova lista contendo os elementos de `arr` ordenados.
        Nota: Esta implementação retorna uma nova lista, em vez de ordenar in-place.
              Se a ordenação in-place for desejada, a abordagem precisaria ser ajustada,
              o que é mais complexo para o Merge Sort canônico.
    """
    n = len(arr)
    if n <= 1:
        return arr

    mid = n // 2
    left_half = arr[:mid]
    right_half = arr[mid:]

    sorted_left_half = merge_sort(left_half)
    sorted_right_half = merge_sort(right_half)

    return _merge(sorted_left_half, sorted_right_half)

def _merge(left_arr: list, right_arr: list) -> list:
    """
    Função auxiliar para mesclar duas listas ordenadas em uma única lista ordenada.
    """
    merged_list = []
    i = 0
    j = 0

    while i < len(left_arr) and j < len(right_arr):
        if left_arr[i] <= right_arr[j]:
            merged_list.append(left_arr[i])
            i += 1
        else:
            merged_list.append(right_arr[j])
            j += 1

    while i < len(left_arr):
        merged_list.append(left_arr[i])
        i += 1

    while j < len(right_arr):
        merged_list.append(right_arr[j])
        j += 1

    return merged_list