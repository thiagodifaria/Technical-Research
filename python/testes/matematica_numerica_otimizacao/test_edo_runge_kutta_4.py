import pytest
import numpy as np
from matematica_numerica_otimizacao.edo_runge_kutta_4 import rk4_solve

def test_edo_simples_solucao_exata():
    """
    Testa a EDO y' = y, com y(0) = 1.
    A solução analítica é y(t) = e^t.
    """
    # Define a função da EDO: dy/dt = f(t, y)
    def f(t, y):
        # y é um array numpy, então retornamos um array
        return y

    y0 = [1.0]
    t_span = (0, 2)
    h = 0.1

    t_values, y_values = rk4_solve(f, y0, t_span, h)
    
    # O último valor de y deve ser aproximadamente e^2
    y_final_numerico = y_values[-1, 0]
    y_final_exato = np.exp(2)
    
    # Verifica se o resultado numérico está muito próximo do exato
    assert y_final_numerico == pytest.approx(y_final_exato, rel=1e-6)

def test_oscilador_harmonico_simples():
    """
    Testa o sistema de EDOs para um oscilador harmônico: y'' = -y.
    Isso é convertido para um sistema de primeira ordem:
    y1' = y2
    y2' = -y1
    onde y1 = y e y2 = y'.
    
    Condições iniciais: y(0)=1, y'(0)=0.
    Solução analítica: y(t) = cos(t), y'(t) = -sin(t).
    """
    def f(t, y):
        # y é o vetor de estado [y1, y2]
        y1, y2 = y
        dy1dt = y2
        dy2dt = -y1
        return np.array([dy1dt, dy2dt])

    y0 = [1.0, 0.0] # [y(0), y'(0)]
    t_span = (0, 2 * np.pi)
    h = 0.01

    t_values, y_values = rk4_solve(f, y0, t_span, h)
    
    y_final = y_values[-1, 0] # Posição em t=2*pi
    z_final = y_values[-1, 1] # Velocidade em t=2*pi

    # Após um período completo (2*pi), o sistema deve retornar ao estado inicial [1, 0]
    assert y_final == pytest.approx(1.0, abs=1e-4)
    assert z_final == pytest.approx(0.0, abs=1e-4)
    
    # Verifica um ponto no meio do caminho, t = pi
    # y(pi) = cos(pi) = -1
    # y'(pi) = -sin(pi) = 0
    indice_pi = np.where(t_values >= np.pi)[0][0]
    y_em_pi = y_values[indice_pi, 0]
    z_em_pi = y_values[indice_pi, 1]
    
    assert y_em_pi == pytest.approx(-1.0, abs=1e-4)
    assert z_em_pi == pytest.approx(0.0, abs=1e-4)

def test_precisao_com_tamanho_passo():
    """
    Verifica se a precisão aumenta quando o passo 'h' diminui.
    Usa a mesma EDO y' = y.
    """
    f = lambda t, y: y
    y0 = [1.0]
    t_span = (0, 1)
    y_exato_em_1 = np.exp(1)
    
    # Solução com passo grande
    _, y_passo_grande = rk4_solve(f, y0, t_span, h=0.1)
    erro_grande = abs(y_passo_grande[-1, 0] - y_exato_em_1)

    # Solução com passo pequeno
    _, y_passo_pequeno = rk4_solve(f, y0, t_span, h=0.01)
    erro_pequeno = abs(y_passo_pequeno[-1, 0] - y_exato_em_1)
    
    # O erro com passo pequeno deve ser significativamente menor
    assert erro_pequeno < erro_grande / 100 # RK4 tem erro O(h^4), 10x menor passo -> 10000x menor erro