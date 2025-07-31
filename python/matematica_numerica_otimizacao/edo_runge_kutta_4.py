import numpy as np

def rk4_solve(f, y0, t_span, h):
    """
    Resolve um sistema de Equações Diferenciais Ordinárias (EDOs) de primeira ordem
    usando o método de Runge-Kutta de 4ª ordem.

    O método aproxima a solução de y' = f(t, y) com y(t0) = y0.

    Args:
        f (callable): A função que define a EDO. Deve aceitar dois argumentos,
                      t (tempo, um float) e y (estado, um np.array), e retornar
                      um np.array com os valores de dy/dt.
        y0 (list or np.array): O vetor de condições iniciais y(t0).
        t_span (tuple): Uma tupla (t_inicial, t_final) especificando o
                        intervalo de integração.
        h (float): O tamanho do passo de integração.

    Returns:
        tuple: Uma tupla (t_values, y_values) onde:
            - t_values é um np.array com os pontos de tempo.
            - y_values é um np.array 2D onde cada linha corresponde ao
              vetor de estado 'y' no tempo correspondente.

    @complexity
    - Time: O((t_final - t_inicial) / h), proporcional ao número de passos.
    - Space: O(N * m), onde N é o número de passos e m é o número de equações.
    """
    t_inicial, t_final = t_span
    t_values = np.arange(t_inicial, t_final + h, h)
    
    # Converte y0 para um array numpy para operações vetoriais
    y = np.array(y0, dtype=float)
    
    # Prepara o array para armazenar os resultados
    y_values = np.zeros((len(t_values), len(y)))
    y_values[0, :] = y

    for i in range(len(t_values) - 1):
        t = t_values[i]
        
        # Fórmula de Runge-Kutta de 4ª Ordem
        k1 = h * f(t, y)
        k2 = h * f(t + 0.5 * h, y + 0.5 * k1)
        k3 = h * f(t + 0.5 * h, y + 0.5 * k2)
        k4 = h * f(t + h, y + k3)
        
        # Atualiza o estado y para o próximo passo de tempo
        y += (k1 + 2*k2 + 2*k3 + k4) / 6.0
        
        y_values[i + 1, :] = y

    return t_values, y_values