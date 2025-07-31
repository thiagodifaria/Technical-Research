package estruturas_dados

/**
 * @file disjoint_set_union.go
 * @brief Contém a implementação da estrutura de dados Disjoint Set Union (DSU) ou Union-Find.
 */

// DSU representa a estrutura de dados Union-Find.
// Ela mantém um conjunto de elementos particionados em um número de conjuntos disjuntos.
type DSU struct {
	// parent[i] armazena o pai do elemento i.
	parent []int
	// rank[i] armazena a "altura" ou "rank" da árvore cujo raiz é i.
	// Usado para a otimização "Union by Rank".
	rank []int
}

// NewDSU cria e inicializa uma nova estrutura DSU com um determinado tamanho.
// Inicialmente, cada elemento está em seu próprio conjunto (é seu próprio pai) com rank 0.
func NewDSU(size int) *DSU {
	parent := make([]int, size)
	rank := make([]int, size)
	for i := 0; i < size; i++ {
		parent[i] = i
		rank[i] = 0
	}
	return &DSU{parent: parent, rank: rank}
}

// Find encontra o representante (raiz) do conjunto ao qual o elemento i pertence.
// Implementa a otimização de "Path Compression" (Compressão de Caminho).
// Durante a busca pela raiz, faz com que todos os nós no caminho apontem
// diretamente para a raiz, achatando a árvore e acelerando buscas futuras.
// A complexidade é O(α(n)) (amortizada), onde α é a função inversa de Ackermann,
// que é praticamente constante para todos os valores práticos de n.
func (dsu *DSU) Find(i int) int {
	if dsu.parent[i] == i {
		return i
	}
	// Compressão de Caminho: aponta o pai de i diretamente para a raiz.
	dsu.parent[i] = dsu.Find(dsu.parent[i])
	return dsu.parent[i]
}

// Union une os conjuntos que contêm os elementos i e j.
// Implementa a otimização de "Union by Rank".
// Para evitar que as árvores se tornem muito altas, a árvore com menor rank
// é sempre anexada à raiz da árvore com maior rank.
// A complexidade também é O(α(n)) (amortizada).
func (dsu *DSU) Union(i, j int) {
	rootI := dsu.Find(i)
	rootJ := dsu.Find(j)

	if rootI != rootJ {
		// Se os ranks são diferentes, a árvore de menor rank se torna filha da de maior rank.
		if dsu.rank[rootI] < dsu.rank[rootJ] {
			dsu.parent[rootI] = rootJ
		} else if dsu.rank[rootJ] < dsu.rank[rootI] {
			dsu.parent[rootJ] = rootI
		} else {
			// Se os ranks são iguais, escolhemos uma como pai e incrementamos seu rank.
			dsu.parent[rootJ] = rootI
			dsu.rank[rootI]++
		}
	}
}