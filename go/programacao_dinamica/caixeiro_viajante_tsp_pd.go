package programacao_dinamica

import "math"

const INF = math.MaxInt32

// TravelingSalespersonDP resolve o Problema do Caixeiro Viajante para um grafo completo
// usando o algoritmo de Held-Karp (Programação Dinâmica com bitmasking).
//
// @param distMatrix A matriz de adjacência representando as distâncias entre as cidades.
// distMatrix[i][j] é a distância da cidade i para a cidade j.
// @return A distância total da rota mais curta e um slice de inteiros representando
// a sequência de cidades na rota ótima (começando e terminando na cidade 0).
//
// @complexity
// - Time: O(N^2 * 2^N), onde N é o número de cidades.
// - Space: O(N * 2^N), para a tabela de DP e a tabela de reconstrução de caminho.
func TravelingSalespersonDP(distMatrix [][]int) (int, []int) {
	n := len(distMatrix)
	if n == 0 {
		return 0, []int{}
	}
	if n == 1 {
		return 0, []int{0}
	}

	// dp[mask][i] armazena o custo do caminho mais curto que começa em 0,
	// visita todas as cidades no 'mask' e termina na cidade 'i'.
	dp := make([][]int, 1<<n)
	// path[mask][i] armazena o predecessor de 'i' no caminho ótimo para o estado {mask, i}.
	path := make([][]int, 1<<n)
	for i := range dp {
		dp[i] = make([]int, n)
		path[i] = make([]int, n)
		for j := range dp[i] {
			dp[i][j] = INF
			path[i][j] = -1
		}
	}

	// Caso base: o caminho que visita apenas a cidade 0 e termina nela tem custo 0.
	// A máscara '1' (binário ...0001) representa o conjunto {cidade 0}.
	dp[1][0] = 0

	// Itera sobre todos os subconjuntos (masks) de cidades
	for mask := 1; mask < 1<<n; mask++ {
		// Itera sobre todas as cidades 'i' como possível ponto final do caminho
		for i := 0; i < n; i++ {
			// Verifica se a cidade 'i' está no subconjunto atual (mask)
			if (mask & (1 << i)) != 0 {
				// Itera sobre todas as cidades 'j' como possível predecessor de 'i'
				for j := 0; j < n; j++ {
					if i != j && (mask&(1<<j)) != 0 {
						prevMask := mask ^ (1 << i) // Subconjunto sem a cidade 'i'
						if dp[prevMask][j] != INF && dp[prevMask][j]+distMatrix[j][i] < dp[mask][i] {
							dp[mask][i] = dp[prevMask][j] + distMatrix[j][i]
							path[mask][i] = j
						}
					}
				}
			}
		}
	}

	// Encontra a rota completa ótima
	finalMask := (1 << n) - 1 // Máscara com todas as cidades visitadas
	minCost := INF
	lastCity := -1

	// Encontra o custo mínimo adicionando a aresta de volta para a cidade 0
	for i := 1; i < n; i++ {
		if dp[finalMask][i] != INF && dp[finalMask][i]+distMatrix[i][0] < minCost {
			minCost = dp[finalMask][i] + distMatrix[i][0]
			lastCity = i
		}
	}

	if lastCity == -1 {
		// Caso de 2 cidades
		if n == 2 {
			return distMatrix[0][1] + distMatrix[1][0], []int{0, 1}
		}
		return -1, nil // Nenhuma solução encontrada
	}

	// Reconstrução do caminho
	optimalPath := make([]int, n)
	currentMask := finalMask
	for i := n - 1; i >= 1; i-- {
		optimalPath[i] = lastCity
		prevCity := path[currentMask][lastCity]
		currentMask ^= (1 << lastCity) // Remove a cidade atual da máscara
		lastCity = prevCity
	}
	optimalPath[0] = 0 // A origem é sempre 0

	return minCost, optimalPath
}