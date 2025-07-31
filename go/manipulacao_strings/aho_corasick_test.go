package manipulacao_strings

import (
	"reflect"
	"sort"
	"testing"
)

// Helper para normalizar o mapa de resultados para comparação,
// ordenando os slices de índices.
func normalizeResults(results map[string][]int) {
	for _, indices := range results {
		sort.Ints(indices)
	}
}

func TestAhoCorasick(t *testing.T) {
	t.Run("Teste Múltiplos Padrões Não Sobrepostos", func(t *testing.T) {
		patterns := []string{"he", "she", "his", "hers"}
		text := "ushers"
		ac := NewAhoCorasick(patterns)
		results := ac.Search(text)
		normalizeResults(results)

		expected := map[string][]int{
			"she":  {1},
			"he":   {2},
			"hers": {2},
		}
		
		if !reflect.DeepEqual(results, expected) {
			t.Errorf("Esperado %v, obtido %v", expected, results)
		}
	})

	t.Run("Teste Padrões Sobrepostos", func(t *testing.T) {
		patterns := []string{"ab", "bca", "ca"}
		text := "abcalog"
		ac := NewAhoCorasick(patterns)
		results := ac.Search(text)
		normalizeResults(results)
		
		expected := map[string][]int{
			"ab":  {0},
			"bca": {1},
			"ca":  {2},
		}

		if !reflect.DeepEqual(results, expected) {
			t.Errorf("Esperado %v, obtido %v", expected, results)
		}
	})
	
	t.Run("Teste Padrão é Substring de Outro", func(t *testing.T) {
		patterns := []string{"a", "ab", "abc"}
		text := "xabcy"
		ac := NewAhoCorasick(patterns)
		results := ac.Search(text)
		normalizeResults(results)

		// A busca deve encontrar "a", "ab", e "abc" quando o 'c' é alcançado.
		expected := map[string][]int{
			"a":   {1},
			"ab":  {1},
			"abc": {1},
		}
		
		if !reflect.DeepEqual(results, expected) {
			t.Errorf("Esperado %v, obtido %v", expected, results)
		}
	})

	t.Run("Teste Sem Correspondências", func(t *testing.T) {
		patterns := []string{"notFound", "missing"}
		text := "this is a simple text"
		ac := NewAhoCorasick(patterns)
		results := ac.Search(text)
		
		if len(results) != 0 {
			t.Errorf("Esperado mapa vazio, obtido %v", results)
		}
	})
	
	t.Run("Teste Casos de Borda", func(t *testing.T) {
		// Lista de padrões vazia
		ac1 := NewAhoCorasick([]string{})
		res1 := ac1.Search("some text")
		if len(res1) != 0 {
			t.Errorf("Esperado mapa vazio para lista de padrões vazia, obtido %v", res1)
		}

		// Texto vazio
		ac2 := NewAhoCorasick([]string{"a", "b"})
		res2 := ac2.Search("")
		if len(res2) != 0 {
			t.Errorf("Esperado mapa vazio para texto vazio, obtido %v", res2)
		}
	})

	t.Run("Teste Múltiplas Ocorrências do Mesmo Padrão", func(t *testing.T) {
		patterns := []string{"ana", "na"}
		text := "banana"
		ac := NewAhoCorasick(patterns)
		results := ac.Search(text)
		normalizeResults(results)

		expected := map[string][]int{
			"ana": {1, 3},
			"na": {2, 4},
		}

		if !reflect.DeepEqual(results, expected) {
			t.Errorf("Esperado %v, obtido %v", expected, results)
		}
	})
}