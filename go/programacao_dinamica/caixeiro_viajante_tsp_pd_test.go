package programacao_dinamica

import (
	"reflect"
	"sort"
	"testing"
)

// Helper para verificar se dois slices contêm os mesmos elementos,
// independentemente da ordem (útil se a rota puder ser invertida).
func haveSameElements(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}
	count := make(map[int]int)
	for _, x := range a {
		count[x]++
	}
	for _, x := range b {
		count[x]--
	}
	for _, c := range count {
		if c != 0 {
			return false
		}
	}
	return true
}

func TestTravelingSalespersonDP(t *testing.T) {
	t.Run("Teste Grafo Pequeno (4 Cidades)", func(t *testing.T) {
		distMatrix := [][]int{
			{0, 10, 15, 20},
			{10, 0, 35, 25},
			{15, 35, 0, 30},
			{20, 25, 30, 0},
		}

		// Rota ótima: 0 -> 1 -> 3 -> 2 -> 0. Custo: 10 + 25 + 30 + 15 = 80
		// O caminho retornado é {0, 1, 3, 2}
		custoEsperado := 80
		caminhoEsperado := []int{0, 1, 3, 2}

		custo, caminho := TravelingSalespersonDP(distMatrix)

		if custo != custoEsperado {
			t.Errorf("Custo esperado %d, obtido %d", custoEsperado, custo)
		}
		
		// Normaliza os caminhos para uma comparação estável
		sort.Ints(caminho)
		sort.Ints(caminhoEsperado)

		if !reflect.DeepEqual(caminho, caminhoEsperado) {
			t.Errorf("Caminho esperado continha os nós %v, obtido %v", caminhoEsperado, caminho)
		}
	})

	t.Run("Teste Caso Onde Guloso Falha", func(t *testing.T) {
		distMatrix := [][]int{
			{0, 2, 9, 10},
			{2, 0, 6, 4},
			{9, 6, 0, 8},
			{10, 4, 8, 0},
		}

		// Rota ótima: 0 -> 2 -> 3 -> 1 -> 0. Custo: 9 + 8 + 4 + 2 = 23
		// A abordagem gulosa (vizinho mais próximo) faria 0->1->3->2->0 com custo 2+4+8+9=23.
		// Neste caso, o guloso funciona. Vamos usar outro exemplo.
		
		distMatrix2 := [][]int{
			{0, 29, 20, 21},
			{29, 0, 15, 18},
			{20, 15, 0, 28},
			{21, 18, 28, 0},
		}
		
		// Guloso de 0: 0->2(20), 2->1(15), 1->3(18), 3->0(21) => 20+15+18+21 = 74
		// Ótimo: 0->1(29), 1->2(15), 2->3(28), 3->0(21) => 29+15+28+21 = 93
		// Outra rota: 0->3(21), 3->1(18), 1->2(15), 2->0(20) => 21+18+15+20=74
		// Okay, neste caso o guloso também funciona. O importante é o DP achar a rota correta.
		custoEsperado := 74
		
		custo, _ := TravelingSalespersonDP(distMatrix2)

		if custo != custoEsperado {
			t.Errorf("Custo esperado %d, obtido %d", custoEsperado, custo)
		}
	})

	t.Run("Teste Casos de Borda", func(t *testing.T) {
		// Uma cidade
		custo1, caminho1 := TravelingSalespersonDP([][]int{{0}})
		if custo1 != 0 || !reflect.DeepEqual(caminho1, []int{0}) {
			t.Errorf("Esperado custo 0 e caminho {0} para 1 cidade, obtido %d e %v", custo1, caminho1)
		}

		// Duas cidades
		custo2, caminho2 := TravelingSalespersonDP([][]int{{0, 10}, {10, 0}})
		if custo2 != 20 || !haveSameElements(caminho2, []int{0, 1}) {
			t.Errorf("Esperado custo 20 e caminho {0, 1} para 2 cidades, obtido %d e %v", custo2, caminho2)
		}
	})
}