package geometria_computacional

import (
	"math"
	"testing"
)

const floatEqualityThreshold = 1e-9

func almostEqual(a, b float64) bool {
	return math.Abs(a-b) <= floatEqualityThreshold
}

func TestClosestPair(t *testing.T) {
	t.Run("Teste Caso Simples", func(t *testing.T) {
		points := []Point{{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}}
		// O par mais próximo é (2,3) e (3,4), distância sqrt( (3-2)^2 + (4-3)^2 ) = sqrt(2)
		distanciaEsperada := math.Sqrt(2)
		distanciaObtida := ClosestPair(points)
		if !almostEqual(distanciaObtida, distanciaEsperada) {
			t.Errorf("Esperado %f, obtido %f", distanciaEsperada, distanciaObtida)
		}
	})

	t.Run("Teste Par Dividido (Split Pair)", func(t *testing.T) {
		// Este caso é projetado para que o par mais próximo esteja na faixa do meio.
		points := []Point{
			{0, 0}, {100, 100}, // Pontos distantes
			{49, 50}, {51, 50},   // O par mais próximo, com distância 2.0
			{48, 0}, {52, 100},  // Outros pontos na faixa
		}
		distanciaEsperada := 2.0
		distanciaObtida := ClosestPair(points)
		if !almostEqual(distanciaObtida, distanciaEsperada) {
			t.Errorf("Esperado %f, obtido %f", distanciaEsperada, distanciaObtida)
		}
	})

	t.Run("Teste Pontos Colineares Verticais", func(t *testing.T) {
		points := []Point{{0, 0}, {0, 10}, {0, 2}, {0, 50}}
		// O par mais próximo é (0,0) e (0,2), distância 2.0
		distanciaEsperada := 2.0
		distanciaObtida := ClosestPair(points)
		if !almostEqual(distanciaObtida, distanciaEsperada) {
			t.Errorf("Esperado %f, obtido %f", distanciaEsperada, distanciaObtida)
		}
	})

	t.Run("Teste Pontos Colineares Horizontais", func(t *testing.T) {
		points := []Point{{0, 0}, {10, 0}, {2, 0}, {50, 0}}
		// O par mais próximo é (0,0) e (2,0), distância 2.0
		distanciaEsperada := 2.0
		distanciaObtida := ClosestPair(points)
		if !almostEqual(distanciaObtida, distanciaEsperada) {
			t.Errorf("Esperado %f, obtido %f", distanciaEsperada, distanciaObtida)
		}
	})

	t.Run("Teste Casos de Borda", func(t *testing.T) {
		// Menos de 2 pontos
		points0 := []Point{}
		points1 := []Point{{1, 1}}
		if !math.IsInf(ClosestPair(points0), 1) || !math.IsInf(ClosestPair(points1), 1) {
			t.Error("Esperado Infinito para menos de 2 pontos")
		}

		// Exatamente 2 pontos
		points2 := []Point{{0, 0}, {3, 4}}
		if !almostEqual(ClosestPair(points2), 5.0) {
			t.Errorf("Esperado 5.0 para os pontos (0,0) e (3,4), obtido %f", ClosestPair(points2))
		}
		
		// Exatamente 3 pontos
		points3 := []Point{{0, 0}, {3, 4}, {7, 0}}
		if !almostEqual(ClosestPair(points3), 5.0) {
			t.Errorf("Esperado 5.0 para o conjunto de 3 pontos, obtido %f", ClosestPair(points3))
		}
	})
}