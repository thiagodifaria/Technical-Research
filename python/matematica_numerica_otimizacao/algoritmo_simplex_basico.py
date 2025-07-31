import numpy as np

def simplex(c, A, b):
    """
    Resolve um problema de programação linear na forma padrão usando o Algoritmo Simplex.

    O problema deve estar no seguinte formato (forma padrão para esta implementação):
    Maximizar: Z = c^T * x
    Sujeito a: A * x <= b
               x >= 0

    Esta é uma implementação básica que utiliza o método do tableau e não lida com
    problemas que requerem o método de duas fases (ex: restrições >= ou =).

    Args:
        c (list or np.array): Vetor de coeficientes da função objetivo.
        A (list of lists or np.array): Matriz de coeficientes das restrições.
        b (list or np.array): Vetor de termos constantes das restrições (lado direito).

    Returns:
        tuple: Uma tupla contendo:
            - A solução ótima (dicionário com os valores das variáveis).
            - O valor máximo da função objetivo.
        Ou (None, None) se o problema for ilimitado.

    Complexity:
        - Time: Exponencial no pior caso, mas geralmente eficiente na prática.
        - Space: O(m * n) para armazenar o tableau, onde m é o número de restrições
                 e n é o número de variáveis de decisão.
    """
    # 1. Configuração do Tableau
    # Converte tudo para arrays numpy para operações matriciais
    A = np.array(A, dtype=float)
    b = np.array(b, dtype=float)
    c = np.array(c, dtype=float)

    num_restricoes, num_variaveis = A.shape

    # Adiciona variáveis de folga para transformar inequações em equações
    # O tableau terá: A | Identidade | b | Z
    tableau = np.zeros((num_restricoes + 1, num_variaveis + num_restricoes + 1))
    
    # Preenche a parte das restrições (A | I | b)
    tableau[:num_restricoes, :num_variaveis] = A
    tableau[:num_restricoes, num_variaveis:num_variaveis + num_restricoes] = np.identity(num_restricoes)
    tableau[:num_restricoes, -1] = b

    # Preenche a última linha com a função objetivo (-c | 0 | 0)
    tableau[-1, :num_variaveis] = -c

    # 2. Loop de Iteração do Simplex
    while np.any(tableau[-1, :-1] < 0):
        # Encontra a coluna do pivô (variável que entra na base)
        # É a coluna com o valor mais negativo na linha da função objetivo
        pivot_col = np.argmin(tableau[-1, :-1])

        # Verifica se o problema é ilimitado
        if np.all(tableau[:-1, pivot_col] <= 0):
            print("Problema é ilimitado. Nenhuma solução ótima finita.")
            return None, None

        # Encontra a linha do pivô (variável que sai da base)
        # É a linha com a menor razão não-negativa b[i] / A[i, pivot_col]
        ratios = np.full(num_restricoes, np.inf)
        for i in range(num_restricoes):
            if tableau[i, pivot_col] > 0:
                ratios[i] = tableau[i, -1] / tableau[i, pivot_col]
        
        pivot_row = np.argmin(ratios)
        
        # 3. Operação de Pivotamento (Gauss-Jordan)
        pivot_element = tableau[pivot_row, pivot_col]
        
        # Normaliza a linha do pivô (divide pelo elemento pivô)
        tableau[pivot_row, :] /= pivot_element

        # Zera os outros elementos na coluna do pivô
        for i in range(num_restricoes + 1):
            if i != pivot_row:
                multiplier = tableau[i, pivot_col]
                tableau[i, :] -= multiplier * tableau[pivot_row, :]

    # 4. Extração da Solução
    solucao = {}
    for i in range(num_variaveis):
        col = tableau[:, i]
        # Uma variável básica tem uma coluna com um único 1 e o resto zeros
        if np.sum(col == 1) == 1 and np.sum(col == 0) == num_restricoes:
            linha_solucao = np.where(col == 1)[0][0]
            solucao[f'x{i+1}'] = tableau[linha_solucao, -1]
        else:
            solucao[f'x{i+1}'] = 0
            
    valor_otimo = tableau[-1, -1]

    return solucao, valor_otimo