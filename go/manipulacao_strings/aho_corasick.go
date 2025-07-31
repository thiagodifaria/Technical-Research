package manipulacao_strings

/**
 * @file aho_corasick.go
 * @brief Contém a implementação do algoritmo Aho-Corasick para busca eficiente de múltiplos padrões.
 */

// TrieNode representa um nó na árvore de prefixos (Trie) usada pelo autômato.
type TrieNode struct {
	children    map[rune]*TrieNode
	failureLink *TrieNode
	// output armazena os padrões completos que terminam neste nó.
	output []string
}

// NewTrieNode cria e inicializa um novo nó da Trie.
func NewTrieNode() *TrieNode {
	return &TrieNode{
		children:    make(map[rune]*TrieNode),
		failureLink: nil,
		output:      []string{},
	}
}

// AhoCorasick é a estrutura principal do autômato.
type AhoCorasick struct {
	root *TrieNode
}

// NewAhoCorasick constrói o autômato de Aho-Corasick a partir de uma lista de padrões.
// A construção envolve duas fases:
// 1. Construir uma Trie com todos os padrões.
// 2. Calcular os "links de falha" para cada nó usando uma busca em largura (BFS).
func NewAhoCorasick(patterns []string) *AhoCorasick {
	ac := &AhoCorasick{root: NewTrieNode()}

	// --- Fase 1: Construir a Trie ---
	for _, pattern := range patterns {
		node := ac.root
		for _, r := range pattern {
			if node.children[r] == nil {
				node.children[r] = NewTrieNode()
			}
			node = node.children[r]
		}
		node.output = append(node.output, pattern)
	}

	// --- Fase 2: Construir os Links de Falha (usando BFS) ---
	queue := []*TrieNode{}

	// Inicializa a fila com os filhos da raiz. O link de falha deles é a própria raiz.
	for _, node := range ac.root.children {
		node.failureLink = ac.root
		queue = append(queue, node)
	}

	for len(queue) > 0 {
		currentNode := queue[0]
		queue = queue[1:]

		for char, childNode := range currentNode.children {
			// Encontra o link de falha para o filho
			tempFailureLink := currentNode.failureLink
			for tempFailureLink != nil && tempFailureLink.children[char] == nil {
				tempFailureLink = tempFailureLink.failureLink
			}

			if tempFailureLink == nil {
				childNode.failureLink = ac.root
			} else {
				childNode.failureLink = tempFailureLink.children[char]
			}

			// Acumula os outputs do link de falha. Essencial para encontrar padrões
			// que são sufixos de outros padrões (ex: "her" dentro de "hers").
			childNode.output = append(childNode.output, childNode.failureLink.output...)
			
			queue = append(queue, childNode)
		}
	}

	return ac
}

// Search encontra todas as ocorrências dos padrões no texto.
// Retorna um mapa onde a chave é o padrão encontrado e o valor é um slice
// com os índices de início das ocorrências.
func (ac *AhoCorasick) Search(text string) map[string][]int {
	foundPatterns := make(map[string][]int)
	currentNode := ac.root

	for i, r := range text {
		// Segue os links de falha até encontrar uma correspondência ou chegar à raiz.
		for currentNode != nil && currentNode.children[r] == nil {
			currentNode = currentNode.failureLink
		}

		if currentNode == nil {
			currentNode = ac.root
			continue
		}

		// Se encontrou uma transição, avança na Trie.
		currentNode = currentNode.children[r]

		// Se o nó atual tem padrões em seu output, encontramos correspondências.
		if len(currentNode.output) > 0 {
			for _, pattern := range currentNode.output {
				startIndex := i - len(pattern) + 1
				foundPatterns[pattern] = append(foundPatterns[pattern], startIndex)
			}
		}
	}
	return foundPatterns
}