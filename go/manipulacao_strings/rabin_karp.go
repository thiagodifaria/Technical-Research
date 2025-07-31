package manipulacao_strings

/**
 * @file rabin_karp.go
 * @brief Contém a implementação do algoritmo Rabin-Karp para busca de padrões.
 */

// constantes para o algoritmo de hash
const (
	// d é o número de caracteres no alfabeto de entrada (ex: 256 para ASCII estendido)
	d = 256
	// q é um número primo para o módulo, usado para manter os valores de hash gerenciáveis
	q = 101
)

// RabinKarp encontra todas as ocorrências de um padrão em um texto usando o algoritmo Rabin-Karp.
//
// O algoritmo funciona calculando um valor de hash para o padrão e para cada
// janela de texto do mesmo tamanho. Se os hashes correspondem, uma verificação
// caractere a caractere é feita para confirmar uma correspondência real e descartar
// colisões de hash (falsos positivos).
//
// @param texto A string na qual a busca será realizada.
// @param padrao A string padrão a ser procurada.
// @return Um slice de inteiros contendo os índices de início de todas as ocorrências.
//
// @complexity
// - Time:
//   - Average/Best Case: O(T + P), onde T é o comprimento do texto e P é o do padrão.
//   - Worst Case: O(T * P), em caso de múltiplas colisões de hash.
// - Space: O(k), onde k é o número de ocorrências, para armazenar o resultado.
func RabinKarp(texto, padrao string) []int {
	T := len(texto)
	P := len(padrao)
	var ocorrencias []int

	if P == 0 || T == 0 || P > T {
		return ocorrencias
	}

	var hashP, hashT int64
	var h int64 = 1

	// O valor de h será pow(d, P-1) % q
	for i := 0; i < P-1; i++ {
		h = (h * d) % q
	}

	// Calcula o valor de hash do padrão e da primeira janela do texto
	for i := 0; i < P; i++ {
		hashP = (d*hashP + int64(padrao[i])) % q
		hashT = (d*hashT + int64(texto[i])) % q
	}

	// Desliza a janela do padrão sobre o texto
	for i := 0; i <= T-P; i++ {
		// Compara os hashes da janela atual e do padrão.
		if hashP == hashT {
			// Se os hashes correspondem, verifica caractere por caractere
			if texto[i:i+P] == padrao {
				ocorrencias = append(ocorrencias, i)
			}
		}

		// Calcula o hash para a próxima janela do texto (rolling hash)
		if i < T-P {
			// Remove o dígito da esquerda e adiciona o da direita
			hashT = (d*(hashT-int64(texto[i])*h) + int64(texto[i+P])) % q

			// Garante que o hash não seja negativo
			if hashT < 0 {
				hashT = (hashT + q)
			}
		}
	}
	return ocorrencias
}