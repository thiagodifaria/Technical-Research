def _partition(arr: list, low: int, high: int) -> int:
    """
    Função auxiliar para particionar o array.
    Esta implementação usa o último elemento como pivô.
    Coloca o pivô em sua posição correta no array ordenado,
    coloca todos os elementos menores que o pivô à esquerda
    e todos os elementos maiores à direita.
    """
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def _quick_sort_recursive(arr: list, low: int, high: int):
    """
    Função recursiva principal do Quick Sort.
    """
    if low < high:
        partition_index = _partition(arr, low, high)

        _quick_sort_recursive(arr, low, partition_index - 1)
        _quick_sort_recursive(arr, partition_index + 1, high)

def quick_sort(arr: list) -> list:
    """
    Ordena uma lista de elementos usando o algoritmo Quick Sort.

    O Quick Sort é um algoritmo de ordenação eficiente do tipo "dividir para conquistar".
    Ele funciona escolhendo um elemento 'pivô' da lista e particionando os outros
    elementos em duas sub-listas, de acordo com se eles são menores ou maiores que o pivô.
    As sub-listas são então ordenadas recursivamente.

    Complexidade:
    - Tempo:
        - Pior Caso: O(n^2) - Ocorre quando o pivô escolhido é consistentemente o menor
          ou o maior elemento, ou quando todos os elementos são iguais.
          Isso leva a partições desbalanceadas.
        - Caso Médio: O(n log n)
        - Melhor Caso: O(n log n) - Ocorre quando as partições são bem balanceadas.
    - Espaço:
        - O(log n) em média (para a pilha de recursão).
        - O(n) no pior caso (para a pilha de recursão com partições desbalanceadas).
        Esta é uma implementação in-place (modifica a lista original).

    Args:
        arr: A lista de elementos a ser ordenada. Os elementos devem ser comparáveis.
             A lista é ordenada in-place.

    Returns:
        A mesma lista `arr` ordenada.
    """
    n = len(arr)
    if n <= 1:
        return arr

    _quick_sort_recursive(arr, 0, n - 1)
    return arr