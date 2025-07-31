package estruturas_dados

import "testing"

// Suíte de testes para a estrutura de dados Disjoint Set Union (DSU)
func TestNewDSU(t *testing.T) {
	t.Run("Verifica a inicialização", func(t *testing.T) {
		size := 10
		dsu := NewDSU(size)

		if len(dsu.parent) != size || len(dsu.rank) != size {
			t.Fatalf("Tamanho incorreto dos slices. Esperado %d, obtido parent=%d, rank=%d", size, len(dsu.parent), len(dsu.rank))
		}

		for i := 0; i < size; i++ {
			if dsu.parent[i] != i {
				t.Errorf("Elemento %d deveria ser seu próprio pai na inicialização, mas é %d", i, dsu.parent[i])
			}
			if dsu.rank[i] != 0 {
				t.Errorf("Rank do elemento %d deveria ser 0 na inicialização, mas é %d", i, dsu.rank[i])
			}
		}
	})
}

func TestUnionAndFind(t *testing.T) {
	t.Run("Verifica operações básicas de Union e Find", func(t *testing.T) {
		dsu := NewDSU(5)

		dsu.Union(0, 2)
		dsu.Union(1, 3)

		if dsu.Find(0) != dsu.Find(2) {
			t.Error("0 e 2 deveriam estar no mesmo conjunto após a união.")
		}
		if dsu.Find(1) != dsu.Find(3) {
			t.Error("1 e 3 deveriam estar no mesmo conjunto após a união.")
		}
		if dsu.Find(0) == dsu.Find(1) {
			t.Error("0 e 1 não deveriam estar no mesmo conjunto.")
		}

		dsu.Union(0, 3)
		if dsu.Find(0) != dsu.Find(3) {
			t.Error("0 e 3 deveriam estar no mesmo conjunto após a união.")
		}
		if dsu.Find(2) != dsu.Find(1) {
			t.Error("2 e 1 deveriam estar no mesmo conjunto após a união transitiva.")
		}
	})
}

func TestPathCompression(t *testing.T) {
	t.Run("Verifica se a compressão de caminho está funcionando", func(t *testing.T) {
		dsu := NewDSU(5)
		// Cria uma cadeia: 0 -> 1 -> 2 -> 3 -> 4 (4 é a raiz)
		// Forçamos a estrutura sem Union by Rank para o teste ser mais claro
		dsu.parent[0] = 1
		dsu.parent[1] = 2
		dsu.parent[2] = 3
		dsu.parent[3] = 4

		// Chama Find em 0. Isso deve comprimir o caminho.
		root := dsu.Find(0)

		if root != 4 {
			t.Fatalf("A raiz de 0 deveria ser 4, mas foi %d", root)
		}

		// Verifica se os pais foram atualizados para apontar diretamente para a raiz.
		if dsu.parent[0] != 4 {
			t.Errorf("Compressão de caminho falhou para o nó 0. Pai é %d, esperado 4", dsu.parent[0])
		}
		if dsu.parent[1] != 4 {
			t.Errorf("Compressão de caminho falhou para o nó 1. Pai é %d, esperado 4", dsu.parent[1])
		}
		if dsu.parent[2] != 4 {
			t.Errorf("Compressão de caminho falhou para o nó 2. Pai é %d, esperado 4", dsu.parent[2])
		}
	})
}

func TestUnionByRank(t *testing.T) {
	t.Run("Verifica se a união por rank está funcionando", func(t *testing.T) {
		dsu := NewDSU(5)

		dsu.Union(0, 1) // rank(raiz de 0) se torna 1
		dsu.Union(2, 3) // rank(raiz de 2) se torna 1

		root0 := dsu.Find(0)
		root2 := dsu.Find(2)
		if dsu.rank[root0] != 1 || dsu.rank[root2] != 1 {
			t.Fatal("Ranks iniciais incorretos após as primeiras uniões.")
		}

		// Une duas árvores de mesmo rank
		dsu.Union(0, 2)
		newRoot := dsu.Find(0)
		if dsu.rank[newRoot] != 2 {
			t.Errorf("Rank da nova árvore deveria ser 2, mas é %d", dsu.rank[newRoot])
		}

		// Une uma árvore de rank 0 a uma de rank 2
		root4 := dsu.Find(4)
		rankBefore := dsu.rank[newRoot]
		dsu.Union(4, 0)
		
		// O pai de 4 deve ser a raiz da outra árvore, e o rank da raiz não deve mudar
		if dsu.Find(4) != newRoot {
			t.Error("A árvore de menor rank (4) não foi anexada à de maior rank.")
		}
		if dsu.rank[newRoot] != rankBefore {
			t.Errorf("O rank da árvore maior não deveria mudar ao anexar uma menor. Esperado %d, obtido %d", rankBefore, dsu.rank[newRoot])
		}
	})
}

func TestUnionOnSameSet(t *testing.T) {
	t.Run("Verifica se a união em um mesmo conjunto não altera a estrutura", func(t *testing.T) {
		dsu := NewDSU(3)
		dsu.Union(0, 1)
		
		root := dsu.Find(0)
		rankBefore := dsu.rank[root]
		
		dsu.Union(0, 1) // Repete a união
		
		if dsu.rank[root] != rankBefore {
			t.Errorf("O rank não deveria mudar ao unir elementos do mesmo conjunto. Esperado %d, obtido %d", rankBefore, dsu.rank[root])
		}
	})
}