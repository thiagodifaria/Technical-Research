package manipulacao_strings

import (
	"reflect"
	"sort"
	"testing"
)

func TestRabinKarp(t *testing.T) {
	testCases := []struct {
		nome     string
		texto    string
		padrao   string
		esperado []int
	}{
		{
			nome:     "Padrão no início",
			texto:    "ABCDEF",
			padrao:   "ABC",
			esperado: []int{0},
		},
		{
			nome:     "Padrão no final",
			texto:    "ABCDEF",
			padrao:   "DEF",
			esperado: []int{3},
		},
		{
			nome:     "Múltiplas ocorrências",
			texto:    "abracadabra",
			padrao:   "abra",
			esperado: []int{0, 7},
		},
		{
			nome:     "Ocorrências sobrepostas",
			texto:    "aaaaa",
			padrao:   "aa",
			esperado: []int{0, 1, 2, 3},
		},
		{
			nome:     "Padrão inexistente",
			texto:    "ABCDEF",
			padrao:   "XYZ",
			esperado: []int{},
		},
		{
			nome:     "Padrão maior que o texto",
			texto:    "curto",
			padrao:   "textomaior",
			esperado: []int{},
		},
		{
			nome:     "Texto vazio",
			texto:    "",
			padrao:   "padrao",
			esperado: []int{},
		},
		{
			nome:     "Padrão vazio",
			texto:    "texto",
			padrao:   "",
			esperado: []int{},
		},
		{
			nome:     "Ambos vazios",
			texto:    "",
			padrao:   "",
			esperado: []int{},
		},
		{
			nome:     "Caso complexo",
			texto:    "AABAACAADAABAABA",
			padrao:   "AABA",
			esperado: []int{0, 9, 12},
		},
	}

	for _, tc := range testCases {
		t.Run(tc.nome, func(t *testing.T) {
			resultado := RabinKarp(tc.texto, tc.padrao)
			// Ordena para garantir comparação determinística
			sort.Ints(resultado)
			sort.Ints(tc.esperado)

			// Lida com o caso de slices nulos vs. vazios para DeepEqual
			if len(resultado) == 0 && len(tc.esperado) == 0 {
				return // Teste passa
			}

			if !reflect.DeepEqual(resultado, tc.esperado) {
				t.Errorf("Esperado %v, obtido %v", tc.esperado, resultado)
			}
		})
	}
}