package manipulacao_bits

import "testing"

// Suíte de testes para a função FindUniqueNonRepeated
func TestFindUniqueNonRepeated(t *testing.T) {
	testCases := []struct {
		nome     string
		entrada  []int
		esperado int
	}{
		{
			nome:     "Caso Simples",
			entrada:  []int{2, 3, 2, 4, 4},
			esperado: 3,
		},
		{
			nome:     "Único no Início",
			entrada:  []int{5, 1, 2, 1, 2},
			esperado: 5,
		},
		{
			nome:     "Único no Final",
			entrada:  []int{1, 2, 1, 2, 5},
			esperado: 5,
		},
		{
			nome:     "Com Números Negativos",
			entrada:  []int{-2, 1, -3, 1, -2},
			esperado: -3,
		},
		{
			nome:     "Slice com um Único Elemento",
			entrada:  []int{100},
			esperado: 100,
		},
		{
			nome:     "Slice Vazio",
			entrada:  []int{},
			esperado: 0,
		},
		{
			nome:     "Com o número Zero como único",
			entrada:  []int{4, 0, 1, 4, 1},
			esperado: 0,
		},
	}

	for _, tc := range testCases {
		t.Run(tc.nome, func(t *testing.T) {
			resultado := FindUniqueNonRepeated(tc.entrada)
			if resultado != tc.esperado {
				t.Errorf("Para a entrada %v, esperado %d, mas obtido %d", tc.entrada, tc.esperado, resultado)
			}
		})
	}
}