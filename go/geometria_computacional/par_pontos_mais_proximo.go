package geometria_computacional

import (
	"math"
	"sort"
)

/**
 * @file par_pontos_mais_proximo.go
 * @brief Contém a implementação do algoritmo de dividir para conquistar para encontrar
 * o par de pontos mais próximo em um plano.
 */

// Point representa um ponto no plano 2D.
type Point struct {
	X, Y float64
}

// distance calcula a distância euclidiana entre dois pontos.
func distance(p1, p2 Point) float64 {
	dx := p1.X - p2.X
	dy := p1.Y - p2.Y
	return math.Sqrt(dx*dx + dy*dy)
}

// bruteForceClosest encontra a menor distância em um pequeno conjunto de pontos
// usando força bruta. Serve como caso base para a recursão.
func bruteForceClosest(points []Point) float64 {
	minDist := math.Inf(1)
	for i := 0; i < len(points); i++ {
		for j := i + 1; j < len(points); j++ {
			dist := distance(points[i], points[j])
			if dist < minDist {
				minDist = dist
			}
		}
	}
	return minDist
}

// closestUtil é a função recursiva principal do algoritmo.
func closestUtil(pointsX []Point) float64 {
	n := len(pointsX)

	// Caso base: se houver 3 ou menos pontos, usa força bruta.
	if n <= 3 {
		return bruteForceClosest(pointsX)
	}

	// Divide
	mid := n / 2
	midPoint := pointsX[mid]

	// Conquista: encontra a menor distância nas metades esquerda e direita.
	distLeft := closestUtil(pointsX[:mid])
	distRight := closestUtil(pointsX[mid:])
	minDist := math.Min(distLeft, distRight)

	// Combina: encontra a menor distância entre pontos que cruzam a linha mediana.
	// Cria uma "faixa" (strip) de pontos que estão a uma distância `minDist` da linha mediana.
	strip := []Point{}
	for i := 0; i < n; i++ {
		if math.Abs(pointsX[i].X-midPoint.X) < minDist {
			strip = append(strip, pointsX[i])
		}
	}
	
	// Ordena a faixa pela coordenada Y para otimizar a busca.
	sort.Slice(strip, func(i, j int) bool {
		return strip[i].Y < strip[j].Y
	})


	// Verifica as distâncias na faixa.
	// A teoria garante que para cada ponto, só precisamos verificar um
	// número constante de pontos seguintes na faixa ordenada por Y.
	for i := 0; i < len(strip); i++ {
		for j := i + 1; j < len(strip) && (strip[j].Y-strip[i].Y) < minDist; j++ {
			dist := distance(strip[i], strip[j])
			if dist < minDist {
				minDist = dist
			}
		}
	}

	return minDist
}


// ClosestPair é a função pública que inicia o processo.
//
// @param points Um slice de Pontos.
// @return A menor distância euclidiana entre qualquer par de pontos.
//
// @complexity
// - Time: O(n log n), dominado pela ordenação inicial. A relação de recorrência
//   do algoritmo é T(n) = 2T(n/2) + O(n), que resolve para O(n log n).
// - Space: O(n), para armazenar cópias dos pontos e a faixa (strip).
func ClosestPair(points []Point) float64 {
	if len(points) < 2 {
		return math.Inf(1)
	}

	// Cria uma cópia para não modificar o slice original.
	pointsCopy := make([]Point, len(points))
	copy(pointsCopy, points)

	// Pré-ordenação por X, que é crucial para a divisão.
	sort.Slice(pointsCopy, func(i, j int) bool {
		return pointsCopy[i].X < pointsCopy[j].X
	})

	return closestUtil(pointsCopy)
}