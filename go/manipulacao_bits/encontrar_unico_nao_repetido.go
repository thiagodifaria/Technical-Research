package manipulacao_bits

/**
 * @file encontrar_unico_nao_repetido.go
 * @brief Contém a implementação para encontrar o único número não repetido em um slice.
 */

// FindUniqueNonRepeated encontra o único elemento em um slice de inteiros que
// aparece apenas uma vez, enquanto todos os outros elementos aparecem duas vezes.
//
// A solução utiliza o operador bitwise XOR (^). Com base nas propriedades
// de que A^A=0 e A^0=A, ao aplicar XOR em todos os elementos do slice, os
// pares de números idênticos se anulam (resultando em 0). O resultado final
// da operação acumulada será o único número que não tinha par.
//
// @param nums O slice de inteiros.
// @return O único elemento que não se repete.
//
// @complexity
// - Time: O(n), pois iteramos pelo slice uma única vez.
// - Space: O(1), pois usamos apenas uma variável extra para o resultado.
func FindUniqueNonRepeated(nums []int) int {
	// O valor inicial é 0, que é o elemento neutro da operação XOR.
	uniqueNum := 0
	for _, num := range nums {
		uniqueNum ^= num
	}
	return uniqueNum
}