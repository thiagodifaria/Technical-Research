import math
import random

# --- Funções Auxiliares (Teste de Primalidade Miller-Rabin) ---

def _power(base, exp, mod):
    """Calcula (base^exp) % mod de forma eficiente."""
    res = 1
    base %= mod
    while exp > 0:
        if exp % 2 == 1:
            res = (res * base) % mod
        base = (base * base) % mod
        exp //= 2
    return res

def _is_prime_miller_rabin(n, k=10):
    """
    Teste de primalidade de Miller-Rabin.
    Retorna True se n for provavelmente primo, False se for composto.
    k é o número de rodadas para aumentar a precisão.
    """
    if n < 2: return False
    if n == 2 or n == 3: return True
    if n % 2 == 0: return False

    d, s = n - 1, 0
    while d % 2 == 0:
        d //= 2
        s += 1

    for _ in range(k):
        a = random.randint(2, n - 2)
        x = _power(a, d, n)
        if x == 1 or x == n - 1:
            continue
        
        composite = True
        for _ in range(s - 1):
            x = _power(x, 2, n)
            if x == n - 1:
                composite = False
                break
        if composite:
            return False
    return True


# --- Algoritmo Principal ---

def pollard_rho(n):
    """
    Encontra um fator não trivial de n usando o Algoritmo Rho de Pollard.
    Retorna n se n for primo.

    @param n O número a ser fatorado.
    @return Um fator não trivial de n, ou n se n for primo.

    @complexity
    - Time: Aproximadamente O(n^(1/4)), em média.
    - Space: O(1)
    """
    if _is_prime_miller_rabin(n):
        return n
    if n % 2 == 0:
        return 2

    # Tenta diferentes pontos de partida e funções se a primeira falhar
    c = 1
    while True:
        f = lambda x: (x**2 + c) % n
        x = y = 2
        d = 1
        while d == 1:
            x = f(x)
            y = f(f(y))
            d = math.gcd(abs(x - y), n)
        
        if d != n:
            return d
        
        # Falhou (encontrou um ciclo antes de um fator), tenta novamente com c diferente
        c += 1

def factorize(n):
    """
    Encontra todos os fatores primos de um número n usando o Algoritmo Rho de Pollard.

    @param n O número a ser fatorado.
    @return Uma lista contendo todos os fatores primos de n, ordenados.
    """
    if n <= 1:
        return []
    
    fatores = []
    
    def get_factors(num):
        if num <= 1:
            return
        if _is_prime_miller_rabin(num):
            fatores.append(num)
            return

        fator = pollard_rho(num)
        get_factors(fator)
        get_factors(num // fator)

    get_factors(n)
    fatores.sort()
    return fatores